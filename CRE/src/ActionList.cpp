/**
* Defines the ActionList class used by Entities to organize
* Actions
* @file ActionList.cpp
* @author Gage Thomas
*/

#include "ActionList.hpp"

namespace CRE{

	/**
	* Doesn't really do anything.
	*/
	ActionList::ActionList(){

	}

	/**
	* Deallocates all memory, including action pointers contained within the list
	*/
	ActionList::~ActionList(){

		clear();
	}

	/**
	* Returns whether or not the list is empty as a bool
	*/
	bool ActionList::is_empty() const{

		return _theActions.empty();
	}

	/**
	* Does exactly what you think it does. Pushes the Action pointer onto the back of the list
	*/
	void ActionList::push_back(Action * theAction){

		_theActions.push_back(theAction);
	}

	/**
	* Does exactly what you think it does. Pushes the Action pointer onto the front of the list
	* making it the active Action
	*/
	void ActionList::push_front(Action * theAction){

		_theActions.push_front(theAction);
	}

	/**
	* Returns the active action by reference
	*/
	Action & ActionList::get_active() const{

		return *(_theActions.front());
	}

	/**
	* Checks if the active action is done. If it is done it is pushed to the back, reset is called
	* on the formerly active action.
	*/
	void ActionList::update(){

		Action *active = _theActions.front();

		if(active -> is_done()){

			active -> reset();
			_theActions.push_back(active);
			_theActions.erase(_theActions.begin());
		}

		active = NULL;
	}

	/**
	* Sets the action specified by the passed ID to the active state and calls reset on the formerly
	* active state. Returns true if this succeeded. Returns false if no Action had the ID.
	*/
	bool ActionList::set_active(std::string actionID){

		/**
		* Iterates through the list, tests each ID
		*/
		for(auto itr = _theActions.begin(); itr != _theActions.end(); ++itr){

			if((*itr) -> get_ID() == actionID){

				///Resets the current active state
				_theActions.front() -> reset();
				///Makes the passed action active by pushing it to the front
				_theActions.push_front(*itr);
				///Erases the former copy of that active action
				_theActions.erase(itr);
				return true;
			}
		}

		///Test must have failed at this point
		return false;
	}

	/**
	* Deallocates the action with the passed ID and removes it from the list. Returns true if it
	* succeeds, false if it fails to find an action with that ID
	*/
	bool ActionList::remove_action(std::string actionID){

		for(auto itr = _theActions.begin(); itr != _theActions.end(); ++itr){

			if((*itr) -> get_ID() == actionID){

				Action *deleteThis = *itr;

				///Removes the specified action from the list
				_theActions.erase(itr);
				///Deallocated the specified action.
				delete deleteThis;
				deleteThis = NULL;

				return true;
			}
		}

		///ID not found at this point
		return false;
	}

	/**
	* Deallocates all actions in the list and clears the list.
	*/

	void ActionList::clear(){

		Action *theAction = NULL;

		for(auto itr = _theActions.begin(); itr != _theActions.end(); ++itr){

			theAction = *itr;
			_theActions.erase(itr);
			delete theAction;
			theAction = NULL;
		}
	}
}