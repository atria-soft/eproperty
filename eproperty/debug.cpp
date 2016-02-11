/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */

#include <eproperty/debug.h>

int32_t eproperty::getLogId() {
	static int32_t g_val = etk::log::registerInstance("eproperty");
	return g_val;
}
