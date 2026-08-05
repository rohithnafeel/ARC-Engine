# Research 4:

## What is a vertex?
*Vertex are the value from graph which is used to create the shape in opengl because the cpu and gpu can't directly produce image.*

## Why do we need three vertices to make a triangle?
*There are three points in a triangle so we need three vertices to make a triangle.*

#### Example:

1. Square = 4 vertices
2. Triangle = 3 vertices
3. Hexagon = 6 vertices

## What is a Vertex Buffer Object (VBO)?
*Vertex buffer object is a process to convert a vertices from cpu memory to gpu memory because gpu can't directly read the vertices.*

## Why can't the GPU directly access CPU memory?
*A gpu can't directly access cpu memory because both has different ram which the cpu ram is controlled by motherboard and the gpu has seperate vram.*

## What is a Vertex Array Object (VAO)?
*Vertex array object is a opengl object which converts the array to a correct order to get the output.It decides how much at a time either 2 or 3 or more.*

## What are Normalized Device Coordinates (NDC)?
*Normalized device coordinates are opengl's internal coordinate for describing where the thigs to appear on screen. No matter if its 800 * 600 or 4k.*

OpenGL always treats the visible area as a fixed square:

x-axis: -1 (left edge) to +1 (right edge)
y-axis: -1 (bottom edge) to +1 (top edge)
(0, 0) = dead center of the screen

*Anything you draw with coordinates inside that -1 to 1 box is potentially visible. Anything outside it gets clipped — OpenGL simply doesn't draw it.*

## Why does OpenGL use values from -1 to 1?
1. Resolution independence
As we covered, if OpenGL used pixel coordinates directly, your vertex data would need to change depending on window size. By fixing the range to -1 to 1 regardless of resolution, your vertex data stays constant, and the viewport transform maps it to actual pixels at draw time. This decoupling is the main reason.

2. Centering at (0,0)
Using -1 to 1 puts the origin at the center of the screen instead of a corner. This is more natural for a lot of graphics math — rotations, scaling, and mirroring all become simpler when done around a center point rather than a corner. If origin were at a corner, scaling an object would also shift its position, which is awkward.

3. Symmetric range simplifies clipping
The GPU has a clipping stage that discards anything outside the visible volume before rasterization. A symmetric range like -1 to 1 makes the clipping test trivial: just check |x| ≤ 1 and |y| ≤ 1. No need to track different bounds for each axis or worry about sign conventions.

4. It falls out of homogeneous coordinates and the perspective divide
This is the deeper reason. In the 3D rendering pipeline, vertices go through matrix transforms into clip space, which uses 4D homogeneous coordinates (x, y, z, w). To get NDC, the GPU does a "perspective divide": divide x, y, z by w. This division naturally produces a normalized, resolution-independent, symmetric range — and -1 to 1 is the conventional range this math is designed to land in.

5. It's a hardware/API convention, not a law of physics
Worth knowing: -1 to 1 isn't universal across all graphics APIs. OpenGL uses -1 to 1 for NDC z-depth too, but Direct3D and Vulkan use 0 to 1 for z. So it's a deliberate design convention OpenGL settled on, and other APIs made slightly different choices for their own reasons.