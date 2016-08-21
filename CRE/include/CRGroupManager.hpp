#ifndef CRGROUPMANAGER_HPP
#define CRGROUPMANAGER_HPP

#include <map>
#include "CRTypes.hpp"
#include "CRGroup.hpp"

namespace CRE
{
    class GroupManager
    {
        public:

            /**
            * Default constructor for the GroupManager
            */
            GroupManager();

            /**
            * Deconstructor deallocates all groups' entities
            */
            ~GroupManager();

            /**
            *
            */
            void add(Group * newGroup);

            /**
            *
            */
            void create_new(std::string groupName);

            /**
            *
            */
            Group& get(std::string groupName);

        private:
            /// Map stores all of the groups added to this GroupManager
            std::map<std::string, Group*> _groups;
    };
}

#endif
