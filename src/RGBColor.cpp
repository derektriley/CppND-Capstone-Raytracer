#include "RGBColor.h"

RGBColor::RGBColor() {

}

RGBColor::RGBColor(float c) {
    r = c;
    g = c;
    b = c;
}
RGBColor::RGBColor(float _r, float _g, float _b) {
    r = _r;
    g = _g;
    b = _b;
}
RGBColor::RGBColor(const RGBColor& c) {
    r = c.r;
    g = c.g;
    b = c.b;
}

RGBColor::~RGBColor() {

}

RGBColor& RGBColor::operator=(const RGBColor& rhs) {
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;
    return *this;
}