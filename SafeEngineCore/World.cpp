//
// Created by muril on 16/06/2022.
//

#include "World.h"

void World::spawnObject(std::shared_ptr<SafeObject> safeObject) {
    objectsInWorld.emplace_back(safeObject);
}
