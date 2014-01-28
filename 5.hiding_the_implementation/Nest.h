#include <string>

using namespace std;

class Nest {
	string name;
public:
	Nest();
	friend class Hen;
	class Hen {
		Nest *pNest;
		string name;
	public:
		Hen(Nest *);
		friend class Egg;
		class Egg {
			Hen *pHen;
			string name;
		public:
			Egg(Hen *);
			void display();
		};
		void display();
	};
	void display();
};

