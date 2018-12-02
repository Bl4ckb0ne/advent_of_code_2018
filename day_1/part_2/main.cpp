#include <fstream>
#include <iostream>
#include <set>

int main()
{
	int sum = 0;
	std::set<int> frequencies;
	frequencies.insert(sum);

	std::ifstream file;
	file.open("input");
	
	std::string line;
	while (true)
	{
		if (!(file >> line))
		{
			file.clear();
			file.seekg(std::ios::beg);
			file >> line;
		}

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

		if (frequencies.insert(sum).second == false)
		{
			break;
		}
	}

	file.close();

	std::cout << "total is " << sum << '\n';

	return 0;
}
