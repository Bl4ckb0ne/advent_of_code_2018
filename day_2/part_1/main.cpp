#include <fstream>
#include <iostream>
#include <string_view>
#include <map>
#include <algorithm>

std::pair<bool, bool> checksum(const std::string_view sv)
{
	std::map<char, int> frequencies;
	std::for_each(std::begin(sv), std::end(sv),
			[&frequencies](const char c)
	{
		frequencies[c]++;
	});

	for (auto it: frequencies)
	{
		std::cout << it.first << " " << it.second << '\n';
	}
	std::cout << '\n';

	bool has_two = false;
	bool has_three = false;

	for(const auto &it : frequencies)
	{
		if (has_two && has_three)
		{
			break;
		}

		if (!has_two && it.second == 2)
		{
			has_two = true;
		}

		if (!has_three && it.second == 3)
		{
			has_three = true;
		}
	}

	return std::make_pair(has_two, has_three);
}

int main()
{
	std::ifstream file;
	file.open("input");

	int twos{}, threes{};

	std::string line;
	while (file >> line)
	{
		const auto [two, three] = checksum(line);
		if (two)
		{
			twos++;
		}

		if (three)
		{
			threes++;
		}
	}

	std::cout << "total is " << twos * threes << '\n';

	file.close();

	return 0;
}

