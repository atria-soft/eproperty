/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */

#include <eproperty/debug.h>
#include <eproperty/List.h>
#include <eproperty/Property.h>

eproperty::Interface::Interface() {
	
}

eproperty::Interface::~Interface() {
	propertyClean();
}

// note this pointer is not allocated and not free at the end of the class
void eproperty::Interface::propertyAdd(eproperty::Property* _pointerOnProperty) {
	if (_pointerOnProperty == nullptr) {
		EPROPERTY_ERROR("Try to link a nullptr properties");
		return;
	}
	for (auto &it : m_list) {
		if(    it != nullptr
		    && it->getName() == _pointerOnProperty->getName()) {
			EPROPERTY_CRITICAL("2 property can not have the same name ... ==> generate runtime error");
		}
	}
	m_list.push_back(_pointerOnProperty);
}

void eproperty::Interface::propertyClean() {
	// remove all pointer on these propertys
	m_list.clear();
}

// Note no lock is needed at this level, because the lock is done is the upper elements ...
// the property set might be done with a pool of property, allone, the overhed is bigger ...
bool eproperty::Interface::propertySet(const std::string& _property, const std::string& _value) {
	for (auto &it : m_list) {
		if(    it != nullptr
		    && it->getName() == _property) {
			it->setString(_value);
			return true;
		}
	}
	// can not find the propertys :
	return false;
}

std::string eproperty::Interface::propertyGet(const std::string& _property) const {
	for (auto &it : m_list) {
		if(    it != nullptr
		    && it->getName() == _property) {
			return it->getString();
		}
	}
	return "???";
}

void eproperty::Interface::propertyDisplay(bool _changeOnly) const {
	EPROPERTY_INFO("    Object propertys:");
	for (auto &it : m_list) {
		if(it != nullptr) {
			std::string paramName = it->getName();
			std::string paramVal = it->getString();
			std::string paramInfo = it->getInfo();
			if (    _changeOnly == false
			     || it->isDefault() == false) {
				EPROPERTY_INFO("    |       param='" << paramName << "' value=" << paramVal << "     (" << paramInfo << ")");
			}
		} else {
			EPROPERTY_INFO("    |       param=nullptr");
		}
	}
}

std::map<std::string, std::string> eproperty::Interface::propertyGetAll(bool _notIfDefault) const {
	std::map<std::string, std::string> out;
	for (auto &it : m_list) {
		if(it != nullptr) {
			std::string paramName = it->getName();
			std::string paramVal = it->getString();
			if (    _notIfDefault == false
			     || it->isDefault() == false) {
				out.insert(std::make_pair(paramName, paramVal));
			}
		}
	}
	return out;
}


size_t eproperty::Interface::getPropertyCount() const {
	return m_list.size();
}

eproperty::Property* eproperty::Interface::getPropertyRaw(const size_t& _id) const {
	if (_id >= m_list.size()) {
		EPROPERTY_ERROR("Wrong ID for property list. " << _id << " >= " << m_list.size());
		return nullptr;
	}
	return m_list[_id];
}

eproperty::Property* eproperty::Interface::getPropertyRaw(const std::string _name) const {
	for (auto &it : m_list) {
		if(it->getName() == _name) {
			return it;
		}
	}
	return nullptr;
}