#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <png.h>
#include <vector>
#include "Window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[5][20]={"white", "black", "red", "dark olive green", "blue"};

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 5; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg) {
  XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}

void Xwindow::drawImage(const char * filename, int x, int y) {
  png_image image;
  memset(&image, 0, sizeof(image));
  image.version = PNG_IMAGE_VERSION;

  if (png_image_begin_read_from_file(&image, filename) == 0) {
    cerr << "Error: %s\n" << image.message << endl;
    return;
  }

  image.format = PNG_FORMAT_RGBA;

  vector<png_byte> buffer(PNG_IMAGE_SIZE(image));

  if (png_image_finish_read(&image, NULL, buffer.data(), 0, NULL) == 0) {
    cerr << "Error: %s\n" << image.message << endl;
    return;
  }
  
  XImage *ximage = XCreateImage(d, CopyFromParent, DefaultDepth(d, DefaultScreen(d)),
                        ZPixmap, 0, (char *)buffer.data(), image.width, image.height, 32, 0);
  
  // XPutImage (Display *, Drawable, GC, XImage *, src_x, src_y, dest_x, dest_y, width, height)
  XPutImage(d, w, gc, ximage, 0, 0, x, y, 100, 200);
  
  png_image_free(&image);
}


