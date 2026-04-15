#include "PhoneBook.hpp"


int main()
{	
	PhoneBook PhoneBook;
	std::string cmd;
	while(1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT)";
		if(!std::getline(std::cin, cmd))
			break;
		if(cmd == "ADD")
			PhoneBook.add_contact();
		else if(cmd == "SEARCH") 
			PhoneBook.search_contact();
		else if(cmd == "EXIT")
			break;
	}
	return 0;
}