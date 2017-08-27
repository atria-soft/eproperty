/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/Vector.hpp>
#include <etk/Map.hpp>

namespace eproperty {
	class Property;
	class Ref;
	/**
	 * @brief Interface data to collect the property list (for abstarction connection)
	 */
	class InterfaceData {
		private:
			etk::Vector<eproperty::Property*> m_list; //!< list of availlable Propertys (no need to free)
		public:
			/**
			 * @brief Constructor.
			 */
			InterfaceData();
			/**
			 * @brief Destructor.
			 */
			virtual ~InterfaceData();
			/**
			 * @brief Register a property class pointer in the List of propertys
			 * @note This class does not destroy the property pointer!!!
			 * @param[in] _pointerOnProperty Pointer on the property that might be added.
			 */
			void add(Property* _pointerOnProperty);
			/**
			 * @brief Remove all the property reference in this class. 
			 * @note no delete, just clean and inform that a property has not been removed.
			 */
			void clean();
			/**
			 * @brief Set a specific value to the property reference name.
			 * @param[in] _property The property string name.
			 * @param[in] _value The new value of the property (string).
			 * @return true Property update.
			 * @return false Property not update.
			 */
			bool set(const etk::String& _property, const etk::String& _value);
			/**
			 * @brief Get a specific value of the property reference name.
			 * @param[in] _property The property string name.
			 * @return The value of the property (string).
			 */
			etk::String get(const etk::String& _property) const;
			/**
			 * @brief Display all the property value with there name.
			 * @param[in] _changeOnly check at true if the user want to display only property that are not at default value.
			 */
			void display(bool _changeOnly = false) const;
			/**
			 * @brief Get All the property configuration:
			 * @param[in] _notIfDefault if true the parameter value with default value are not extracted.
			 * @return map on the propertys
			 */
			etk::Map<etk::String, etk::String> getAll(bool _notIfDefault=true) const;
		public:
			/**
			 * @brief Get count of propertys.
			 * @return The number of the property.
			 */
			size_t size() const;
			/**
			 * @brief Get name of a propertys.
			 * @param[in] _id Id of the property.
			 * @return pointer on the property.
			 */
			eproperty::Property* getRaw(const size_t& _id) const;
			/**
			 * @brief Get name of a propertys.
			 * @param[in] _name name of the property.
			 * @return pointer on the property.
			 */
			eproperty::Property* getRaw(const etk::String _name) const;
	};
}

