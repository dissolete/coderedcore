#ifndef CRENTITYMANAGER_CPP
#define CRENTITYMANAGER_CPP

#include "CREntityManager.hpp"

namespace CRE{

EntityManager::EntityManager(){ // so far cant think of anything

}

EntityManager :: ~EntityManager(){ // same as constructor

}

void EntityManager:: add_Entity(Entity * theEntity, std::string entityID){

ordered_map.insert(std::pair<std::string, Entity>(entityID, theEntity) );

}

Entity& EntityManager:: get_Entity(std::string entityID){

return & ordered_map[entityID];

}


		

void EntityManager::update_Entities(float appTime){
 	for(std::map<std::string, Entity>::iterator it=ordered_map.begin(); it!=ordered_map.end(); ++it){
 		it->update(appTime);
 	}

}

		

void EntityManager::draw_Entities(){

	for(std::map< std::string, Entity>::iterator it=ordered_map.begin(); it!=ordered_map.end(); ++it){
     
     _theApp -> _window.draw(&it); //not sure about the pointer

	}	

}

		
void EntityManager::remove_Entity(std::string entityID){

	ordered_map.erase(entityID);

		}

		

void EntityManager::clear(){

	ordered_map.clear();

}

		
void EntityManager::draw_Entity(std::string entityID){

	_theApp->_window.draw(ordered_map[entityID]);

}

		
void EntityManager::update_Entity(std::string entityID){

	float app_time; // entity manager needs this as a parameter

	ordered_map[entityID]-> update(app_time); // what about the apptime??

}

}

#endif