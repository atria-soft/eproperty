#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools
import lutin.debug as debug
import os


def get_type():
	return "LIBRARY"

def get_desc():
	return "eproperty is a property interface for basic class"

def get_licence():
	return "APACHE-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def get_version():
	return "version.txt"

def create(target, module_name):
	my_module = module.Module(__file__, module_name, get_type())
	my_module.add_extra_flags()
	my_module.add_src_file([
		'eproperty/debug.cpp',
		'eproperty/Property.cpp',
		'eproperty/InterfaceData.cpp',
		'eproperty/details/Range.cpp',
		'eproperty/details/Value.cpp',
		])
	my_module.add_header_file([
		'eproperty/debug.hpp',
		'eproperty/Value.hpp',
		'eproperty/Interface.hpp',
		'eproperty/InterfaceData.hpp',
		'eproperty/Property.hpp',
		'eproperty/PropertyType.hpp',
		'eproperty/Range.hpp',
		'eproperty/List.hpp',
		'eproperty/details/Range.hxx',
		'eproperty/details/Value.hxx',
		])
	my_module.add_depend(['etk'])
	my_module.add_path(tools.get_current_path(__file__))
	my_module.add_flag('c++', [
		"-DEPROPERTY_VERSION=\"\\\"" + tools.version_to_string(get_version()) + "\\\"\""
		])
	return my_module

