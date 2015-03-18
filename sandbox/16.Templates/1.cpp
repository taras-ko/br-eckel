#include <iostream>

#define _dc(Obj) \
	Obj() { std::cout << #Obj"::"#Obj"()" << std::endl; }

#define _df(Obj, fname) \
	void fname() { std::cout << #Obj"::"#fname"()" << std::endl; }

class Shape {
	int i;
public:
	_dc(Shape);
	virtual void rotate() = 0;
};

inline void Shape::rotate() { std::cout << "Shape::rotate()" << std::endl; }

class Circle : public Shape {
public:
	_dc(Circle);
};
class Square : public Shape {
public:
	_dc(Square);
};
class Triangle : public Shape {
public:
	_dc(Triangle);
	_df(Triangle, rotate);
};

class Object {
public:
	_dc(Object);
};

class OShape : public Object, public Shape {
public:
	_dc(OShape);
	_df(OShape, rotate);
};

class OCircle : public OShape, public Circle {
public:
	_dc(OCircle);
};

class OSquare : public OShape, public Square {
public:
	_dc(OSquare);
};

class OTriangle : public OShape, public Triangle {
public:
	_dc(OTriangle);
};

int main()
{
	OTriangle ot;

	OShape *O[] = { &ot };

	O[0]->rotate();

	Triangle *T[] = { &ot };

	T[0]->rotate();

	// Ambigues call
	//	ot.rotate();

}
