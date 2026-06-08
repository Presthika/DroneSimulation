# DroneSimulation

# DroneSimulations
EECE2140 Final Project - Drone show simulations

**Drone Fleet Simulator** <br>
Team Members: Riley Ashok and Presthika Vijaykumar  <br>
Course: EECE 2140 — Computing Fundamentals in C++ <br>
Date: April 10th, 2026

**Project Overview:** <br>
A C++ simulation of a drone fleet management system. The simulator allows users to register drones, assign missions, plan paths, detect collisions, and run a full simulation of a drone show with real-time status updates.

**Main Functionalities:** <br>
Drone Registration — Add and initialize drones into the fleet <br>
Mission Assignment — Assign shape formation missions to groups of drones <br>
Path Planning — Calculate optimal collision-free paths for each drone <br>
Collision Detection & Avoidance — Detect proximity risks and reroute drones <br>
Simulation Update — Advance the simulation step by step and display status <br>

**OOP Design Summary** <br>
Class                                           Responsibility <br>
Drone                 Stores individual drone data (ID, position, velocity) and handles movement <br>
FleetManager              Manages the full collection of drones, handles adding and removing <br>
MissionPlanner              Assigns missions, plans paths, and manages the mission queue <br>
SimulationEngine                  Runs each simulation step and displays fleet status <br>



**Tools and Technologies:** <br>
C++ <br>
clang++ compiler <br>
VS Code <br>
GitHub  <br>


**Folder Structure** <br>
DroneFleetSimulator/ <br>
│ <br>
├── README.md <br>
├── docs/ <br>
│   └── System_Design_Overview.pdf <br>
├── pseudocode/ <br>
│   └── pseudocode.txt <br>
├── src/ <br>
│   ├── main.cpp <br>
│   ├── Drone.h <br>
│   ├── Drone.cpp <br>
│   ├── FleetManager.h <br>
│   ├── FleetManager.cpp <br>
│   ├── MissionPlanner.h <br>
│   ├── MissionPlanner.cpp <br>
│   ├── SimulationEngine.h <br>
│   └── SimulationEngine.cpp <br>
└── images/ <br>
    └── system_diagram.png <br>


**Project Goals:** <br>
Simulate a real-world drone fleet show in C++ <br>
Demonstrate OOP principles through class design and interaction <br>
Implement collision detection and path planning logic <br>
Visualize drone positions and mission progress <br>

**Current Implementation Status:** <br>
OOP class design finalized <br>
Drone class implemented with Rule of Three <br>
FleetManager class implemented <br>
MissionPlanner class implemented <br>
SimulationEngine class implemented <br>
Main simulation loop complete <br>
5 formation shapes (Line, Circle, Triangle, Diamond, Star) <br>
Input validation with error handling <br>
Collision detection between drones <br>


