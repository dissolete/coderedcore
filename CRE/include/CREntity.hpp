/**
 * @file CREntity.hpp
 *
 * @brief Header file for Entity class
 * 
 * @details Every function is pure virtual
 *
 * @author Nina Hees
 *
 * @version 1.00 (10 July 2016)
 *
 * @Note 
 */


//This is a datatype 
#ifndef CRENTITY_HPP
#define CRENTITY_HPP

#include <SFML/System/Vector2.hpp>
#include "CRTypes.hpp"
#include "CRApp.hpp"

namespace CRE{

	class Entity{

	public:

		/**
 		* @brief Constructor
 		*
 		* @details It does nothing
 		*          
 		* @param None
 		*
 		* @note Its does nothing 
 		*/
		Entity();

		Entity(int positionX, int positionY, unsigned int width, unsigned int height);

		/**
 		* @brief Deconstructor 
 		*
 		* @details It does nothing 
 		*          
 		* @param None
 		*
 		* @note its virtual
 		*/
        virtual ~Entity();

        /**
 		* @brief Process events
 		*
 		* @details Allow the entity to do its own event handling 
 		*          
 		* @param None
 		*
 		* @note its pure virtual
 		*/
		virtual void process_events() = 0;

		/**
 		* @brief init
 		*
 		* @details Allocates and creates resources needed by the entity
 		*          
 		* @param None
 		*
 		* @note its pure virtual
 		*/
		virtual void init() = 0;

		/**
 		* @brief cleanup
 		*
 		* @details Deallocates resources created by the entity
 		*          
 		* @param None
 		*
 		* @note its pure virtual
 		*/
		virtual void cleanup() = 0;

		/**
 		* @brief update
 		*
 		* @details Updates the entity 
 		*          
 		* @param None
 		*
 		* @note its pure virtual
 		*/
		virtual void update(float appTime) = 0;

		/**
 		* @brief draw
 		*
 		* @details renders the entity in the window
 		*          
 		* @param None
 		*
 		* @note its pure virtual
 		*/
		virtual void draw() = 0;

		sf::Vector2f get_position() const;

		unsigned int get_width() const;

		unsigned int get_height() const;

		void set_position(int x, int y);

		void set_position(sf::Vector2f newPosition);

		void set_width(unsigned int newWidth);

		void set_height(unsigned int newHeight);


	private:
		// TODO: Perhaps have a map of stats called attributes
		// So each entity could have a container for their
		// specific attributes
		sf::Vector2f _position;
		unsigned int _width, _height;
	};

}

#endif