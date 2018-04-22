

#include <string>
using namespace std;

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include  <pybind11/chrono.h>
namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<int>);


class Item 
{
public:
    void set(int n) { n_ = n; }
    int get() { return n_; }  

private:
    int n_;    
public:
    string s;
    vector<int> v;
};

int add(int i, int j) {
    return i + j;
}


PYBIND11_MODULE(sbind, m) {
    // m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add);

    py::class_<Item>(m, "Item")
        .def(py::init<>())
        .def("set", &Item::set)
        .def("get", &Item::get)
        .def_readwrite("s", &Item::s)
        .def_readwrite("v", &Item::v)
    ;

    m.def("sum", [](int a, int b) -> int {
        return a + b;
    });


}