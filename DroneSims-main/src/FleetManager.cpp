#include "FleetManager.h"
#include <iostream>
using namespace std;

// FleetManager uses a fixed array (O(1) access) over a linked list
// since random access by index is the primary operation in this simulation.

FleetManager::FleetManager() {
    droneCount = 0;
    droneAngle = 0.0;
}
int FleetManager::getDroneCount() { return droneCount; }
void FleetManager::addDrone(int droneID) {
    for (int i = 0; i < droneCount; i++) {
        if (drone[i].getID() == droneID) {
            cout << "Drone with ID " << droneID << " already exists." << endl;
            return;
        }
    }
    drone[droneCount].setID(droneID);
    droneCount++;
    cout << "Drone with ID " << droneID << " added." << endl;
}
void FleetManager::deleteDrone(int droneID) {
    for (int i = 0; i < droneCount; i++) {
        if (drone[i].getID() == droneID) {
            for (int j = i; j < droneCount - 1; j++) drone[j] = drone[j+1];
            droneCount--;
            cout << "Drone with ID " << droneID << " deleted." << endl;
            return;
        }
    }
    cout << "Drone with ID " << droneID << " not found." << endl;
}
Drone& FleetManager::getDrone(int index) { return drone[index]; }
void FleetManager::displayFleet() {
    cout << "Fleet has " << droneCount << " drone(s)." << endl;
    for (int i = 0; i < droneCount; i++) drone[i].displayInfo();
}