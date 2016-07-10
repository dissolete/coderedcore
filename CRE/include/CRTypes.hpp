/**
* Forward declares neccessary class objects used by the CR Core
* to combat circular dependency.
*/

#ifndef CRTYPES_HPP
#define CRTYPES_HPP

#include <stdint.h>

namespace CRE
{
	class App;
	class State;

	class StateManager;
	class TextManager;
	class SoundManager;
    class EntityManager;

    class ActionList;

    class Entity;
    class Action;
    class Hitbox;
	class CRMusic;
	class CRSound;
	class CRText;
}

#endif