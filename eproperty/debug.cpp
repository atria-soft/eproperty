/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */

#include <eproperty/debug.hpp>

int32_t eproperty::getLogId() {
	static int32_t g_val = elog::registerInstance("eproperty");
	return g_val;
}
