#include "Vector3D.h"

Vector3D::Vector3D() :
	m_x{ 0.0f },
	m_y{ 0.0f },
	m_z{ 0.0f }
{
}

Vector3D::Vector3D(double x, double y, double z) :
	m_x{ x },
	m_y{ y },
	m_z{ z }
{
}

Vector3D::~Vector3D()
{
}

double Vector3D::X()
{
	return m_x;
}

double Vector3D::Y()
{
	return m_y;
}

double Vector3D::Z()
{
	return m_z;
}

double Vector3D::length() 
{
	return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Vector3D::lengthSquared() 
{
	return (m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3D Vector3D::crossProduct(const Vector3D V) const
{
	const double x = m_y * V.m_z - m_z * V.m_y;
	const double y = m_z * V.m_x - m_x * V.m_z;
	const double z = m_x * V.m_y - m_y * V.m_x;
	return Vector3D(x, y, z);
}

void Vector3D::normalise()
{
	if (length() > 0.0f)
	{
		double originalLength = length();
		m_x /= originalLength;
		m_y /= originalLength;
		m_z /= originalLength;
	}
}

Vector3D Vector3D::operator+(Vector3D v)
{
	return Vector3D(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
}

Vector3D Vector3D::operator-(Vector3D v)
{
	return Vector3D(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
}

Vector3D Vector3D::operator-()
{
	return Vector3D(-m_x, -m_y, -m_z);
}

double Vector3D::operator*(Vector3D v)
{
	return (m_x * v.m_x + m_y * v.m_y + m_z * v.m_z);
}

Vector3D Vector3D::operator*(double k)
{
	return Vector3D(m_x * k, m_y * k, m_z * k);
}

Vector3D Vector3D::operator*(float k)
{
	return Vector3D(m_x * k, m_y * k, m_z * k);
}

Vector3D Vector3D::operator*(int k)
{
	return Vector3D(m_x * k, m_y * k, m_z * k);
}

Vector3D Vector3D::operator^(Vector3D v)
{
	return Vector3D(m_y * v.m_z - m_z * v.m_y, m_z * v.m_x - m_x * v.m_z, m_x * v.m_y - m_y * v.m_x);
}

Vector3D Vector3D::operator/(Vector3D v)
{
	return Vector3D(m_x / v.m_x, m_y / v.m_y, m_z / v.m_z);
}

std::string Vector3D::ToString()
{
	char tmpbuf[256];
	//sprintf_s(tmpbuf, "[ %g, %g, %g ]", m_x, m_y, m_z);
	return tmpbuf;
}

