#include "CREntity.hpp"

namespace CRE
{
    Entity::Entity() :
        _position(0,0),
        _width(0),
        _height(0)
    {}

    Entity::Entity(int positionX, int positionY, 
            unsigned int width, unsigned int height) :
        _position(positionX, positionY),
        _width(width),
        _height(height)
    {}

    Entity::~Entity()
    {}

    sf::Vector2f Entity::get_position() const
    {
        return _position;
    }

    unsigned int Entity::get_width() const
    {
        return _width;
    }

    unsigned int Entity::get_height() const
    {
        return _height;
    }

    void Entity::set_position(int x, int y)
    {
        _position.x = x;
        _position.y = y;
    }

    void Entity::set_position(sf::Vector2f newPos)
    {
        _position = newPos;
    }

    void Entity::set_width(unsigned int newWidth)
    {
        _width = newWidth;
    }

    void Entity::set_height(unsigned int newHeight)
    {
        _height = newHeight;
    }

}