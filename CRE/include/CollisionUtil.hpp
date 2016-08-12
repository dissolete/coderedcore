/**
* @file CollisionUtil.hpp
* @author Jake Shepherd
*/

#ifndef COLLISIONUTIL_HPP
#define COLLISIONUTIL_HPP

#include "CRHitBox.hpp"

namespace CRE
{
    /**
    * Checks for basic rectangle collision and returns true if the two
    * rectangles bounding the entities collide. Note that this uses the
    * rectangles bounding the sf::ConvexShape of the hitbox and not the
    * actual entity. Assumes that the hitboxes are oriented correctly
    * around the entity.
    *
    * @param[in] Constant references to the entities being tested.
    * @return true if the two rectangles overlap
    */
    bool rectangle_collision(const HitBox & hOne, const HitBox & hTwo);

    /**
    * Checks for collision using the serperation of axis theorem (SAT). The details
    * of the theorem are better outlined in the implementation of this function.
    * Use this collision type for more acurate collision between any two
    * convex shapes.
    *
    * @param[in] Constant references to the entities being tested.
    * @return true if the SAT test passes.
    */
    bool sat_collision(const HitBox & hOne, const HitBox & hTwo);

}

#endif