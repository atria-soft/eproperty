/** @file
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
	/**
	 * @brief Set a list of value availlable (for enumeration)
	 */
	template<class TYPE> class List : public PropertyType<TYPE> {
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
			 * @brief virtualisation of Destructor.
			 */
			virtual ~List() = default;
			/**
			 * @brief Add a value in the list of parameter
			 * @param[in] _value Value of the string
			 * @param[in] _name String of the value
			 * @param[in] _description Description of the parameter value
			 */
			void add(const TYPE& _value, const std::string& _name, const std::string& _description = "") {
				auto it = m_list.find(_name);
				if (it != m_list.end()) {
					it->second = _value;
					return;
				}
				m_list.insert(std::make_pair(_name, _value));
			}
			/**
			 * @brief Remove a value of the element availlable
			 * @param[in] _name Name of the value to remove
			 */
			void remove(const std::string& _name) {
				auto it = m_list.find(_name);
				bool firstValue = false;
				bool firstDefault = false;
				if (it != m_list.end()) {
					if (it->second == eproperty::PropertyType<TYPE>::m_value) {
						EPROPERTY_ERROR("property value='" << it->first << "' has been removed and this value was set ... change it before removing value to remove this error");
						firstValue = true;
					}
					if (it->second == eproperty::PropertyType<TYPE>::m_default) {
						EPROPERTY_ERROR("property default='" << it->first << "' has been removed and this value was set ... change it before removing value to remove this error");
						firstDefault = true;
					}
					m_list.erase(it);
					return;
				}
				if (m_list.size() == 0) {
					EPROPERTY_INFO("property All value removed ==> can not change default and value");
					return;
				}
				if (firstDefault == true) {
					eproperty::PropertyType<TYPE>::m_default = m_list.begin()->second;
				}
				if (firstValue == true) {
					eproperty::PropertyType<TYPE>::m_value = m_list.begin()->second;
				}
			}
			/**
			 * @brief Rename a value of the property
			 * @param[in] _nameOld Old property name to replace
			 * @param[in] _nameNew New name of the property
			 */
			void rename(const std::string& _nameOld, const std::string& _nameNew) {
				//get old value
				TYPE value;
				auto it = m_list.find(_nameOld);
				if (it != m_list.end()) {
					value = it->second;
				} else {
					EPROPERTY_ERROR("paramList rename can not be done '" << _nameOld << "' in '" << _nameNew << "' parameter name does not exist");
					return;
				}
				remove(_nameOld);
				add(value, _nameNew);
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
				#ifdef DEBUG
					for (auto &it : m_list) {
						EPROPERTY_VERBOSE("        element : " << it.first);
					}
				#endif
			}
			std::string getInfo() const override {
				std::string list = "List default=" + getValueSpecific(eproperty::PropertyType<TYPE>::m_default) + " in : [";
				for (auto &it : m_list) {
					list += it.first + "/";
				}
				return list + "]";
			}
			std::vector<std::string> getListValue() const override {
				std::vector<std::string> out;
				for (auto &it : m_list) {
					out.push_back(it.first);
				}
				return out;
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
			void setDirectCheck(const TYPE& _newVal) override {
				if (_newVal == eproperty::PropertyType<TYPE>::m_value) {
					return;
				}
				for (auto &it : m_list) {
					if (it.second == _newVal) {
						eproperty::PropertyType<TYPE>::m_value = it.second;
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
	//! @not_in_doc
	template<typename TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::List<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

