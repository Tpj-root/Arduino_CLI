#!/bin/bash

# Get current script location
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BIN_DIR="$SCRIPT_DIR/bin"
echo "alias ard=\"$BIN_DIR/arduino-cli\"" >> ~/.bashrc
echo "alias arduino-cli=\"$BIN_DIR/arduino-cli\"" >> ~/.bashrc

source ~/.bashrc
bash

cd "$BIN_DIR" || exit 1

# Get current version
if [[ -x "./arduino-cli" ]]; then
    CURRENT_VERSION=$(./arduino-cli version | awk '{print $3}')
    echo "Current version: $CURRENT_VERSION"
else
    echo "arduino-cli not found or not executable."
    CURRENT_VERSION="none"
fi

# Get latest version
LATEST_VERSION=$(curl -s https://api.github.com/repos/arduino/arduino-cli/releases/latest | grep '"tag_name":' | cut -d '"' -f4)
LATEST_VERSION_STRIPPED=${LATEST_VERSION#v}
echo "Latest version: $LATEST_VERSION"




# Check if update is needed
if [[ "$CURRENT_VERSION" == "$LATEST_VERSION_STRIPPED" ]]; then
    echo "Already up to date."
    echo "${BIN_DIR}"
    alias ard="${BIN_DIR}/arduino-cli"
    exit 0
fi

# Backup old version
if [[ -x "./arduino-cli" ]]; then
    mv arduino-cli "arduino-cli_${CURRENT_VERSION}"
    echo "Backed up old version as arduino-cli_${CURRENT_VERSION}"
fi

# Download and extract new version
TEMP_DIR=$(mktemp -d)
cd "$TEMP_DIR" || exit 1

ARCH="64bit"
OS="Linux"
FILENAME="arduino-cli_${LATEST_VERSION_STRIPPED}_${OS}_${ARCH}.tar.gz"
URL="https://downloads.arduino.cc/arduino-cli/${FILENAME}"

echo "Downloading $URL"
curl -fsSLO "$URL"
tar -xzf "$FILENAME"

# Install new binary
mv arduino-cli "$BIN_DIR/arduino-cli_${LATEST_VERSION_STRIPPED}"
chmod +x "$BIN_DIR/arduino-cli_${LATEST_VERSION_STRIPPED}"
ln -sfn "arduino-cli_${LATEST_VERSION_STRIPPED}" "$BIN_DIR/arduino-cli"

# Cleanup
rm -rf "$TEMP_DIR"
cd "$BIN_DIR"

echo "arduino-cli updated to $LATEST_VERSION"
echo "Add to PATH if needed:"
echo "${BIN_DIR}"
#echo "export PATH=\$PATH:$BIN_DIR"


