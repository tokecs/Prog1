#include <iostream>
#include "./GUI/Simple_window.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) {return slope(cos(x));}

int main() {
    Point origin(300,300);
    int points = 400, scale = 20, start = -10, end = 11;

    Window w(Point(0,0), 600,600, "Function graphs.");
    Axis ax(Axis::x, Point(100,300), 400, 20, "1 == 20 pixels"),
    ay(Axis::y, Point(300,500), 400, 20, "1 == 20 pixels");
    ax.set_color(Color::red);
    ay.set_color(Color::red);
    Function oneFunc(one, start, end, origin, points, scale, scale),
    slopeFunc(slope, start, end , origin, points, scale, scale),
    squareFunc(square, start, end, origin, points, scale, scale),
    cosFunc(cos, start, end, origin, points, scale, scale),
    slopingCosFunc(sloping_cos, start, end, origin, points, scale, scale)
    ;
    cosFunc.set_color(Color::blue);

    Text slopeLabel(Point(100, 360), "x/2");

    w.attach(slopingCosFunc);
    w.attach(cosFunc);
    w.attach(slopeLabel);
    w.attach(squareFunc);
    w.attach(oneFunc);
    w.attach(slopeFunc);
    w.attach(ax);
    w.attach(ay);
    w.show();
    while (true)
        Fl::wait();
}
