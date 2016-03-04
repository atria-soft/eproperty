/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/PropertyType.h>
#include <map>
#include <typeinfo>

namespace eproperty {
	template<typename TYPE> class List : public PropertyType<TYPE> {
		private:
			std::map<std::string, TYPE> m_list; //!< pointer on the list of all elements.
		public:
			/**
			 * @brief Create a parameter with List of element parameter.
			 * @param[in] _owner reference on the parameter lister.
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _description description of the parameter.
			 * @param[in] _setObs function of the class that opserve the change of the value
			 */
			template<class CLASS_TYPE>
			List(CLASS_TYPE* _owner,
			     const std::string& _name,
			     const TYPE& _defaultValue,
			     const std::string& _description="",
			     void (CLASS_TYPE::*_setObs)()=nullptr) :
			  eproperty::PropertyType<TYPE>(_owner, _name, _defaultValue, _description, _setObs) {
				
			};
			/**
			 * @brief Destructor.
			 */
			virtual ~List() = default;
			void add(const TYPE& _value, const std::string& _name, const std::string& _description = "") {
				auto it = m_list.find(_name);
				if (it != m_list.end()) {
					it->second = _value;
					return;
				}
				m_list.insert(std::make_pair(_name, _value));
			}
			std::string getPropertyType() const override {
				return "eproperty::List";
			}
			void setString(const std::string& _newVal) override {
				auto it = m_list.find(_newVal);
				if (it != m_list.end()) {
					if (it->second != eproperty::PropertyType<TYPE>::m_value) {
						eproperty::PropertyType<TYPE>::m_value = it->second;
						eproperty::PropertyType<TYPE>::notifyChange();
					}
					return;
				}
				EPROPERTY_WARNING("paramList value='" << _newVal << "' is not un the list ... ==> no change");
				for (auto &it : m_list) {
					EPROPERTY_VERBOSE("        element : " << it.first);
				}
			}
			std::string getInfo() const override {
				std::string list = "List default=" + getValueSpecific(eproperty::PropertyType<TYPE>::m_default) + " in : [";
				for (auto &it : m_list) {
					list += it.first + "/";
				}
				return list + "]";
			}
			/**
			 * @brief Set the value of the current parameter.
			 * @param[in] _newVal New value of the parameter. (not set if out of range)
			 */
			void set(const TYPE& _newVal) override {
				if (_newVal == eproperty::PropertyType<TYPE>::m_value) {
					return;
				}
				for (auto &it : m_list) {
					if (it.second == _newVal) {
						eproperty::PropertyType<TYPE>::m_value = it.second;
						eproperty::PropertyType<TYPE>::notifyChange();
						return;
					}
				}
				EPROPERTY_WARNING("paramList value=??? is not un the list ... ==> no change");
			}
		private:
			/**
			 * @brief Get the element description from real Value.
			 * @param[in] _intValue value that might be converted in string.
			 * @return the description string coresponding to this ID.
			 */
			std::string getValueSpecific(const TYPE& _valueRequested) const override {
				for (auto &it : m_list) {
					if (it.second == _valueRequested) {
						return it.first;
					}
				}
				return "???";
			}
	};
	template<typename TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::List<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

