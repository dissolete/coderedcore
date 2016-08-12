/**
* Defines useful math functions possibly used with the Code Red
* Engine.
*/

#ifndef CRMATH_HPP
#define CRMATH_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include "CRTypes.hpp"

namespace CRE
{

    const float PI = 3.141592653589793;

    ///////////////////////
    /* Random generation */
    ///////////////////////

    /**
    * Sets the seed for the random number generator.
    */
    void set_seed(uint32_t theSeed);

    /**
    * Returns a random float (inclusive) between a min value and a max value.
    */
    float random(float min, float max);

    /**
    * Returns a random int (inclusive) between a min value and a max value.
    */
    int random(int min, int max);

    /**
    * Returns a random 32-bit int (inclusive) between a min value and a max value.
    */
    uint32_t random(uint32_t min, uint32_t max);

    /////////////////////////
    /* Vector manipulation */
    /////////////////////////

    /**
    * Returns the dot product of two vectors.
    */
    float dot_product(sf::Vector2f vectorA, sf::Vector2f vectorB);

    /**
    * Returns the normal vector.
    */
    sf::Vector2f normalize_vector(sf::Vector2f theVector);

    sf::Vector2f vector_between_points(const sf::Vector2f & vectorOne, const sf::Vector2f & vectorTwo);

    //////////////////////////
    /* Trigonometry helpers */
    //////////////////////////

    /**
    * Converts radians into degrees
    */
    float to_degrees(float radians);

    /**
    * Converts degrees into radians
    */
    float to_radians(float degrees);
}

#endif