#!/usr/bin/env bash
set -e

# =========================
# Config
# =========================
WS_DIR="$(cd "$(dirname "$0")/.." && pwd)"

LAUNCH_PKG="poli_sail"

LAUNCH_FILE="live_poli_sail_system.launch.py"



# =========================
# Environment
# =========================
echo "📦 Workspace: $WS_DIR"
echo "📄 Launch file: $LAUNCH_FILE"

# =========================
# Setup Ambiente
# =========================
source /opt/ros/jazzy/setup.bash

# Controlla se il workspace è stato compilato prima di fare il source
if [ -f "$WS_DIR/install/setup.bash" ]; then
    source "$WS_DIR/install/setup.bash"
else
    echo "⚠️  Attenzione: file di setup non trovato. Sicuro di aver lanciato build.sh?"
fi

# =========================
# Run
# =========================
exec ros2 launch "$LAUNCH_PKG" "$LAUNCH_FILE"