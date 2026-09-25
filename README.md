# Drone Fleet Simulator

A C++ simulator for a drone light show, built as the final project for EECE 2140: Computing Fundamentals for Engineers at Northeastern University (April 2026). Users pick a formation, choose how many drones to fly, and step through the simulation while it tracks every drone's position and flags collisions.

## Features

- **Five formations:** Line, Circle, Triangle, Diamond, and Star, each with its own drone count limits
- **3D motion:** every drone tracks position, velocity, and acceleration, updated each time step
- **Collision detection:** each step checks every pair of drones and warns when two get within a set distance; drones can reverse course to avoid each other
- **Input validation:** menu inputs are range-checked so bad input doesn't crash the program

## Class design

| Class | Responsibility |
|---|---|
| `Drone` | Stores one drone's ID, position, velocity, acceleration, and color; handles movement and collision checks. Implements the Rule of Three (copy constructor, copy assignment, destructor). |
| `FleetManager` | Holds up to 100 drones in a fixed array for O(1) access by index; adds and removes drones and blocks duplicate IDs |
| `MissionPlanner` | Stores mission details and assigns missions to single drones or the whole fleet |
| `SimulationEngine` | Advances the simulation step by step, runs collision checks, and prints fleet status |

## How to run

```bash
cd DroneSims-main
clang++ -std=c++17 src/main.cpp -o drone_sim
./drone_sim
```

## Project files

- `DroneSims-main/src/`: C++ source and header files
- `DroneSims-main/Pseudocode/`: pseudocode for each class, written before implementation

## Team

Riley Ashok and Presthika Vijaykumar
