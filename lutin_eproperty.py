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
	return ["Mr DUPIN Edouard <yui.heero@gmail.com>"]

def get_version():
	return [0,1,"dev"]

def create(target, module_name):
	my_module = module.Module(__file__, module_name, get_type())
	my_module.add_extra_compile_flags()
	my_module.add_src_file([
		'eproperty/debug.cpp',
		'eproperty/Property.cpp',
		'eproperty/Interface.cpp',
		'eproperty/Variant.cpp',
		])
	my_module.add_header_file([
		'eproperty/debug.h',
		'eproperty/Value.h',
		'eproperty/Interface.h',
		'eproperty/Property.h',
		'eproperty/PropertyType.h',
		'eproperty/Range.h',
		'eproperty/List.h',
		'eproperty/Variant.h',
		'eproperty/VariantBase.h'
		])
	my_module.add_module_depend(['etk'])
	my_module.add_path(tools.get_current_path(__file__))
	my_module.compile_flags('c++', [
		"-DEPROPERTY_VERSION=\"\\\"" + tools.version_to_string(get_version()) + "\\\"\""
		])
	return my_module

