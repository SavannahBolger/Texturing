#pragma once
/// <summary>
/// @author: Savannah Bolger
/// @student number: C00215747
/// @date: 8/1/2018
/// @approx no hours: 0 hrs
/// </summary>

#include <iostream>
#include "Vector3D.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(double a11, double a12, double a13,
			double a21, double a22, double a23,
			double a31, double a32, double a33);
	Matrix3(Vector3D row1, Vector3D row2, Vector3D row3);
	~Matrix3();

	Matrix3 operator +(Matrix3 M);
	Matrix3 operator -(Matrix3 M);
	Vector3D operator *(Vector3D V);
	Matrix3 operator *(double scale) ;
	Matrix3 operator *(Matrix3 M);
	Vector3D operator /(Vector3D V);

	Matrix3 transpose();
	double determinant();
	Matrix3 inverse();
	Vector3D row(int row);
	Vector3D column(int column);

	static Matrix3 rotationZ(double angleRadians);
	static Matrix3 rotationY(double angleRadians);
	static Matrix3 rotationX(double angleRadians);

	static Matrix3 translation(Vector3D displacement);
	static Matrix3 scale(double scalingfactor);

	std::string ToString();

private:
	double m11;
	double m12;
	double m13;
	double m21;
	double m22;
	double m23;
	double m31;
	double m32;
	double m33;
};
