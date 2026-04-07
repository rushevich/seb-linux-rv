#!/usr/bin/env bash
set -euo pipefail

# Minimal Cage kiosk launcher for SEB on Wayland.
# Usage:
#   ./scripts/run-cage.sh -- [seb args...]
#
# Notes:
# - Forces Qt onto Wayland and WPE onto the fdo backend.
# - Disables JSC JIT for riscv64 stability/security (can be overridden).

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"

export QT_QPA_PLATFORM="${QT_QPA_PLATFORM:-wayland}"
export WPE_BACKEND="${WPE_BACKEND:-fdo}"
export JavaScriptCoreUseJIT="${JavaScriptCoreUseJIT:-0}"

# When selecting the WPE engine, SEB will use the embedded WPEView (if enabled in the build).
export SEB_BROWSER_ENGINE="${SEB_BROWSER_ENGINE:-wpe}"

BIN="${ROOT_DIR}/build/bin/safe-exam-browser"
if [[ ! -x "${BIN}" ]]; then
  echo "error: binary not found at ${BIN}. Build first (./scripts/build.sh)." >&2
  exit 1
fi

if ! command -v cage >/dev/null 2>&1; then
  echo "error: cage not found. Install it (e.g. 'sudo apt install cage')." >&2
  exit 1
fi

ARGS=()
if [[ "${1:-}" == "--" ]]; then
  shift
fi
ARGS+=("$@")

exec cage -- "${BIN}" "${ARGS[@]}"

