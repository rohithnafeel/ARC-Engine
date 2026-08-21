# Research 04: OpenGL Fundamentals

Notes on the low-level building blocks of OpenGL rendering — vertices, buffers, and coordinate systems.

## Table of Contents

- [What is a Vertex?](#what-is-a-vertex)
- [Why Do We Need Three Vertices to Make a Triangle?](#why-do-we-need-three-vertices-to-make-a-triangle)
- [What is a Vertex Buffer Object (VBO)?](#what-is-a-vertex-buffer-object-vbo)
- [Why Can't the GPU Directly Access CPU Memory?](#why-cant-the-gpu-directly-access-cpu-memory)
- [What is a Vertex Array Object (VAO)?](#what-is-a-vertex-array-object-vao)
- [What are Normalized Device Coordinates (NDC)?](#what-are-normalized-device-coordinates-ndc)
- [Why Does OpenGL Use Values From -1 to 1?](#why-does-opengl-use-values-from--1-to-1)
- [References](#references-2)

---

## What is a Vertex?

A vertex is a value from a graph used to create shapes in [OpenGL](https://www.opengl.org/), because the CPU and GPU can't directly produce an image on their own.

## Why Do We Need Three Vertices to Make a Triangle?

A triangle has three points, so three vertices are needed to define it.

### Example

| Shape | Vertices |
|---|---|
| Square | 4 |
| Triangle | 3 |
| Hexagon | 6 |

## What is a Vertex Buffer Object (VBO)?

A Vertex Buffer Object is the mechanism used to transfer vertex data from CPU memory to GPU memory, since the GPU can't directly read vertices stored in CPU memory.

## Why Can't the GPU Directly Access CPU Memory?

A GPU can't directly access CPU memory because the two use separate RAM: CPU RAM is controlled by the motherboard, while the GPU has its own dedicated VRAM.

## What is a Vertex Array Object (VAO)?

A Vertex Array Object is an OpenGL object that arranges vertex data into the correct order to produce the intended output. It defines how the data is read at a time — for example, in groups of 2, 3, or more values.

## What are Normalized Device Coordinates (NDC)?

Normalized Device Coordinates (NDC) are OpenGL's internal coordinate system for describing where things appear on screen, regardless of whether the display is 800×600 or 4K.

OpenGL always treats the visible area as a fixed square:

- **x-axis:** -1 (left edge) to +1 (right edge)
- **y-axis:** -1 (bottom edge) to +1 (top edge)
- **(0, 0):** dead center of the screen

Anything drawn with coordinates inside that -1 to 1 box is potentially visible. Anything outside it gets clipped — OpenGL simply doesn't draw it.

## Why Does OpenGL Use Values From -1 to 1?

1. **Resolution independence**
   If OpenGL used pixel coordinates directly, vertex data would need to change depending on window size. By fixing the range to -1 to 1 regardless of resolution, vertex data stays constant, and the viewport transform maps it to actual pixels at draw time. This decoupling is the main reason for the convention.

2. **Centering at (0, 0)**
   Using -1 to 1 places the origin at the center of the screen instead of a corner. This is more natural for graphics math — rotations, scaling, and mirroring all become simpler around a center point than around a corner. If the origin were at a corner, scaling an object would also shift its position, which is awkward.

3. **Symmetric range simplifies clipping**
   The GPU has a clipping stage that discards anything outside the visible volume before rasterization. A symmetric range like -1 to 1 makes the clipping test trivial — just check `|x| ≤ 1` and `|y| ≤ 1` — with no need to track different bounds per axis or worry about sign conventions.

4. **It falls out of homogeneous coordinates and the perspective divide**
   This is the deeper reason. In the 3D rendering pipeline, vertices pass through matrix transforms into clip space, which uses 4D homogeneous coordinates `(x, y, z, w)`. To get NDC, the GPU performs a **perspective divide** — dividing x, y, and z by w. This division naturally produces a normalized, resolution-independent, symmetric range, and -1 to 1 is the conventional range this math is designed to land in.

5. **It's a hardware/API convention, not a law of physics**
   The -1 to 1 range isn't universal across graphics APIs. OpenGL uses -1 to 1 for NDC z-depth as well, but [Direct3D](https://learn.microsoft.com/en-us/windows/win32/direct3d) and [Vulkan](https://www.vulkan.org/) use 0 to 1 for z instead. It's a deliberate design convention OpenGL settled on — other APIs made different choices for their own reasons.

## References

- [OpenGL Official Site](https://www.opengl.org/)
- [OpenGL Wiki — Vertex Specification](https://www.khronos.org/opengl/wiki/Vertex_Specification)
- [OpenGL Wiki — Coordinate Systems](https://learnopengl.com/Getting-started/Coordinate-Systems)
- [Direct3D Documentation](https://learn.microsoft.com/en-us/windows/win32/direct3d)
- [Vulkan Official Site](https://www.vulkan.org/)
