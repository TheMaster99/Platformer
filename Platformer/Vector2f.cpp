#include "Vector2f.h"

Vector2f Vector2f::operator+(Vector2f v2)
{
	Vector2f newVector = { x + v2.x, y + v2.y };

	return newVector;
}

Vector2f Vector2f::operator-(Vector2f v2)
{
	Vector2f newVector = { x - v2.x, y - v2.y };

	return newVector;
}

Vector2f Vector2f::operator*(Vector2f v2)
{
	Vector2f newVector = { x * v2.x, y * v2.y };

	return newVector;
}

Vector2f Vector2f::operator/(Vector2f v2)
{
	Vector2f newVector = { x / v2.x, y / v2.y };

	return newVector;
}

void Vector2f::operator+=(Vector2f v2)
{
	x += v2.x;
	y += v2.y;
}

void Vector2f::operator-=(Vector2f v2)
{
	x -= v2.x;
	y -= v2.y;
}

void Vector2f::operator*=(Vector2f v2)
{
	x *= v2.x;
	y *= v2.y;
}

void Vector2f::operator/=(Vector2f v2)
{
	x /= v2.x;
	y /= v2.y;
}

bool Vector2f::operator==(Vector2f v2)
{
	bool result = (x == v2.x && y == v2.y);

	return result;
}

bool Vector2f::operator!=(Vector2f v2)
{
	bool result = (x != v2.x || y != v2.y);

	return result;
}