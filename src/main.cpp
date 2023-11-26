#include "Aria/aria.h"


#include <iostream>
int main(int argc, char* argv[])
{

	 Aria s = Aria();
	 s.setup();
	 s.run();
	 int a;
	 for (int i = 0; i < 10; i++)
	 {
		 std::cin >> a;
		 std::cout << "Thanks for the protein sir: " << a << std::endl;
	 }
	return 0;
}


