%module bmi_swig

%{
#define SWIG_FILE_WITH_INIT
#include "BMIswig.h"
%}

// %include "numpy.i"

%init %{
import_array();
%}

%include "std_string.i"
%include "numpy.i"
%include "std_vector.i"
%include "std_map.i"
%template(DoubleVector) std::vector<double>;
%template(IntVector)    std::vector<int>;
%template(StringVector) std::vector<std::string>;

%apply (double* IN_ARRAY1, int DIM1) {(double* array, int size)}

%include "BMIswig.h"
