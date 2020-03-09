#pragma once
#include <iostream>

/* 2d vector class with operators for easier manipulatios */
namespace Mara {
	struct Vector2 {

		int x;
		int y;
		float xpos;
		float ypos;

		Vector2();
		Vector2(int x, int y);
		Vector2(float x, float y);

		Vector2& Add(const Vector2& vec);
		Vector2& Subtract(const Vector2& vec);
		Vector2& Multiply(const Vector2& vec);
		Vector2& Divide(const Vector2& vec);

		friend Vector2 operator+(Vector2& v1, Vector2& v2);
		friend Vector2 operator-(Vector2& v1, Vector2& v2);
		friend Vector2 operator*(Vector2& v1, Vector2& v2);
		friend Vector2 operator/(Vector2& v1, Vector2& v2);

		Vector2& operator+=(const Vector2& vec);
		Vector2& operator-=(const Vector2& vec);
		Vector2& operator*=(const Vector2& vec);
		Vector2& operator/=(const Vector2& vec);

		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
	};
}
