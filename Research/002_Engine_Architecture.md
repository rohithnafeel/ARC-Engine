# Research 02:

## Rendering:

*Rendering is a process of generating 2D images and animations from a 3D environment. It acts as a digital camera and taking coordinates.*

*In video games the process relies on real-time rendering which generates 30 to 120+ frames per second to create a illusion of motion.*

### Rendering pipeline:

1. Culling
2. Transform and Projection
3. Rastorization
4. Shading and lighting

## Physics in game engine:

*Physics engine is a subsystem in a game engine which uses mathematical calculation to simulate real world physics like motion, gravity and collision in game.*

### How it works:

**A Physics engine runs simulations decoupled from the rendering engine. It continuously updates in frames by three steps they are,**

1. **Inputs:** It gathers the properties of objects alongside applied forces.

2. **Calculations:** It appiles newtonian physics and uses collision detection to predict when and were objects intersect.

3. **Outputs:** It calculates the new positions and orientations of objects which the rendering engine the n uses to draw them on the screen.

### Types of physics objects:

1. **Static Objects:** Immovable objects like the ground, walls and barriers.

2. **Dynamic Bodies:** Objects which has physical forces like bounce, fall and collide.

3. **Kinetic Bodies:** Objects which can be moved by code rather than any other external sources.

#### Popular Physics Based Engines:

- Unreal Engine
- Unity
- Havok
- Nvidia PhysX
