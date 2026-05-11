#!/bin/bash
set -e # Se un comando fallisce, ferma tutto lo script

# ==========================================
# 1. SETUP PERCORSI
# ==========================================
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_DIR="$(dirname "$SCRIPT_DIR")"

echo "📍 Workspace root: $WS_DIR"

# ==========================================
# 2. PULIZIA DEL WORKSPACE
# ==========================================
echo "🧹 Pulisco le vecchie build..."
rm -rf "$WS_DIR/build" "$WS_DIR/install" "$WS_DIR/log"
# Pulizia di eventuali errori da parte dei ragazzi
rm -rf "$WS_DIR/src/build" "$WS_DIR/src/install" "$WS_DIR/src/log"

# ==========================================
# 3. COMPILAZIONE SEMPLICE
# ==========================================
echo "🏗️  Compilazione in corso..."
cd "$WS_DIR"

# Compila tutto il workspace in un colpo solo
colcon build --symlink-install

echo "=========================================="
echo "✅ BUILD COMPLETATA CON SUCCESSO!"
echo "👉 Ricorda di fare 'source install/setup.bash' se apri un nuovo terminale!"
echo "=========================================="