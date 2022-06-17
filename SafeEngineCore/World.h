//
// Created by muril on 16/06/2022.
//

#ifndef SAFEENGINECORE_WORLD_H
#define SAFEENGINECORE_WORLD_H

#include <vector>
#include <array>
#include "Objects/SafeObject/SafeObject.h"


class World {
    std::vector<std::shared_ptr<SafeObject>> objectsInWorld;
    std::array<double, 3> maxBounderies;
    std::array<double, 3> minBounderies;

public:
    World(double x, double y, double z): maxBounderies({x, y, z}), minBounderies({-1 * x, -1 * y, -1 * z}){}
    void spawnObject(std::shared_ptr<SafeObject> safeObject);
    std::vector<std::shared_ptr<SafeObject>>& getWorldObjects(){return objectsInWorld;}
};


#endif //SAFEENGINECORE_WORLD_H
