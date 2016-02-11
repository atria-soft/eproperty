/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.h>
#include <eproperty/Property.h>
#include <typeinfo>

namespace eproperty {
	template<typename MY_TYPE, bool isEventReceiving=false> class Range : public Property {
		private:
			MY_TYPE m_value; //!< Current value.
			MY_TYPE m_min; //!< Minimum value.
			MY_TYPE m_max; //!< Maximum value.
			MY_TYPE m_default; //!< Default value.
		public:
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _objectLink reference on the parameter lister.
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _min Minumum value.
			 * @param[in] _max Maximum value.
			 * @param[in] _description description of the parameter.
			 */
			Range(eproperty::Interface& _paramInterfaceLink,
			      const std::string& _name,
			      const MY_TYPE& _defaultValue,
			      const MY_TYPE& _min,
			      const MY_TYPE& _max,
			      const std::string& _description = "") :
			  Property(_paramInterfaceLink, _name),
			  m_value(_defaultValue),
			  m_min(_min),
			  m_max(_max),
			  m_default(_defaultValue) {
				
			};
			/**
			 * @brief Destructor.
			 */
			virtual ~Range() = default;
			// herited methode
			virtual std::string getPropertyType() const {
				return "eproperty::Range";
			}
			// herited methode
			virtual std::string getType() const {
				return typeid(MY_TYPE).name();
			}
			// herited methode
			virtual std::string getString() const {
				return getValueSpecific(m_value);
			};
			// herited methode
			virtual std::string getDefault() const {
				return getValueSpecific(m_default);
			};
			// herited methode
			virtual void setString(const std::string& _newVal) {
				MY_TYPE val;
				// when you want to set an element in parameter you will implement the function template std::from_string
				etk::from_string(val, _newVal);
				set(val);
			}
			// herited methode
			virtual std::string getInfo() const {
				return getType() + " default=" + getDefault();
			}
			// herited methode
			virtual bool isDefault() const {
				return m_value == m_default;
			}
			// herited methode
			virtual void setDefault() {
				set(m_default);
			}
		public:
			/**
			 * @brief Get the value of the current parameter.
			 * @note For performence, this function must be inline
			 * @return the Reference value
			 */
			inline MY_TYPE& get() {
				return m_value;
			};
			const inline MY_TYPE& get() const {
				return m_value;
			};
			/**
			 * @brief Set a new value for this parameter
			 * @param[in] newVal New value to set (set the nearest value if range is set)
			 */
			void set(const MY_TYPE& _newVal) {
				if (m_min == m_max) {
					if (_newVal != m_value) {
						m_value = _newVal;
						notifyChange();
					}
				} else {
					MY_TYPE newVal = std::avg(m_min, _newVal, m_max);
					if (newVal != m_value) {
						m_value = newVal;
						notifyChange();
					}
				}
			}
		private:
			/**
			 * @brief Get the string of the specify value.
			 * @return convetion of the velue in string.
			 */
			std::string getValueSpecific(const MY_TYPE& _valueRequested) const {
				return etk::to_string(_valueRequested);
			}
		public:
			/**
			 * @brief assignement operator.
			 * @param[in] newVal The new value of the parameter.
			 */
			const Range<MY_TYPE>& operator= (const MY_TYPE& _newVal) {
				set(_newVal);
				return *this;
			};
			operator const MY_TYPE&() const {
				return m_value;
			}
			MY_TYPE& operator *() const noexcept {
				return m_value;
			}
			const MY_TYPE* operator->() const noexcept {
				return &m_value;
			}
			MY_TYPE* operator->() noexcept {
				return &m_value;
			}
	};
	
	template<typename MY_TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::Range<MY_TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

