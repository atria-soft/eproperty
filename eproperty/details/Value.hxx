/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/Value.h>

#undef __class__
#define __class__ "Value<T>"

template<class TYPE>
std::string eproperty::Value<TYPE>::getValueSpecific(const TYPE& _valueRequested) const {
	return etk::to_string(_valueRequested);
}

template<class TYPE>
void eproperty::Value<TYPE>::setString(const std::string& _newVal) {
	// when you want to set an element in parameter you will implement the function template std::from_string
	etk::from_string(eproperty::PropertyType<TYPE>::m_value, _newVal);
	// TODO : Do it better ...
	eproperty::PropertyType<TYPE>::notifyChange();
}


#undef __class__
#define __class__ nullptr

