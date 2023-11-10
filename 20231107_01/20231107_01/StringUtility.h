#pragma once
#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> Split(std::string text, char delimiterChar)
{
	auto chars = text.c_str();
	int i = 0;
	int j = 0;
	std::vector<std::string> rv;
	while (chars[i] != '\0')
	{
		j = 0;
		char buffer[1024]{};
		while (chars[i] != delimiterChar&& chars[i] != '\0')
		{
			buffer[j] = chars[i];
			i++;
			j++;
		}
		i++;
		buffer[j] = '\0';
		if (strlen(buffer) != 0)
		{
			rv.push_back(std::string(buffer));
		}
	}
	return rv;
}