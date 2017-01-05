/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <eproperty/Range.hpp>


template<class TYPE>
eproperty::Range<TYPE>::Range(const TYPE& _defaultValue,
                              const TYPE& _min,
                              const TYPE& _max) :
  eproperty::Value<TYPE>(_defaultValue),
  m_min(_min),
  m_max(_max) {
	if (m_min > m_max) {
		//EPROPERTY_CRITICAL("min > max...");
	}
}

template<class TYPE>
std::string eproperty::Range<TYPE>::getPropertyType() const {
	return "eproperty::Range";
}

template<class TYPE>
void eproperty::Range<TYPE>::setString(const std::string& _newVal) {
	TYPE val;
	// when you want to set an element in parameter you will implement the function template std::from_string
	etk::from_string(val, _newVal);
	set(val);
}

template<class TYPE>
std::string eproperty::Range<TYPE>::getInfo() const {
	return eproperty::Value<TYPE>::getType() + " default=" + eproperty::Value<TYPE>::getDefault();
}

template<class TYPE>
void eproperty::Range<TYPE>::set(const TYPE& _newVal) {
	if (m_min == m_max) {
		if (_newVal != eproperty::Value<TYPE>::m_value) {
			eproperty::Value<TYPE>::m_value = _newVal;
			eproperty::Value<TYPE>::notifyChange();
		}
	} else {
		TYPE newVal = std::avg(m_min, _newVal, m_max);
		if (newVal != eproperty::Value<TYPE>::m_value) {
			eproperty::Value<TYPE>::m_value = newVal;
			eproperty::Value<TYPE>::notifyChange();
		}
	}
}

template<class TYPE>
void eproperty::Range<TYPE>::setDirectCheck(const TYPE& _newVal) {
	if (m_min == m_max) {
		if (_newVal != eproperty::Value<TYPE>::m_value) {
			eproperty::Value<TYPE>::m_value = _newVal;
		}
	} else {
		TYPE newVal = std::avg(m_min, _newVal, m_max);
		if (newVal != eproperty::Value<TYPE>::m_value) {
			eproperty::Value<TYPE>::m_value = newVal;
		}
	}
}



