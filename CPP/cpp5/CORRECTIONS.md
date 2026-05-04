# Corrections à Apporter - Module CPP05

## 🔴 CRITIQUE - EX03

### ex03/main.cpp
**Ligne 18-19: Variable inutilisée + typo**

```diff
- AForm* rrf;
- rrf = someRandomIntern.makeForm("robotom request", "Bender");
+ AForm* rrf;
+ rrf = someRandomIntern.makeForm("robotomy request", "Bender");
+ delete rrf;
```

**Problèmes:**
- Variable `rrf` déclarée mais pas utilisée → erreur `-Werror=unused-but-set-variable`
- Typo: `"robotom request"` → `"robotomy request"`
- Fuite mémoire: allocation sans libération

**Code corrigé:**
```cpp
int main(void) {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	return (0);
}
```

---

## 🟠 IMPORTANT - EX02

### ex02/AForm.hpp
**Ligne 34: Destructeur virtuel**

```diff
- virtual ~AForm(void) = 0;
+ virtual ~AForm(void);
```

**Problème:** Un destructeur ne doit pas être déclaré comme pur virtuel (`= 0`). Il doit avoir une implémentation vide.

**Vérifier aussi dans AForm.cpp que le destructeur existe:**
```cpp
AForm::~AForm() {}
```

---

## 🟡 MINEUR - Messages d'Erreur

### ex02/AForm.cpp
**Lignes 70-73: Fautes dans les messages d'exception**

```diff
const char *AForm::GradeTooHighException::what() const throw() {
-  return ("grade is to high");
+  return ("Grade is too high");
}
const char *AForm::GradeTooLowException::what() const throw() {
-  return ("grade is to low");
+  return ("Grade is too low");
}
```

**Problèmes:**
- "is to" → "is too"
- Majuscule pour cohérence

---

### ex02/RobotomyRequestForm.cpp
**Ligne 44: Grammaire incorrect**

```diff
- std::cout << this->_target << " fail the robotomize" << std::endl;
+ std::cout << this->_target << " robotomization failed" << std::endl;
```

---

## 📋 Checklist Avant Correction

- [ ] EX03/main.cpp - Corriger la variable inutilisée
- [ ] EX03/main.cpp - Corriger le typo "robotom" → "robotomy"
- [ ] EX03/main.cpp - Ajouter `delete rrf;` pour éviter fuite mémoire
- [ ] EX02/AForm.hpp - Supprimer `= 0` du destructeur
- [ ] EX02/AForm.cpp - Vérifier destructeur implémenté
- [ ] EX02/AForm.cpp - Corriger messages d'erreur
- [ ] EX02/RobotomyRequestForm.cpp - Corriger grammaire
- [ ] Tester compilation: `make clean && make` dans chaque ex

---

## ✅ Tests Post-Correction

```bash
# EX00
cd ex00 && make clean && make && ./bureaucrat

# EX01
cd ex01 && make clean && make && ./form

# EX02
cd ex02 && make clean && make

# EX03 - IMPORTANT
cd ex03 && make clean && make
```

**Vérifier qu'il n'y a plus d'erreurs de compilation.**

---

## 📝 Résumé des Changements

| Fichier | Ligne | Type | Changement |
|---------|------|------|-----------|
| ex03/main.cpp | 18-19 | Critique | Corriger typo + utiliser variable |
| ex02/AForm.hpp | 34 | Important | Destructeur sans `= 0` |
| ex02/AForm.cpp | 70-73 | Mineur | Messages d'erreur |
| ex02/RobotomyRequestForm.cpp | 44 | Mineur | Grammaire |
