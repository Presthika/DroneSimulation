#pragma once
#include "Drone.h"

// Manages a fleet of up to 100 drones.
// Supports adding, deleting, and accessing drones by index.
class FleetManager {
private:
    Drone drone[100];  // Fixed-size array of drones; O(1) access by index
    int droneCount;
    double droneAngle;
public:
    FleetManager();
    void addDrone(int droneID);      // Adds drone if ID not already present
    void deleteDrone(int droneID);   // Removes drone and shifts array
    Drone& getDrone(int index);      // Returns drone by index for direct access
    void displayFleet();             // Prints all drone info
    int getDroneCount();             // Returns current number of drones
};