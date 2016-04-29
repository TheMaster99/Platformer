#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f
{
public:
	float x, y; // X and Y values of the vector
	Vector2f operator+(Vector2f v2); // Add two vectors
	Vector2f operator-(Vector2f v2); // Subtract two vectors
	Vector2f operator*(Vector2f v2); // Multiply two vectors
	Vector2f operator/(Vector2f v2); // Divide two vectors
	void operator+=(Vector2f v2); // Add vector to another
	void operator-=(Vector2f v2); // Subtract vector from another
	void operator*=(Vector2f v2); // Multiply vector with another
	void operator/=(Vector2f v2); // Divide vector with another
	bool operator==(Vector2f v2); // Test if two vectors are equal
	bool operator!=(Vector2f v2); // Test if two vectors are unequal
};

#endif