# Product Requirements Document: Tower Defense Game (OOP Semester Project)

## 1. Objectives

- **OOP Concepts:** Demonstrate Inheritance and Polymorphism through a real, working application.
- **Graphics Programming:** Integrate a graphics library and write an event-driven program in C++.

## 2. Game Overview

A Tower Defense game is a strategy game in which the player places defensive towers along or beside a path to prevent waves of enemies from reaching a protected goal (base or exit). Enemies march along a fixed route; towers detect and attack any enemy that enters their range. The player earns in-game currency by defeating enemies and spends it to buy or upgrade towers.

Each successive wave of enemies is harder — more numerous, faster, or tougher. The player loses a life each time an enemy reaches the exit. When all lives are gone, the game ends. Surviving every wave wins the game.

### Core Game Elements

| Element | Description |
|---|---|
| Map & Path | Grid-based map with a fixed path enemies follow from entry to exit. |
| Enemies | Units that travel the path; each type has different speed, HP, and special traits. |
| Towers | Defensive structures placed by the player that automatically attack enemies in range. |
| Waves | Rounds of enemies sent in sequence; each round is harder than the last. |
| Economy | Players earn gold on kills and spend it to place or upgrade towers. |
| Lives | The player starts with a fixed number of lives, losing one per enemy that escapes. |

## 3. Required Class Hierarchy

The core OOP requirement is a well-structured inheritance hierarchy that uses runtime polymorphism. All towers and enemies must be stored and manipulated through base-class pointers. Virtual functions such as `attack()`, `move()`, `takeDamage()`, and `render()` must be overridden in every derived class.

### 3.1 Entity Hierarchy

| Base Class | Derived (abstract) | Concrete Subclasses |
|---|---|---|
| `Entity` (abstract base) | `Enemy` (abstract) | `BasicEnemy`, `FastEnemy`, `TankEnemy`, `FlyingEnemy`, + 1 custom |
| | `Tower` (abstract) | `CannonTower`, `SniperTower`, `MachineGunTower`, `SlowTower`, + 1 custom |

### 3.2 Enemy Types

| Type | Characteristics |
|---|---|
| BasicEnemy | Average speed and HP. The default enemy type. |
| FastEnemy | High speed, very low HP. Difficult to hit before it escapes. |
| TankEnemy | Slow but extremely high HP. Requires sustained or heavy damage. |
| FlyingEnemy | Moves in a straight line, ignoring ground obstacles. |
| (custom) | Design an additional enemy type with a unique behavior or ability. |

### 3.3 Tower Types

| Type | Behavior |
|---|---|
| CannonTower | High damage per shot, slow fire rate. Good against tanks. |
| SniperTower | Very long range, targets a single enemy precisely. |
| MachineGunTower | Rapid fire, low damage per bullet. Effective against swarms. |
| SlowTower | Reduces enemy movement speed within its area of effect. |
| (custom) | Add one more tower type with a unique attack mechanic. |

## 4. Project Requirements

### 4.1 Core Gameplay (Required)

- A playable map with a clearly visible enemy path from entry point to exit.
- At least 3 distinct enemy types with overridden movement and behavior.
- At least 3 distinct tower types with overridden attack logic.
- At least 5 progressive waves of enemies, each harder than the previous.
- An economy system: players earn gold by defeating enemies and spend gold to place towers.
- A lives/HP system with a proper game-over screen.
- A win condition when all waves are completed.

### 4.2 OOP Requirements (Required)

- Abstract base classes for `Enemy` and `Tower` with pure virtual functions.
- Proper use of inheritance for all enemy and tower subtypes.
- Runtime polymorphism: towers and enemies stored and accessed through base-class pointers.
- Encapsulation enforced: private/protected members, getters and setters where appropriate.
- Correct use of constructors and destructors. No memory leaks.
- Meaningful use of operator overloading at least once.

### 4.3 Graphical Interface (Required)

- The game must run in a graphical window. Console-only submissions will not be accepted.
- The player must be able to place towers by clicking on the map with the mouse.
- Enemy HP bars or equivalent HP indicators must be visible on screen.
- Current wave number, gold count, and remaining lives must be permanently displayed.
- Any GUI library may be used (SFML, SDL2, Qt, raylib, or other).

### 4.4 Bonus Features (Optional)

- Tower upgrade system: each tower can be upgraded 1–2 levels.
- Multiple maps or selectable difficulty levels.
- Special enemy abilities (shielding, splitting on death, healing nearby enemies).
- Sound effects and/or background music.
- Persistent high score or save system.
- In-game shop UI with tower descriptions and stats.

## 5. Submission & Repository Requirements

### 5.1 GitHub Repository

- Create a GitHub repository at the start of the project (descriptive name, e.g. `TowerDefense-OOP`).
- May be kept private initially, made public at submission time.
- Progressive/incremental commits are strongly encouraged over a single final commit.
- Must include a `README.md` covering:
  - How to compile and run the project.
  - Which GUI library was used and how to install it.
  - Any known issues or limitations.

### 5.2 Deliverables

| # | Deliverable |
|---|---|
| 1 | All `.cpp` and `.h` source files zipped in a folder named with the student's roll number. |
| 2 | Link to the GitHub repository. |

## 6. Suggested Development Approach

1. Design the class hierarchy on paper before writing any code.
2. Implement the abstract base classes and game loop first, then add one enemy and one tower type to verify everything compiles and runs.
3. Get a window rendering with a hardcoded path on screen early.
4. Add enemy and tower subtypes one at a time; test polymorphism with base-class pointers at each step.
5. Build the wave and economy systems after the basic combat loop works.
6. Commit to GitHub frequently to maintain a working fallback version.
