#include <Python.h>
#include <cairo.h>
#include <math.h>

static PyObject *pycairo_draw(PyObject *self, PyObject *args)
{
	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 640, 480);
        cairo_t *cr = cairo_create(surface);

	double xc = 128.0;
	double yc = 128.0;
	double radius = 100.0;
	double angle1 = 45.0  * (M_PI / 180.0);
	double angle2 = 180.0 * (M_PI / 180.0);

	cairo_set_line_width (cr, 10.0);
	cairo_arc (cr, xc, yc, radius, angle1, angle2);
	cairo_stroke (cr);

	cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
	cairo_set_line_width (cr, 6.0);

	cairo_arc (cr, xc, yc, 10.0, 0, 2 * M_PI);
	cairo_fill (cr);

	cairo_arc (cr, xc, yc, radius, angle1, angle1);
	cairo_line_to (cr, xc, yc);
	cairo_arc (cr, xc, yc, radius, angle2, angle2);
	cairo_line_to (cr, xc, yc);
	cairo_stroke (cr);

	cairo_destroy(cr);
	cairo_surface_write_to_png (surface, "helloPython.png");
	cairo_surface_destroy (surface);

	Py_RETURN_NONE;
}

static PyMethodDef cairo_methods[] = {
    { "draw", (PyCFunction) pycairo_draw, METH_NOARGS, 0 },
    { 0, 0, 0, 0 }
};

PyMODINIT_FUNC initcairo()
{
	Py_InitModule3("cairo", cairo_methods, "Extension module");
}
