# RollingStats - C++ rolling statistics class with a python swig wrapper
uses swig3.0, (can also compile using swig2.0)

see compile script for compiling 

###### Usage
import RollingStats

x = [1,3,6,4,7,8,0,6,4,7,9,0,7,5]

roll = RollingStats.RollingStats(x, 3)

sums = [i for i in roll.sum]

means = [i for i in roll.sma]

vars = [i for i in roll.variance]

stds = [i for i in roll.stddev]

zs = [i for i in roll.zscore]
