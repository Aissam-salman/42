#pragma once
#include <vector>
#include <string>
#include <iostream>

class bigint {
public:
    // ─── Forme canonique orthodoxe ───────────────────────────────────────────
    bigint();                                    // → 0
    bigint(unsigned long long n);                // depuis un entier
    bigint(const std::string& s);               // depuis une string
    bigint(const bigint& other);                 // copie
    bigint& operator=(const bigint& other);      // affectation
    ~bigint();

    // ─── Addition ────────────────────────────────────────────────────────────
    bigint  operator+ (const bigint& other) const;
    bigint& operator+=(const bigint& other);

    // ─── Incrémentation ──────────────────────────────────────────────────────
    bigint& operator++();    // préfixe  ++b
    bigint  operator++(int); // postfixe b++

    // ─── Digit Shift (paramètre bigint pour supporter >>=(const bigint)2) ────
    bigint  operator<< (const bigint& n) const;  // × 10^n
    bigint& operator<<=(const bigint& n);
    bigint  operator>> (const bigint& n) const;  // ÷ 10^n (entier)
    bigint& operator>>=(const bigint& n);

    // ─── Comparaisons ────────────────────────────────────────────────────────
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator< (const bigint& other) const;
    bool operator> (const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    // ─── Affichage ───────────────────────────────────────────────────────────
    friend std::ostream& operator<<(std::ostream& os, const bigint& b);

private:
    // little-endian : 1337 → {7, 3, 3, 1}   (_digits[0] = unités)
    std::vector<int> _digits;

    void               _removeLeadingZeros();
    unsigned long long _toULL() const; // convertit le bigint en ULL (pour les shifts)
};
