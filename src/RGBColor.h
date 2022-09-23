#ifndef __RGBCOLOR__
#define __RGBCOLOR__
class RGBColor {
    public:
        float r, g, b;

        RGBColor();
        RGBColor(float c);
        RGBColor(float _r, float _g, float _b);
        RGBColor(const RGBColor& c);
        ~RGBColor();

        RGBColor& operator=(const RGBColor& rhs);
};
#endif