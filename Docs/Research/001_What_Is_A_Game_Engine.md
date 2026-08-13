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
