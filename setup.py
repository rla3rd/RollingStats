#!/usr/bin/env python

from setuptools import setup

setup( 
    name='RollingStats',
    version='0.3.1',
    author='Rick Albright',
    description="Rolling Statistics Class",
    requires=['pandas', 'numpy'],
    py_modules=['RollingStats'],
    license='MIT License' 
)
