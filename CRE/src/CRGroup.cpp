#include "CRGroup.hpp"

namespace CRE
{
    Group::Group(std::string ID) :
        _entities(),
        _ID(ID)
    {}

    Group::~Group()
    {
    }

    std::string Group::get_ID() const
    {
        return _ID;
    }

    void Group::add(Entity * newEntity)
    {
        // Make sure the pointer provided is not bad
        if( newEntity != NULL )
        {
            // Get the order of the entity
            unsigned int entityOrder = newEntity->get_order();

            auto it = _entities.begin();
            int count = 0;
            while(count < entityOrder and it != _entities.end())
            {
                it++;
                count++;
            }

            _entities.insert(it, newEntity);

            // Then increment the order of everything begind this
            while(count <= _entities.size())
            {
                _entities.at(count)->_order++;
                count++;
            }
        }
        else
        {
            //TODO: Log that the entity could not be added
        }
    }

    void Group::draw(sf::RenderTarget& theTarget)
    {
        // Iterate through entity vector and draw them to the RenderTarget
        for(auto entityIT : _entities)
            theTarget.draw(*entityIT);
    }

    void Group::update()
    {
        // Iterate through entity vector and call their update function
        for(auto entityIT : _entities)
            entityIT->update();
    }

    bool Group::has_entity(std::string entityID)
    {
        // Iterate through entity vector and return true if entityID is found
        for(auto entityIT : _entities)
            if(entityIT->get_ID() == entityID)
                return true;
        // Return false otherwise
        return false;
    }

    Entity& Group::get_entity(std::string entityID)
    {
        for(auto entityIT : _entities)
        {
            if(entityIT->get_ID() == entityID)
                return *entityIT;
        }
        // TODO: WHAT DO I RETURN IF THE ENTITY DOESNT EXIST? D:
    }

    void Group::cleanup()
    {
        Entity * anEntity = NULL;
        while( not _entities.empty() )
        {
            // Get a pointer to the entity in the back of the vector
            anEntity = _entities.back();

            // Remove the entity ptr from the vector
            _entities.pop_back();

            // Deallocate the entity
            delete anEntity;

            // Remove local pointer
            anEntity = NULL;
        }
    }
}
