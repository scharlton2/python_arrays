#include "BMIswig.h"


std::string BMIswig::GetComponentName()
{
    return "BMIswig";
}

std::vector<std::string> BMIswig::GetInputVarNames()
{
    std::vector <std::string> names;
    names.push_back("Ca");
    names.push_back("Cl");
    names.push_back("H");
    names.push_back("O");
    return names;
}    

void BMIswig::GetValue(const std::string name, std::vector<double>& values)
{
    auto it = _vectors.find(name);
    if (it != _vectors.end())
    {
        values = _vectors[name];
    }
}

void BMIswig::SetValue(const std::string name, const std::vector<double>& values)
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
