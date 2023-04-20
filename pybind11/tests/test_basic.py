import bmipybind as pb
import numpy as np

def test_main():
    bmi = pb.bmi_ex()

    component_name = bmi.get_component_name()
    assert(component_name == "bmipybind")

    input_vars = bmi.get_input_var_names()
    assert(isinstance(input_vars, tuple))
    assert(isinstance(input_vars[0], str))

    nxyz = 40

    density_input = np.full((nxyz,), 1.0)
    bmi.set_value("Density", density_input)

    density_output = bmi.get_value("Density")
    assert(isinstance(density_output, np.ndarray))
