#include "ViewPlane.h"

ViewPlane::ViewPlane() {

}

ViewPlane::ViewPlane(const ViewPlane& viewPlane) {

}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs) {
    return *this;
}

ViewPlane::~ViewPlane() {

}

void ViewPlane::set_hres(const int h_res) {
    this->hres = h_res;
}

void ViewPlane::set_vres(const int v_res) {
    this->vres = v_res;
}

void ViewPlane::set_pixel_size(const float size) {
    this->s = size;
}

void ViewPlane::set_samples(const int n) {
    this->num_samples = n;
}