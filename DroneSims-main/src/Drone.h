#pragma once
#include <string>

// Represents a single drone with position, velocity, acceleration, and color.
// Supports movement, collision detection, and status display.
class Drone {
private:
    int droneID;
    double position[3];
    double velocity[3];
    double acceleration[3];
    std::string color;
public:
    // Constructors & Rule of Three
    Drone(int id, double x, double y, double z, double vx, double vy, double vz, double ax, double ay, double az);
    Drone();
    Drone(const Drone& other);               // Copy constructor
    Drone& operator=(const Drone& other);    // Copy assignment
    ~Drone();                                // Destructor

    // Setters
    void setID(int id);
    void setDroneID(int id);
    void setPosition(double x, double y, double z);
    void setVelocity(double vx, double vy, double vz);
    void setAcceleration(double ax, double ay, double az);
    void setColor(std::string c);

    // Getters
    int getID();
    int getDroneID();
    double* getPosition();
    double* getVelocity();
    double* getAcceleration();
    std::string getColor();
    double getSpeed();
    double getVelocityAngle();
    double getDistanceFromOrigin();
    double getDistanceFromOther(Drone& other);
    double getAccelerationMagnitude();

    // Functions
    void displayInfo();
    void updatePosition(double time);
    void updateVelocity(double ax, double ay, double az, double time);
    void applyAcceleration(double ax, double ay, double az, double time);
    void stop();
    void reset();
    int detectCollision(Drone& other, double collisionDistance);
    void avoidCollision(Drone& other, double collisionDistance);
};