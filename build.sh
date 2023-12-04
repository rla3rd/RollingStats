#!/bin/bash
cd $PYBUILD/Dropbox/projects/RollingStats
$PYTHON setup.py build
$PYTHON setup.py sdist
$PYTHON setup.py install
