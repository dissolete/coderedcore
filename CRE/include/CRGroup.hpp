/**
* Defines the Group class. The group class is inspired by the group
* object in the Pygame library. It is 2:20AM and I am tired. TODO:
* define this shit lol. This will replace the EntityManager class.
*/

#ifndef CRGROUP_HPP
#define CRGROUP_HPP

#include "CRTypes.hpp"
#include "CREntity2.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace CRE
{
    // Group inherits from vector class to have the basic functionality
    // as std::vector but with added functionality defined below.
    class Group
    {
        public:

            /**
            * Default constructor for Group class
            */
            Group(std::string ID);

            /**
            * Group Deconstructor. Removes all entity pointers. IMPORTANT:
            * this only removes the POINTERS to the entities and DOES NOT
            * deallocate them!!! Proper deallocation should be handled by
            * the group manager class. If using a group outside the group
            * manager class, use the clean function to properly deallocate
            * the entities.
            */
            ~Group();

            /**
            * Returns the ID for this group.
            */
            std::string get_ID() const;

            /**
            * Adds a new entity to the group and places it in the proper
            * location to be rendered or updated.
            */
            void add(Entity * newEntity);

            /**
            * Draws all sf::Drawables to the RenderTarget
            */
            void draw(sf::RenderTarget& theTarget);

            /**
            * Updates the entities included in this Group class.
            */
            void update();

            /**
            * Returns true if the entityID is found in this group
            */
            bool has_entity(std::string entityID);

            /**
            * Returns a reference to an entity if it exists in this group
            */
            Entity& get_entity(std::string entityID);

            /**
            * Deallocates the entities included in this group.
            */
            void cleanup();
        private:
            std::vector<Entity*> _entities;
            std::string _ID;
    };
}//namespace CRE
#endif
