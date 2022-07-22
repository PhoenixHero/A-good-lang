#include <iostream>
#include <string>
#include <map>
#include <fstream>

std::map<std::string, double> ints;
std::map<std::string, std::string> strings;
std::map < std::string, bool> bools;

void createvar(std::string line)
{
	std::string name = line, val = line;
	name.erase(name.find_first_of(' '), name.size());
	val.erase(0, name.find_first_of(' ') + 1);


}

void parse(std::string filep)
{
	std::string ln, temp;
	std::ifstream file(filep);
	while (file.is_open())
	{
		while (std::getline(file, ln))
		{
			temp = ln; 
			ln.erase(ln.find_first_of(' '), ln.size());
			temp.erase(0, ln.find_first_of(' ') + 1);
			if (ln == "var")
			{
				createvar(temp);
			}
		}
		file.close();
	}
}


int main()
{
	parse("main.cb");
}