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

void Shape::draw() const { std::cout << "Shape::draw()" << std::endl;}

class Circle : public Shape {
public:
  _dc(Circle);
  _df(Circle, draw);
};

class DerivedCircle : public Circle {
public:
  _dc(DerivedCircle);
  _df(DerivedCircle, draw);
};

class Square : public Shape {
public:
  _dc(Square);
  _df(Square, draw);
};

class Triangle : public Shape {
public:
  _dc(Triangle);
  void draw() const {
    Shape::draw(); //use defined pure virtual function
    std::cout << "Triangle::draw()" << std::endl;
  }
};

void foo(Circle& circle)
{
  circle.draw();
}

int main()
{
  /*
  Shape *S[] = { new Circle, new Square, new Triangle };

  S[0]->draw();
  S[1]->draw();
  S[2]->draw();
  */

  DerivedCircle dcircle;

  foo(dcircle);
}
