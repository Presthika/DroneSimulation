#pragma once
#include "FleetManager.h"

// Runs the drone fleet simulation step by step.
// Handles position updates and collision detection each step.
class SimulationEngine {
private:
    float timeStep;     // Time increment per step (seconds)
    int totalSteps;     // Total number of steps to run
    int currentStep;    // Current step counter
    FleetManager& fleet;
public:
    SimulationEngine(float timeStep, int totalSteps, FleetManager& fleet);
    void runStep();            // Advances simulation by one time step
    void runFullSimulation();  // Runs all steps from start to finish
    void displayStatus();      // Prints current positions of all drones
};