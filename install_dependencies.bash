#!/bin/bash

# Dependencies for Debian/Ubuntu
declare -a DEBIAN_DEPENDENCIES=("clang" "llvm" "build-essential" "gcc-aarch64-linux-gnu" "qemu-system-arm")

# Dependencies for Fedora
declare -a FEDORA_DEPENDENCIES=("clang" "llvm" "gcc-c++" "aarch64-linux-gnu-gcc" "qemu-system-arm")

# Dependencies for macOS
declare -a MACOS_DEPENDENCIES=("llvm" "gcc-arm-none-eabi" "qemu")

# Function to check the OS type
check_os()
{
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        # Check for Debian/Ubuntu-based systems
        if [ -f /etc/debian_version ]; then
            echo "Detected OS: Ubuntu/Debian"
            OS="debian"
        elif [ -f /etc/fedora-release ]; then
            echo "Detected OS: Fedora"
            OS="fedora"
        else
            echo "Unsupported Linux distribution"
            exit 1
        fi
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo "Detected OS: macOS"
        OS="macos"
    else
        echo "Unsupported OS: $OSTYPE"
        exit 1
    fi
}

# Function to install dependencies for Debian/Ubuntu
install_debian()
{
    sudo apt update
    for package in "${DEBIAN_DEPENDENCIES[@]}"; do
        sudo apt install -y "$package"
    done
}

# Function to install dependencies for Fedora
install_fedora()
{
    sudo dnf install -y "${FEDORA_DEPENDENCIES[@]}"
}

# Function to install dependencies for macOS
install_macos()
{
    # Check if Homebrew is installed
    if ! command -v brew &> /dev/null; then
        echo "Homebrew not found, installing..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi

    brew update
    for package in "${MACOS_DEPENDENCIES[@]}"; do
        brew install "$package"
    done
}

# Main logic to determine OS and install dependencies
main()
{
    check_os

    case "$OS" in
        debian)
            install_debian
            ;;
        fedora)
            install_fedora
            ;;
        macos)
            install_macos
            ;;
        *)
            echo "Unknown OS. Exiting."
            exit 1
            ;;
    esac

    echo "All dependencies installed successfully!"
}

# Run the main function
main
