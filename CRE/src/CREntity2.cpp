#include "CREntity2.hpp"

namespace CRE
{
    Entity::Entity(std::string ID, unsigned int order) :
        sf::Drawable(),
        sf::Transformable(),
        _properties(),
        _entityID(ID),
        _order(order)
    {}

    std::string Entity::get_ID() const
    {
        return _entityID;
    }

    void Entity::update(){}

    unsigned int Entity::get_order() const
    {
        return _order;
    }

    void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
    }
}
