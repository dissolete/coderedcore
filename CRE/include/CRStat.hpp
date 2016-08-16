/**
* @file CRStat.hpp
* @author Gage Thomas
*/

#ifndef CRSTAT_HPP
#define CRSTAT_HPP

#include <string>
#include "CRTypes.hpp"

namespace CRE {

	/**
	* Base class to be inherited by the Stat class to allow data structures of Stats
	* of differrent types. DO NOT DECLARE OBJECTS OF THIS TYPE, ONLY POINTERS THAT
	* ARE REFERENCES TO STAT. eg. IStat *var = new Stat("mean", 5);
	*/

	class IStat{

	public:

		/**
		* Requires a virtual function, will be defined
		*/
		virtual ~IStat(){}

		/**
		* Implemented after Stat implementation
		* @return whatever value the Stat is currently holding by reference
		*/
		template<class T>
		const T& get_value() const;

		/**
		* Implemented after Stat implementation, sets the value stored by the Stat
		@param[in] newVal that will be stored in this Stat
		*/
		template<class T, class U>
		void set_value(U& newVal);

	};

	template<typename T>
	class Stat : public IStat{

		public:

			/**
			* Stat class constructor
			* @param[in] theID for this Stat
			* @param[in] theStat that this Stat will contain
			*/
			Stat(T& theStat) : _value(theStat){}

			/**
			* Stat deconstructor
			*/
			virtual ~Stat(){}

			/**
			* @return the statistic by reference that is contained in this Stat
			*/
			T& get_value(void) const{
				return _value;
			}

			/**
			* Sets the statistic stored in this Stat
			* @param[in] newStat to be saved in the current Stat. Must be same type as what
			* was originally stored
			*/
			void set_value(T& newStat){
				_value = newStat;
			}

		private:

			///The statistic that this Stat stores
			T& _value;
	};

	/**
	* Begin implementation of IStat functions
	* Uses dynamic_cast to cast this IStat as a Stat. These casts will return NULL if this
	* IStat is not also a Stat, which will cause an error if these functions are called
	* by something that is only an IStat. Once again, DO NOT DECLARE THINGS SOLELY AS ISTAT
	*/

	template<class T>
	const T& IStat::get_value() const{
		return dynamic_cast<const Stat<T>&>(*this).get_value();
	}

	template<class T, class U>
	void IStat::set_value(U& newVal){
		dynamic_cast<Stat<T>&>(*this).set_value(newVal);
	}
}

#endif