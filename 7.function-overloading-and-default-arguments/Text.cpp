#include <iostream>
#include <fstream>
#include <string>

#include <require.h>

using namespace std;

class Text {
	string text;
public:
	Text(char *filename = "Text.cpp");
	void contents();
};

Text::Text(char *filename)
{
	ifstream file(filename);
	assure(file, filename);

	string line;
	while (getline(file, line)) {
		text.append(line);
		text.push_back('\n');
	}
}

void Text::contents()
{
	cout << text;
}

int main()
{
	Text text;

	text.contents();
}
