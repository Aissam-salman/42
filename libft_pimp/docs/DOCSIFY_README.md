# Documentation Docsify - Libft

## 📖 Consulter la documentation

### Option 1 : Docsify en local (Recommandé)

#### Installation de Docsify

```bash
# Installer docsify-cli globalement
npm install -g docsify-cli

# Ou avec yarn
yarn global add docsify-cli
```

#### Lancer le serveur

```bash
# Depuis le dossier libft_pimp
docsify serve docs

# La documentation sera accessible sur http://localhost:3000
```

### Option 2 : Serveur HTTP simple

Si vous n'avez pas Node.js/npm :

```bash
# Avec Python 3
cd docs
python3 -m http.server 3000

# Ouvrir http://localhost:3000 dans votre navigateur
```

```bash
# Avec PHP
cd docs
php -S localhost:3000

# Ouvrir http://localhost:3000 dans votre navigateur
```

### Option 3 : Ouvrir directement le fichier

Vous pouvez simplement ouvrir `docs/index.html` dans votre navigateur, mais certaines fonctionnalités (comme la recherche) peuvent ne pas fonctionner.

## 📝 Structure de la documentation

```
docs/
├── index.html           # Page principale Docsify
├── _coverpage.md        # Page de couverture
├── _sidebar.md          # Menu de navigation
├── README.md            # Page d'accueil
├── introduction.md      # Introduction au projet
├── installation.md      # Guide d'installation
├── string/              # Fonctions de manipulation de chaînes
├── memory/              # Fonctions de manipulation de mémoire
├── character/           # Fonctions de vérification de caractères
├── conversion/          # Fonctions de conversion
├── io/                  # Fonctions d'entrée/sortie
├── list/                # Fonctions de listes chaînées
├── gnl/                 # get_next_line
└── utils/               # Fonctions utilitaires
```

## 🔧 Personnalisation

Pour personnaliser la documentation, éditez :

- `docs/index.html` : Configuration Docsify (thème, plugins, etc.)
- `docs/_sidebar.md` : Structure du menu
- `docs/_coverpage.md` : Page de couverture

## 🚀 Fonctionnalités

La documentation inclut :

- ✅ Recherche en temps réel
- ✅ Copie de code en un clic
- ✅ Navigation par pagination
- ✅ Coloration syntaxique (C, Bash)
- ✅ Design responsive
- ✅ Thème moderne

## 📚 Ajouter de nouvelles pages

1. Créez un fichier `.md` dans le dossier approprié
2. Ajoutez l'entrée dans `_sidebar.md`
3. Rechargez la page

## 🛠️ Régénérer la documentation

Si vous avez ajouté de nouvelles fonctions :

```bash
python3 generate_docs.py
```

Ce script régénère automatiquement toutes les pages de documentation.

---

Pour plus d'informations sur Docsify : https://docsify.js.org
