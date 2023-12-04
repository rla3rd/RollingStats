# RollingStats - Rolling Statistics class
###### Usage
import RollingStats

x = [1,3,6,4,7,8,0,6,4,7,9,0,7,5]

roll = RollingStats.RollingStats(x, 3)

sums = [i for i in roll.sum]

means = [i for i in roll.sma]

vars = [i for i in roll.variance]

stds = [i for i in roll.stddev]

zs = [i for i in roll.zscore]
