#!/bin/zsh

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

cd "$PROJECT_ROOT"

if ! command -v ant >/dev/null 2>&1; then
    echo "Error: Apache Ant is not installed."
    exit 1
fi

if [[ ! -f build.xml ]]; then
    echo "Error: build.xml was not found in:"
    pwd
    exit 1
fi

echo "1. Cleaning project..."
ant clean

echo
echo "2. Building C++ unit-test and debug configuration..."
ant cppUnitBuild

echo
echo "Build completed successfully."
echo "Executable: build/graph"
echo "Run it with: ./build/graph"
echo "Or run it with: ant run"