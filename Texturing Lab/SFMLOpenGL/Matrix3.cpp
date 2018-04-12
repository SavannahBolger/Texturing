#include "Matrix3.h"

Matrix3::Matrix3() :
	m11{ 0.0f },
	m12{ 0.0f },
	m13{ 0.0f },
	m21{ 0.0f },
	m22{ 0.0f },
	m23{ 0.0f },
	m31{ 0.0f },
	m32{ 0.0f },
	m33{ 0.0f }
{
}

Matrix3::Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) :
	m11{ a11 },
	m12{ a12 },
	m13{ a13 },
	m21{ a21 },
	m22{ a22 },
	m23{ a23 },
	m31{ a31 },
	m32{ a32 },
	m33{ a33 }
{
}

Matrix3::Matrix3(Vector3D row1, Vector3D row2, Vector3D row3) :
	m11{ row1.X() },
	m12{ row1.Y() },
	m13{ row1.Z() },
	m21{ row2.X() },
	m22{ row2.Y() },
	m23{ row2.Z() },
	m31{ row3.X() },
	m32{ row3.Y() },
	m33{ row3.Z() }
{
}

Matrix3::~Matrix3()
{
}

Matrix3 Matrix3::operator+(Matrix3 M)
{
	return Matrix3(m11 + M.m11, m12 + M.m12, m13 + M.m13,
				   m21 + M.m21, m22 + M.m22, m23 + M.m23,
				   m31 + M.m31, m32 + M.m32, m33 + M.m33);
}

Matrix3 Matrix3::operator-(Matrix3 M)
{
	return Matrix3(m11 - M.m11, m12 - M.m12, m13 - M.m13,
				   m21 - M.m21, m22 - M.m22, m23 - M.m23,
				   m31 - M.m31, m32 - M.m32, m33 - M.m33);
}

Vector3D Matrix3::operator*(Vector3D V)
{
	return Vector3D(m11 * V.X() + m12 * V.Y() + m13 * V.Z(),
				    m21 * V.X() + m22 * V.Y() + m23 * V.Z(),
				    m31 * V.X() + m32 * V.Y() + m33 * V.Z());
}

Matrix3 Matrix3::operator*(double scale)
{
	return Matrix3(m11 * scale, m12 * scale, m13 * scale,
				   m21 * scale, m22 * scale, m23 * scale,
				   m31 * scale, m32 * scale, m33 * scale);
}

Matrix3 Matrix3::operator*(Matrix3 M)
{
	return Matrix3(m11 * M.m11 + m12 * M.m21 + m13 * M.m31, m11 * M.m12 + m12 * M.m22 + m13 * M.m32, m11 * M.m13 + m12 * M.m23 + m13 * M.m33,
				   m21 * M.m11 + m22 * M.m21 + m23 * M.m31, m21 * M.m12 + m22 * M.m22 + m23 * M.m32, m21 * M.m13 + m22 * M.m23 + m23 * M.m33,
				   m31 * M.m11 + m32 * M.m21 + m33 * M.m31, m31 * M.m12 + m32 * M.m22 + m33 * M.m32, m31 * M.m13 + m32 * M.m23 + m33 * M.m33);
}

Vector3D Matrix3::operator/(Vector3D V)
{
	return Vector3D(m11 / V.X() + m12 / V.Y() + m13 / V.Z(),
		m21 / V.X() + m22 / V.Y() + m23 / V.Z(),
		m31 / V.X() + m32 / V.Y() + m33 / V.Z());
}



Matrix3 Matrix3::transpose()
{
	return Matrix3();
}

double Matrix3::determinant()
{
	return (m11 * (m22 * m33 - m32 * m23) - m21 * (m33 * m12 - m32 * m13) + m31 * (m23 * m12 - m22 * m13));
}

Matrix3 Matrix3::inverse()
{
	return Matrix3(m33 * m22 - m32 * m23, m32 * m13 - m33 * m12, m23 * m12 - m22 * m13,
				   m31 * m23 - m33 * m21, m33 * m11 - m31 * m13, m21 * m13 - m23 * m11,
				   m32 * m21 - m31 * m22, m31 * m12 - m32 * m11, m22 * m11 - m21 * m12);
}

Vector3D Matrix3::row(int row)
{
	switch (row)
	{
	case 1:
		return Vector3D(m11, m12, m13);
	case 2:
		return Vector3D(m21, m22, m23);
	case 3:
		return Vector3D(m31, m32, m33);
	}
	return Vector3D();
}

Vector3D Matrix3::column(int column)
{
	switch (column)
	{
	case 1:
		return Vector3D(m11, m21, m31);
	case 2:
		return Vector3D(m12, m22, m32);
	case 3:
		return Vector3D(m13, m23, m33);
	}
	return Vector3D();
}

Matrix3 Matrix3::rotationZ(double angleRadians)
{
	return Matrix3(cos(angleRadians), -sin(angleRadians), 0,
				   sin(angleRadians), cos(angleRadians), 0,
				   0, 0, 1);
}

Matrix3 Matrix3::rotationY(double angleRadians)
{
	return Matrix3(cos(angleRadians), 0, sin(angleRadians),
				   0, 1, 0,
				   -sin(angleRadians), 0, cos(angleRadians));
}

Matrix3 Matrix3::rotationX(double angleRadians)
{
	return Matrix3(1, 0, 0,
				   0, cos(angleRadians), -sin(angleRadians),
				   0, sin(angleRadians), cos(angleRadians));
}

Matrix3 Matrix3::translation(Vector3D displacement)
{
	return Matrix3(1, 0, displacement.X(),
				   0, 1, displacement.Y(),
				   0, 0, 1);
}

Matrix3 Matrix3::scale(double scalingfactor)
{
	return Matrix3(scalingfactor, 0, 0,
				   0, scalingfactor, 0,
				   0, 0, scalingfactor);
}

std::string Matrix3::ToString()
{
	char tmpbuf[512];
	//sprintf_s(tmpbuf, "{ [ %g, %g, %g ] [ %g, %g, %g ] [ %g, %g, %g ] }", m11, m12, m13, m21, m22, m23, m31, m32, m33);
	return tmpbuf;
}
