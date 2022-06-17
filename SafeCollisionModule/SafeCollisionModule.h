//
// Created by muril on 16/06/2022.
//

#ifndef SAFEPHYSICSENGINE_SAFECOLLISIONMODULE_H
#define SAFEPHYSICSENGINE_SAFECOLLISIONMODULE_H

#include "SafeModule.h"
#include "Objects/SafeSphere/SafeSphere.h"

struct Collision {
    std::shared_ptr<SafeObject> a;
    std::shared_ptr<SafeObject> b;
    Eigen::Vector3d normal = (a->getCenter() - b->getCenter()).normalized();
    Collision(std::shared_ptr<SafeObject> a, std::shared_ptr<SafeObject> b): a(a), b(b){
    }
};

class SafeCollisionModule: public SafeModule {

public:
    SafeCollisionModule(){
        setReceiveTickUpdate(true);
    }
    bool checkIfSphereIsColliding(std::shared_ptr<SafeSphere> a, std::shared_ptr<SafeSphere> b);
    void solveSphereCollision(Collision& collision);
    void onLoad() override;
    void onTick(World &world) override;
};


#endif //SAFEPHYSICSENGINE_SAFECOLLISIONMODULE_H
