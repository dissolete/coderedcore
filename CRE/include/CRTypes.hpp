/**
* Forward declares neccessary class objects used by the CR Core
* to combat circular dependency.
*/

#ifndef CRTYPES_HPP
#define CRTYPES_HPP

#include <stdint.h>

namespace CRE
{

    // Interface classes
	class App;
	class State;

    // Entity classes
    class Entity;
    class Action;
    class Hitbox;
    class ActionList;

    // Asset Classes
	class CRMusic;
	class CRSound;
	class CRText;

	template <typename T>
	class Stat;

	class Timer;

    // Manager Classes
    class StateManager;
    class TextManager;
    class SoundManager;
    class EntityManager;
    class StatManager;
    class TimerManager;
	class GroupManager;
	class TileMapManager;


    // Unclassified atm
    class CRTileMap;
	class PropertyManager;
	class IProperty;
	class Group;
}

#endif
