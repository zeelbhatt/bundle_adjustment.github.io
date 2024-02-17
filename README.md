# Camera Calibration and Bundle Adjustment

Camera calibration involves determining the internal parameters of a camera that explain how a point in a 3D world is translated onto a 2D image plane.This subject is significantly popular but remains widely misunderstood. It delves into a complex web of related topics, including linear transformations, Singular value decomposition(SVD), Bundle Adjustment, Non-linear least-sqauares etc. We will discuss them all and also see the code. We will also make use of powerfull C++ libraries like Eigen and Ceres to solve our Linear and nonlinear problems. We will see... 
- What exactly is camera calibration? 
- The linear solution using linear algebra
- The Non-linear soltion using Bundle Adjustment 

The pinhole camera model describes the mathematical relationship between the coordinates of a point in three-dimensional space and its projection onto the image plane of an ideal pinhole camera, where the camera aperture is described as a point and no lenses are used to focus light.
<p align="center">
  <img src="images/camera_model.png" width="400"> 
</p>

Assuming the world and image points are represented in homogeneous coordinates, then the projection of 3D point X can simply expressed as a linear mapping between their homogeneous coordinates in terms of matrix multiplication by u,

<p align="center">
  <img src="images/eq_1.png" width="500"> 
</p>


To solve for M , we need pairs of image points ⃗u and 3D points X. We may be calibrating a camera to capture images of a planar surface (e.g., a checker-board pattern).
Since we are deciding the coordinate frame. We can put the checkerboard plane as Z = 0
<p align="center">
  <img src="images/eq_2.png" width="300"> 
</p>
We can solve this linear system using Least Squared method in this form A⃗x = 0





