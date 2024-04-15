#ifndef SEARCHSCENE_H
#define SEARCHSCENE_H

#include "scene.h"
#include "keystroke.h"
#include <set>
//#include "digscene.h"
//#include "museumscene.h"

//class MuseumScene;

class SearchScene : public Scene
{
public:
    explicit SearchScene(PlayerState& player, Scene** currentScene, QObject *parent = nullptr);
    virtual QPixmap buildScene();
    void initializePointers(DigScene &digScene, MuseumScene &museumScene);
    void updateWorld();

protected:
    virtual void activate();
    virtual void deactivate();
    virtual void processPlayerInput();
    virtual void setupBox2D();

    std::set<b2Contact*> charToFG1Contacts;
    std::set<b2Contact*> charToFG2Contacts;

    b2BodyDef characterBody;
    b2BodyDef foreground1Body;
    b2BodyDef foreground2Body;

    b2Body* staticCharBody;
    b2Body* dynForegrnd1Body;
    b2Body* dynForegrnd2Body;

    b2PolygonShape charBox;
    b2PolygonShape foregrnd1Box;
    b2PolygonShape foregrnd2Box;

    b2FixtureDef foregrnd1Fixture;
    b2FixtureDef foregrnd2Fixture;

    b2WorldManifold worldManifold;

    bool fixtureIsForegrnd1(b2Fixture* f);
    bool fixtureIsForegrnd2(b2Fixture* f);

    bool contactIsCharVsFG1(b2Contact* contact);
    bool contactIsCharVsFG2(b2Contact* contact);

    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);

    void ParticleBuilder(b2Vec2 worldPoint, float velocityA, float velocityB, float intensity);
    void GenerateParticles(std::set<b2Contact*> set);

private:
    DigScene* digPtr;
    MuseumScene* museumPtr;

    QPixmap background;

    QPixmap foreground;
    QPixmap otherForeground;
    QPixmap cactus;
    QPixmap currentCharacter;

    QPixmap rightIdleCharacter;
    QPixmap rightStep1Character;
    QPixmap rightStep2Character;

    QPixmap leftIdleCharacter;
    QPixmap leftStep1Character;
    QPixmap leftStep2Character;

    QPixmap digImage;

    DinosaurName currentDinosaur;
    DinosaurBone currentBone;

    //int cactusX = -9999;
    int stepCounter = 0;
    int spriteMovementIndex = 0;
    int movementFrameCounter = 0;
    int foregroundX = 0;
    int otherForegroundX = 1080;

    int digLocationX = 0;


    enum moving{right, left, idleRight, idleLeft};
    moving direction;
    moving prevDirection;

    bool isMoving;

    bool digSpot;

    bool bonePassed;

    bool digSoundPlayed;


    //REMOVE - ONLY FOR TESTING
    void printDinosaur();

    void moveRight();
    void moveLeft();
    void updatePlayerMovement();
    void updateForeground();
    void checkDigCollision();
    void drawUI();

    void spawnBone();

};

#endif // SEARCHSCENE_H
