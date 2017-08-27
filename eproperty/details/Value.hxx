/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <eproperty/Value.hpp>


template<class TYPE>
eproperty::Value<TYPE>::Value(const TYPE& _defaultValue) :
  eproperty::PropertyType<TYPE>(_defaultValue) {
	
}

template<class TYPE>
etk::String eproperty::Value<TYPE>::getValueSpecific(const TYPE& _valueRequested) const {
	return etk::toString(_valueRequested);
}

template<class TYPE>
void eproperty::Value<TYPE>::setString(const etk::String& _newVal) {
	// when you want to set an element in parameter you will implement the function template std::from_string
	etk::from_string(eproperty::PropertyType<TYPE>::m_value, _newVal);
	// TODO : Do it better ...
	eproperty::PropertyType<TYPE>::notifyChange();
}
