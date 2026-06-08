#pragma once
#include <string>
#include "FleetManager.h"

// Plans and assigns missions to a fleet or individual drones.
// Supports named mission elements and overloaded assignment.
class MissionPlanner {
private:
    int missionID;
    std::string missionName;
    std::string missionType;
    std::string missionRunNames[10];  // Up to 10 named mission elements
    int missionRunCount;
public:
    MissionPlanner(int ID, std::string name, std::string type);
    MissionPlanner();
    void setMissionID(int ID);
    void setMissionName(std::string name);
    void setMissionType(std::string type);
    int getMissionID();
    std::string getMissionName();
    std::string getMissionType();
    void displayMissionInfo();
    void assignMission(FleetManager& fleet);  // Assign to whole fleet
    void assignMission(Drone& drone);          // Overload: assign to one drone
    void deleteMission();
    void addMissionElement(std::string name);
};