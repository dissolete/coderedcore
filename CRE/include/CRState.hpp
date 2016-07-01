#ifndef CRSTATE_HPP
#define CRSTATE_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CRTypes.hpp"

namespace CRE
{
    class State
    {
        public:

            /**
            * State constructor.
            * @param[in] theStateID to use for this State object
            * @param[in] theApp is the address to the IApp derived class
            */
            State(const std::string stateID, App& theApp);

            /**
            * State deconstructor.
            */
            virtual ~State();

            /**
            * Returns the string identification for this state.
            * @return std::string The ID for this state
            */
            const std::string get_ID(void) const;

            /**
            * Init is responsible for initializing this State.  HandleCleanup will
            * be called if _cleanup is true so derived classes should always call
            * State::init() first before initializing their assets.
            */
            virtual void init(void);

            /**
            * ReInit is responsible for Reseting this state when the
            * StateManager::reset_active_state() function is called.  This way a Game
            * State can be restarted without unloading and reloading the game assets
            */
            virtual void reinit(void) = 0;

            /**
            * DeInit is responsible for marking this state to be cleaned up
            */
            void deinit(void);

            /**
            * is_init_complete will return true if the init function has been called
            * for this state.
            * @return true if init() has been called, false otherwise or if deinit()
            *         was called
            */
            bool is_init_complete(void);

            /**
            * is_paused will return true if this state is not the currently active
            * state.
            * @return true if state is not current active state, false otherwise
            */
            bool is_paused(void);

            /**
            * pause is responsible for pausing this State since the Application
            * may have lost focus or another State has become active.
            */
            virtual void pause(void);

            /**
            * resume is responsible for resuming this State since the Application
            * may have gained focus or the previous State was removed.
            */
            virtual void resume(void);

            /**
            * Handle events acted on by the SFML render window.
            */
            virtual void handle_events(sf::Event theEvent);

            /**
            * Allow the polymorphic state to update.
            */
            virtual void update(void) = 0;

            /**
            * update_variable is responsible for handling all State variable update
            * needs for this State when it is the active State.
            * @param[in] elapsedTime since the last draw() was called
            */
            virtual void update_variable(float elapsedTime) = 0;

            /**
            * Renders this state to the SFML renderwindow defined in the
            * app interface.
            */
            virtual void draw(void) = 0;

            /**
            * This state's default cleanup.
            */
            void cleanup(void);

            /**
            * Return the amount of time passed since this state was created.
            */
            float get_elapsed_time(void) const;

        protected:

            // The address to the App class
            App& _theApp;

            /**
            * Allow the polymorphic state to cleanup anything allocated.
            */
            virtual void handle_cleanup(void) = 0;

        private:
            
            // The state ID
            const std::string _stateID;

            // Total time since init() was called
            float _elapsedTime;

            // Total time paused since init() was called
            float _pausedTime;

            // Clock will keep track of running and paused elapsed
            sf::Clock _elapsedClock;

            // Clock will keep track of time paused
            sf::Clock _pausedClock;

            // Bool that indicates that init() has been called
            bool _initialized;

            // State is currently paused
            bool _paused;

            // State needs to be cleaned up
            bool _cleanup;

            /**
            * Copy constructor is private because we do not allow copies of this
            * class.
            */
            State(const State&); // intentionally undefined

            /**
            * Assignment operator is private because we do not allow copies of
            * this class.
            */
            State & operator=(const State&); // intentionally undefined

    }; // class State
} // namespace CRE

#endif