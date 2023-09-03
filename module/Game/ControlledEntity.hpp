#ifndef NFFSMODULE_CONTROLLEDENTITY_HPP
#define NFFSMODULE_CONTROLLEDENTITY_HPP

#include "../src/Drawing.hpp"

#include "../src/Window.hpp"

#include "../src/Data.hpp"

#include "../src/CollisionHandler.hpp"

#include "HUD.hpp"

class ControlledEntity{
public:
    ControlledEntity();

    void init(Engine::Window *windowPtr, Engine::Data *dataPtr);

    void draw();

    //external control by arena

    void setExternalPosition(sf::Vector2f position);

    void moveExternalBy(sf::Vector2f by);

    void rotateExternalBy(double degrees);

    void restrictCollision(bool axisX, bool axisY);

    void performDamage(int amount);

    Engine::CollisionHandler collisionHandler;

private:
    void updateControls();

    void updateMovements();

    void updateTimings();

    void updateArrow();

    void updateWeaponary();

    void calculateCollisionEdges();

    void performDash(sf::Vector2f force);
    void performMovement();
    void performBackFlip();
    void performAttack(bool weapon);
    void performEndAttack(bool weapon);

    void stopMovement();

    void updateRegeneration();

    Engine::Window *windowPtr;
    Engine::Data *dataPtr;

    Engine::Drawing entity;
    Engine::Drawing arrow;
    Engine::Drawing weaponLeft;
    Engine::Drawing weaponRight;
    HUD hud;

    sf::Keyboard::Key keyTurnLeft{sf::Keyboard::Key::A};
    sf::Keyboard::Key keyTurnRight{sf::Keyboard::Key::D};
    sf::Keyboard::Key keyMoveForward{sf::Keyboard::Key::W};
    sf::Keyboard::Key keyMoveBackward{sf::Keyboard::Key::S};
    sf::Keyboard::Key keyDashForward{sf::Keyboard::Key::Space};


    double currentDashAngle{0};
    double dashTimer;

    bool isDashOnCooldown{false};

    sf::Vector2f moveVector;
    bool outOfBounds{false};

    double dashTimeInterval{0.33};
    float rotationForce{320.0f};
    sf::Vector2f moveForce{400.0f, 400.0f};
    sf::Vector2f dashForce{1700.0f, 1700.0f};
    sf::Vector2f backForce{1200.0f, 1200.0f};
    sf::Vector2f forceVector{0, 0};
    //This divides overall force, not subtracts
    sf::Vector2f forceReduction{200.0, 200.0};

    //
    float arrowTransparency{255};
    float arrowTransparencyDegradeSpeed{350};
    float arrowTransparencyMin{90};
    float arrowSizeChangeSpeed{0.4f};
    float arrowSizeMin{0.7f};
    float arrowSizeMax{1.0f};
    float dynamicArrowSizeMul{1.0f};

    //
    double health_{200};
    double stamina_{100};

    double healthCap{200};
    double staminaCap{100};

    //
    double healthRegeneration{40};
    double staminaRegeneration{5};

    //
    std::vector<sf::Vector2f> attackPoints;
    bool inAttackState{false};
    bool isInFlyingState{false};
    double attackIterator{0};
    double attackIteratorSpeed{1850};
    double attackCounter{0};
    double attackTimeLimit{0.5};

};

#endif //NFFSMODULE_CONTROLLEDENTITY_HPP
