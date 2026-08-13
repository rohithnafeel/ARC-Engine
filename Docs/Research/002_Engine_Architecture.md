# Game Engine Research

Personal research notes on game engine fundamentals, architecture, and the motivation behind building one from scratch.

## Table of Contents

- [What is a Game Engine?](#what-is-a-game-engine)
- [Why Do Games Use an Engine?](#why-do-games-use-an-engine)
- [How Do Unity and Unreal Work Internally?](#how-do-unity-and-unreal-work-internally)
- [Core Modules of a Game Engine](#core-modules-of-a-game-engine)
- [Why Build a Game Engine From Scratch?](#why-build-a-game-engine-from-scratch)
- [References](#references)

---

## What is a Game Engine?

A game engine is a framework used to create and publish games. It also includes specialized software libraries and packages that handle the underlying technical systems a game needs to run.

## Why Do Games Use an Engine?

Game engines provide prebuilt, reusable systems — such as rendering, physics, and AI — which save years of development time and prevent developers from having to write core infrastructure from scratch.

## How Do Unity and Unreal Work Internally?

| Engine | Architecture | Language |
|---|---|---|
| [Unity](https://unity.com/) | Lightweight, component-based architecture (Entity-Component pattern) | C# |
| [Unreal Engine](https://www.unrealengine.com/) | Heavier, object-oriented framework | C++ |

## Core Modules of a Game Engine

| # | Module | Responsibility |
|---|---|---|
| 1 | Rendering Module | Draws graphics/visuals to the screen |
| 2 | Physics Engine | Simulates collisions, gravity, and motion |
| 3 | Audio System | Handles sound effects and music playback |
| 4 | Input Handling & Core System | Processes user input and manages the core game loop |
| 5 | Asset Management | Loads, stores, and organizes game assets |
| 6 | Networking Module | Enables multiplayer and online communication |
| 7 | Animation Engine | Drives character and object animations |

## Why Build a Game Engine From Scratch?

To learn deeply about [OpenGL](https://www.opengl.org/) and game engine architecture, and to gain full control over the engine's design and capabilities.

## References

- [Unity Official Site](https://unity.com/)
- [Unreal Engine Official Site](https://www.unrealengine.com/)
- [OpenGL Official Site](https://www.opengl.org/)
- [Unity Manual — Entity Component System](https://docs.unity3d.com/Packages/com.unity.entities@latest)
- [Unreal Engine Documentation](https://dev.epicgames.com/documentation/en-us/unreal-engine)

---

# Research 02: Core Engine Subsystems

Deeper research into the major subsystems that make up a game engine — rendering, physics, audio, input, scene management, ECS, and scripting.

## Table of Contents

- [Rendering](#rendering)
- [Physics in Game Engines](#physics-in-game-engines)
- [Audio in Game Engines](#audio-in-game-engines)
- [Input Handling](#input-handling)
- [Scene Management](#scene-management)
- [Entity Component System (ECS)](#entity-component-system-ecs)
- [Scripting](#scripting)
- [References](#references-1)

---

## Rendering

Rendering is the process of generating 2D images and animations from a 3D environment. It acts like a digital camera, taking coordinates and converting them into a viewable image.

In video games, this relies on **real-time rendering**, which generates 30 to 120+ frames per second to create the illusion of motion.

### Rendering Pipeline

1. Culling
2. Transform and Projection
3. Rasterization
4. Shading and Lighting

## Physics in Game Engines

A physics engine is a subsystem in a game engine that uses mathematical calculations to simulate real-world physics — such as motion, gravity, and collision — inside a game.

### How It Works

A physics engine runs simulations decoupled from the rendering engine. It continuously updates every frame through three steps:

1. **Inputs:** Gathers the properties of objects alongside any applied forces.
2. **Calculations:** Applies Newtonian physics and uses collision detection to predict when and where objects intersect.
3. **Outputs:** Calculates the new positions and orientations of objects, which the rendering engine then uses to draw them on screen.

### Types of Physics Objects

| Type | Description |
|---|---|
| **Static Objects** | Immovable objects like the ground, walls, and barriers |
| **Dynamic Bodies** | Objects affected by physical forces — bounce, fall, collide |
| **Kinematic Bodies** | Objects moved by code rather than external physical forces |

### Popular Physics-Based Engines

- [Unreal Engine](https://www.unrealengine.com/)
- [Unity](https://unity.com/)
- [Havok](https://www.havok.com/)
- [Nvidia PhysX](https://developer.nvidia.com/physx-sdk)

## Audio in Game Engines

Audio in a game engine manages the playback, spatialization, and real-time mixing of sound effects, dialogue, and music. Engines often use third-party software such as [FMOD Studio](https://www.fmod.com/) to process complex, dynamic audio.

### Third-Party Audio Software

- [FMOD](https://www.fmod.com/)
- [Wwise](https://www.audiokinetic.com/en/wwise/overview/)
- Built-in engine solutions

## Input Handling

Input handling in a game engine translates hardware signals from keyboards, mice, or controllers, which can then be interpreted and acted on by game logic.

### Input States

1. Pressed
2. Held / Down
3. Released

## Scene Management

The scene manager in a game engine is the control system that handles loading, unloading, and transitioning between different game areas. It manages the active environment, prevents memory leaks, and passes data between scenes.

### Key Components in Scene Management

- State Delegation
- Asynchronous Loading
- Transition Effects

## Entity Component System (ECS)

The Entity Component System (ECS) is a software architectural pattern used in modern game engines to separate data from behavior.

### ECS Is Built on Three Core Pillars

| Pillar | Role |
|---|---|
| **Entities** | A unique identifier representing a game object |
| **Components** | Plain data structures with no logic or behavior |
| **Systems** | Logic-driven code that iterates over entities with specific component combinations to perform actions |

## Scripting

Scripting is the process of writing code or using visual nodes to control game logic, mechanics, and object behaviors — without altering the engine's core C or C++ source code.

### Engines and Their Scripting Languages

| Engine | Scripting Language |
|---|---|
| [Unity](https://unity.com/) | C# |
| [Unreal Engine](https://www.unrealengine.com/) | C++ |
| [Godot](https://godotengine.org/) | GDScript / C# |
| [GameMaker](https://gamemaker.io/) | GML (GameMaker Language) |

## References

- [FMOD Official Site](https://www.fmod.com/)
- [Wwise Official Site](https://www.audiokinetic.com/en/wwise/overview/)
- [Havok Official Site](https://www.havok.com/)
- [Nvidia PhysX](https://developer.nvidia.com/physx-sdk)
- [Godot Engine](https://godotengine.org/)
- [GameMaker](https://gamemaker.io/)
