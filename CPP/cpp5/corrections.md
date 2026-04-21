# Corrections et Améliorations - CPP Module 05

Voici la liste des modifications à apporter avant de rendre ton projet :

## 1. Forme Canonique Orthodoxe (Coplien) ⚠️
Il manque la forme canonique complète dans certaines de tes classes, notamment `Bureaucrat`.
- **Fichiers concernés** : `ex00/Bureaucrat.hpp`, `ex01/Bureaucrat.hpp`, `ex02/Bureaucrat.hpp`, `ex03/Bureaucrat.hpp`
- **Action** : Ajoute le **constructeur de recopie** (`Bureaucrat(const Bureaucrat &)`) et **l'opérateur d'affectation** (`Bureaucrat &operator=(const Bureaucrat &)`).
- *Note* : Assure-toi que toutes tes classes (`AForm`, `PresidentialPardonForm`, `RobotomyRequestForm`, `ShrubberyCreationForm`, `Intern`) respectent bien cette règle. Même si tu as des attributs `const` (comme `_name`), tu dois déclarer et définir ces éléments.

## 2. Emplacement et implémentation de `signForm` (Ex01 / Ex02 / Ex03)
Le sujet demande explicitement d'ajouter une fonction membre `signForm()` à la classe `Bureaucrat`.
- **Fichiers concernés** : Les `Bureaucrat.cpp` et `Bureaucrat.hpp` (ex01 à ex03), et `AForm.cpp` / `AForm.hpp`.
- **Action** :
  - Supprime `void signAForm(Bureaucrat const &bureaucrat)` de `AForm`.
  - Ajoute `void signForm(AForm &form)` dans `Bureaucrat`.
  - Dans cette fonction `signForm`, le Bureaucrat doit appeler `form.beSigned(*this)` dans un bloc `try/catch` et afficher `"<bureaucrat> signed <form>"` en cas de succès, ou `"<bureaucrat> couldn't sign <form> because <reason>."` en cas d'échec.

## 3. Les affichages dans `Intern` (Ex03)
Le sujet exige des messages spécifiques lors de la création d'un formulaire par l'Intern.
- **Fichier concerné** : `ex03/Intern.cpp` (fonction `makeForm`)
- **Action** :
  - **Succès** : Si le formulaire est trouvé, affiche `Intern creates <form_name>` juste avant de retourner le pointeur.
  - **Échec** : Si le formulaire n'est pas trouvé, affiche un message d'erreur explicite (ex: `std::cout << "Intern cannot create " << nameForm << " because the form type is unknown." << std::endl;`) avant de faire ton `return NULL;`.

## 4. Sécurité des Incrémentations et Décrémentations
Pour plus de robustesse, il est recommandé de vérifier les limites avant de modifier la valeur.
- **Fichiers concernés** : Tous les `Bureaucrat.cpp` (fonction `increment` et `decrement`)
- **Action** : Inverse la logique pour lever l'exception *avant* de modifier la variable.
- **Exemple** :
  ```cpp
  void Bureaucrat::increment(void) {
    if (this->_grade - 1 < 1)
      throw Bureaucrat::GradeTooHighException();
    this->_grade--;
  }

  void Bureaucrat::decrement(void) {
    if (this->_grade + 1 > 150)
      throw Bureaucrat::GradeTooLowException();
    this->_grade++;
  }
  ```

## 5. Checklist Bonus
- [x] Vérifier la présence du destructeur `virtual` dans `AForm`.
- [ ] Compiler avec `-Wall -Wextra -Werror -std=c++98`.
- [ ] Vérifier les fuites mémoire (leaks) avec `valgrind`, particulièrement dans l'`ex03` où `Intern::makeForm` utilise `new`. Attention à bien `delete` les formulaires créés dans le `main`.
