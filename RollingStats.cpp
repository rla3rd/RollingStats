#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class RollingStats {
    
  public:
    
    RollingStats( vector<double> list, double period );
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

RollingStats::RollingStats( std::vector< double > list, double period ) {
  inList = list;
  n = period;
  xsum = 0;
  x2sum = 0;

  // if n is > the vector length set return calcs to 0
  //
  if( n > inList.size() )
  {
    sum.push_back( 0 );
    sma.push_back( 0 );
    variance.push_back( 0 );
    stddev.push_back( 0 );
    zscore.push_back( 0 );
  }
  // if n <= vector length start the calcs
  else
  {
    for(i = 0; i <  n; i++)
    {
      xsum += inList.at( i );
      x2sum += pow(inList.at( i ), 2);
    }
    sum.push_back( xsum );
    mean = xsum / n;
    sma.push_back( mean );
    var = ( x2sum - pow(xsum, 2) / n ) / n;
  
    if( var < 0 )
    {
      var = 0;
    }
    variance.push_back( var );
    std = sqrt( var );
    stddev.push_back( std );
  
    // i has been incremented after leaving the loop above so subtract 1
    if( std != 0 )
    {
      zs = ( inList.at( i - 1 ) - mean ) / std;
    }
    else
    {
      zs = 0;
    }
  
    zscore.push_back( zs );
    // we only need to go further if n < input vector length
    if( n < inList.size() )
    {  
      for( i = n; i < inList.size(); i++ )
      {
        xsum += inList.at( i ) - inList.at( i-n );
        x2sum += pow( inList.at( i ), 2 ) - pow( inList.at( i-n ), 2 );
        sum.push_back( xsum );
        mean = xsum / n;
        sma.push_back( mean );
        var = ( x2sum - pow( xsum, 2) / n ) / n;
    
        if( var < 0 )
        {
          var = 0;
        }
        variance.push_back( var );
        std = sqrt( var );
        stddev.push_back( std );
    
        if( std != 0 )
        {
          zs = ( inList.at( i ) - mean ) / std;
        }
        else
        {
          zs = 0;
        }
    
        zscore.push_back( zs );
      }
    }
  }
};
