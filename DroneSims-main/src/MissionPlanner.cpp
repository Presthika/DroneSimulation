#include <iostream>
#include <string>
#include "MissionPlanner.h"
using namespace std;

MissionPlanner::MissionPlanner(int ID, string name, string type) {
    missionID = ID;
    missionName = name;
    missionType = type;
    missionRunCount = 0;
}
MissionPlanner::MissionPlanner() {
    missionID = 0;
    missionName = "Default Mission";
    missionType = "Default Type";
    missionRunCount = 0;
}
void MissionPlanner::setMissionID(int ID) { missionID = ID; }
void MissionPlanner::setMissionName(string name) { missionName = name; }
void MissionPlanner::setMissionType(string type) { missionType = type; }
int MissionPlanner::getMissionID() { return missionID; }
string MissionPlanner::getMissionName() { return missionName; }
string MissionPlanner::getMissionType() { return missionType; }

void MissionPlanner::displayMissionInfo() {
    cout << "---------Mission Info---------" << endl;
    cout << "Mission ID: " << missionID << endl;
    cout << "Mission Name: " << missionName << endl;
    cout << "Mission Type: " << missionType << endl;
}
void MissionPlanner::assignMission(FleetManager& fleet) {
    cout << "Assigning mission: " << missionName << " to fleet." << endl;
}
void MissionPlanner::assignMission(Drone& drone) {
    cout << "Assigning mission: " << missionName << " to Drone ID#" << drone.getID() << endl;
}
void MissionPlanner::deleteMission() {
    missionID = 0;
    missionName = "Deleted Mission";
    missionType = "Deleted Type";
    cout << "Mission deleted." << endl;
}
void MissionPlanner::addMissionElement(string name) {
    if (missionRunCount < 10) {
        missionRunNames[missionRunCount] = name;
        missionRunCount++;
        cout << "Mission element: " << name << " added to mission: " << missionName << endl;
    } else {
        cout << "Mission element limit reached." << endl;
    }
}