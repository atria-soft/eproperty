#!/usr/bin/python
import os
import doxy.module as module
import doxy.debug as debug
import doxy.tools as tools

def create(target, module_name):
	my_module = module.Module(__file__, module_name)
	my_module.set_version([0,1,"dev"])
	my_module.set_title("eproperty: Ewol property interface")
	my_module.set_website("http://atria-soft.github.io/" + module_name)
	my_module.set_website_sources("http://github.com/atria-soft/" + module_name)
	my_module.add_path([
	    module_name,
	    "doc"
	    ])
	my_module.add_depend([
	    'etk'
	    ])
	my_module.add_sample_path([
	    'sample'
	    ])
	my_module.add_exclude_symbols([
	    '*operator<<*',
	    ])
	my_module.add_exclude_file([
	    'debug.hpp',
	    ])
	my_module.add_file_patterns([
	    '*.hpp',
	    '*.md',
	    ])
	
	return my_module