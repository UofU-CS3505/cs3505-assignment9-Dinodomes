#ifndef SCENE_H
#define SCENE_H

// #include "keystroke.h"
#include "playerstate.h"
// #include "dinosaurbone.h"
// #include "dinosaurname.h"
#include <QPixmap>
#include <Box2D/Box2D.h>
#include <QPainter>

#include <QDebug>

/// @brief Header file for scene superclass
/// Superclass for various scenes. Keeps track of and initializes default world states for each subclass scene
/// Reviewed by Arjun Sarkar

/// @brief Forward declaration of dig scene class to avoid recursive includes with pointers
class DigScene;

/// @brief Forward declaration of search scene class to avoid recursive includes with pointers
class SearchScene;

/// @brief Forward declaration of museum scene class to avoid recursive includes with pointers
class MuseumScene;

class Scene : public QObject
{
    Q_OBJECT
public:
    /// @brief Constructor that takes in parameters to initialize a scene based on the provided parameters
    /// @param player: passes the player state
    /// @param currentScene: sets the current scene to passed param
    /// @param parent: initializes QObject
    explicit Scene(PlayerState& player, Scene** currentScene, QObject *parent = nullptr);

    /// @brief buildScene: Builds the current image to be shown on the screen
    /// @return The current scene as a QImage
    virtual QPixmap buildScene();

protected:
    /// @brief Stores the player state and supporting field values
    PlayerState* player;

    /// @brief Stores created Box2D world and its supporting gravity value
    b2World world;

    /// @brief Stores the current frame
    QPixmap frame;

    /// @brief Stores a QPainter object to paint the scenes
    QPainter painter;

    /// @brief Pointer to a pointer that stores what the current scene is
    Scene** currentScene;

    /// @brief Float that keeps track of frames per second
    float32 timeStep;

    /// @brief Keeps track if the scene is activated or not (mainly utilized in subclasses)
    bool activated;

    /// @brief Method that is overridden by the subclasses to build the scene and set it as the current one
    virtual void activate();

    /// @brief Method that is overridden by the subclasses and makes it so the scene is no longer the current scene
    virtual void deactivate();

    /// @brief Method that is overridden by the subclasses to proccess the player input
    virtual void processPlayerInput();

signals:
};

#endif // SCENE_H
