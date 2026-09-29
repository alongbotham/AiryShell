# AiryShell

Computational form-finding framework for pure-compression shells using radial basis function (RBF) interpolation in C. Developed for seismic-resilient structural design.

## Overview

AiryShell implements a **meshless radial basis function (RBF) interpolation framework** for equilibrium analysis of thin, pure-compression shells. The framework applies Mamikon Mnatsakanian's sweeping tangent theorem to decompose 2-manifolds into tangent-developed beam segments, encoding directional stiffness via anisotropic Wendland C² kernels with compact support.

### Research Goals

- **Fabrication-aware form-finding**: Respect material anisotropy during optimization, not as post-hoc constraint
- **Higher-genus topology support**: Extend Airy stress function methodology beyond simple manifolds
- **Seismic resilience**: Map horizontal load effects onto planar stress fields for rapid iteration of earthquake-resistant geometries
- **Open accessibility**: Tools released under MIT License for researchers, artists, and engineers

## Build Instructions

### Dependencies

- **Compiler**: GCC or Clang with C11 support
- **GLFW 3.x**: Window management and OpenGL context
- **OpenGL development libraries**: Rendering backend

#### Ubuntu/Debian
```bash
sudo apt-get install libglfw3-dev libgl1-mesa-dev build-essential
