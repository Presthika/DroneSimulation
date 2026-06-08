#include <iostream>
#include <string>
#include <cmath>
#include "Drone.h"
using namespace std;

Drone::Drone(int id, double x, double y, double z, double vx, double vy, double vz, double ax, double ay, double az) {
    droneID = id;
    position[0]=x; position[1]=y; position[2]=z;
    velocity[0]=vx; velocity[1]=vy; velocity[2]=vz;
    acceleration[0]=ax; acceleration[1]=ay; acceleration[2]=az;
}
Drone::Drone() {
    droneID = 0;
    position[0]=position[1]=position[2]=0.0;
    velocity[0]=velocity[1]=velocity[2]=0.0;
    acceleration[0]=acceleration[1]=acceleration[2]=0.0;
}
// Copy constructor: copies all fields from another Drone
Drone::Drone(const Drone& other) {
    droneID = other.droneID;
    color = other.color;
    for (int i = 0; i < 3; i++) {
        position[i] = other.position[i];
        velocity[i] = other.velocity[i];
        acceleration[i] = other.acceleration[i];
    }
}
// Copy assignment operator
Drone& Drone::operator=(const Drone& other) {
    if (this != &other) {
        droneID = other.droneID;
        color = other.color;
        for (int i = 0; i < 3; i++) {
            position[i] = other.position[i];
            velocity[i] = other.velocity[i];
            acceleration[i] = other.acceleration[i];
        }
    }
    return *this;
}
Drone::~Drone() {} // No dynamic memory, but defined for Rule of Three

void Drone::setID(int id) { droneID = id; }
void Drone::setDroneID(int id) { droneID = id; }
void Drone::setPosition(double x, double y, double z) { position[0]=x; position[1]=y; position[2]=z; }
void Drone::setVelocity(double vx, double vy, double vz) { velocity[0]=vx; velocity[1]=vy; velocity[2]=vz; }
void Drone::setAcceleration(double ax, double ay, double az) { acceleration[0]=ax; acceleration[1]=ay; acceleration[2]=az; }
void Drone::setColor(string c) { color = c; }
int Drone::getID() { return droneID; }
int Drone::getDroneID() { return droneID; }
double* Drone::getPosition() { return position; }
double* Drone::getVelocity() { return velocity; }
double* Drone::getAcceleration() { return acceleration; }
string Drone::getColor() { return color; }
double Drone::getSpeed() { return sqrt(velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2]); }
double Drone::getVelocityAngle() { return atan2(velocity[1], velocity[0]) * 180.0 / M_PI; }
double Drone::getDistanceFromOrigin() { return sqrt(position[0]*position[0] + position[1]*position[1] + position[2]*position[2]); }
double Drone::getDistanceFromOther(Drone& other) {
    double dx=position[0]-other.position[0], dy=position[1]-other.position[1], dz=position[2]-other.position[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}
double Drone::getAccelerationMagnitude() { return sqrt(acceleration[0]*acceleration[0] + acceleration[1]*acceleration[1] + acceleration[2]*acceleration[2]); }
void Drone::displayInfo() {
    cout << "Drone ID: " << droneID << endl;
    cout << "Position: (" << position[0] << ", " << position[1] << ", " << position[2] << ")" << endl;
    cout << "Velocity: (" << velocity[0] << ", " << velocity[1] << ", " << velocity[2] << ")" << endl;
    cout << "Color: " << color << endl;
}
void Drone::updatePosition(double time) {
    position[0]+=velocity[0]*time; position[1]+=velocity[1]*time; position[2]+=velocity[2]*time;
}
void Drone::updateVelocity(double ax, double ay, double az, double time) {
    velocity[0]+=ax*time; velocity[1]+=ay*time; velocity[2]+=az*time;
}
void Drone::applyAcceleration(double ax, double ay, double az, double time) {
    updateVelocity(ax, ay, az, time);
    updatePosition(time);
}
void Drone::stop() { velocity[0]=velocity[1]=velocity[2]=0.0; }
void Drone::reset() {
    position[0]=position[1]=position[2]=0.0;
    velocity[0]=velocity[1]=velocity[2]=0.0;
    acceleration[0]=acceleration[1]=acceleration[2]=0.0;
}
int Drone::detectCollision(Drone& other, double collisionDistance) {
    double dx=position[0]-other.position[0], dy=position[1]-other.position[1], dz=position[2]-other.position[2];
    return sqrt(dx*dx+dy*dy+dz*dz) < collisionDistance ? 1 : 0;
}
void Drone::avoidCollision(Drone& other, double collisionDistance) {
    if (detectCollision(other, collisionDistance)) {
        velocity[0]=-velocity[0]; velocity[1]=-velocity[1]; velocity[2]=-velocity[2];
    }
}