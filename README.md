# Bundle Adjustment

The pinhole camera model describes the mathematical relationship between the coordinates of a point in three-dimensional space and its projection onto the image plane of an ideal pinhole camera, where the camera aperture is described as a point and no lenses are used to focus light.
<p align="center">
  <img src="images/camera_model.png" width="400"> 
</p>

Assuming the world and image points are represented in homogeneous coordinates, then central projection can simply expressed as a linear mapping between their homogeneous coordinates in terms of matrix multiplication by,

<p align="center">
  <img src="images/eq_1.png" width="500"> 
</p>




