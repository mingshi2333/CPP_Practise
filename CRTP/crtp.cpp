
#include <iostream>
#include <vector>

template <typename Child>
struct Base
{
	void interface()
	{
		static_cast<Child*>(this)->implementaiton();
	}
};

struct Derived:Base<Derived>
{
	void implementation() { std::cerr << "Derived implementation\n"; }
};


class Mathkl
{
	public:
		virtual void Printelem()=0;
};

template<typename T>
struct VectorBase:Mathkl
{

	void Printelem() override
	{
		this->underlying().Printnum();
	}
	T& underlying() { return static_cast<T&>(*this); }
	T const& underlying() const { return static_cast<T const&>(*this); }

	inline T& operator+=(const T& rhs)
	{
		this->underlying() = this->underlying() + rhs;
		return this->underlying();
	}

	inline T& operator-=(const T& rhs)
	{
		this->underlying() = this->underlying() - rhs;
		return this->underlying();
	}
	inline T& operator*=(const T& rhs)
	{
		this->underlying() = this->underlying() * rhs;
		return this->underlying();
	}
	inline T& operator/=(const T& rhs)
	{
		this->underlying() = this->underlying() / rhs;
		return this->underlying();
	}

	//.....
};

struct Vector3 : public VectorBase<Vector3>
{
	float x;
	float y;
	float z;

	Vector3() = default;

	Vector3(float _x, float _y, float _z):x(_x),y(_y),z(_z){}

	void Printnum()
	{
		std::cout << "x = " << x << " y= " << y << " z= " << z << std::endl;
	}
};
inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	return result;
}

inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;
	return result;
}
inline  Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs.x * rhs.x;
	result.y = lhs.y * rhs.y;
	result.z = lhs.z * rhs.z;
	return result;
}

inline  Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs.x / rhs.x;
	result.y = lhs.y / rhs.y;
	result.z = lhs.z / rhs.z;
	return result;
}

struct Vector2: public VectorBase<Vector2>
{
	float x;
	float y;

	Vector2() = default;
	Vector2(float _x, float _y) :x(_x), y(_y){}
	void Printnum()
	{
		std::cout << "x =  " << x << " y = " << y << std::endl;
	}
};
inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return result;
}

inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	return result;
}
inline  Vector2 operator*(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs.x * rhs.x;
	result.y = lhs.y * rhs.y;
	return result;
}

inline  Vector2 operator/(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs.x / rhs.x;
	result.y = lhs.y / rhs.y;
	return result;
}

//......

int main()
{
	Vector3 v0(6.0f, 5.0f, 4.0f);
	Vector3 v2(4.0f, 5.0f, 6.0f);
	auto v3 = v0 + v2;
	std::vector<Mathkl*> mytest;
	mytest.push_back(new Vector3(6.0f, 5.0f, 4.0f));
	mytest.push_back(new Vector2(1.f,2.f));
	mytest.push_back(new Vector2(1.f, 2.2f));
	for(auto& index:mytest)
	{
		index->Printelem();
	}
	
	

	

	return 0;
}