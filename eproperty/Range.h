/**
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <eproperty/Interface.h>
#include <eproperty/Value.h>
#include <typeinfo>

namespace eproperty {
	template<typename TYPE> class Range : public Value<TYPE> {
		private:
			TYPE m_min; //!< Minimum value.
			TYPE m_max; //!< Maximum value.
		public:
			/**
			 * @brief Create a parameter with a specific type.
			 * @param[in] _owner reference on the parameter lister.
			 * @param[in] _name Static name of the parameter.
			 * @param[in] _defaultValue Default value of the parameter.
			 * @param[in] _min Minumum value.
			 * @param[in] _max Maximum value.
			 * @param[in] _description description of the parameter.
			 * @param[in] _setObs function of the class that opserve the change of the value
			 */
			template<class CLASS_TYPE>
			Range(CLASS_TYPE* _owner,
			      const std::string& _name,
			      const TYPE& _defaultValue,
			      const TYPE& _min,
			      const TYPE& _max,
			      const std::string& _description = "",
			      void (CLASS_TYPE::*_setObs)()=nullptr) :
			  eproperty::Value<TYPE>(_owner, _name, _defaultValue, _description, _setObs),
			  m_min(_min),
			  m_max(_max) {
				if (m_min > m_max) {
					//EPROPERTY_CRITICAL("min > max...");
				}
			};
			/**
			 * @brief Destructor.
			 */
			virtual ~Range() = default;
			std::string getPropertyType() const override {
				return "eproperty::Range";
			}
			void setString(const std::string& _newVal) override {
				TYPE val;
				// when you want to set an element in parameter you will implement the function template std::from_string
				etk::from_string(val, _newVal);
				set(val);
			}
			std::string getInfo() const override {
				return eproperty::Value<TYPE>::getType() + " default=" + eproperty::Value<TYPE>::getDefault();
			}
		public:
			/**
			 * @brief Set a new value for this parameter
			 * @param[in] newVal New value to set (set the nearest value if range is set)
			 */
			void set(const TYPE& _newVal) override {
				if (m_min == m_max) {
					if (_newVal != eproperty::Value<TYPE>::m_value) {
						eproperty::Value<TYPE>::m_value = _newVal;
						eproperty::Value<TYPE>::notifyChange();
					}
				} else {
					TYPE newVal = std::avg(m_min, _newVal, m_max);
					if (newVal != eproperty::Value<TYPE>::m_value) {
						eproperty::Value<TYPE>::m_value = newVal;
						eproperty::Value<TYPE>::notifyChange();
					}
				}
			}
			void setDirectCheck(const TYPE& _newVal) override {
				if (m_min == m_max) {
					if (_newVal != eproperty::Value<TYPE>::m_value) {
						eproperty::Value<TYPE>::m_value = _newVal;
					}
				} else {
					TYPE newVal = std::avg(m_min, _newVal, m_max);
					if (newVal != eproperty::Value<TYPE>::m_value) {
						eproperty::Value<TYPE>::m_value = newVal;
					}
				}
			}
	};
	
	template<typename TYPE> std::ostream& operator <<(std::ostream& _os, const eproperty::Range<TYPE>& _obj) {
		_os << _obj.get();
		return _os;
	}
}

