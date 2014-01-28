#include <iostream>

#include <Stash.h>
#include <Stack.h>

#include "Nest.h"

Nest::Nest(): name("Nest") {};
Nest::Hen::Hen(Nest *pNest): pNest(pNest), name("Hen") {};
Nest::Hen::Egg::Egg(Hen *pHen): pHen(pHen), name("Egg") {};

void Nest::display()
{
	cout << name << endl;
}

void Nest::Hen::display()
{
	cout << name << " -> " <<
		pNest->name << endl;
}

void Nest::Hen::Egg::display()
{
	cout <<
		name << " -> " <<
		pHen->name << " -> " <<
		pHen->pNest->name << endl;

}

int main()
{
	Stash henStash;
	Nest nest;
	Nest::Hen hen1(&nest), hen2(&nest), hen3(&nest);

	henStash.initialize(sizeof(Nest::Hen));

	henStash.add(&hen1);
	henStash.add(&hen2);
	henStash.add(&hen3);

	for (int i = 0; i < henStash.count(); i++)
		((Nest::Hen *) henStash.fetch(i))->display();

	henStash.cleanup();

	Stack henStack;

	henStack.initialize();

	henStack.push(&hen1);
	henStack.push(&hen2);
	henStack.push(&hen3);

	Nest::Hen *pHen;
	while ((pHen = (Nest::Hen *) henStack.pop()) != 0)
		pHen->display();

	henStack.cleanup();
}
