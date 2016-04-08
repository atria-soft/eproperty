Tutorial                                         {#eproperty_tutorial}
========

@tableofcontents

What is a property:                                {#eproperty_tutorial_what}
===================

A property is a generic interface to manage parameter of a class whithout redeclare all the time the setter and getter (that is a little boring)

Calling a property car mermit to be notify when the value change and to control the values range of list ...

A property can use agreator interface eproperty::interface that declare a **"properties"** variablke that permit to acces at all the property declared.

Declare a class that have this interface:
@snippet sampleAll.cpp eproperty_sample_declare_class_with_interface


Declare property:                                {#eproperty_tutorial_declare}
=================

We have some basic properties:
  - eproperty::Value Simple store of a unique Value
  - eproperty::Range Store a value inside an authorized range
  - eproperty::List Store a value inside a list of values (set in constructor)

Declare a Value property:                                {#eproperty_tutorial_declare_value}
-------------------------

Do the correct include:
@snippet sampleAll.cpp eproperty_sample_declare_value

Declare your property:
@snippet sampleAll.cpp eproperty_sample_declare_class_property_value

Construct the property with eproperty::Interface:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_value

Construct the property with **NO** eproperty::Interface:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_value2

Configure your property:
@snippet sampleAll.cpp eproperty_sample_use_set_value_1

Use your property:
@snippet sampleAll.cpp eproperty_sample_get_value_value


Declare a Range property:                                {#eproperty_tutorial_declare_range}
-------------------------

Do the correct include:
@snippet sampleAll.cpp eproperty_sample_declare_range

Declare your property:
@snippet sampleAll.cpp eproperty_sample_declare_class_property_range

Construct the property with eproperty::Interface:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_range

Construct the property with **NO** eproperty::Interface:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_range2

Configure your property:
@snippet sampleAll.cpp eproperty_sample_use_set_range_1

Use your property:
@snippet sampleAll.cpp eproperty_sample_get_value_range


Declare a List property:                                {#eproperty_tutorial_declare_list}
------------------------

Do the correct include:
@snippet sampleAll.cpp eproperty_sample_declare_list

Declare your property:
@snippet sampleAll.cpp eproperty_sample_declare_class_property_list

Construct the property with eproperty::Interface:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_list

Construct the property with **NO** eproperty::Interface:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_list2

Special case for the List is adding the value with their string assiciated:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_list_add

Configure your property:
@snippet sampleAll.cpp eproperty_sample_use_set_list_1

Use your property:
@snippet sampleAll.cpp eproperty_sample_get_value_list



Particularity:                                {#eproperty_tutorial_particularity}
==============

Define a callback:                                {#eproperty_tutorial_particularity_callback}
------------------

All property can define a callback, it is used to update class property with special settings.

The callback is set in the construction instruction like:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_value

The fucntion define is like:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_value_callback

It is called every time the Value change, if the value is identical the callback is not called.


Set value without calling the callback:               {#eproperty_tutorial_particularity_direct_set}
---------------------------------------

To set a value in a property without calling the nitifiction function, you might use:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_set_direct

Please do not use it ouside the internal class that define the peoperty (call me if you have an api to control it at the compilation time)

Heritage and callback:                                {#eproperty_tutorial_particularity_heritage}
----------------------

When you herit from an other class with theire property you can prefer changing the default value or set an other list of parameter.

To set value without calling the callback (that can be virtual then ==0 in the initialisation state), you need to call:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_set_direct

For the eproperty::List, you chan rename enumeration or remove values:
@snippet sampleAll.cpp eproperty_sample_initialize_class_property_list_rename


All sample Code:                                {#eproperty_tutorial_all_code}
================

This Will generate this simple sample code:
@snippet sampleAll.cpp eproperty_sample_all