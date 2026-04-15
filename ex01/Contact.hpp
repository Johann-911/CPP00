#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <stdexcept>

class Contact 
{
	private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

	public:
	void setFirstName(const std::string str);
	void setLastName(const std::string str);
	void setNickName(const std::string str);
	void setDarkestSecret(const std::string str);
	int setPhoneNumber(const std::string str);
	std::string getFirstName()const;
	std::string getLastName()const;
	std::string getNickName()const;
	std::string getDarkestSecret() const;
	std::string getPhoneNumber() const;
};

#endif



