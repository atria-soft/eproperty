/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.hpp>
#include <eproperty/Property.hpp>
#include <eproperty/debug.hpp>
#include <etk/typeInfo.hpp>

namespace eproperty {
	/**
	 * @brief Template base of the property (have a generic set and get for string)
	 */
	template<class TYPE> class PropertyType : public Property {
		protected:
			TYPE m_value; //!< Current value.
			TYPE m_default; //!< Default value.
		public:
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _owner Owner of the parameter (null if none).
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _description description of the parameter.
			 * @param[in] _setObs function of the class that opserve the change of the value
			 */
			template<class CLASS_TYPE>
			PropertyType(CLASS_TYPE* _owner,
			             const etk::String& _name,
			             const TYPE& _defaultValue,
			             const etk::String& _description = "",
			             void (CLASS_TYPE::*_setObs)()=null) :
			  Property(_owner, _name),
			  m_value(_defaultValue),
			  m_default(_defaultValue) {
				if (_setObs != null) {
					setObserver([=](){(*_owner.*_setObs)();});
				}
			}
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _defaultValue Default value of the parameter.
			 */
			PropertyType(const TYPE& _defaultValue) :
			  m_value(_defaultValue),
			  m_default(_defaultValue) {
				
			}
			/**
			 * @brief Remove copy contructor
			 */
			PropertyType(PropertyType& _obj) = delete;
			/**
			 * @brief Enable move contructor
			 */
			PropertyType(PropertyType&& _obj) {
				Property::internalSwap(&_obj);
				etk::swap(m_default, _obj.m_default);
				etk::swap(m_value, _obj.m_value);
			}
			/**
			 * @brief Destructor.
			 */
			virtual ~PropertyType() = default;
			/**
			 * @brief Remove copy operator
			 */
			PropertyType& operator=(PropertyType& _obj) = delete;
			/**
			 * @brief Enable move operator
			 */
			PropertyType& operator=(PropertyType&& _obj) {
				Property::internalSwap(&_obj);
				etk::swap(m_default, _obj.m_default);
				etk::swap(m_value, _obj.m_value);
				return *this;
			}
			etk::String getPropertyType() const override {
				return "eproperty::Value";
			}
			etk::String getType() const override {
				//return typeid(TYPE).name(); // With generic STL & RTTI ...
				return ETK_GET_TYPE_NAME(TYPE);
			}
			etk::String getString() const override {
				return getValueSpecific(m_value);
			}
			etk::String getDefault() const override {
				return getValueSpecific(m_default);
			}
			etk::String getInfo() const override {
				return getType() + " default=" + getDefault();
			}
			bool isDefault() const override {
				return m_value == m_default;
			}
			void setDefault() override {
				set(m_default);
			}
			/**
			 * @brief Set new default value on the property
			 * @param[in] _newDefault New value to set
			 */
			virtual void changeDefault(const TYPE& _newDefault) {
				m_default = _newDefault;
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
			 * @param[in] _newVal New value to set (set the nearest value if range is set)
			 */
			virtual void set(const TYPE& _newVal) {
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
			 * @param[in] _newVal New value to set 
			 */
			inline void setDirect(const TYPE& _newVal) {
				m_value = _newVal;
			}
			/**
			 * @brief Set the value of the current parameter (check range and ... if needed).
			 * @note Only use by the owner of the property/
			 * @param[in] _newVal New value to set
			 */
			virtual void setDirectCheck(const TYPE& _newVal) {
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
			/**
			 * @brief Get the string of the specify value.
			 * @param[in] _valueRequested Value to convert in string
			 * @return convertion of the value in string.
			 */
			virtual etk::String getValueSpecific(const TYPE& _valueRequested) const = 0;
		public:
			/**
			 * @brief Const cast the property in the Type of the data
			 * @return Const reference on the value.
			 */
			operator const TYPE&() const {
				return m_value;
			}
			/**
			 * @brief Get the property Value
			 * @return Const reference on the value.
			 */
			const TYPE& operator *() const noexcept {
				return m_value;
			}
			/**
			 * @brief Get the property Value
			 * @return Const reference on the value.
			 */
			const TYPE* operator->() const noexcept {
				return &m_value;
			}
			/**
			 * @brief Assignation opérator (REMOVED)
			 * @param _newVal Value to asign
			 * @return Reference on current object
			 */
			PropertyType<TYPE>& operator= (const TYPE& _newVal) = delete;
	};
	//! @not_in_doc
	template<typename TYPE> etk::Stream& operator <<(etk::Stream& _os, const eproperty::PropertyType<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}
