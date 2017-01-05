e-property
==========

`eproperty` is c++ simple class property handling that permit to change parameter through XML file.

Release (master)
----------------

[![Build Status](https://travis-ci.org/atria-soft/eproperty.svg?branch=master)](https://travis-ci.org/atria-soft/eproperty)
[![Coverage Status](http://atria-soft.com/ci/coverage/atria-soft/eproperty.svg?branch=master)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Test Status](http://atria-soft.com/ci/test/atria-soft/eproperty.svg?branch=master)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Warning Status](http://atria-soft.com/ci/warning/atria-soft/eproperty.svg?branch=master)](http://atria-soft.com/ci/atria-soft/eproperty)

[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=master&tag=Linux)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=master&tag=MacOs)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=master&tag=Mingw)](http://atria-soft.com/ci/atria-soft/eproperty)

[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=master&tag=Android)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=master&tag=IOs)](http://atria-soft.com/ci/atria-soft/eproperty)

Developement (dev)
------------------

[![Build Status](https://travis-ci.org/atria-soft/eproperty.svg?branch=dev)](https://travis-ci.org/atria-soft/eproperty)
[![Coverage Status](http://atria-soft.com/ci/coverage/atria-soft/eproperty.svg?branch=dev)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Test Status](http://atria-soft.com/ci/test/atria-soft/eproperty.svg?branch=dev)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Warning Status](http://atria-soft.com/ci/warning/atria-soft/eproperty.svg?branch=dev)](http://atria-soft.com/ci/atria-soft/eproperty)

[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=dev&tag=Linux)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=dev&tag=MacOs)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=dev&tag=Mingw)](http://atria-soft.com/ci/atria-soft/eproperty)

[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=dev&tag=Android)](http://atria-soft.com/ci/atria-soft/eproperty)
[![Build Status](http://atria-soft.com/ci/build/atria-soft/eproperty.svg?branch=dev&tag=IOs)](http://atria-soft.com/ci/atria-soft/eproperty)


Instructions
============

download Build system:
----------------------

	sudo pip install lutin
	sudo pip install pillow

download the software:
----------------------

	mkdir WORKING_DIRECTORY
	cd WORKING_DIRECTORY
	git clone https://github.com/atria-soft/etk.git
	git clone https://github.com/atria-soft/elog.git
	git clone https://github.com/atria-soft/ememory.git
	git clone https://github.com/atria-soft/eproperty.git
	git clone https://github.com/generic-library/gtest-lutin.git --recursive
	git clone https://github.com/generic-library/z-lutin.git --recursive

Compile software:
-----------------

	cd WORKING_DIRECTORY
	lutin -C -P eproperty-test eproperty-sample


License (MPL v2.0)
=====================
Copyright eproperty Edouard DUPIN

Licensed under the Mozilla Public License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://www.mozilla.org/MPL/2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

