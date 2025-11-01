# Use Ubuntu as a base (same behavior as WSL)
FROM ubuntu:24.04

# Install toolchain, build system, and QEMU
RUN apt update && apt install -y \
    build-essential \
    cmake \
    python3 \
    git \
    vim \
    && apt clean

# Copy your dependency install script into the image
COPY ../tools/scripts/install_dependencies.bash /tmp/install_deps.sh

# Make it executable
RUN chmod +x /tmp/install_deps.sh

# Run your script to install your toolchain, QEMU, etc.
RUN /tmp/install_deps.sh

# Default work directory when opening the container
WORKDIR /workspace

# You can define an entrypoint (optional)
CMD ["/bin/bash"]
