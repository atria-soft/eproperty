/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */

#include <eproperty/debug.hpp>
#include <eproperty/List.hpp>
#include <eproperty/Property.hpp>
#include <eproperty/InterfaceData.hpp>

eproperty::InterfaceData::InterfaceData() {
	
}

eproperty::InterfaceData::~InterfaceData() {
	clean();
}

// note this pointer is not allocated and not free at the end of the class
void eproperty::InterfaceData::add(eproperty::Property* _pointerOnProperty) {
	if (_pointerOnProperty == null) {
		EPROPERTY_ERROR("Try to link a null properties");
		return;
	}
	for (auto &it : m_list) {
		if(    it != null
		    && it->getName() == _pointerOnProperty->getName()) {
			EPROPERTY_CRITICAL("2 property can not have the same name ... ==> generate runtime error");
		}
	}
	m_list.pushBack(_pointerOnProperty);
}

void eproperty::InterfaceData::remove(eproperty::Property* _pointerOnProperty) {
	if (_pointerOnProperty == null) {
		EPROPERTY_ERROR("Try to un-link a null properties");
		return;
	}
	auto it = m_list.begin();
	while (it != m_list.end()) {
		if(*it == _pointerOnProperty) {
			it = m_list.erase(it);
		} else {
			++it;
		}
	}
}
void eproperty::InterfaceData::clean() {
	// remove all pointer on these properties
	m_list.clear();
}

// Note no lock is needed at this level, because the lock is done is the upper elements ...
// the property set might be done with a pool of property, allone, the overhed is bigger ...
bool eproperty::InterfaceData::set(const etk::String& _property, const etk::String& _value) {
	for (auto &it : m_list) {
		if(    it != null
		    && it->getName() == _property) {
			it->setString(_value);
			return true;
		}
	}
	// can not find the properties :
	return false;
}

etk::String eproperty::InterfaceData::get(const etk::String& _property) const {
	for (auto &it : m_list) {
		if(    it != null
		    && it->getName() == _property) {
			return it->getString();
		}
	}
	return "???";
}

void eproperty::InterfaceData::display(bool _changeOnly) const {
	EPROPERTY_INFO("    Object properties:");
	for (auto &it : m_list) {
		if(it != null) {
			etk::String paramName = it->getName();
			etk::String paramVal = it->getString();
			etk::String paramInfo = it->getInfo();
			if (    _changeOnly == false
			     || it->isDefault() == false) {
				EPROPERTY_INFO("    |       param='" << paramName << "' value=" << paramVal << "     (" << paramInfo << ")");
			}
		} else {
			EPROPERTY_INFO("    |       param=null");
		}
	}
}

etk::Map<etk::String, etk::String> eproperty::InterfaceData::getAll(bool _notIfDefault) const {
	etk::Map<etk::String, etk::String> out;
	for (auto &it : m_list) {
		if(it != null) {
			etk::String paramName = it->getName();
			etk::String paramVal = it->getString();
			if (    _notIfDefault == false
			     || it->isDefault() == false) {
				out.set(paramName, paramVal);
			}
		}
	}
	return out;
}


size_t eproperty::InterfaceData::size() const {
	return m_list.size();
}

eproperty::Property* eproperty::InterfaceData::getRaw(const size_t& _id) const {
	if (_id >= m_list.size()) {
		EPROPERTY_ERROR("Wrong ID for property list. " << _id << " >= " << m_list.size());
		return null;
	}
	return m_list[_id];
}

eproperty::Property* eproperty::InterfaceData::getRaw(const etk::String _name) const {
	for (auto &it : m_list) {
		if(it->getName() == _name) {
			return it;
		}
	}
	return null;
}

