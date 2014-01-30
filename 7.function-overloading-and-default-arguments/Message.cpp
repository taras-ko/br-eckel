#include <iostream>
#include <string>

using namespace std;

class Message {
	string message;
public:
	Message(char *);
	void print(char *str = "");
};

Message::Message(char *msg) {
	message.append(msg);
};

void Message::print(char *s)
{
	cout << message << s << endl;
}

int main()
{
	Message msg("Hello");

	msg.print();
	msg.print(" World!");
}
