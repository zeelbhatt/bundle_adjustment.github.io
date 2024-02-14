# Camera Calibration and Bundle Adjustment

Camera calibration means that we want to estimate the parameters which sits inside the cmaera which describe us how a point in a 3D world is mapped into the 2D image plane. This topic is very popular yet misunderstood by many. But here we will discuss this in very detail and at last we will see the code with/without using any direct camera calibration funtions. Some of the importatnt terms will will use here are (Linear transformation, non-linear transformation, Least Square optimisation. Singular )  
- What exactly is camera calibration? 
- Challanges in estimating the camera parameters
- The linear solution using linear algebra
- The Non-linear soltion using Bundle Adjustment 

The pinhole camera model describes the mathematical relationship between the coordinates of a point in three-dimensional space and its projection onto the image plane of an ideal pinhole camera, where the camera aperture is described as a point and no lenses are used to focus light.
<p align="center">
  <img src="images/camera_model.png" width="400"> 
</p>

Assuming the world and image points are represented in homogeneous coordinates, then central projection can simply expressed as a linear mapping between their homogeneous coordinates in terms of matrix multiplication by,

<p align="center">
  <img src="images/eq_1.png" width="500"> 
</p>




