#include "CRGroupManager.hpp"

namespace CRE
{
    GroupManager::GroupManager()
    {}

    GroupManager::~GroupManager()
    {
        // Cleanup all entities
        for(auto it = _groups.begin(); it != _groups.end(); ++it)
        {
            // Get reference to group
            Group * aGroup = it->second;

            // Remove pair from map
            _groups.erase(it);

            // Cleanup group
            aGroup->cleanup();

            // Delete the group
            delete aGroup;

            // Remove local pointer
            aGroup = NULL;
        }
    }

    void GroupManager::add(Group * newGroup)
    {
        // TODO: Check if the group already exists in the map, if it does,
        // log that it does and quit app?

        // Check if the ptr is not bad
        if( newGroup != NULL )
            _groups.insert(std::pair<std::string, Group*>(newGroup->get_ID(), newGroup));
    }

    void GroupManager::create_new(std::string groupName)
    {
        // TODO: Check if the group already exists in the map, if it does,
        // log that it does and quit app?

        // Allocate new group
        Group * newGroup = new(std::nothrow) Group(groupName);

        if( newGroup != NULL )
            _groups.insert(std::pair<std::string, Group*>(newGroup->get_ID(), newGroup));

        // Remove local pointer
        newGroup = NULL;

    }

    Group& GroupManager::get(std::string groupName)
    {
        // TODO: What to do if the group doesn't exist?
        return *(_groups.at(groupName));
    }
}
