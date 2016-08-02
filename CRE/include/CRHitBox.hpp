/**
 * @file CRHitBox.hpp
 *
 * @brief Header file for HitBox class
 * 
 * @details 
 *
 * @author Nina Hees
 *
 * @version 1.00 (24 July 2016)
 *
 * @Note The hitbox is an invisibile box around the entity
 */
#ifndef CRHITBOX_HPP
#define CRHITBOX_HPP

#include "CREntity.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/ConvexShape.hpp>


namespace CRE{

	class HitBox{

	public:


		/**
  * @brief I
  *
  * @details 
  *
  * @pre 
  *
  *
  * @post l
  * 
  * @par Algorithim
  *      
  *
  * @exception 
  *
  * @param[in] 
  *
  *
  * @return 
  *
  * @note 
  */      
		HitBox(Entity& theEntity);

		~HitBox();

		void set_point_count(int _points ); // will call the sfml function

		//The order in which you define the points is very important. They must all be defined either 
		//in clockwise or counter-clockwise order. If you define them in an inconsistent order, the shape will be constructed incorrectly. 

		void set_point(int index,	const sf::Vector2f & point   ); // POINTS NEED TO BE DEFINED

        // returns reference for collision system
		sf::ConvexShape& get_convex_shape() ;


		void set_transparent(int transparent);


		void update();




	private:

		Entity& _classEntity;

		sf::ConvexShape _hitBox;






	};
}


#endif