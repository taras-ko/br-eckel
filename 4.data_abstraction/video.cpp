#include <iostream>
#include <string>

#include <Stack.h>
#include <require.h>

using namespace std;

class Video {
	string title;
public:
	void print_title();
};

void Video::print_title()
{
	cout << title << endl;
}

int main(int argc, char *argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);

	Stack videos;
	videos.initialize();
	string title;

	while(getline(in, title))
		videos.push(new string(title));

	Video *pvideo;

	while ((pvideo = (Video *) videos.pop()) != 0) {
		pvideo->print_title();
		delete pvideo;
	}

	videos.cleanup();
}
