/**
* @file CRStatManager.cpp
* @author Gage Thomas
*/

#include <assert.h>
#include "CRStatManager.hpp"
#include "CRConstants.hpp"
#include "CRApp.hpp"

namespace CRE{

	StatManager::StatManager() : 
		_theApp(NULL), 
		_mapKeys(),
		_statMap()
	{

	}

	StatManager::~StatManager(){

		///Delete everything in memory
		clear();

		///remove app pointer
		_theApp = NULL;
	}

	void StatManager::register_app(App * theApp){

		// Check that our pointer is good
        assert(NULL != theApp and "StatManager::register_app() theApp pointer provided is bad");

        // Make a note of the pointer
        assert(NULL == _theApp and "StatManager::register_app() theApp pointer was already registered");

        _theApp = theApp;
	}

	template <typename T>
	void StatManager::add_stat(std::string thisID, T& addThis){

		IStat *newStat = new Stat<T>(addThis);
		_mapKeys.push_back(thisID);
		_statMap.insert(std::pair<std::string, IStat *>(thisID, newStat));
	}

	template <typename T>
	T* StatManager::get_stat(std::string searchID){

		return _statMap[searchID] -> get_value<T *>();
	}

	template <typename T>
	void StatManager::set_stat(std::string searchID, T& newVal){

		_statMap[searchID] -> set_value<T&>(newVal);
	}

	void StatManager::remove_stat(std::string removeID){

		IStat *toDelete = _statMap[removeID];///creates a new IStat * if removeID is not an existing ID

		///Remove searched stat from map
		_statMap.erase(removeID);

		///remove the key from _mapKeys
		for(auto it = _mapKeys.begin(); it != _mapKeys.end(); ++it){

			if(*it == removeID){
				_mapKeys.erase(it);
				break;///Assumes each key is unique and only has to be removed once
			}
		}

		///Delete actual Stat object
		delete toDelete;
		toDelete = NULL;
	}

	bool StatManager::clear(){

		if(_mapKeys.empty()){///If there are no Stats to clear
			return false;
		} else {

			IStat *deleteThis = NULL;
			///Iterate through keys, erasing each one from the map before deleting
			for(auto it = _mapKeys.begin(); it != _mapKeys.end(); ++it){

				///Get Stat to be deleted
				deleteThis = _statMap[*it];

				///Erase the current Stat from the map
				_statMap.erase(*it);

				///Delete stat
				delete deleteThis;
				deleteThis = NULL;

				///Remove from keys
				_mapKeys.erase(it);
			}
		}
	}
}