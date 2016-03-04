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
#include <eproperty/VariantBase.h>
#include <eproperty/Value.h>


namespace eproperty {
	class Variant {
		private:
			std::unique_ptr<VariantBase> m_value;
		public:
			template<class TYPE>
			Variant(TYPE&& _value):
			  m_value() {
				eproperty::VariantSpecify<TYPE>* _val = new eproperty::VariantSpecify<TYPE>();
			}
			~Variant();
	};
}
