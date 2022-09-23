#ifndef __VIEWPLANE__
#define __VIEWPLANE__

class ViewPlane {
    public:
        int hres;
        int vres;
        float s;
        int num_samples;

        float gamma;
        float inv_gamma;
        bool show_out_of_gamut;

        ViewPlane();

        ViewPlane(const ViewPlane& viewPlane);

        ViewPlane& operator=(const ViewPlane& rhs); // assignment operator

        ~ViewPlane();
        
        void set_hres(const int h_res);

        void set_vres(const int v_res);

        void set_pixel_size(const float size);

        void set_samples(const int n);

};
#endif