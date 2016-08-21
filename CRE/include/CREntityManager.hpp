#ifndef CRENTITYMANAGER_HPP
#define CRENTITYMANAGER_HPP

#include "CRApp.hpp"
#include "CRTypes.hpp"
#include "CREntity2.hpp"
#include <string>
#include <map>


namespace CRE{

	class EntityManager{

	public:

		// EntityManager();
		//
		// ~EntityManager();
		//
		// void add_entity(std::string entityID, Entity* theEntity);
		//
		// Entity& get_entity(std::string entityID);
		//
		// void update_entities(float appTime);
		//
		// void draw_entities();
		//
		// void remove_entity(std::string entityID);
		//
		// void clear();
		//
		// void draw_entity(std::string entityID);
		//
		// void update_entity(std::string entityID);

		//TODO: bool collides_with()

	private:

		//App * _theApp;
        // the map that holds all of the entities
		std::map<std::string, Entity*> _entityMap;

	};
}


#endif
