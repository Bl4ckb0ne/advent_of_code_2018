#include <fstream>
#include <iostream>

int main()
{
	int sum = 0;

	std::ifstream file;
	file.open("input");
	
	std::string line;
	while (file >> line)
	{
		const char front = line.front();

		int value = std::stoi(std::string(std::begin(line) + 1, std::end(line)));

		if (front == '+')
		{
			sum = sum + value;
		}
		else if (front == '-')
		{
			sum = sum - value;
		}
	}

	file.close();

	std::cout << "total is " << sum << '\n';

	return 0;
}
