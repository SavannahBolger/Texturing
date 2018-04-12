#pragma once
/// <summary>
/// @author: Savannah Bolger
/// @student number: C00215747
/// @date: 8/1/2018
/// @approx no hours: 0 hrs
/// </summary>

#include <iostream>

class Vector3D
{
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();

	double X();
	double Y();
	double Z();
	
	double length();
	double lengthSquared();
	Vector3D crossProduct(const Vector3D V)const;
	void normalise();

	Vector3D operator +(Vector3D v);
	Vector3D operator -(Vector3D v);
	Vector3D operator -();
	double operator *(Vector3D v);
	Vector3D operator *(double k);
	Vector3D operator *(float k);
	Vector3D operator *(int k);
	Vector3D operator ^(Vector3D v);
	Vector3D operator /(Vector3D v);

	std::string ToString();

private:
	double m_x;
	double m_y;
	double m_z;
};
