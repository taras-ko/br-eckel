#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	virtual ~Shape() { cout << "~Shape()" << endl; }
	virtual void draw() const = 0;
};

class Circle : public Shape {
public:
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

int main()
{

	Shape *A[] = { new Circle, new Square, new Triangle };

	for (int i = 0; i < sizeof A / sizeof *A; i++) {
		A[i]->draw();
		delete A[i];
	}

}
