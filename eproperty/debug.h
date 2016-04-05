/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <elog/log.h>

namespace eproperty {
	int32_t getLogId();
};
#define EPROPERTY_BASE(info,data)     ELOG_BASE(eproperty::getLogId(),info,data)

#define EPROPERTY_PRINT(data)         EPROPERTY_BASE(-1, data)
#define EPROPERTY_CRITICAL(data)      EPROPERTY_BASE(1, data)
#define EPROPERTY_ERROR(data)         EPROPERTY_BASE(2, data)
#define EPROPERTY_WARNING(data)       EPROPERTY_BASE(3, data)
#ifdef DEBUG
	#define EPROPERTY_INFO(data)          EPROPERTY_BASE(4, data)
	#define EPROPERTY_DEBUG(data)         EPROPERTY_BASE(5, data)
	#define EPROPERTY_VERBOSE(data)       EPROPERTY_BASE(6, data)
	#define EPROPERTY_TODO(data)          EPROPERTY_BASE(4, "TODO : " << data)
#else
	#define EPROPERTY_INFO(data)          do { } while(false)
	#define EPROPERTY_DEBUG(data)         do { } while(false)
	#define EPROPERTY_VERBOSE(data)       do { } while(false)
	#define EPROPERTY_TODO(data)          do { } while(false)
#endif

#define EPROPERTY_ASSERT(cond,data) \
	do { \
		if (!(cond)) { \
			EPROPERTY_CRITICAL(data); \
			assert(!#cond); \
		} \
	} while (0)

