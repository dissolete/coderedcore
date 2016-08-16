/**
* @file CRStatManager.hpp
* @author Gage Thomas
*/

#ifndef CRSTATMANAGER_HPP
#define CRSTATMANAGER_HPP

#include "CRTypes.hpp"
#include "CRStat.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace CRE
{
	class StatManager{
	public:

		StatManager();

		virtual ~StatManager();

		void register_app(App * theApp);

		/**
		* @param[in] thisID to be used for the new statistic
		* @param[in] addThis Statistic to be stored in the StatManager
		*/
		template <typename T>
		void add_stat(std::string thisID, T& addThis);

		/**
		* @param[in] searchID to be used to find the requested statistic
		* @return the requested statistic as a pointer. Null if searchID is not found
		*/
		template <typename T>
		T* get_stat(std::string searchID);

		/**
		* Modifies the value of the querried stat. Requires that T matches the type of the Stat
		* querried and that searchID is an actually used ID
		* @param[in] searchID to be used to find the requested stat
		* @param[in] newVal to be saved to the Stat
		*/
		template <typename T>
		void set_stat(std::string searchID, T& newVal);

		/**
		* @param[in] removeID is the ID of the Stat to be removed
		*/
		void remove_stat(std::string removeID);

		/**
		* Clears and deallocates all Stats stored in the manager
		* @return true if there were Stats that were removed, false if already empty
		*/
		bool clear();



	private:

		App * _theApp;


		///Stores the keys for the unordered map so it can be iterated through while still maintaining
		///constant access time
		std::vector<std::string> _mapKeys;

		///Map used to hold the stats
		std::unordered_map<std::string, IStat *> _statMap;

		/**
	    * Copy constructor is private because we do not allow copies of this
	    * class.
	    */
	    StatManager(const StatManager&);

	    /**
	    * Overloaded assignment operator is private because we do not allow copies of StatManagers
	    * to be made
	    */

	    StatManager& operator=(const StatManager&);

	};
}

#endif