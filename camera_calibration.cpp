#include <cers/ceres.h>
#include <iostream>

struct ReprojectionError{
    ReprojectionError(double px, double py, double x, double y, double z) : _px(px), _py(py), _x(x), _y(y), _z(z) {}

    template<typename T>
    bool operator()(const T* const camera, T* residuals) const {
        residuals = _x - _px;
        return true;
    }

    double _x;
    double _y;
    double _px;
    double _py;
    double _pz; 
};

int main (int argc, char **argv){

    ceres::Problem problem;
    for (int i = 0; i < N; i++){
        problem.AddResidualBlock(
            new ceres::AutoDiffCostFunction<ReprojectionError, 1, 1>(new ReprojectionError()), nullptr, abc
        )
    }

    ceres::Solver::Options options;
    options.linear_solver_type = ceres::LinearSolverType::SPARSE_SCHUR
    options.minimizer_progress_to_stdout
}
