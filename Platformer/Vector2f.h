#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f
{
public:
	float x, y;
	Vector2f operator+(Vector2f v2);
	Vector2f operator-(Vector2f v2);
	Vector2f operator*(Vector2f v2);
	Vector2f operator/(Vector2f v2);
	void operator+=(Vector2f v2);
	void operator-=(Vector2f v2);
	void operator*=(Vector2f v2);
	void operator/=(Vector2f v2);
	bool operator==(Vector2f v2);
	bool operator!=(Vector2f v2);
};

#endif