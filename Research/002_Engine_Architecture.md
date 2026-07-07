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

## Audio in game engine:

*Audio in game engine manages the playback,spatialization and real-time mixing of sound effects, dialogue and music. Engines uses thirdparty softwares like FMOD studio to prosses complex dynamic audio.*

### Thirdparty audio softwares:

* FMOD
* Wwise
* Built-in solutions

## Input Handling:

*Input Handling in game engine translates hardware signals from keyboards, mouse or controllers. It can be controlled by game logic.*

#### Input States:

1. Pressed
2. Held/Down
3. Released

## Scene Management:

*Scene manager in game engine is the control system that handles loading, unloading and transition between differnet game areas. It manage the active environment and prevent memory leaks also pass data between scenes.*

#### Key components in Scene Management:

- State Delegation
- Asunchronous Loading
- Transition Effects

## Entity Component System(ECS):

*The Entity Component System (ECS) is a software architectural pattern used in modern game engines to separate data from behavior.*

### ECS is built on three core pillars, each with specific roles:

1. Entities: A unique identifier representing a game object.

2. Components: Plain data structures with no logic or behavior.

3. Systems: Logic-driven code that iterates over entities containing specific component combinations to perform actions.

## Scripting:

*Scripting is a process for writing code or using visual nodes to control game logic, mechanics, and object behaviours without altering engin's core C or C++ source code.*

#### Engine and its scripting language:

1. Unity - C#
2. Unreal - C++
3. Godot - GDScript/C#
4. GameMaker - GML(GameMaker Language)

#### Core architecture:

+-------------------------------------------------------+
|                 Gameplay Script Layer                 |
|        (Lua, GDScript, C#, Blueprints, GML)           |
+-------------------------------------------------------+
                           │
                           │  Glue Code / Bindings API
                           ▼
+-------------------------------------------------------+
|                  Core Engine Layer                    |
|      (C / C++: Rendering, Physics, Memory)           |
+-------------------------------------------------------+
```