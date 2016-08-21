/**
* @file CRSTimer.hpp
* @author Gage Thomas
*/

#ifndef CRTIMER_HPP
#define CRTIMER_HPP

#include <SFML/System/Clock.hpp>
#include <unordered_map>
#include <string>

namespace CRE{

	class Timer{

	public:

		/**
		* Creates the Timer object. Timer is "paused" upon creation, though the Clock technically isn't
		*/
		Timer();

		~Timer();

		/**
		* Starts the timer if it is not already started
		* @return false if the timer was already started, true otherwise
		*/
		bool start_timer();

		/**
		* Pauses the timer if it is not already paused
		* @return false if the timer was already paused, true otherwise
		*/
		bool pause_timer();

		/**
		* returns whether or not the timer is paused
		*/
		bool timer_is_paused();

		/**
		* @return the current elapsed time (in milliseconds) as an unsigned integer
		*/
		uint32_t get_elapsed_time();

		/**
		* Clears the timer and pauses it.
		* @return false if the timer is already cleared, true otherwise
		*/
		bool clear();


	private:

		///Keeps track of the current elapsed time since the clock was last paused
		sf::Clock _theClock;

		///Stores whether or not the timer is currently paused
		bool _isPaused;

		///Keeps track of the time (in milliseconds) stored by the timer from before the last pause
		uint32_t _totElapsedTime;
	};

	/**
	* Stores a map of different timer objects. It is able to pause, start, and reset all timers
	*/

	class TimerManager{

	public:

		TimerManager();

		~TimerManager();

		/**
		* Adds a timer to the manager. Timers are paused when they are created
		* @param[in] timerID a string representing the name of the newly created timer
		*/
		void add_timer(std::string timerID);

		/**
		* removes the timer matching that ID from the manager.
		* @param[in] a string ID for the timer that you wish to remove
		*/
		void remove_timer(std::string timerID);

		/**
		* Starts the passed timer if it exists
		* @param[in] a string ID for the timer that should be started
		* @return false if the timer is already started or doesn't exist, true otherwise
		*/
		bool start_timer(std::string timerID);

		/**
		* Pauses the passed timer if it exists
		* @param[in] a string ID for the timemr that should be paused
		* @return false if already paused or doesn't exist, true otherwise
		*/
		bool pause_timer(std::string timerID);

		/**
		* @return the current elapsed time of the timer as a 32 bit int, 0 if it doesn't exist
		* @param[in] the string ID for the desired timer
		*/
		uint32_t get_elapsed_time(std::string timerID);

		/**
		* Clears the passed timer if it exists
		* @param[in] the timerID to be cleared
		* @return false if already cleared or time doesn't exist, true otherwise
		*/
		bool clear_timer(std::string timerID);

		/**
		* Checks if the given ID corresponds to a timer
		*/
		bool timer_exists(std::string timerID);


	private:

		///Stores each of the timers
		std::unordered_map<std::string, Timer> _timers;
	};
}

#endif