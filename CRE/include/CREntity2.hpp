/**
* This is a revision of the CREntity Class.
*/

#ifndef CRENTITY2_HPP
#define CRENTITY2_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "CRPropertyManager.hpp"
#include "CRTypes.hpp"

namespace CRE
{

    class Entity : public sf::Drawable, public sf::Transformable
    {
        public:
            /// The entity's PropertyManager
            PropertyManager _properties;

            /**
            * Constructor sets the entityID (the name of the entity)
            */
            Entity(std::string ID, unsigned int order = 0);

            /**
            * Returns the string ID for this entity.
            */
            std::string get_ID() const;

            unsigned int get_order() const;

            virtual void update();

        private:

            /**
            *
            */
            virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

            /// The ID for this Entity
            std::string _entityID;

            unsigned int _order;

            /// The sprite that will be drawn to the window
            sf::Sprite _activeFrame;

            // TODO: Create an animator class

            friend Group;
    };

}

#endif
