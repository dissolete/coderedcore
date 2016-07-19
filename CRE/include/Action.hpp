/**
* Defines the action class used by Entities.
* @file Action.hpp
* @author Jake Shepherd
*/

#ifndef ACTION_HPP
#define ACTION_HPP

#include <string>
#include <SFML/Window.hpp>
#include "CRTypes.hpp"

namespace CRE
{
    class Action
    {
        public:

            /**
            * Default constructor for this Action class
            */
            Action(std::string actionID, float durationInSeconds = 1, bool useProgress = false);

            /**
            * Deconstructor
            */
            virtual ~Action();

            /**
            * Sets the duration of the action. This is how long it takes for the
            * progress to go from 0 to 1.
            */
            void set_duration(float durationInSeconds);

            /**
            * Returns the duration in seconds the action will last.
            */
            float get_duration() const;

            /**
            * Returns the current progress for the action.
            */
            float get_progress() const;

            /**
            * Returns the string ID for this action
            */
            const std::string get_ID() const;

            /**
            * Returns true if progress is >= 1 AND if bool use_progress is true.
            */
            bool is_done() const;

            /**
            * Base function resets progress to 0.
            */
            virtual void reset();

            /**
            * Performs the action on the entity. Base function only calculates
            * progress based on the time elapsed.
            * @param[in] timeElapsed - the time since the last window update
            */
            virtual void do_action(Entity * theEntity, float timeElapsed);

            /**
            * Handle any event handling this action may need to perform
            * @param[in] the event to be processed
            */
            virtual void process_events(sf::Event theEvent) = 0;

        private:

            /// The string ID for this action
            const std::string _actionID;

            /// The current progress for the action
            float _progress;

            /// The duration of the action
            float _duration;

            /// When this is true, progress is updated
            bool _use_progress;

    };
}

#endif