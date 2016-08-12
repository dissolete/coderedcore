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

            ActionList();

            ~ActionList();

            bool is_empty() const;

            void push_back(Action * theAction);

            void push_front(Action * theAction);

            Action & get_active() const;

            void update();

            void set_active(std::string actionID);

            void remove_action(std::string actionID);

            void clear();

        private:

            std::list<Action *> _theActions;
    };
}

#endif