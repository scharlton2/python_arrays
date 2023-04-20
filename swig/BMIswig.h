#if !defined(BMISWIG_INCLUDED)
#define BMISWIG_INCLUDED

#include <string>
#include <vector>
#include <map>

class BMIswig
{
public:
    std::string GetComponentName();

    std::vector<std::string> GetInputVarNames();

    void GetValue(const std::string name, std::vector<double>& values);

    void SetValue(const std::string name, const std::vector<double>& values);

private:
    std::map<std::string, std::vector<double>> _vectors;

};

#endif // BMISWIG_INCLUDED