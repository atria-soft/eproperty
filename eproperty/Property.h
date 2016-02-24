/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.h>
#include <string>
#include <typeinfo>

namespace eproperty {
	class Ref;
	class Property {
		private:
			eproperty::Interface& m_interfaceLink;
			std::string m_name;
		public:
			Property(eproperty::Interface& _paramInterfaceLink, const std::string& _name);
			virtual ~Property() = default;
			/**
			 * @brief call main class that PropertyChange
			 */
			void notifyChange() const;
			/**
			 * @brief Get the name of the Property.
			 * @return The name of the Property
			 */
			virtual std::string getName() const {
				return m_name;
			};
			/**
			 * @brief Description of the Propertys.
			 * @return Descriptive information of the Property (for remote UI).
			 */
			virtual std::string getInfo() const = 0;
			/**
			 * @brief Get the Property type of the class in string mode.
			 * @return The string type of the Property.
			 */
			virtual std::string getPropertyType() const = 0;
			/**
			 * @brief Get the type of the Property in string mode.
			 * @return The string type of the Property.
			 */
			virtual std::string getType() const = 0;
			/**
			 * @brief Get the string of the current value of the Property.
			 * @return The string description of the value.
			 */
			virtual std::string getString() const = 0;
			/**
			 * @brief Get the string of the default value of the Property.
			 * @return the string decription of the default value.
			 */
			virtual std::string getDefault() const = 0;
			/**
			 * @brief Set a new value of the Property (with string interface).
			 * @param[in] _newVal New value of the Propertys.
			 */
			virtual void setString(const std::string& _newVal) = 0;
			/**
			 * @brief Check if the value is the default
			 * @return true : the vakue is the default one, false otherwise.
			 */
			virtual bool isDefault() const = 0;
			/**
			 * @brief Reset the value to the default value.
			 */
			virtual void setDefault() = 0;
		public:
			template<class TYPE>
			bool operator== (const TYPE& _obj) const = delete;
			template<class TYPE>
			bool operator!= (const TYPE& _obj) const = delete;
			template<class TYPE>
			bool operator<= (const TYPE& _obj) const = delete;
			template<class TYPE>
			bool operator>= (const TYPE& _obj) const = delete;
			template<class TYPE>
			bool operator< (const TYPE& _obj) const = delete;
			template<class TYPE>
			bool operator> (const TYPE& _obj) const = delete;
	};
	class Ref {
		public:
			const Property* m_ref;
			Ref(const Property* _ref) :
			  m_ref(_ref) {
				// nothing to do ...
			}
	};
	bool operator==(const Ref& _obj, const Property& _obj2) noexcept;
	bool operator==(const Property& _obj2, const Ref& _obj) noexcept;
}

