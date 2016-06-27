#ifndef CRSTATEMANAGER_HPP
#define CRSTATEMANAGER_HPP

#include <string>
#include <vector>
#include "CRTypes.hpp"

namespace CRE
{
    class StateManager
    {
        public:

            /////////////////////////////
            /* Public member functions */
            /////////////////////////////

            /**
            * Constructor for the Statemanager class.
            */
            StateManager();

            /**
            * Deconstructor for the manager class.
            * TODO: Does this really need to be virtual?
            */
            virtual ~StateManager();

            /**
            * Registers the app pointer for this class so we can refer
            * back to the app for error handling or other needs.
            */
            void register_app(App * theApp);

            /**
            * Returns whether or not the active state stack is empty.
            */
            bool is_empty(void);

            /**
            * Adds an active state to the top of the state stack.
            */
            void add_active_state(State * newState);

            /**
            * Adds a state to the bottom of the state stack.
            */
            void add_inactive_state(State * newState);

            /**
            * Gets a reference to the current active state.
            */
            State & get_active_state(void);

            /**
            * Deactivates the active state. Does not deinit the state.
            */
            void deactivate_active_state(void);

            /**
            * Drops the active state. Deinits the state.
            */
            void drop_active_state(void);

            /**
            * Resumes the active state.
            */
            void reset_active_state(void);

            /**
            * Kills the active state. State is moved to the dead state stack.
            */
            void remove_active_state(void);

            /**
            * Sets a specific state to become active. Current active state gets
            * paused.
            */
            void set_active_state(std::string stateID);

            /**
            * Properly destroys a state in the dead state stack. This function is called
            * every frame. Does nothing if there are no states to destroy.
            */
            void cleanup();

        private:

            //////////////////////////////
            /* Private member variables */
            //////////////////////////////

            // Pointer to the App class for error handling and logging
            App * _theApp;

            // Stack to store the current and previously active game states
            std::vector<State*> _activeStack;

            // Stack to store the dead states until they are properly cleaned
            std::vector<State*> _deadStack;

            //////////////////////////////
            /* Private member functions */
            //////////////////////////////

            /**
            * Copy constructor is private because we do not allow
            * copies of our class.
            */
            StateManager(const StateManager&); // intentionally undefined

            /**
            * Assignment operator is private because we do not allow
            * copies of our class.
            */
            StateManager & operator=(const StateManager&); // intentionally undefined

    }; // class StateManager
} // namespace CRE

#endif