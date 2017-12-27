/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.hpp>
#include <eproperty/Value.hpp>

namespace eproperty {
	/**
	 * @brief Range template of the property (limit with a min and a max value)
	 * @tparam TYPE Tpe of the range value
	 */
	template<class TYPE> class Range : public Value<TYPE> {
		private:
			TYPE m_min; //!< Minimum value.
			TYPE m_max; //!< Maximum value.
		public:
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _owner reference on the parameter lister (nullptr if none).
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _min Minumum value.
			 * @param[in] _max Maximum value.
			 * @param[in] _description description of the parameter.
			 * @param[in] _setObs function of the class that opserve the change of the value
			 */
			template<class CLASS_TYPE>
			Range(CLASS_TYPE* _owner,
			      const etk::String& _name,
			      const TYPE& _defaultValue,
			      const TYPE& _min,
			      const TYPE& _max,
			      const etk::String& _description = "",
			      void (CLASS_TYPE::*_setObs)()=nullptr) :
			  eproperty::Value<TYPE>(_owner, _name, _defaultValue, _description, _setObs),
			  m_min(_min),
			  m_max(_max) {
				if (m_min > m_max) {
					//EPROPERTY_CRITICAL("min > max...");
				}
			};
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _min Minumum value.
			 * @param[in] _max Maximum value.
			 */
			Range(const TYPE& _defaultValue,
			      const TYPE& _min,
			      const TYPE& _max);
			/**
			 * @brief Remove copy contructor
			 */
			Range(Range& _obj) = delete;
			/**
			 * @brief Enable move contructor
			 */
			Range(Range&& _obj) :
			  Value<TYPE>::Value(_obj.m_default) {
				Property::internalSwap(&_obj);
				etk::swap(PropertyType<TYPE>::m_default, _obj.m_default);
				etk::swap(PropertyType<TYPE>::m_value, _obj.m_value);
				etk::swap(m_min, _obj.m_min);
				etk::swap(m_max, _obj.m_max);
			};
			/**
			 * @brief Destructor.
			 */
			virtual ~Range() = default;
			/**
			 * @brief Remove copy operator
			 */
			Range& operator=(Range& _obj) = delete;
			/**
			 * @brief Enable move operator
			 */
			Range& operator=(Range&& _obj) {
				Property::internalSwap(&_obj);
				etk::swap(PropertyType<TYPE>::m_default, _obj.m_default);
				etk::swap(PropertyType<TYPE>::m_value, _obj.m_value);
				etk::swap(m_min, _obj.m_min);
				etk::swap(m_max, _obj.m_max);
				return *this;
			};
			etk::String getPropertyType() const override;
			void setString(const etk::String& _newVal) override;
			etk::String getInfo() const override;
		public:
			void set(const TYPE& _newVal) override;
			void setDirectCheck(const TYPE& _newVal) override;
	};
	//! @not_in_doc
	template<typename TYPE> etk::Stream& operator <<(etk::Stream& _os, const eproperty::Range<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}
