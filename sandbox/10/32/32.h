#include <iostream>
#include <string>

class Mirror {
	Mirror *pmirror;
	bool flag;
	static int cnt;
public:
	Mirror(const std::string& label) : flag(true), pmirror(0) {
		cnt++;
		echo(label + " Mirror::Mirror()");
	}
	Mirror(Mirror *_pmirror, const std::string& label)
		: pmirror(_pmirror), flag(false) {
		cnt++;
		echo(label + " Mirror::Mirror(Mirror *)");
	}
	bool test() const {
		return (pmirror != 0) ? pmirror->test() : flag;
	}
	void echo(const std::string& obj = "noobj") const {
		std::cout << obj << " - " << cnt << std::endl;
	}
};
