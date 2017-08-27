/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */

#include <eproperty/debug.hpp>
#include <eproperty/Interface.hpp>
#include <eproperty/Property.hpp>


eproperty::Property::Property(eproperty::Interface* _paramInterfaceLink, const etk::String& _name) :
  m_interfaceLink(_paramInterfaceLink),
  m_setObserver(),
  m_name(_name) {
	// add a reference on the current Property ...
	if (m_interfaceLink != nullptr) {
		m_interfaceLink->properties.add(this);
	}
}

eproperty::Property::Property() :
  m_interfaceLink(nullptr),
  m_setObserver(),
  m_name("") {
	
}

void eproperty::Property::setObserver(eproperty::Property::Observer _setObs) {
	m_setObserver = _setObs;
}

etk::String eproperty::Property::getName() const {
	return m_name;
}

void eproperty::Property::notifyChange() const {
	if (m_setObserver != nullptr) {
		m_setObserver();
	}
	//m_interfaceLink.onPropertyChangeValue();
}

