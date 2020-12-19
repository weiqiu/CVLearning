#ifndef SRC_IMAGE_CVL_MAT_H__
#define SRC_IMAGE_CVL_MAT_H__

#include <Eigen/Eigen>

namespace cvl
{
	using Mat2i = Eigen::Matrix2i;
	using Mat3i = Eigen::Matrix3i;
	using Mat4i = Eigen::Matrix4i;
	using MatXi = Eigen::MatrixXi;

	using Mat2f = Eigen::Matrix2f;
	using Mat3f = Eigen::Matrix3f;
	using Mat4f = Eigen::Matrix4f;
	using MatXf = Eigen::MatrixXf;

	using Mat2d = Eigen::Matrix2d;
	using Mat3d = Eigen::Matrix3d;
	using Mat4d = Eigen::Matrix4d;
	using MatXd = Eigen::MatrixXd;
} // namespace cvl

#endif //!SRC_IMAGE_CVL_MAT_H__