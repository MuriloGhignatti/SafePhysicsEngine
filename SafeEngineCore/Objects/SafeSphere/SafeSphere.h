//
// Created by muril on 16/06/2022.
//

#ifndef SAFEPHYSICSENGINE_SAFESPHERE_H
#define SAFEPHYSICSENGINE_SAFESPHERE_H


#include "../SafeObject/SafeObject.h"

class SafeSphere: public SafeObject {
    double radius;
public:
    SafeSphere(std::string name, double x, double y, double z, double radius, double mass, double restituition): radius(radius){
        setObjName(name);
        setCenter(x, y, z);
        setMass(mass);
        setRestituition(restituition);
    }
    double getRadius(){return radius;}
};


#endif //SAFEPHYSICSENGINE_SAFESPHERE_H
