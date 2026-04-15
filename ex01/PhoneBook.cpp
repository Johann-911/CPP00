#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    size = 0;
    index = 0;
}

void PhoneBook::add_contact()
{
	std::string input;
	int ret;

	std::cout << "Enter first Name: " << std::endl;
	std::getline(std::cin, input);
	contacts[index].setFirstName(input);
	std::cout << "Enter last name: " << std::endl;
	std::getline(std::cin, input);
	contacts[index].setLastName(input);
	std::cout << "Enter nick name: " << std::endl;
	std::getline(std::cin, input);
	contacts[index].setNickName(input);
	std::cout << " And now enter your darkest secret: " << std::endl;
	std::getline(std::cin, input);
	contacts[index].setDarkestSecret(input);
	while(1)
	{
		std::cout << "Enter your phone Number: " << std::endl;
		std::getline(std::cin, input);
		ret = contacts[index].setPhoneNumber(input);
		if(ret == 0)
			break;
		std::cout << "Invalid Phone Number, try again." << std::endl;
	}
	if(size < 8)
		size++;
	index = (index + 1) % 8;
	
}

void PhoneBook::search_contact()
{
	if(size == 0)
	{
		std::cout << " Phonebook is empty" << std::endl;
		return;
	}
	auto format = [](const std::string &s)
	{
		if(s.length() > 10)
			return s.substr(0, 9) + ".";
		return s;
	};
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;
	for(int i = 0;i < size; i++)
	{
		std::string firsName = format(contacts[i].getFirstName());
		std::string lastName = format(contacts[i].getLastName());
		std::string nickName = format(contacts[i].getNickName());
		std::cout << std::setw(10) << (i + 1) << "|" 
				  << std::setw(10) << firsName << "|"
				  << std::setw(10) << lastName << "|"
				  << std::setw(10) << nickName << std::endl;
	}
	std::string input;
	std::cout << "enter index to view details: ";
	if(!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "no index entered" << std::endl;
		return;
	}
	int index;
	try
	{
		size_t pos = 0;
		index = std::stoi(input, &pos);
		if(pos != input.size())
			throw std::invalid_argument("bad");	
		
	}
	catch(...)
	{
		std::cout << "Invalid Index" << std::endl;
		return;
	}
	if(index < 1 || index > size)
	{
		std::cout << "index out of range" << std::endl;
		return ;
	}
	int j = index - 1;
	std::cout << "First Name: " << contacts[j].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[j].getLastName() << std::endl;
	std::cout << "Nick Name: " << contacts[j].getNickName() << std::endl;
	std::cout << "Darkest Secret: " << contacts[j].getDarkestSecret()<< std::endl;
	std::cout << "Phone Number: " << contacts[j].getPhoneNumber() << std::endl;
}