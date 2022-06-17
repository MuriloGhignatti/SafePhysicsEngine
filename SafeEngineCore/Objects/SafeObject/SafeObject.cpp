//
// Created by muril on 16/06/2022.
//

#include "SafeObject.h"

void SafeObject::update(float deltaTime) {
    center += (velocity * deltaTime);
    std::cout << objName << " New position: (" << center.x() << ", " << center.y() << ", " << center.z() << ")" << "\n";
}

double SafeObject::getRestituition() const {
    return restituition;
}

void SafeObject::setRestituition(double restituition) {
    SafeObject::restituition = restituition;
}

const std::string &SafeObject::getObjName() const {
    return objName;
}

void SafeObject::setObjName(const std::string &objName) {
    SafeObject::objName = objName;
}
