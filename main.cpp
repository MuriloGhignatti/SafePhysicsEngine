//
// Created by muril on 16/06/2022.
//

#include "SafeModuleManager.h"
#include "Objects/SafeSphere/SafeSphere.h"
#include "World.h"
#include <chrono>

int main(int argc, char* argv[])
{
    SafeModuleManager safeModuleManager("E:\\Codes\\C++\\SafePhysicsEngine\\cmake-build-debug-visual-studio\\SafeCollisionModule");
    safeModuleManager.loadPlugins();
    World world(100, 100, 100);

    auto firstSphere = std::make_shared<SafeSphere>("Sphere1", 0.0,0.0,0.0,1.0, 1.0, 0.1);
    auto secondSphere = std::make_shared<SafeSphere>("Sphere2", 10.0,0.0,0.0,2,2.0, 0.1);

    firstSphere->setVelocity(1,0,0);
    secondSphere->setVelocity(-1,0,0);

    world.spawnObject(firstSphere);
    world.spawnObject(secondSphere);

    float deltaTime = 0.016;

    while(true){
        auto start = std::chrono::high_resolution_clock::now();
        for(auto& obj: world.getWorldObjects()){
            obj->update(deltaTime);
        }
        safeModuleManager.sendTickUpdates(world);
        deltaTime =  std::chrono::duration<float, std::chrono::seconds::period>(std::chrono::high_resolution_clock::now() - start).count();
    }
    return 0;
}