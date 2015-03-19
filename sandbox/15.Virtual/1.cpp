#include <iostream>

#define _dc(Obj) \
	Obj() { std::cout << #Obj"::"#Obj"()" << std::endl; }

#define _df(Obj, fname) \
	void fname() const { std::cout << #Obj"::"#fname"()" << std::endl; }


class Shape {
public:
	_dc(Shape);
	virtual void draw() const = 0;
};

class Circle : public Shape {
public:
	_dc(Circle);
	_df(Circle, draw);
};

class Square : public Shape {
public:
	_dc(Square);
	_df(Square, draw);
};

class Triangle : public Shape {
public:
	_dc(Triangle);
	_df(Triangle, draw);
};

int main()
{
	Shape *S[] = { new Circle, new Square, new Triangle };

	S[0]->draw();
	S[1]->draw();
	S[2]->draw();
}
