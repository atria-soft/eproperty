/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/debug.h>
#include <eproperty/Interface.h>
#include <eproperty/Property.h>
#include <map>
#include <typeinfo>

namespace eproperty {
	template<typename TYPE> class List : public Property {
		private:
			TYPE m_value; //!< Element value ==> can be directly used.
			TYPE m_default; //!< Default value.
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
			  Property(_owner, _name),
			  m_value(_defaultValue),
			  m_default(_defaultValue) {
				if (_setObs != nullptr) {
					setObserver([=](){(*_owner.*_setObs)();});
				}
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
			// herited methode
			virtual std::string getPropertyType() const {
				return "eproperty::List";
			}
			// herited methode
			virtual std::string getType() const {
				return typeid(TYPE).name();
			}
			// herited methode
			virtual std::string getString() const {
				return getElement(m_value);
			}
			// herited methode
			virtual std::string getDefault() const {
				return getElement(m_default);
			}
			// herited methode
			virtual void setString(const std::string& _newVal) {
				auto it = m_list.find(_newVal);
				if (it != m_list.end()) {
					if (it->second != m_value) {
						m_value = it->second;
						notifyChange();
					}
					return;
				}
				EPROPERTY_WARNING("paramList value='" << _newVal << "' is not un the list ... ==> no change");
				for (auto &it : m_list) {
					EPROPERTY_VERBOSE("        element : " << it.first);
				}
			}
			// herited methode
			virtual std::string getInfo() const {
				std::string list = "List default=" + getElement(m_default) + " in : [";
				for (auto &it : m_list) {
					list += it.first + "/";
				}
				return list + "]";
			}
			// herited methode
			virtual bool isDefault() const {
				return m_value == m_default;
			}
			// herited methode
			virtual void setDefault() {
				set(m_default);
			}
			void setDefaultValue(const TYPE& _value) {
				m_default = _value;
			}
			/**
			 * @brief Get the value of the current parameter.
			 * @return the Reference value
			 */
			const inline TYPE& get() const {
				return m_value;
			};
			/**
			 * @brief Set the value of the current parameter.
			 * @param[in] _newVal New value of the parameter. (not set if out of range)
			 */
			void set(TYPE _newVal) {
				if (_newVal == m_value) {
					return;
				}
				for (auto &it : m_list) {
					if (it.second == _newVal) {
						m_value = it.second;
						notifyChange();
						return;
					}
				}
				EPROPERTY_WARNING("paramList value=??? is not un the list ... ==> no change");
			}
			/**
			 * @brief Set the value of the current parameter (no check (for internal set with no check).
			 * @note For performence, this function must be inline
			 * @note Only use by the owner of the property (can not be check on compile time for now ...)
			 * TODO: Do it better ... compile check
			 * @param[in] newVal New value to set 
			 */
			inline void setDirect(const TYPE& _newVal) {
				m_value = _newVal;
			};
			/**
			 * @brief Get the value of the current parameter (no check (for internal set with no check).
			 * @note For performence, this function must be inline
			 * @note Only use by the owner of the property (can not be check on compile time for now ...)
			 * TODO: Do it better ... compile check
			 * @return a reference on the value
			 */
			TYPE& getDirect() {
				return m_value;
			}
		private:
			/**
			 * @brief Get the element description from real Value.
			 * @param[in] _intValue value that might be converted in string.
			 * @return the description string coresponding to this ID.
			 */
			std::string getElement(TYPE _intValue) const {
				for (auto &it : m_list) {
					if (it.second == _intValue) {
						return it.first;
					}
				}
				return "???";
			}
		public:
			const List<TYPE>& operator= (const TYPE& _newVal) = delete;
			operator const TYPE&() const {
				return m_value;
			}
			const TYPE& operator *() const noexcept {
				return m_value;
			}
			const TYPE* operator->() const noexcept {
				return &m_value;
			}
	};
	template<typename TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::List<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

