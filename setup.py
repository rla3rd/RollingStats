#!/usr/bin/env python

from setuptools import setup, Extension

RollingStats_module = Extension('_RollingStats', sources=[ 'RollingStats.cpp', 'RollingStats_wrap.cxx' ] )

setup ( name='RollingStats',
        version = '0.1',
        author = 'Richard Albright',
        description = "C++ Swig Wrapped RollingStats Class",
        ext_modules = [ RollingStats_module ],
        py_modules = [ "RollingStats" ] 
)
