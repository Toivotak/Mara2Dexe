#include "Vector2.h"

using namespace Mara;

Vector2::Vector2()
	: xpos(0.0f), ypos(0.0f) {
}

Vector2::Vector2(int x, int y)
	: x(x), y(y){
}

Vector2::Vector2(float x, float y)
	: xpos(x), ypos(y) {
}

Vector2& Vector2::Add(const Vector2& vec){
	this->xpos += vec.xpos;
	this->ypos += vec.ypos;

	return *this;
}

Vector2& Vector2::Subtract(const Vector2& vec) {
	this->xpos -= vec.xpos;
	this->ypos -= vec.ypos;

	return *this;
}

Vector2& Vector2::Multiply(const Vector2& vec) {
	this->xpos *= vec.xpos;
	this->ypos *= vec.ypos;

	return *this;
}

Vector2& Vector2::Divide(const Vector2& vec) {
	this->xpos /= vec.xpos;
	this->ypos /= vec.ypos;

	return *this;
}

Vector2 operator+(Vector2& v1, Vector2& v2) {
	return v1.Add(v2);
}

Vector2 operator-(Vector2& v1, Vector2& v2) {
	return v1.Subtract(v2);
}

Vector2 operator*(Vector2& v1, Vector2& v2) {
	return v1.Multiply(v2);
}

Vector2 operator/(Vector2& v1, Vector2& v2) {
	return v1.Divide(v2);;
}

Vector2& Vector2::operator+=(const Vector2& vec) {
	return this->Add(vec);
}

Vector2& Vector2::operator-=(const Vector2& vec) {
	return this->Subtract(vec);
}

Vector2& Vector2::operator*=(const Vector2& vec) {
	return this->Multiply(vec);
}

Vector2& Vector2::operator/=(const Vector2& vec) {
	return this->Divide(vec);
}

std::ostream& operator<<(std::ostream& stream, const Vector2& vec)
{
	stream << "Vector (" << vec.xpos << " , " << vec.ypos << ")";
	return stream;
}


