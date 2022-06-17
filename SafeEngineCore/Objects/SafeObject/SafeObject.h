//
// Created by muril on 16/06/2022.
//

#ifndef SAFEPHYSICSENGINE_SAFEOBJECT_H
#define SAFEPHYSICSENGINE_SAFEOBJECT_H

#include "Eigen"
#include <iostream>

class SafeObject {
private:
    std::string objName;
    Eigen::Vector3d center{0,0,0};
    Eigen::Vector3d velocity{0,0,0};
    double mass{0.0};
    double restituition{0.0};

public:
    virtual ~SafeObject() = default;

    void update(float deltaTime);

    Eigen::Vector3d getCenter() {return center;}
    void setCenter(double x, double y, double z) {center.x() = x; center.y() = y; center.z() = z;}

    Eigen::Vector3d getVelocity() {return velocity;}
    void setVelocity(double x, double y, double z) {velocity.x() = x; velocity.y() = y; velocity.z() = z;}
    void setVelocity(Eigen::Vector3d vector3D){velocity = vector3D;}

    double getMass(){return mass;}
    void setMass(double mass){this->mass = mass;}

    double getRestituition() const;

    void setRestituition(double restituition);

    const std::string &getObjName() const;

    void setObjName(const std::string &objName);
};


#endif //SAFEPHYSICSENGINE_SAFEOBJECT_H
