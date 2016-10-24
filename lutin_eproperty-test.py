#!/usr/bin/python
import lutin.debug as debug
import lutin.tools as tools


def get_type():
	return "BINARY"

def get_sub_type():
	return "TEST"

def get_desc():
	return "e-property test software"

def get_licence():
	return "APACHE-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def configure(target, my_module):
	my_module.add_src_file([
	    'test/main.cpp',
	    'test/declareProperties.cpp',
	    'test/test_list.cpp',
	    'test/test_range.cpp',
	    'test/test_value.cpp'
	    ])
	my_module.add_depend([
	    'eproperty',
	    'gtest',
	    'test-debug'
	    ])
	return True
