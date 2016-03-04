/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.h>
#include <eproperty/Property.h>

namespace eproperty {
	class VariantBase {
		protected:
			uint64_t m_type;
		public:
			VariantBase(const uint64_t& _type) :
			  m_type(_type) {
				
			}
			virtual ~VariantBase() = default;
	};
}

