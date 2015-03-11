#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	Shape() { cout << "Shape()" << endl; }
	virtual ~Shape() { cout << "~Shape()" << endl; }
	virtual void draw() {};
};

//void Shape::draw() const { cout << "Shape::draw()" << endl; }

class Circle : public Shape {
public:
	Circle() { cout << "Circle()" << endl; }
	virtual ~Circle() { cout << "~Circle()" << endl; }
	virtual void draw() const { cout << "Circle" << endl; }
};

class Square : public Shape {
public:
	virtual ~Square() { cout << "~Square()" << endl; }
	virtual void draw() const { cout << "Square" << endl; }
};

class Triangle : public Shape {
public:
	virtual ~Triangle() { cout << "~Triangle()" << endl; }
	virtual void draw() const { cout << "Triangle" << endl; }
};

void foo(Shape sh)
{
	cout << "foo()" << endl;
}

int main()
{

	Circle c;

	foo(c);

	/*
	Shape *A[] = { new Circle, new Square, new Triangle };

	for (int i = 0; i < sizeof A / sizeof *A; i++) {
		A[i]->draw();
		delete A[i];
	}
	*/

}
