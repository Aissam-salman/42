#!/bin/bash

# Script de lancement de la documentation Docsify

echo "🚀 Lancement de la documentation Libft..."
echo ""

# Vérifier si docsify-cli est installé
if command -v docsify &> /dev/null; then
    echo "✅ Docsify trouvé!"
    echo "📖 Démarrage du serveur sur http://localhost:3000"
    echo ""
    echo "Appuyez sur Ctrl+C pour arrêter le serveur"
    echo ""
    docsify serve
elif command -v python3 &> /dev/null; then
    echo "⚠️  Docsify non trouvé, utilisation de Python à la place"
    echo "📖 Démarrage du serveur sur http://localhost:3000"
    echo ""
    echo "Appuyez sur Ctrl+C pour arrêter le serveur"
    echo ""
    echo "💡 Pour une meilleure expérience, installez Docsify:"
    echo "   npm install -g docsify-cli"
    echo ""
    python3 -m http.server 3000
elif command -v php &> /dev/null; then
    echo "⚠️  Docsify et Python non trouvés, utilisation de PHP"
    echo "📖 Démarrage du serveur sur http://localhost:3000"
    echo ""
    echo "Appuyez sur Ctrl+C pour arrêter le serveur"
    echo ""
    php -S localhost:3000
else
    echo "❌ Erreur: Aucun serveur disponible"
    echo ""
    echo "Installez l'un des outils suivants:"
    echo "  - Docsify: npm install -g docsify-cli"
    echo "  - Python 3"
    echo "  - PHP"
    echo ""
    echo "Ou ouvrez docs/index.html directement dans votre navigateur"
    exit 1
fi
