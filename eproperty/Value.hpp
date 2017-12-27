/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <eproperty/PropertyType.hpp>
#include <etk/types.hpp>
#include <etk/math/Vector2D.hpp>
#include <etk/math/Vector3D.hpp>
#include <etk/Color.hpp>

namespace eproperty {
	/**
	 * @brief Simple Value of the property (need to implement fuction etk::from_string<TYPE> to use it)
	 */
	template<class TYPE> class Value : public PropertyType<TYPE> {
		public:
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _owner Owner of the parameter (nullptr if none).
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _description description of the parameter.
			 * @param[in] _setObs function of the class that opserve the change of the value
			 */
			template<class CLASS_TYPE>
			Value(CLASS_TYPE* _owner,
			      const etk::String& _name,
			      const TYPE& _defaultValue,
			      const etk::String& _description = "",
			      void (CLASS_TYPE::*_setObs)()=nullptr) :
			  eproperty::PropertyType<TYPE>(_owner, _name, _defaultValue, _description, _setObs) {
				
			}
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _defaultValue Default value of the parameter.
			 */
			Value(const TYPE& _defaultValue);
			/**
			 * @brief Remove copy contructor
			 */
			Value(Value& _obj) = delete;
			/**
			 * @brief Enable move contructor
			 */
			Value(Value&& _obj) :
			  PropertyType<TYPE>::PropertyType(_obj.m_default) {
				Property::internalSwap(&_obj);
				etk::swap(PropertyType<TYPE>::m_default, _obj.m_default);
				etk::swap(PropertyType<TYPE>::m_value, _obj.m_value);
			};
			/**
			 * @brief default destructor
			 */
			virtual ~Value() = default;
			/**
			 * @brief Remove copy operator
			 */
			Value& operator=(Value& _obj) = delete;
			/**
			 * @brief Enable move operator
			 */
			Value& operator=(Value&& _obj) {
				Property::internalSwap(&_obj);
				etk::swap(PropertyType<TYPE>::m_default, _obj.m_default);
				etk::swap(PropertyType<TYPE>::m_value, _obj.m_value);
				return *this;
			};
		public:
			etk::String getValueSpecific(const TYPE& _valueRequested) const override;
			void setString(const etk::String& _newVal) override;
	};
	//! @not_in_doc
	template<typename TYPE> etk::Stream& operator <<(etk::Stream& _os, const eproperty::Value<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

