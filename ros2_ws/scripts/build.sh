#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_DIR="$(dirname "$SCRIPT_DIR")"

echo "🧹 Pulizia workspace..."
rm -rf "$WS_DIR/build" "$WS_DIR/install" "$WS_DIR/log"

# ==========================================
# MAGIA DEL TEAM: Generazione Endpoints C++
# ==========================================
echo "🔧 Generazione degli endpoints C++ da YAML..."
python3 "$WS_DIR/tools/gen_endpoints.py"

echo "🏗️ Compilazione in corso..."
cd "$WS_DIR"
colcon build --symlink-install

echo "✅ BUILD COMPLETATA CON SUCCESSO!"