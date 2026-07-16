#include "bigint.hpp"
#include <stdexcept>
#include <algorithm>

// ═══════════════════════════════════════════════════════════════════════════════
//  UTILITAIRES PRIVÉS
// ═══════════════════════════════════════════════════════════════════════════════

// Supprime les zéros de tête (en queue du vecteur little-endian).
// Garde toujours au moins un chiffre (le cas "0").
void bigint::_removeLeadingZeros() {
    while (_digits.size() > 1 && _digits.back() == 0)
        _digits.pop_back();
}

// Convertit le bigint en unsigned long long.
// Utilisé pour les shifts (on suppose que n tient dans un ULL).
unsigned long long bigint::_toULL() const {
    unsigned long long result = 0;
    unsigned long long base   = 1;
    for (size_t i = 0; i < _digits.size(); ++i) {
        result += static_cast<unsigned long long>(_digits[i]) * base;
        base   *= 10;
    }
    return result;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  FORME CANONIQUE ORTHODOXE
// ═══════════════════════════════════════════════════════════════════════════════

// Constructeur par défaut → 0
bigint::bigint() : _digits(1, 0) {}

// Depuis un unsigned long long
//   Ex: 1337 → _digits = {7, 3, 3, 1}
bigint::bigint(unsigned long long n) {
    if (n == 0) {
        _digits.push_back(0);
        return;
    }
    while (n > 0) {
        _digits.push_back(static_cast<int>(n % 10));
        n /= 10;
    }
}

// Depuis une string
//   Ex: "1337" → _digits = {7, 3, 3, 1}
bigint::bigint(const std::string& s) {
    if (s.empty())
        throw std::invalid_argument("bigint: chaîne vide");
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        if (s[i] < '0' || s[i] > '9')
            throw std::invalid_argument("bigint: caractère invalide");
        _digits.push_back(s[i] - '0');
    }
    _removeLeadingZeros();
}

// Constructeur par copie
bigint::bigint(const bigint& other) : _digits(other._digits) {}

// Opérateur d'affectation
bigint& bigint::operator=(const bigint& other) {
    if (this != &other)
        _digits = other._digits;
    return *this;
}

// Destructeur
bigint::~bigint() {}

// ═══════════════════════════════════════════════════════════════════════════════
//  ADDITION
// ═══════════════════════════════════════════════════════════════════════════════

//  Algorithme : addition chiffre par chiffre avec retenue, gauche → droite
//  Ex:  123 + 99
//       A = {3,2,1}   B = {9,9}
//       i=0 : 3+9    = 12  → push 2, carry=1
//       i=1 : 2+9+1  = 12  → push 2, carry=1
//       i=2 : 1+0+1  =  2  → push 2, carry=0
//       résultat : {2,2,2} → "222" ✓

bigint bigint::operator+(const bigint& other) const {
    bigint result;
    result._digits.clear();

    int    carry  = 0;
    size_t maxLen = std::max(_digits.size(), other._digits.size());

    for (size_t i = 0; i < maxLen || carry; ++i) {
        int sum = carry;
        if (i < _digits.size())       sum += _digits[i];
        if (i < other._digits.size()) sum += other._digits[i];

        result._digits.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  INCRÉMENTATION
// ═══════════════════════════════════════════════════════════════════════════════

// Préfixe : ++b → incrémente puis retourne *this
bigint& bigint::operator++() {
    *this += bigint(1ULL);
    return *this;
}

// Postfixe : b++ → sauvegarde l'ancienne valeur, incrémente, retourne l'ancienne
bigint bigint::operator++(int) {
    bigint old(*this);
    *this += bigint(1ULL);
    return old;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  DIGIT SHIFT GAUCHE  (× 10^n)
// ═══════════════════════════════════════════════════════════════════════════════

//  42 << 3  →  42000
//  little-endian : {2,4} << 3  →  {0,0,0,2,4}
//  On insère n zéros au début du vecteur (positions de poids faible).

bigint bigint::operator<<(const bigint& n) const {
    // 0 << n = 0
    if (_digits.size() == 1 && _digits[0] == 0)
        return *this;

    unsigned long long shift = n._toULL();

    bigint result;
    result._digits.clear();
    result._digits.resize(shift, 0);                        // n zéros devant
    result._digits.insert(result._digits.end(),
                          _digits.begin(), _digits.end()); // puis les chiffres
    return result;
}

bigint& bigint::operator<<=(const bigint& n) {
    *this = *this << n;
    return *this;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  DIGIT SHIFT DROITE  (÷ 10^n, division entière)
// ═══════════════════════════════════════════════════════════════════════════════

//  1337 >> 2  →  13
//  little-endian : {7,3,3,1} >> 2  →  supprime les 2 premiers  →  {3,1}  →  "13"

bigint bigint::operator>>(const bigint& n) const {
    unsigned long long shift = n._toULL();

    // Si on décale plus que la longueur → résultat = 0
    if (shift >= _digits.size())
        return bigint(0ULL);

    bigint result;
    result._digits.clear();
    result._digits.insert(result._digits.end(),
                          _digits.begin() + static_cast<long>(shift),
                          _digits.end());
    result._removeLeadingZeros();
    return result;
}

bigint& bigint::operator>>=(const bigint& n) {
    *this = *this >> n;
    return *this;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  COMPARAISONS
// ═══════════════════════════════════════════════════════════════════════════════

//  Stratégie :
//  1. Compare les longueurs (plus de chiffres = plus grand)
//  2. Si égales, compare chiffre par chiffre du plus significatif au moins

bool bigint::operator==(const bigint& other) const {
    return _digits == other._digits;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
    // Nombre de chiffres différent → le plus court est plus petit
    if (_digits.size() != other._digits.size())
        return _digits.size() < other._digits.size();

    // Même longueur → compare du chiffre le plus significatif (fin du vecteur)
    for (int i = static_cast<int>(_digits.size()) - 1; i >= 0; --i) {
        if (_digits[i] != other._digits[i])
            return _digits[i] < other._digits[i];
    }
    return false; // égaux
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(other < *this);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

// ═══════════════════════════════════════════════════════════════════════════════
//  AFFICHAGE
// ═══════════════════════════════════════════════════════════════════════════════

//  Affiche du chiffre le plus significatif (fin du vecteur) au moins significatif.
//  Pas de zéros en tête (garantis par _removeLeadingZeros).

std::ostream& operator<<(std::ostream& os, const bigint& b) {
    for (int i = static_cast<int>(b._digits.size()) - 1; i >= 0; --i)
        os << b._digits[i];
    return os;
}
