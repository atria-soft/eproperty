/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <vector>
#include <map>
#include <eproperty/InterfaceData.hpp>

namespace eproperty {
	/**
	 * @brief Interface to collect the property list (for abstarction "set" and "get")
	 * It create a simple "properties" member that permit to access at the properties.
	 */
	class Interface {
		public:
			eproperty::InterfaceData properties; //!< Interface to access at all properties...
	};
}

