/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.hpp>
#include <etk/String.hpp>
#include <typeinfo>
#include <functional>

/**
 * @brief eproperty global interface for all property implementation
 */
namespace eproperty {
	class Ref;
	/**
	 * @brief Base of the property With all generic element needed
	 */
	class Property {
		public:
			using Observer = etk::Function<void()>; //!< Local main object observer of changing value of the property
		private:
			eproperty::Interface* m_interfaceLink; //!< Base interface class to group all the property
			Observer m_setObserver; //!< Observer of the changing value
			etk::String m_name; //!< Name of the property
		public:
			/**
			 * @brief Basic property elements
			 * @param[in] _paramInterfaceLink Link on the esignal::Interface class to register parameter (can be nullptr)
			 * @param[in] _name Name of the parameter (must be unique if _paramInterfaceLink is define)
			 */
			Property(eproperty::Interface* _paramInterfaceLink, const etk::String& _name);
			/**
			 * @brief Basic property elements
			 */
			Property();
			/**
			 * @brief Virtualize the destructor
			 * @internal
			 */
			virtual ~Property() = default;
		protected:
			/**
			 * @brief Set the change observer of the property
			 * @param[in] _setObs New observer of the property
			 */
			void setObserver(eproperty::Property::Observer _setObs);
		public:
			/**
			 * @brief call main class that PropertyChange
			 */
			void notifyChange() const;
			/**
			 * @brief Get the name of the Property.
			 * @return The name of the Property
			 */
			virtual etk::String getName() const;
			/**
			 * @brief Description of the Propertys.
			 * @return Descriptive information of the Property (for remote UI).
			 */
			virtual etk::String getInfo() const = 0;
			/**
			 * @brief Get the Property type of the class in string mode.
			 * @return The string type of the Property.
			 */
			virtual etk::String getPropertyType() const = 0;
			/**
			 * @brief Get the type of the Property in string mode.
			 * @return The string type of the Property.
			 */
			virtual etk::String getType() const = 0;
			/**
			 * @brief Get the string of the current value of the Property.
			 * @return The string description of the value.
			 */
			virtual etk::String getString() const = 0;
			/**
			 * @brief Get the string of the default value of the Property.
			 * @return the string decription of the default value.
			 */
			virtual etk::String getDefault() const = 0;
			/**
			 * @brief Set a new value of the Property (with string interface).
			 * @param[in] _newVal New value of the Propertys.
			 */
			virtual void setString(const etk::String& _newVal) = 0;
			/**
			 * @brief Check if the value is the default
			 * @return true : the vakue is the default one, false otherwise.
			 */
			virtual bool isDefault() const = 0;
			/**
			 * @brief Reset the value to the default value.
			 */
			virtual void setDefault() = 0;
			/**
			 * @brief Specific for eproperty::List to get all the possible values
			 * @return Descriptive information of the Property (for remote UI).
			 */
			virtual etk::Vector<etk::String> getListValue() const {
				return etk::Vector<etk::String>();
			}
		public:
			/**
			 * @brief Eguality comparaison operator (REMOVED)
			 * @param[in] _obj Object to compare
			 * @return true The current object is identic
			 * @return false The current object is NOT identic
			 */
			template<class TYPE>
			bool operator== (const TYPE& _obj) const = delete;
			/**
			 * @brief IN-Eguality comparaison operator (REMOVED)
			 * @param[in] _obj Object to compare
			 * @return true The current object is NOT identic
			 * @return false The current object is identic
			 */
			template<class TYPE>
			bool operator!= (const TYPE& _obj) const = delete;
			/**
			 * @brief Lesser eguality comparaison operator (REMOVED)
			 * @param[in] _obj Object to compare
			 * @return true The current object lesser or equal than input object
			 * @return false The current object greater than input object
			 */
			template<class TYPE>
			bool operator<= (const TYPE& _obj) const = delete;
			/**
			 * @brief Greater eguality comparaison operator (REMOVED)
			 * @param[in] _obj Object to compare
			 * @return true The current object greater or equal than input object
			 * @return false The current object lesser than input object
			 */
			template<class TYPE>
			bool operator>= (const TYPE& _obj) const = delete;
			/**
			 * @brief Lesser comparaison operator (REMOVED)
			 * @param[in] _obj Object to compare
			 * @return true The current object lesser than input object
			 * @return false The current object greater or equal than input object
			 */
			template<class TYPE>
			bool operator< (const TYPE& _obj) const = delete;
			/**
			 * @brief Greater comparaison operator (REMOVED)
			 * @param[in] _obj Object to compare
			 * @return true The current object greater than input object
			 * @return false The current object lesser or equal than input object
			 */
			template<class TYPE>
			bool operator> (const TYPE& _obj) const = delete;
	};
}

