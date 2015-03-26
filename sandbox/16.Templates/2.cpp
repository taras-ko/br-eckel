#include <iostream>
#include "TStack2.h"

#define _dc(Obj) \
	Obj() { std::cout << #Obj"::"#Obj"()" << std::endl; }

#define _dd(Obj) \
	virtual ~Obj() { std::cout << #Obj"::~"#Obj"()" << std::endl; }

#define _df(Obj, fname) \
	void fname() const { std::cout << #Obj"::"#fname"()" << std::endl; }


class Shape {
public:
	_dc(Shape);
  _dd(Shape);
	virtual void draw() const = 0;
};

class Circle : public Shape {
public:
	_dc(Circle);
  _dd(Circle);

	_df(Circle, draw);
};

class Square : public Shape {
public:
	_dc(Square);
  _dd(Square);

	_df(Square, draw);
};

class Triangle : public Shape {
public:
	_dc(Triangle);
  _dd(Triangle);

	_df(Triangle, draw);
};

int main()
{
	Stack<Shape> shapes;

	shapes.push(new Circle);
	shapes.push(new Square);
	shapes.push(new Triangle);

	Stack<Shape>::iterator it = shapes.begin();

  /*
	it->draw();
	it++;
	it->draw();
	it++;
	it->draw();
  */

	while (it != shapes.end()) {
		it->draw();
    it++;
	}
}
