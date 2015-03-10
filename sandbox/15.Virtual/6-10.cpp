#include <iostream>
#include <vector>

using namespace std;

class RodentMouse {
public:
	virtual ~RodentMouse() { cout << "~RodentMouse()" << endl; }
	virtual void feed() const = 0;
};

void RodentMouse::feed() const { cout << "RodentMouse::feed()" << endl; }

class Gerbil : public RodentMouse {
public:
	~Gerbil() { cout << "~Gerbil()" << endl; }
	void feed() const { cout << "Gerbil::feed()" << endl; }
};

class Hamster : public RodentMouse {
public:
	~Hamster() { cout << "~Hamster()" << endl; }
	void feed() const { cout << "Hamster::feed()" << endl; }
};

class BlueHamster : public Hamster {
public:
	~BlueHamster() { cout << "~BlueHamster()" << endl; }
	void feed() const { cout << "BlueHamster::feed()" << endl; }
};

class Cage {
	vector<RodentMouse *> rodents;
public:
	Cage(vector<RodentMouse *> &_rodents) : rodents(_rodents) {}
	~Cage();
	void feed() const;
};

Cage::~Cage() {
	for (int i = 0; i < rodents.size(); i++) {
		delete rodents[i];
	}
}

void Cage::feed() const {
	for (int i = 0; i < rodents.size(); i++) {
		rodents[i]->feed();
	}
}

int main() {
	vector<RodentMouse *> rodents { new Gerbil, new Hamster, new BlueHamster };
	Cage c(rodents);

	c.feed();
}
