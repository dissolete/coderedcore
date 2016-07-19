#ifndef CRENTITYMANAGER_HPP
#define CRENTITYMANAGER_HPP

#include "CRApp.hpp"
#include "CRTypes.hpp"
#include "CREntity.hpp"
#include <string>
#include <map>


namespace CRE{
	
	class EntityManager{

	public:

		EntityManager();

		~EntityManager();

		void add_Entity(Entity* theEntity , std::string entityID);

		Entity& get_Entity(std::string entityID);

		void update_Entities(float appTime);

		void draw_Entities();

		void remove_Entity(std::string entityID);

		void clear();

		void draw_Entity(std::string entityID);

		void update_Entity(std::string entityID);



		


	private:

		App * _theApp;
        // the map that holds all of the entities
		std::map<std::string, Entity*> ordered_map;

	};
}


#endif