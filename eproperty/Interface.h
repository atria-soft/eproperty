/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <vector>
#include <map>

namespace eproperty {
	class Property;
	class Ref;
	class Interface {
		friend class eproperty::Property; // to register property in the list.
		private:
			std::vector<eproperty::Property*> m_list; //!< list of availlable Propertys (no need to free)
		public:
			/**
			 * @brief Constructor.
			 */
			Interface();
			/**
			 * @brief Destructor.
			 */
			virtual ~Interface();
			/**
			 * @brief Register a property class pointer in the List of propertys
			 * @note This class does not destroy the property pointer!!!
			 * @param[in] pointerOnProperty Pointer on the property that might be added.
			 */
			void propertyAdd(Property* _pointerOnProperty);
			/**
			 * @brief Remove all the property reference in this class. 
			 * @note no delete, just clean and inform that a property has not been removed.
			 */
			void propertyClean();
			/**
			 * @brief Set a specific value to the property reference name.
			 * @param[in] property The property string name.
			 * @param[in] value The new value of the property (string).
			 * @return true Property update.
			 * @return false Property not update.
			 */
			bool propertySet(const std::string& _property, const std::string& _value);
			/**
			 * @brief Get a specific value of the property reference name.
			 * @param[in] property The property string name.
			 * @return The value of the property (string).
			 */
			std::string propertyGet(const std::string& _property) const;
			/**
			 * @brief Display all the property value with there name.
			 * @param[in] changeOnly check at true if the user want to display only property that are not at default value.
			 */
			void propertyDisplay(bool _changeOnly = false) const;
			/**
			 * @brief Get All the property configuration:
			 * @return map on the propertys
			 */
			std::map<std::string, std::string> propertyGetAll(bool _notIfDefault=true) const;
		public:
			/**
			 * @brief Get count of propertys.
			 * @return The number of the property.
			 */
			size_t getPropertyCount() const;
			/**
			 * @brief Get name of a propertys.
			 * @param[in] _id Id of the property.
			 * @param[in] _name name of the property.
			 * @return pointer on the property.
			 */
			eproperty::Property* getPropertyRaw(const size_t& _id) const;
			//! @previous
			eproperty::Property* getPropertyRaw(const std::string _name) const;
	};
}

