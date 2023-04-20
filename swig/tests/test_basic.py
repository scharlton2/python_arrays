import bmi_swig as sg
import numpy as np

def test_main():
    bmi = sg.BMIswig()

    component_name = bmi.GetComponentName()
    assert(component_name == "BMIswig")
    assert(isinstance(component_name, str))

    input_vars = bmi.GetInputVarNames()
    assert(isinstance(input_vars, tuple))
    assert(isinstance(input_vars[0], str))

    nxyz = 40

    density_list = [1.0] * nxyz
    bmi.SetValue("Density", density_list)

    density_tuple = tuple([1.0] * nxyz)
    bmi.SetValue("Density", density_tuple)

    density_ndarray = np.full((nxyz,), 1.0)
    bmi.SetValue("Density", density_ndarray)

    # density_output = bmi.GetValue("Density")  ->  TypeError: BMIswig.GetValue() missing 1 required positional argument: 'values'

    dv = sg.DoubleVector()
    bmi.GetValue("Density", dv)
    assert(dv.size() == nxyz)


'''
import bmi_swig as sg
import numpy as np
bmi = sg.BMIswig()
component_name = bmi.GetComponentName()

assert(component_name == "BMIswig")
assert(isinstance(component_name, str))

input_vars = bmi.GetInputVarNames()
assert(isinstance(input_vars, tuple))
assert(isinstance(input_vars[0], str))

nxyz = 40

density_list = [1.0] * nxyz
bmi.SetValue("Density", density_list)

density_tuple = tuple([1.0] * nxyz)
bmi.SetValue("Density", density_tuple)

density_ndarray = np.full((nxyz,), 1.0)
bmi.SetValue("Density", density_ndarray)

# density_output = bmi.GetValue("Density")  ->  TypeError: BMIswig.GetValue() missing 1 required positional argument: 'values'

dv = sg.DoubleVector()
bmi.GetValue("Density", dv)
assert(dv.size() == nxyz)
'''
