#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

std::string Contact::getNickName() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

void Contact::setFirstName(const std::string str)
{
	this->firstName = str;
}

void Contact::setLastName(const std::string str)
{
	this->lastName = str;
}

void Contact::setDarkestSecret(const std::string str)
{
	this->darkestSecret = str;
}

void Contact::setNickName(const std::string str)
{
	this->nickname = str;
}

int Contact::setPhoneNumber(const std::string str)
{	
	size_t i = 0;
	if(str[i] == '+')
		i++;
	for(;i<str.length();i++)
	{
		if(!isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return -1;
	}
	this->phoneNumber = str;
	return 0;
}