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


namespace eproperty {
	template<typename TYPE> class Value : public Property {
		private:
			TYPE m_value; //!< Current value.
			TYPE m_default; //!< Default value.
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
			Value(eproperty::Interface& _paramInterfaceLink,
			      const std::string& _name,
			      const TYPE& _defaultValue,
			      const std::string& _description = "") :
			  Property(_paramInterfaceLink, _name),
			  m_value(_defaultValue),
			  m_default(_defaultValue) {
				
			}
			Value(eproperty::Interface& _paramListLink,
			      const std::string& _name,
			      const std::string& _description = "") :
			  Property(_paramListLink, _name),
			  m_value(),
			  m_default() {
				
			}
			/**
			 * @brief Destructor.
			 */
			virtual ~Value() = default;
			// herited methode
			virtual std::string getPropertyType() const {
				return "eproperty::Value";
			}
			// herited methode
			virtual std::string getType() const {
				return typeid(TYPE).name();
			}
			// herited methode
			virtual std::string getString() const {
				return getValueSpecific(m_value);
			}
			// herited methode
			virtual std::string getDefault() const {
				return getValueSpecific(m_default);
			}
			// herited methode
			virtual void setString(const std::string& _newVal) {
				// when you want to set an element in parameter you will implement the function template std::from_string
				etk::from_string(m_value, _newVal);
				// TODO : Do it better ...
				notifyChange();
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
			const inline TYPE& get() const {
				return m_value;
			};
			/**
			 * @brief Set a new value for this parameter
			 * @param[in] newVal New value to set (set the nearest value if range is set)
			 */
			void set(const TYPE& _newVal) {
				if (_newVal != m_value) {
					m_value = _newVal;
					notifyChange();
				}
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
			}
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
			 * @brief Get the string of the specify value.
			 * @return convetion of the velue in string.
			 */
			std::string getValueSpecific(const TYPE& _valueRequested) const {
				return etk::to_string(_valueRequested);
			}
		public:
			operator const TYPE&() const {
				return m_value;
			}
			const TYPE& operator *() const noexcept {
				return m_value;
			}
			const TYPE* operator->() const noexcept {
				return &m_value;
			}
			const Value<TYPE>& operator= (const TYPE& _newVal) = delete;
	};
	
	template<typename TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::Value<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

