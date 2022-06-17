//
// Created by muril on 16/06/2022.
//

#include "SafeCollisionModule.h"

bool SafeCollisionModule::checkIfSphereIsColliding(std::shared_ptr<SafeSphere> a, std::shared_ptr<SafeSphere> b) {
    return (a->getRadius() + b->getRadius()) > (a->getCenter() - b->getCenter()).squaredNorm();
}

void SafeCollisionModule::onTick(World &world) {
    std::cout << "Received tick update" << "\n";
    for(auto const & obj: world.getWorldObjects()){
        auto currentObj = std::dynamic_pointer_cast<SafeSphere>(obj);
        if(currentObj){
            for(auto const & obj: world.getWorldObjects()){
                auto secondObj = std::dynamic_pointer_cast<SafeSphere>(obj);
                if(secondObj && secondObj != currentObj && checkIfSphereIsColliding(currentObj, secondObj)){
                    Collision collision(currentObj, secondObj);
                    solveSphereCollision(collision);
                }
            }
        }
    }
}

void SafeCollisionModule::solveSphereCollision(Collision &collision) {
    auto rv = Eigen::Vector3d(collision.a->getVelocity() - collision.b->getVelocity());
    double velAlongNormal = rv.dot(collision.normal);
    if(velAlongNormal > 0)
        return;
    double e = std::min(collision.a->getRestituition(), collision.b->getRestituition());
    double j = -(1 + e) * velAlongNormal;
    j /= 1 / collision.a->getMass() + 1 / collision.b->getMass();
    Eigen::Vector3d impulse = j * collision.normal;
    auto aVelocity = collision.a->getVelocity();
    auto bVelocity = collision.b->getVelocity();
    aVelocity += 1 / collision.a->getMass() * impulse;
    bVelocity -= 1 / collision.b->getMass() * impulse;
    collision.a->setVelocity(aVelocity);
    collision.b->setVelocity(bVelocity);
}

void SafeCollisionModule::onLoad() {
    std::cout << "Collision Module Loaded" << "\n";
}

DEFINE_PLUGIN(SafeCollisionModule, "SafeCollisionModule", "0.0.1")