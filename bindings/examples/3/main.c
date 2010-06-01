#include <Python.h>
#include <cairo.h>
#include <math.h>

static cairo_surface_t *surface = 0;
static cairo_t *cr = 0;

static PyObject *pycairo_draw(PyObject *self, PyObject *args)
{
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
	cairo_surface_write_to_png (surface, "hello.png");
	cairo_surface_destroy (surface);

	Py_RETURN_NONE;
}

static PyObject *pycairo_set_line_width(PyObject *self, PyObject *args)
{
	double lineWidth;

	if (!PyArg_ParseTuple(args, "d", &lineWidth)) {
		return 0;
	}

	cairo_set_line_width(cr, lineWidth);

	Py_RETURN_NONE;
}

static PyObject *pycairo_arc(PyObject *self, PyObject *args)
{
	double xc, yc, radius, angle1, angle2;

	if (!PyArg_ParseTuple(args, "ddddd", &xc, &yc, &radius, &angle1, &angle2)) {
		return 0;
	}

	cairo_arc(cr, xc, yc, radius, angle1, angle2);

	Py_RETURN_NONE;
}

static PyObject *pycairo_stroke(PyObject *self, PyObject *args)
{
	cairo_stroke(cr);

	Py_RETURN_NONE;
}

static PyObject *pycairo_set_source_rgba(PyObject *self, PyObject *args)
{
	double r, g, b, a;

	if (!PyArg_ParseTuple(args, "dddd", &r, &g, &b, &a)) {
		return 0;
	}

	cairo_set_source_rgba(cr, r, g, b, a);

	Py_RETURN_NONE;
}

static PyObject *pycairo_fill(PyObject *self, PyObject *args)
{
	cairo_fill(cr);

	Py_RETURN_NONE;
}

static PyObject *pycairo_line_to(PyObject *self, PyObject *args)
{
	double xc, yc;

	if (!PyArg_ParseTuple(args, "dd", &xc, &yc)) {
		return 0;
	}

	cairo_line_to(cr, xc, yc);

	Py_RETURN_NONE;
}

static PyObject *pycairo_surface_write_to_png(PyObject *self, PyObject *args)
{
	const char *filename = 0;

	if (!PyArg_ParseTuple(args, "s", &filename)) {
		return 0;
	}

	cairo_surface_write_to_png(surface, filename);

	Py_RETURN_NONE;
}

static PyMethodDef cairo_methods[] = {
    { "draw", (PyCFunction) pycairo_draw, METH_NOARGS, 0 },
    { "set_line_width", (PyCFunction) pycairo_set_line_width, METH_VARARGS, 0  },
    { "arc", (PyCFunction) pycairo_arc, METH_VARARGS, 0  },
    { "stroke", (PyCFunction) pycairo_stroke, METH_VARARGS, 0  },
    { "set_source_rgba", (PyCFunction) pycairo_set_source_rgba, METH_VARARGS, 0  },
    { "fill", (PyCFunction) pycairo_fill, METH_VARARGS, 0  },
    { "line_to", (PyCFunction) pycairo_line_to, METH_VARARGS, 0  },
    { "surface_write_to_png", (PyCFunction) pycairo_surface_write_to_png, METH_VARARGS, 0  },
    { 0, 0, 0, 0 }
};

PyMODINIT_FUNC initcairo()
{
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 640, 480);
	cr = cairo_create(surface);
	Py_InitModule3("cairo", cairo_methods, "Extension module");
}
