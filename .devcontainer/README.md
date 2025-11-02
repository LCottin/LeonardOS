# LeonardOS Dev Container

This configuration lets you develop and build LeonardOS seamlessly on any system
(macOS, Windows, Linux) using an identical Linux environment.

## 🧱 Requirements
- [Docker Desktop](https://www.docker.com/products/docker-desktop/)
- [Visual Studio Code](https://code.visualstudio.com/)
- VS Code Extension: `Dev Containers` (by Microsoft)

## 🚀 Usage
1. Clone the LeonardOS repository normally.
2. Open the project folder in VS Code.
3. When prompted, click **"Reopen in Container"**.
4. Wait for the image to build (only once).
5. Your workspace opens *inside the container*.

You can now:
```bash
make build_os
