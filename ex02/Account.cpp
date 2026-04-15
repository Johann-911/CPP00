#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account:: _totalNbWithdrawals = 0;

int Account::getNbAccounts(void) 
{
	return _nbAccounts;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" <<_nbAccounts
			  << ";total:" << _totalAmount
			  << "; deposits: " << _totalNbDeposits
			  << ";withdrawls: " << _totalNbWithdrawals
			  << std::endl;
}


void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	std::cout << "["
			  << (now->tm_year + 1900)
			  <<std:: setw(2) << std::setfill('0') << (now->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << (now->tm_mday)
			  << "_0"
			  << std::setw(2) << std::setfill('0') << now->tm_hour
			  << std::setw(2) << std::setfill('0') << now->tm_min
			  << std::setw(2) << std::setfill('0') << now->tm_sec
			  << "]";
	std::cout << std::setfill(' ');
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" <<_accountIndex
			  << ";ammount:" << _amount
			  << ";created:" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amoount:" << _amount
			  << ";closed:" <<  std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << "p_amount" << _amount;
	_amount+= deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawl)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  <<";p_+amount" << _amount;

	if(withdrawl > _amount)
	{
		std::cout << ";withdrawl:refused" << std::endl;
		return false;
	}
	_amount -= withdrawl;
	_nbWithdrawals++;
	_totalAmount -= withdrawl;
	_totalNbWithdrawals++;

	std::cout << "withfrawl:" << withdrawl
			  << ";amount" << _amount
			  << ";_nbwithdrawls:" << _nbWithdrawals
			  << std::endl;
	return true;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposit:" <<_nbDeposits
			  << ";withdrawls" << _nbWithdrawals
			  << std::endl;
}

int Account::checkAmount(void)const
{
	return _amount;
}