#include <Python.h>
#include <cairo.h>
#include <math.h>

static PyObject *pycairo_draw(PyObject *self, PyObject *args)
{
	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 640, 480);
        cairo_t *cr = cairo_create(surface);

	cairo_save(cr);

	cairo_pattern_t *pat;

	pat = cairo_pattern_create_linear (0.0, 0.0,  0.0, 512.0);
	cairo_pattern_add_color_stop_rgba (pat, 1, 0, 0, 0, 1);
	cairo_pattern_add_color_stop_rgba (pat, 0, 1, 1, 1, 1);
	cairo_rectangle (cr, 0, 0, 640, 480);
	cairo_set_source (cr, pat);
	cairo_fill (cr);
	cairo_pattern_destroy (pat);

	cairo_restore(cr);
	cairo_save(cr);


	int              w, h;
	cairo_surface_t *image;

	cairo_arc (cr, 128.0, 128.0, 76.8, 0, 2*M_PI);
	cairo_clip (cr);
	cairo_new_path (cr);

	image = cairo_image_surface_create_from_png("tux.png");
	w = cairo_image_surface_get_width (image);
	h = cairo_image_surface_get_height (image);

	cairo_scale (cr, 256.0/w, 256.0/h);
	cairo_translate(cr, 0, 60);

	cairo_set_source_surface (cr, image, 0, 0);
	cairo_paint (cr);

	cairo_surface_destroy (image);

	cairo_restore(cr);

	cairo_translate(cr, 300, 200);

	pat = cairo_pattern_create_radial (115.2, 102.4, 25.6,
		                           102.4,  102.4, 128.0);
	cairo_pattern_add_color_stop_rgba (pat, 0, 1, 1, 1, 1);
	cairo_pattern_add_color_stop_rgba (pat, 1, 0, 0, 0, 1);
	cairo_set_source (cr, pat);
	cairo_arc (cr, 128.0, 128.0, 76.8, 0, 2 * M_PI);
	cairo_fill (cr);
	cairo_pattern_destroy (pat);

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
