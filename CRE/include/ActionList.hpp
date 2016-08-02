#ifndef ACTIONLIST_HPP
#define ACTIONLIST_HPP

#include <string>
#include <list>
#include "CRTypes.hpp"
#include "Action.hpp"

namespace CRE
{
    class ActionList
    {
        public:

            ActionList();//won't really do anything

            ~ActionList();//clear memory, actions will be dynamically allocated. Actions deleted here. Call clear

            bool is_empty() const;

            void push_back(Action * theAction);//add to the back of the list

            void push_front(Action * theAction);//add to the front of the list

            Action & get_active() const;//return action at the front of the list

            void update();//check to see if active action is done. Call isDone. If it is done, push it to the back and call reset on previously active action

            bool set_active(std::string actionID);//iterate through list, find action by ID, push to front. Previous active goes to the second spot. Call reset on the action moved from the front

            bool remove_action(std::string actionID);//deallocate the action with that ID

            void clear();//same as deconstructor

        private:

            std::list<Action *> _theActions;
    };
}

#endif