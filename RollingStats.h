#ifndef RollingStats_class
#define RollingStats_class

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class RollingStats
{
  public:
    RollingStats( vector<double> , double period );
    vector<double> sum; // sum of x over n periods
    vector<double> sma; // mean of x over n periods
    vector<double> variance; // variance of x over n periods
    vector<double> stddev; // std dev of x over n periods
    vector<double> zscore; // zscore of x over n periods
  
  private:
    double x2sum; // rolling sum of x squared
    double xsum; // rolling sum of x
    double mean; // rolling mean of x
    double var; // rolling variance of x
    double std; // rolling stddev of x
    double zs; // rolling zs of x
    vector<double> inList; // input vector
    double n; // input period length
    int i; // for loop iterator
};
#endif