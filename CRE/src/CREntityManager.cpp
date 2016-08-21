// #include "CREntityManager.hpp"
//
// namespace CRE
// {
//
// 	EntityManager::EntityManager()
// 	{ // so far cant think of anything
//
// 	}
//
//
// 	EntityManager :: ~EntityManager()
// 	{ // same as constructor
// 		clear();
// 	}
//
//
// 	void EntityManager::add_entity(std::string entityID, Entity * theEntity)
// 	{
//
// 		_entityMap.insert(std::pair<std::string, Entity*>(entityID, theEntity));
//
// 	}
//
// 	Entity& EntityManager::get_entity(std::string entityID)
// 	{
// 
// 		return *(_entityMap[entityID]);
//
// 	}
//
// 	void EntityManager::update_entities(float appTime)
// 	{
// 		// Iterate through entity map
// 	 	for(auto it = _entityMap.begin(); it != _entityMap.end(); ++it)
// 	 	{
// 	 		// Call update function on entity
// 	 		(*it).second->update(appTime);
// 	 	}
//
// 	}
//
// 	void EntityManager::draw_entities()
// 	{
// 		// Iterate through entity map
// 		for(auto it = _entityMap.begin(); it != _entityMap.end(); ++it)
// 		{
// 			// Call draw function on entity
// 			(*it).second->draw();
// 		}
//
// 	}
//
// 	void EntityManager::remove_entity(std::string entityID)
// 	{
//
// 		// Get pointer to the entity to be deleted
// 		Entity * theEntity = _entityMap[entityID];
//
// 		// Remove the pointer from the map
// 		_entityMap.erase(entityID);
//
// 		// Deallocate the memory
// 		delete theEntity;
//
// 		// Remove local pointer
// 		theEntity = NULL;
//
// 	}
//
// 	void EntityManager::clear()
// 	{
// 		// Local entity pointer
// 		Entity * theEntity;
//
// 		// Iterate through map
// 		for(auto it = _entityMap.begin(); it != _entityMap.end(); ++it)
// 		{
// 			// Get pointer to the entity to be deleted
// 			theEntity = (*it).second;
//
// 			// Remove this pointer from the map
// 			_entityMap.erase(it);
//
// 			// Deallocate the memory for the entity
// 			delete theEntity;
// 		}
//
// 		// Remove local pointer
// 		theEntity = NULL;
// 	}
//
//
// 	void EntityManager::draw_entity(std::string entityID)
// 	{
// 		_entityMap[entityID]->draw();
// 	}
//
//
// 	void EntityManager::update_entity(std::string entityID)
// 	{
//
// 		float app_time; // entity manager needs this as a parameter
//
// 		_entityMap[entityID]->update(app_time); // what about the apptime??
//
// 	}
//
//
// }
