/* RollingStats.i */
%module RollingStats
%{
#include "RollingStats.h"
%}
%include "std_vector.i"
%include "exception.i"

%exception {
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  }
}

namespace std {
    %template(vectord) vector<double>;
};

using namespace std;

class RollingStats {
    public:
        RollingStats( std::vector<double> v, double period);
        std::vector<double> sum; // sum of x over n periods
        std::vector<double> sma; // mean of x over n periods
        std::vector<double> variance; // variance of x over n periods
        std::vector<double> stddev; // std dev of x over n periods
        std::vector<double> zscore; // zscore of x over n periods
};
