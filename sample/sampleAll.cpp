/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#include <etk/etk.hpp>
#include <test-debug/debug.hpp>

//! [eproperty_sample_all]

//! [eproperty_sample_declare_interface]
#include <eproperty/Interface.hpp>
//! [eproperty_sample_declare_interface]
//! [eproperty_sample_declare_value]
#include <eproperty/Value.hpp>
//! [eproperty_sample_declare_value]
//! [eproperty_sample_declare_list]
#include <eproperty/List.hpp>
//! [eproperty_sample_declare_list]
//! [eproperty_sample_declare_range]
#include <eproperty/Range.hpp>
//! [eproperty_sample_declare_range]

//! [eproperty_sample_declare_an_enum]
enum simpleEnum {
	simpleEnum_enum1,
	simpleEnum_enum2,
	simpleEnum_enum3,
	simpleEnum_enum4,
};
//! [eproperty_sample_declare_an_enum]

//! [eproperty_sample_class_with_interface]
//! [eproperty_sample_declare_class_with_interface]
class sampleClassGroup : public eproperty::Interface {
//! [eproperty_sample_declare_class_with_interface]
	public:
		//! [eproperty_sample_declare_class_property_value]
		eproperty::Value<std::string> propertyValue; //!< Simple property Value with type string
		//! [eproperty_sample_declare_class_property_value]
		//! [eproperty_sample_declare_class_property_list]
		eproperty::List<enum simpleEnum> propertyList; //!< Simple property List with type enumeration
		//! [eproperty_sample_declare_class_property_list]
		//! [eproperty_sample_declare_class_property_range]
		eproperty::Range<int32_t> propertyRange; //!< Simple property Range with type integer
		//! [eproperty_sample_declare_class_property_range]
		
		sampleClassGroup():
		//! [eproperty_sample_initialize_class_property_value]
		  propertyValue(this, "value", "default value", "optionnal Description", &sampleClassGroup::onPropertyChangeValue),
		//! [eproperty_sample_initialize_class_property_value]
		//! [eproperty_sample_initialize_class_property_list]
		  propertyList(this, "list", simpleEnum_enum4),
		//! [eproperty_sample_initialize_class_property_list]
		//! [eproperty_sample_initialize_class_property_range]
		  propertyRange(this, "range", 5646546, -5, 555555555) {
		//! [eproperty_sample_initialize_class_property_range]
			// add all enumeration values
			//! [eproperty_sample_initialize_class_property_list_add]
			propertyList.add(simpleEnum_enum1, "enum1");
			propertyList.add(simpleEnum_enum2, "enum2");
			propertyList.add(simpleEnum_enum3, "enum3");
			propertyList.add(simpleEnum_enum4, "enum4");
			//! [eproperty_sample_initialize_class_property_list_add]
			//! [eproperty_sample_initialize_class_property_list_rename]
			// Rename an element
			propertyList.rename("enum1", "new enum name");
			// Remove an element
			propertyList.remove("enum2");
			//! [eproperty_sample_initialize_class_property_list_rename]
			//! [eproperty_sample_initialize_class_property_set_direct]
			// no check on the value set (the faster in CPU cycle)
			propertyValue.setDirect("New Value to Set");
			// Check the internal value (better for range)
			propertyRange.setDirectCheck(-5555);
			//! [eproperty_sample_initialize_class_property_set_direct]
		}
		//! [eproperty_sample_initialize_class_property_value_callback]
		void onPropertyChangeValue() {
			TEST_PRINT("Property value has change ... " << *propertyValue);
			
			TEST_INFO("Use properties:");
			//! [eproperty_sample_get_value_value]
			TEST_INFO("    value:" << *propertyValue);
			//! [eproperty_sample_get_value_value]
			//! [eproperty_sample_get_value_range]
			TEST_INFO("    range:" << *propertyRange);
			//! [eproperty_sample_get_value_range]
			//! [eproperty_sample_get_value_list]
			TEST_INFO("    list:" << *propertyList);
			//! [eproperty_sample_get_value_list]
			
			
		}
		//! [eproperty_sample_initialize_class_property_value_callback]
};
//! [eproperty_sample_class_with_interface]

//! [eproperty_sample_class_without_interface]
class sampleClassSolo {
	public:
		eproperty::Value<std::string> propertyValue;
		eproperty::List<enum simpleEnum> propertyList;
		eproperty::Range<int32_t> propertyRange;
		sampleClassSolo():
		//! [eproperty_sample_initialize_class_property_value2]
		  propertyValue("default value"),
		//! [eproperty_sample_initialize_class_property_value2]
		//! [eproperty_sample_initialize_class_property_list2]
		  propertyList(simpleEnum_enum4),
		//! [eproperty_sample_initialize_class_property_list2]
		//! [eproperty_sample_initialize_class_property_range2]
		  propertyRange(5646546, -5, 555555555) {
		//! [eproperty_sample_initialize_class_property_range2]
			propertyList.add(simpleEnum_enum1, "enum1");
			propertyList.add(simpleEnum_enum2, "enum2");
			propertyList.add(simpleEnum_enum3, "enum3");
			propertyList.add(simpleEnum_enum4, "enum4");
		}
};
//! [eproperty_sample_class_without_interface]

void simpleSet() {
	//! [eproperty_sample_use_declare_class]
	sampleClassGroup myClass;
	//! [eproperty_sample_use_declare_class]
	
	//! [eproperty_sample_use_set_value_1]
	myClass.propertyValue.set("New Value");
	myClass.propertyValue.setString("New Value 2");
	//! [eproperty_sample_use_set_value_1]
	//! [eproperty_sample_use_set_list_1]
	myClass.propertyList.set(simpleEnum_enum3);
	myClass.propertyList.setString("enum3");
	//! [eproperty_sample_use_set_list_1]
	//! [eproperty_sample_use_set_range_1]
	myClass.propertyRange.set(15621);
	myClass.propertyRange.setString("15621");
	//! [eproperty_sample_use_set_range_1]
	
	//! [eproperty_sample_use_set_value_2]
	myClass.properties.set("value", "New Value in string");
	//! [eproperty_sample_use_set_value_2]
	//! [eproperty_sample_use_set_list_2]
	myClass.properties.set("list", "enum4");
	//! [eproperty_sample_use_set_list_2]
	//! [eproperty_sample_use_set_range_2]
	myClass.properties.set("range", "-2");
	//! [eproperty_sample_use_set_range_2]
	
}
//! [eproperty_sample_all]


int main(int _argc, const char *_argv[]) {
	etk::init(_argc, _argv);
	TEST_INFO("simpleSet [START] ***************************");
	simpleSet();
	TEST_INFO("simpleSet [STOP]  ***************************");
	return 0;
}
