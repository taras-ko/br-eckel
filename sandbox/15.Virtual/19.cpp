class Base {
public:
  virtual void __fun__() const {};
};
/*
class Derived : public Base {
public:
  virtual void __fun__() const {};
};

void foo(Base& b)
{
  b.__fun__();
}
*/
int main()
{
 Base b;

 b.__fun__();
 // foo(d);
}
