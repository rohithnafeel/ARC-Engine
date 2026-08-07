# Contributing to Arc Engine

First of all, thank you for your interest in contributing to Arc Engine.

Arc Engine is an open-source game engine built in modern C++ with the goal of creating a fast, modular, and developer-friendly engine. Every contribution, whether it's a bug fix, new feature, documentation improvement, or performance optimization, is appreciated.

---

## Before You Start

Before contributing, please:

- Read the README.md
- Make sure your changes fit the project's architecture
- Search existing issues and pull requests to avoid duplicate work

If you are planning a major feature or redesign, please open an issue first to discuss it.

---

## Development Environment

Recommended tools:

- C++20
- CMake 3.20+
- Visual Studio 2022 or Visual Studio Code
- MinGW or MSVC
- Git

Supported platforms:

- Windows (Primary)
- Linux (Planned)
- macOS (Planned)

---

## Project Structure

```
Engine/
    Core/
    Renderer/
    Scene/
    Physics/
    Editor/
    Events/
    Input/

Sandbox/

ThirdParty/

Assets/
```

Please place new code in the appropriate module instead of creating unrelated folders.

---

## Coding Style

Please follow these guidelines:

- Use meaningful class and variable names.
- Keep functions focused on a single responsibility.
- Avoid duplicated code.
- Prefer modern C++ features where appropriate.
- Keep code readable and maintainable.

Example:

```cpp
class Renderer
{
public:
    void BeginScene();
    void EndScene();
};
```

---

## Commit Messages

Write clear commit messages.

Good examples:

```
Add framebuffer resize support

Implement LayerStack

Fix viewport rendering

Refactor renderer initialization
```

Avoid messages like:

```
update

fix

changes

done
```

---

## Pull Requests

Before opening a pull request:

- Ensure the project builds successfully.
- Test your changes.
- Keep pull requests focused on a single feature or fix.
- Update documentation if necessary.

Please include:

- A clear description
- Screenshots (if UI changes)
- Reason for the change

---

## Reporting Bugs

When reporting a bug, include:

- Operating System
- Compiler
- CMake version
- Steps to reproduce
- Expected behavior
- Actual behavior

Providing screenshots or logs is helpful.

---

## Feature Requests

Feature requests are welcome.

Please explain:

- What problem it solves
- Why it would benefit Arc Engine
- A possible implementation (optional)

---

## Code of Conduct

Be respectful.

Constructive discussions are encouraged.

Harassment, discrimination, or toxic behavior will not be tolerated.

---

## Questions

If you have questions about the engine architecture or implementation, feel free to open an issue.

---

Thank you for helping improve Arc Engine.

Every contribution helps make the engine better.
