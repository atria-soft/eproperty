/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/PropertyType.h>


namespace eproperty {
	template<typename TYPE> class Value : public PropertyType<TYPE> {
		public:
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _owner Owner of the parameter.
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _description description of the parameter.
			 * @param[in] _setObs function of the class that opserve the change of the value
			 */
			template<class CLASS_TYPE>
			Value(CLASS_TYPE* _owner,
			      const std::string& _name,
			      const TYPE& _defaultValue,
			      const std::string& _description = "",
			      void (CLASS_TYPE::*_setObs)()=nullptr) :
			  eproperty::PropertyType<TYPE>(_owner, _name, _defaultValue, _description, _setObs) {
				
			}
		protected:
			/**
			 * @brief Get the string of the specify value.
			 * @return convetion of the velue in string.
			 */
			std::string getValueSpecific(const TYPE& _valueRequested) const override {
				return etk::to_string(_valueRequested);
			}
			void setString(const std::string& _newVal) override {
				// when you want to set an element in parameter you will implement the function template std::from_string
				etk::from_string(eproperty::PropertyType<TYPE>::m_value, _newVal);
				// TODO : Do it better ...
				eproperty::PropertyType<TYPE>::notifyChange();
			}
	};
	
	template<typename TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::Value<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

