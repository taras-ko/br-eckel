#include <iostream>

class PrnConn {
	static int prn_fd;
public:
	PrnConn(int fd = 0) {
		if (is_free())
			prn_fd = fd;
		else
			std::cout << "Warning: printer already assigned to fd: "
				<< prn_fd << std::endl;
	}
	bool is_free() const { return prn_fd == 0; }
};

int PrnConn::prn_fd = 0;

int main()
{
	PrnConn con1(1);
	PrnConn con2(2);
}
