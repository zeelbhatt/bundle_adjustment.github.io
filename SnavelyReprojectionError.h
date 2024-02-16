#ifndef SnavelyReprojection_H
#define SnavelyReprojection_H

#include <iostream>
#include <ceres/ceres.h>
#include "rotation.h"


class SnavelyReprojectionError{
    public:
    SnavelyReprojectionError(double observation_x, double observation_y): observed_x(observation_x), observed_y(observation_y){}

    template<typename T>
    bool operator()(const T *const camera, const T *const point, T *residuals) const {
        T predictions[2];
        CamProjectionWithDistortion(camera, point, predictions);
        residuals[0] = predictions[0] - T(observed_x);
        residuals[1] = predictions[1] - T(observed_y);

        return true;
    }

    // camera : 9 dims array
    // [0-2] : angle-axis rotation
    // [3-5] : translation
    // [6-8] : camera parameter, [6] focal length, [7-8] second and forth order radial distortion
    // point : 3D location.
    // predictions : 2D predictions with center of the image plane.

    template<typename T>
    static inline bool CamProjectionWithDistortion(const T *camera, const T *point, T *prediction) {
        T p[3];
        AngleAxisRotatePoint(camera, point, p);
        p[0] += camera[3];
        p[1] += camera[4];
        p[2] += camera[5];

        T xp = -p[0] / p[2];
        T yp = -p[1] / p[2];

        // Apply Distortion
        const T &l1 = camera[7];
        const T &l2 = camera[8];

        T r2 = xp*xp + yp*yp;
        T distortion = T(1.0) + r2 * (l1 + l2*r2);

        const T &focal = camera[6];
        prediction[0] = focal*distortion*xp;
        prediction[1] = focal*distortion*yp;

        return true;
    }

    static ceres::CostFunction *Create(const double observed_x, const double observed_y){
        return (new ceres::AutoDiffCostFunction<SnavelyReprojectionError, 2, 9, 3>(new SnavelyReprojectionError(observed_x, observed_y)));
    }

    private:
    double observed_x;
    double observed_y;
};

#endif // SnavelyReprojection_H

