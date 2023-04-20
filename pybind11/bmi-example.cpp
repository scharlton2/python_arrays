#include <vector>
#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>


class BMIexample
{
public:
    std::string GetComponentName()
    {
        return "bmipybind";
    }

    std::vector<std::string> GetInputVarNames()
    {
        std::vector <std::string> names;
        names.push_back("Ca");
        names.push_back("Cl");
        names.push_back("H");
        names.push_back("O");
        return names;
    }    

    void GetValue(std::string name, std::vector<double>& values)
    {
        auto it = _vectors.find(name);
        if (it != _vectors.end())
        {
            values = _vectors[name];
        }
    }

    void SetValue(std::string name, const std::vector<double>& values)
    {
        auto it = _vectors.find(name);
        if (it != _vectors.end())
        {
            it->second = values;
        }
        else
        {
            _vectors[name] = values;
        }
    }

private:
    std::map<std::string, std::vector<double>> _vectors;

};


namespace py = pybind11;


PYBIND11_MODULE(bmipybind, m) {
    m.doc() = R"pbdoc(
        bmipybind
        ---------
    )pbdoc";

    py::class_<BMIexample>(
			m, "bmi_ex"
    )
    .def(py::init())

    .def("get_component_name", &BMIexample::GetComponentName)

    // .def("GetInputVarNames", &BMIexample::GetInputVarNames)
    .def("get_input_var_names", [](BMIexample &self) {
        auto output = self.GetInputVarNames();
        py::tuple out = py::cast(output);
        return out;
    })

    .def("get_value", [](BMIexample &self, const std::string &name) {
        std::vector<double> output;
        self.GetValue(name, output);
        py::array out = py::cast(output);
        return out;
    })


    .def("set_value", [](BMIexample &self, std::string name, const py::array_t<double>& src) {
        // Extract the buffer information from the numpy array.
        py::buffer_info info = src.request();

        // Construct a std::vector<double> from the buffer data.
        double* ptr = static_cast<double*>(info.ptr);
        size_t size = info.shape[0];
        std::vector<double> src_vec(ptr, ptr + size);

        self.SetValue(name, src_vec);
    },
        py::arg("name"),
        py::arg("src")
    )
    ;
}