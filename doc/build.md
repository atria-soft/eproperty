Build lib & build sample                           {#eproperty_build}
========================

@tableofcontents

Download:                                          {#eproperty_build_download}
=========

eproperty use some tools to manage source and build it:

lutin (build-system):                              {#eproperty_build_download_lutin}
---------------------

```{.sh}
	pip install lutin --user
	# optionnal dependency of lutin (manage image changing size for application release
	pip install pillow --user
```


dependency:                                        {#eproperty_build_download_dependency}
-----------

```{.sh}
	mkdir framework
	cd framework
	git clone https://github.com/atria-soft/elog.git
	git clone https://github.com/atria-soft/etk.git
	cd ..
```

sources:                                           {#eproperty_build_download_sources}
--------

```{.sh}
	cd framework
	git clone https://github.com/atria-soft/eproperty.git
	cd ..
```

Build:                                             {#eproperty_build_build}
======


library:                                           {#eproperty_build_build_library}
--------

```{.sh}
	lutin -mdebug eproperty
```

Sample:                                            {#eproperty_build_build_sample}
-------

```{.sh}
	lutin -mdebug eproperty-sample
```


Run sample:                                        {#eproperty_build_run_sample}
===========

```{.sh}
	lutin -mdebug eproperty-sample?run
```
