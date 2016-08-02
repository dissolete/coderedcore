
#include "CRHitBox.hpp"

namespace CRE{


/**
  * @brief Implemtation of the constructor for hitbox
  *
  * @details gets the position of entity and creates the hitbox around it
  *
  * @pre hitbox has not been set yet
  *
  *
  * @post hitbox is now set around entity
  * 
  * @par Algorithim
  *      
  *
  *
  * @param[in] the Entity the hitbox is around
  *
  *
  * @return nothing
  *
  * @note 
  */   
HitBox::HitBox(Entity& theEntity): 
	_classEntity(theEntity)
{

   sf::Vector2f _position = _classEntity.get_position();

   _hitBox.setPosition(_position.x, _position.y);
   

}


		/**
  * @brief Deconstructor
  *
  * @details it does nothing
  *
  */   
HitBox::~HitBox()
{

	

}

/**
  * @brief Implementation of set point counf
  *
  * @details does what the title says
  *
  * 
  * @par Algorithim calls the sfml function
  *      
  *
  *
  * @param[in] number of points the hitbox will have
  *
  *
  * @return nothing
  *
  * @note see below the function implemenation 
  */   
void HitBox::set_point_count(int _points)
{

 _hitBox.setPointCount(_points);

} 

		

	/*****The order in which you define the points is very important. They must all be defined either ****/
	/***in clockwise or counter-clockwise order. If you define them in an inconsistent order, the shape will be constructed incorrectly. */
		

		/**
  * @brief Implemtation of set point
  *
  * @details sets the location of a specific point
  *
  *
  * @param[in] the index and vector coordinatesS
  *
  *
  * @return nothing
  *
  * @note 
  */   
void HitBox::set_point(int index,	const sf::Vector2f & point   )
{

_hitBox.setPoint(index, point);

} // POINTS NEED TO BE DEFINED

 
		/**
  * @brief Implemtation of get convex
  *
  * @details returns the convex shape
  *
  *
  *
  * @return the convex shape 
  *
  * @note 
  */           
sf::ConvexShape& HitBox::get_convex_shape() 
{

	return _hitBox; // doesnt like it when I return a reference unsure why

}

		/**
  * @brief Implemtation of set tranparent
  *
  * @details make the shape transparent
  *
  * @pre was transparent
  *
  *
  * @post is transparetn
  * 
  * @par Algorithim
  *		calls setfillcolor and set outlinecolor
  *      

  *
  * @param[in] 
  *
  *
  * @return 
  *
  * @note 
  */   
void HitBox::set_transparent(int transparent)
{  /// do we still want an opacity value??

		_hitBox.setFillColor(sf::Color::Transparent);
		_hitBox.setOutlineColor(sf::Color::Transparent);
         
}

		/**
  * @brief Implemntation of update
  *
  * @details Updates the hitbox
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
  */   // how will I update it ???????
void HitBox::update()
{
// calls entity update needs a time in the parameter??
}

	}
