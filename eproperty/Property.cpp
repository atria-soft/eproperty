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


void eproperty::Property::linkInterface() {
	// add a reference on the current Property ...
	if (m_interfaceLink != null) {
		m_interfaceLink->properties.add(this);
	}
}

void eproperty::Property::unLinkInterface() {
	if (m_interfaceLink != null) {
		m_interfaceLink->properties.remove(this);
	}
}

eproperty::Property::Property(eproperty::Interface* _paramInterfaceLink, const etk::String& _name) :
  m_interfaceLink(_paramInterfaceLink),
  m_setObserver(),
  m_name(_name) {
	linkInterface();
}

void eproperty::Property::internalSwap(Property* _obj) {
	// unplug main class
	_obj->unLinkInterface();
	unLinkInterface();
	// change data
	etk::swap(m_interfaceLink, _obj->m_interfaceLink);
	etk::swap(m_setObserver, _obj->m_setObserver);
	etk::swap(m_name, _obj->m_name);
	// replug main class
	linkInterface();
	_obj->linkInterface();
}

eproperty::Property::Property() {
	
}

eproperty::Property::Property(Property&& _obj) {
	// unplug main class
	_obj.unLinkInterface();
	// change data
	etk::swap(m_interfaceLink, _obj.m_interfaceLink);
	etk::swap(m_setObserver, _obj.m_setObserver);
	etk::swap(m_name, _obj.m_name);
	// replug main class
	linkInterface();
}

eproperty::Property::~Property(){
	unLinkInterface();
}

eproperty::Property& eproperty::Property::operator=(Property&& _obj) {
	// unplug main class
	_obj.unLinkInterface();
	unLinkInterface();
	// change data
	etk::swap(m_interfaceLink, _obj.m_interfaceLink);
	etk::swap(m_setObserver, _obj.m_setObserver);
	etk::swap(m_name, _obj.m_name);
	// replug main class
	_obj.linkInterface();
	linkInterface();
	return *this;
}

void eproperty::Property::setObserver(eproperty::Property::Observer _setObs) {
	m_setObserver = _setObs;
}

etk::String eproperty::Property::getName() const {
	return m_name;
}

void eproperty::Property::notifyChange() const {
	if (m_setObserver != null) {
		m_setObserver();
	}
	//m_interfaceLink.onPropertyChangeValue();
}

