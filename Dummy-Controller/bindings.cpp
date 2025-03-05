#include <pybind11/pybind11.h>
#include "DummyMicroscope.hpp"

namespace py = pybind11;

PYBIND11_MODULE(dummy_microscope, m) {
    m.doc() = "Dummy Microscope control module";

    py::class_<DummyMicroscope>(m, "DummyMicroscope")
        .def(py::init<>())
        .def("initialize", &DummyMicroscope::initialize, "Initialize the microscope")
        .def("set_power_level", &DummyMicroscope::setPowerLevel, "Set power level", py::arg("level"))
        .def("acquire_image", &DummyMicroscope::acquireImage, "Acquire an image", py::arg("width"), py::arg("height"))
        .def("shutdown", &DummyMicroscope::shutdown, "Shutdown the microscope");
}
