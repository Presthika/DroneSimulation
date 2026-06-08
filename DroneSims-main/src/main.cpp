#include <iostream>
#include <cmath>
#include <string>
#include "Drone.h"
#include "FleetManager.h"
#include "MissionPlanner.h"
#include "SimulationEngine.h"
#include "Drone.cpp"
#include "FleetManager.cpp"
#include "MissionPlanner.cpp"
#include "SimulationEngine.cpp"
using namespace std;

int getValidInt(string prompt, int min, int max) {
    int val;
    while (true) {
        cout << prompt;
        cin >> val;
        if (cin.fail() || val < min || val > max) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
        } else return val;
    }
}

string getValidShape() {
    while (true) {
        cout << "\nSelect a formation shape:" << endl;
        cout << "  1. Line" << endl;
        cout << "  2. Circle" << endl;
        cout << "  3. Triangle" << endl;
        cout << "  4. Diamond" << endl;
        cout << "  5. Star" << endl;
        cout << "  6. Exit" << endl;
        cout << "Enter choice (1-6): ";
        int choice;
        cin >> choice;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }
        if (choice == 1) return "Line";
        if (choice == 2) return "Circle";
        if (choice == 3) return "Triangle";
        if (choice == 4) return "Diamond";
        if (choice == 5) return "Star";
        if (choice == 6) return "Exit";
        cout << "Invalid choice. Please select 1-6." << endl;
    }
}

int main() {
    cout << "=== Drone Fleet Simulator ===" << endl;

    while (true) {
        string shape = getValidShape();
        if (shape == "Exit") {
            cout << "Exiting simulator. Goodbye!" << endl;
            return 0;
        }

        int minDrones, maxDrones;
        if (shape == "Line")          { minDrones = 2; maxDrones = 10; }
        else if (shape == "Circle")   { minDrones = 3; maxDrones = 10; }
        else if (shape == "Triangle") { minDrones = 3; maxDrones = 10; }
        else if (shape == "Diamond")  { minDrones = 4; maxDrones = 4;  }
        else if (shape == "Star")     { minDrones = 5; maxDrones = 10; }
        else                          { minDrones = 1; maxDrones = 10; }

        string dronePrompt = "Enter number of drones (" + to_string(minDrones) + "-" + to_string(maxDrones) + "): ";
        int numDrones = getValidInt(dronePrompt, minDrones, maxDrones);
        int steps = getValidInt("Enter number of simulation steps (1-20): ", 1, 20);

        FleetManager fleet;
        for (int i = 1; i <= numDrones; i++) {
            fleet.addDrone(i);
            if (shape == "Line") {
                fleet.getDrone(i-1).setPosition(i * 2.0, 0, 0);
                fleet.getDrone(i-1).setVelocity(1, 0, 0);
            } else if (shape == "Circle") {
                double angle = (2 * M_PI / numDrones) * (i - 1);
                fleet.getDrone(i-1).setPosition(5 * cos(angle), 5 * sin(angle), 0);
                fleet.getDrone(i-1).setVelocity(-sin(angle), cos(angle), 0);
            } else if (shape == "Triangle") {
                fleet.getDrone(i-1).setPosition(i * 2.0, (i % 2) * 2.0, 0);
                fleet.getDrone(i-1).setVelocity(0, 1, 0);
            } else if (shape == "Diamond") {
                double diamondX[] = {0, 3, 0, -3};
                double diamondY[] = {3, 0, -3, 0};
                int idx = (i - 1) % 4;
                fleet.getDrone(i-1).setPosition(diamondX[idx], diamondY[idx], 0);
                fleet.getDrone(i-1).setVelocity(0, 1, 0);
            } else if (shape == "Star") {
                double outerR = 5.0, innerR = 2.0;
                double angle = (M_PI / 5) * (i - 1);
                double r = (i % 2 == 1) ? outerR : innerR;
                fleet.getDrone(i-1).setPosition(r * cos(angle), r * sin(angle), 0);
                fleet.getDrone(i-1).setVelocity(-sin(angle), cos(angle), 0);
            }
        }

        cout << "\n--- Initial Fleet ---" << endl;
        fleet.displayFleet();

        MissionPlanner mission(1, shape + " Formation", "Shape");
        mission.addMissionElement(shape);
        mission.displayMissionInfo();
        mission.assignMission(fleet);

        cout << "\n--- Running Simulation ---" << endl;
        SimulationEngine sim(0.5, steps, fleet);
        sim.runFullSimulation();

        cout << "\nRun another simulation? (1 = Yes, 2 = No, other = exit): ";
        int again;
        cin >> again;
        if (again != 1) {
            cout << "Exiting simulator. Goodbye!" << endl;
            return 0;
        }
    }
}
