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
		Entity()
		{}

		/**
 		* @brief Deconstructor 
 		*
 		* @details It does nothing 
 		*          
 		* @param None
 		*
 		* @note its virtual
 		*/
        virtual ~Entity()
        {}

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
 		* @param appTime- time since last screen refresh
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

		sf::Vector2f get_position(){

			return _position;
		}

	private:

		sf::Vector2f _position;


			};

}

#endif