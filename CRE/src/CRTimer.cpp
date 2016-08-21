/**
* @file CRRimer.cpp
* @author Gage Thomas
*/

#include "CRTimer.hpp"

namespace CRE{

///Timer is paused at start, 0 elapsed time
	Timer::Timer() : _theClock(), _isPaused(true), _totElapsedTime(0)

	{}

///Nothing to deallocate
	Timer::~Timer(){}

	///Starts the timer if paused, returns false if already started
	bool Timer::start_timer(){

		///If the timer is already started
		if(!_isPaused){
			return false;
		} else {
			_isPaused = false;
			_theClock.restart();
			return true;
		}
	}

	///Pauses the timer if started, returns false if already paused
	bool Timer::pause_timer(){

		///If the timer is already paused...
		if(_isPaused){
			return false;
		} else {

			_isPaused = true;
			_totElapsedTime += _theClock.getElapsedTime().asMilliseconds();
			return true;
		}
	}

	///Returns whether or not the timer is paused
	bool Timer::timer_is_paused(){
		return _isPaused;
	}

	///Returns the current elapsed time in milliseconds
	uint32_t Timer::get_elapsed_time(){

		if(_isPaused){

			return _totElapsedTime;
		} else {

			return _totElapsedTime + _theClock.getElapsedTime().asMilliseconds();
		}
	}

///Sets the total elapsed time to 0, pauses the timer. Returns false if it is already cleared
	bool Timer::clear(){

		///If the timer is already cleared
		if(_totElapsedTime == 0 && _isPaused){
			return false;
		} else {
			_totElapsedTime = 0;
			_isPaused = true;
			return true;
		}
	}

	///Creates an empty timer manager
	TimerManager::TimerManager() : _timers()
	{}

	///Does nothing
	TimerManager::~TimerManager(){}

	///Adds a timer to the manager
	void TimerManager::add_timer(std::string timerID){

		_timers.insert(std::pair<std::string, Timer>(timerID, Timer()));
	}

	///Removes the passed timer if it exists
	void TimerManager::remove_timer(std::string timerID){

		auto thisTimer = _timers.find(timerID);

		///If the timer exists, erase it
		if(thisTimer != _timers.end()){
			_timers.erase(thisTimer);
		}
	}

	///starts the timer if it exists
	bool TimerManager::start_timer(std::string timerID){

		auto thisTimer = _timers.find(timerID);

		///If this timer doesn't exist, return false
		if(thisTimer == _timers.end()){
			return false;
		} else {
			///If the timer is not paused
			if(!(thisTimer -> second.timer_is_paused())){
				return false;
			} else {
				thisTimer -> second.start_timer();
				return true;
			}
		}
	}

	///pauses the timer if it exists
	bool TimerManager::pause_timer(std::string timerID){

		auto thisTimer = _timers.find(timerID);

		///If this timer doesn't exist, return false
		if(thisTimer == _timers.end()){
			return false;
		} else {

			///If the timer is already paused
			if(thisTimer -> second.timer_is_paused()){
				return false;
			} else {

				thisTimer -> second.pause_timer();
				return true;
			}
		}
	}

	///Returns the elapsed time for a timer. Will return 0 if timer does not exist
	uint32_t TimerManager::get_elapsed_time(std::string timerID){

		auto thisTimer = _timers.find(timerID);

		///If this timer doesn't exist, return 0
		if(thisTimer == _timers.end()){
			return 0;
		} else {

			return thisTimer -> second.get_elapsed_time();
		}
	}

	///Clears the passed timer
	bool TimerManager::clear_timer(std::string timerID){

		auto thisTimer = _timers.find(timerID);

		///If it doesn't exist, return false
		if(thisTimer == _timers.end()){
			return false;
		} else {
			return thisTimer -> second.clear();
		}
	}

	///Returns whether or not the timer exists
	bool TimerManager::timer_exists(std::string timerID){

		return _timers.find(timerID) == _timers.end();
	}
}