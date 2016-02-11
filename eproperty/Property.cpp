/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */

#include <eproperty/debug.h>
#include <eproperty/Interface.h>
#include <eproperty/Property.h>


eproperty::Property::Property(eproperty::Interface& _paramInterfaceLink, const std::string& _name) :
  m_interfaceLink(_paramInterfaceLink),
  m_name(_name) {
	// add a reference on the current Property ...
	m_interfaceLink.propertyAdd(this);
}

void eproperty::Property::notifyChange() const {
	m_interfaceLink.onPropertyChangeValue(eproperty::Ref(this));
}

bool eproperty::operator==(const eproperty::Ref& _obj, const eproperty::Property& _obj2) noexcept {
	return &_obj2 == _obj.m_ref;
}

bool eproperty::operator==(const eproperty::Property& _obj2, const eproperty::Ref& _obj) noexcept {
	return &_obj2 == _obj.m_ref;
}

