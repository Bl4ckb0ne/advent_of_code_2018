#include <fstream>
#include <iostream>
#include <string_view>
#include <map>
#include <algorithm>
#include <vector>

int diff(const std::string_view s1, const std::string_view s2)
{
	std::string_view::const_iterator it1 = std::begin(s1);
	std::string_view::const_iterator it2 = std::begin(s2);

	int total = 0;
	while (it1 != std::end(s1) && it2 != std::end(s2))
	{
		if (*it1 != *it2)
		{
			total++;
		}

		it1++;
		it2++;
	}

	return total;
}

int main()
{
	std::ifstream file;
	file.open("input");

	std::vector<std::string> inputs;

	std::string line;
	while (file >> line)
	{
		inputs.push_back(line);
	}

	std::string id1 = inputs.front();
	std::string id2 = inputs.front();
	int best_diff = 9999999;
	for (std::vector<std::string>::const_iterator it1 = std::begin(inputs);
			it1 != std::end(inputs); ++it1)
	{
		for (std::vector<std::string>::const_iterator it2 =
				std::begin(inputs); it2 != std::end(inputs); ++it2)
		{
			if (*it1 == *it2)
			{
				continue;
			}

			int d = diff(*it1, *it2);

			if (d < best_diff)
			{
				best_diff = d;
				id1 = *it1;
				id2 = *it2;
			}
		}
	}

	std::string str_diff = "";
	std::string::const_iterator it1 = std::begin(id1);
	std::string::const_iterator it2 = std::begin(id2);

	while (it1 != std::end(id1) && it2 != std::end(id2))
	{
		if (*it1 == *it2)
		{
			str_diff += *it2;
		}
		it1++;
		it2++;
	}
	std::cout << str_diff << '\n';

	file.close();

	return 0;
}

