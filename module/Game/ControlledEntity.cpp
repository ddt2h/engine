#include "ControlledEntity.hpp"

ControlledEntity::ControlledEntity() {

}

void ControlledEntity::init(Engine::Window *windowPtr, Engine::Data *dataPtr) {
    this->windowPtr = windowPtr;
    this->dataPtr = dataPtr;

    this->entity.initialize(dataPtr->getTexture("entity.png"), windowPtr->getWindowPtr());
    this->entity.setCentration();

    this->arrow.initialize(dataPtr->getTexture("arrow.png"), windowPtr->getWindowPtr());
    this->arrow.setCentration();

    this->hud.initValues(&health_, &stamina_, windowPtr->getWindowPtr());
    this->hud.addDelta(windowPtr->getDeltaTimePtr());

    this->weaponLeft.initialize(dataPtr->getTexture("w_l_2.png"), windowPtr->getWindowPtr());
    this->weaponLeft.setCentration();
    this->weaponRight.initialize(dataPtr->getTexture("w_l_2.png"), windowPtr->getWindowPtr());
    this->weaponRight.setCentration();


    collisionHandler.addPlane({{0, 0}, {0, 0}});
    collisionHandler.addPlane({{0, 0}, {0, 0}});
    collisionHandler.addPlane({{0, 0}, {0, 0}});
    collisionHandler.addPlane({{0, 0}, {0, 0}});
}

void ControlledEntity::updateControls() {

    if (!windowPtr->getWindowPtr()->hasFocus())
        return;

    if (sf::Keyboard::isKeyPressed(this->keyTurnLeft)){
        this->entity.rotateBy(*windowPtr->getDeltaTimePtr() * -rotationForce);
        this->arrow.rotateBy(*windowPtr->getDeltaTimePtr() * -rotationForce);
        this->weaponLeft.rotateBy(*windowPtr->getDeltaTimePtr() * -rotationForce);
        this->weaponRight.rotateBy(*windowPtr->getDeltaTimePtr() * -rotationForce);
        this->currentDashAngle+=*windowPtr->getDeltaTimePtr() * -rotationForce;
    }
    if (sf::Keyboard::isKeyPressed(this->keyTurnRight)){
        this->entity.rotateBy(*windowPtr->getDeltaTimePtr() * rotationForce);
        this->arrow.rotateBy(*windowPtr->getDeltaTimePtr() * rotationForce);
        this->weaponLeft.rotateBy(*windowPtr->getDeltaTimePtr() * rotationForce);
        this->weaponRight.rotateBy(*windowPtr->getDeltaTimePtr() * rotationForce);
        this->currentDashAngle+=*windowPtr->getDeltaTimePtr() * rotationForce;

    }

    if (sf::Keyboard::isKeyPressed(this->keyMoveForward)){
        performMovement();
    }
    if (!sf::Keyboard::isKeyPressed(this->keyMoveForward)){
        stopMovement();
    }

    if (sf::Keyboard::isKeyPressed(this->keyMoveBackward)){
        performBackFlip();
    }

    if (sf::Keyboard::isKeyPressed(this->keyDashForward)){
        performDash(dashForce);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        performAttack(0);
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        performEndAttack(0);
    }

}

void ControlledEntity::draw() {
    updateControls();
    updateTimings();
    updateMovements();
    updateArrow();
    updateRegeneration();
    updateWeaponary();
    calculateCollisionEdges();


    this->entity.drawTo();
    this->arrow.drawTo();
    this->weaponLeft.drawTo();
    this->weaponRight.drawTo();

    this->hud.draw(std::ref(*windowPtr->getWindowPtr()));
}

void ControlledEntity::setExternalPosition(sf::Vector2f position) {
    this->entity.setPosition(position);
    this->arrow.setPosition(position);
}

void ControlledEntity::moveExternalBy(sf::Vector2f by) {

}

void ControlledEntity::performMovement() {

    sf::Vector2f moveTrajectory;
    moveTrajectory.x = cos((double)currentDashAngle * 3.14159f / 180.0f) * moveForce.x ;
    moveTrajectory.y = sin((double)currentDashAngle * 3.14159f / 180.0f) * moveForce.y ;

    this->forceVector.x += moveTrajectory.x * *windowPtr->getDeltaTimePtr() * 10;
    this->forceVector.y += moveTrajectory.y * *windowPtr->getDeltaTimePtr() * 10;
}

void ControlledEntity::performDash(sf::Vector2f force) {

    if (isDashOnCooldown || stamina_ < 10)
        return;

    sf::Vector2f dashTrajectory;
    dashTrajectory.x = cos((double)currentDashAngle * 3.14159f / 180.0f) * force.x;
    dashTrajectory.y = sin((double)currentDashAngle * 3.14159f / 180.0f) * force.y;

    arrowTransparency = 255;

    this->forceVector += dashTrajectory;

    dynamicArrowSizeMul = arrowSizeMax;

    isDashOnCooldown = true;

    this->stamina_ -= 10;

}

void ControlledEntity::performBackFlip() {
    if (isDashOnCooldown || stamina_ < 10)
        return;

    this->entity.rotateBy(180);
    this->arrow.rotateBy(180);
    this->weaponLeft.rotateBy(180);
    this->weaponRight.rotateBy(180);
    this->currentDashAngle+=180;

    performDash(backForce);

    isDashOnCooldown = true;
}

void ControlledEntity::updateMovements() {
    forceVector.x -= forceVector.x / forceReduction.x;
    forceVector.y -= forceVector.y / forceReduction.y;

    this->entity.moveBy({static_cast<float>((forceVector.x) * *windowPtr->getDeltaTimePtr()),
                         static_cast<float>((forceVector.y) * *windowPtr->getDeltaTimePtr())});

    this->arrow.moveBy({static_cast<float>((forceVector.x) * *windowPtr->getDeltaTimePtr()),
                         static_cast<float>((forceVector.y) * *windowPtr->getDeltaTimePtr())});

}

void ControlledEntity::updateTimings() {
    if (isDashOnCooldown){
        dashTimer += *windowPtr->getDeltaTimePtr();

        if (dashTimer >= dashTimeInterval){
            dashTimer = 0;
            isDashOnCooldown = false;
        }
    }

}

void ControlledEntity::stopMovement() {
    this->moveVector = {0, 0};
}

void ControlledEntity::updateArrow() {
    //Transparency
    arrowTransparency -= arrowTransparencyDegradeSpeed * *windowPtr->getDeltaTimePtr();

    if (arrowTransparency <= arrowTransparencyMin)
        arrowTransparency = arrowTransparencyMin;

    //Size
    static bool inversion = false;

    if (inversion)
        dynamicArrowSizeMul += arrowSizeChangeSpeed * *windowPtr->getDeltaTimePtr();

    if (!inversion)
        dynamicArrowSizeMul += arrowSizeChangeSpeed * *windowPtr->getDeltaTimePtr() * -5;

    if (dynamicArrowSizeMul <= arrowSizeMin){
        inversion = true;
    }

    if (dynamicArrowSizeMul >= arrowSizeMax){
        inversion = false;
    }

    this->arrow.rescaleTo({dynamicArrowSizeMul,
                           dynamicArrowSizeMul});


    this->arrow.setTransparency((unsigned char)arrowTransparency);
}

void ControlledEntity::restrictCollision(bool axisX, bool axisY) {
    outOfBounds = true;
}

void ControlledEntity::calculateCollisionEdges() {

    sf::Vector2f topRight, topLeft, botLeft, botRight;
    sf::Vector2f center = entity.getPosition();
    float width = entity.getSize().x;
    float height = entity.getSize().y;
    float angle = currentDashAngle;

    //Top right
    topRight.x = center.x + ((width / 2) * cos(angle)) - ((height / 2) * sin(angle));
    topRight.y = center.y + ((width / 2) * sin(angle)) + ((height / 2) * cos(angle));

    //Top left
    topLeft.x = center.x - ((width / 2) * cos(angle)) - ((height / 2) * sin(angle));
    topLeft.y = center.y - ((width / 2) * sin(angle)) + ((height / 2) * cos(angle));

    //Bot left
    botLeft.x = center.x - ((width / 2) * cos(angle)) + ((height / 2) * sin(angle));
    botLeft.y = center.y - ((width / 2) * sin(angle)) - ((height / 2) * cos(angle));

    //Bot right
    botRight.x = center.x + ((width / 2) * cos(angle)) + ((height / 2) * sin(angle));
    botRight.y = center.y + ((width / 2) * sin(angle)) - ((height / 2) * cos(angle));

    collisionHandler.setPlane(0, {{topLeft.x, topLeft.y}, {topRight.x, topRight.y}});
    collisionHandler.setPlane(1, {{botLeft.x, botLeft.y}, {botRight.x, botRight.y}});
    collisionHandler.setPlane(2, {{topLeft.x, topLeft.y}, {botLeft.x, botLeft.y}});
    collisionHandler.setPlane(3, {{topRight.x, topRight.y}, {botRight.x, botRight.y}});
}

void ControlledEntity::rotateExternalBy(double degrees) {
    this->currentDashAngle = degrees;
    this->entity.rotateBy(degrees);
    this->arrow.rotateBy(degrees);
}

void ControlledEntity::performDamage(int amount) {
    health_ -= amount;

    if (health_ <= 0){
        health_ = 0;
        //resp
    }

}

void ControlledEntity::updateRegeneration() {
    health_ += healthRegeneration * *windowPtr->getDeltaTimePtr();
    stamina_ += staminaRegeneration * *windowPtr->getDeltaTimePtr();

    if (health_ >= healthCap)
        health_ = healthCap;

    if (stamina_ >= staminaCap)
        stamina_ = staminaCap;

    if (health_ <= 0)
        health_ = 0;

    if (stamina_ <= 0)
        stamina_ = 0;

}

void ControlledEntity::updateWeaponary() {

    if (!isInFlyingState){
        sf::Vector2f leftPos;
        sf::Vector2f rightPos;

        leftPos.x = entity.getPosition().x + cos((double)(currentDashAngle - 90) * 3.14159f / 180.0f)
                                             * (entity.getSize().x + weaponLeft.getSize().x) / 2;
        leftPos.y = entity.getPosition().y + sin((double)(currentDashAngle - 90) * 3.14159f / 180.0f)
                                             * (entity.getSize().x + weaponLeft.getSize().x) / 2;

        rightPos.x = entity.getPosition().x + cos((double)(currentDashAngle + 90) * 3.14159f / 180.0f)
                                              * (entity.getSize().x + weaponLeft.getSize().x) / 2;
        rightPos.y = entity.getPosition().y + sin((double)(currentDashAngle + 90) * 3.14159f / 180.0f)
                                              * (entity.getSize().x + weaponLeft.getSize().x) / 2;

        weaponLeft.setRotation(currentDashAngle + 90);
        weaponRight.setRotation(currentDashAngle + 90);

        weaponLeft.setPosition(leftPos);
        weaponRight.setPosition(rightPos);

    }

}

void ControlledEntity::performAttack(bool weapon) {
    //move forward, set bigger size, rotate in slice

    attackCounter += *windowPtr->getDeltaTimePtr();

    if (attackCounter >= attackTimeLimit){
        attackCounter = 0;
        inAttackState = false;
        stamina_ -= 20;
        attackPoints.clear();
        return;
    }

    sf::Vector2f point;
    point = {(float)sf::Mouse::getPosition(*windowPtr->getWindowPtr()).x,
             (float)sf::Mouse::getPosition(*windowPtr->getWindowPtr()).y};

    attackPoints.push_back(point);

    sf::VertexArray vertexes;
    vertexes.setPrimitiveType(sf::LinesStrip);
    vertexes.resize(attackPoints.size());
    for (int i = 0; i < attackPoints.size(); i++){

        vertexes[i].position.x = attackPoints[i].x;
        vertexes[i].position.y = attackPoints[i].y;

        vertexes[i].color = sf::Color::Black;
    }
    inAttackState = true;

    windowPtr->getWindowPtr()->draw(vertexes);
}

void ControlledEntity::performEndAttack(bool weapon) {

    attackCounter = 0;

    if (inAttackState && !attackPoints.empty()){

        isInFlyingState = true;
        //Distance to first point
        float distance = sqrt(pow(attackPoints[0].x - entity.getPosition().x, 2)
                + pow(attackPoints[0].y - entity.getPosition().y, 2) * 1.0);

        //Overall distance
        float globalDistance = 0;
       /* for (int i = 0; i < attackPoints.size() - 1; i++){
            globalDistance += (int)sqrt(pow(attackPoints[i].x - attackPoints[i + 1].x, 2)
                                  + pow(attackPoints[i].y - attackPoints[i + 1].y, 2) * 1.0);
        }*/

        if (distance > 200 || globalDistance > 1500){
            attackPoints.clear();
            attackIterator = 0;
            inAttackState = false;
          //  isInFlyingState = false;
            return;
        }

        attackIterator += attackIteratorSpeed * *windowPtr->getDeltaTimePtr();

        if ((int)attackIterator >= attackPoints.size()){
            attackPoints.clear();
            attackIterator = 0;
            inAttackState = false;
            stamina_ -= 20;
            isInFlyingState = false;
            return;
        }

        sf::Vector2f vec;
        vec.x = attackPoints[(int)attackIterator].x;
        vec.y = attackPoints[(int)attackIterator].y;


        float angle = atan2f(entity.getPosition().y - vec.y, entity.getPosition().x - vec.x);
        weaponLeft.setRotation(angle * 180 / 3.1415);


        weaponLeft.setPosition(vec);
    }

/*    if (!attackPoints.empty()){
        attackPoints.clear();
    }*/
}




