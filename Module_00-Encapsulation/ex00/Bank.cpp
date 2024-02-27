#include "Bank.hpp"

// ACCOUNT CLASS
int Bank::Account::lastId = 0;

Bank::Account::Account() : id(Account::lastId++), balance(0), debt_value(0)
{
	std::cout << "Account " << this->id << " opened" << std::endl;
}

Bank::Account::~Account()
{
	std::cout << "Account " << this->id << " closed" << std::endl;
}

const int &Bank::Account::getId() const
{
	return (this->id);
}

const int &Bank::Account::getBalance() const
{
	return (this->balance);
}

const int &Bank::Account::getDebtValue() const
{
	return (this->debt_value);
}

std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account)
{
	p_os << "Account informations : " << std::endl;
	p_os << "  |- Id : " << p_account.getId() << std::endl;
	p_os << "  |- Balance : " << p_account.getBalance() << std::endl;
	p_os << "  |- Debt value : " << p_account.getDebtValue() << std::endl;
	return (p_os);
}

// EXCEPTIONS

const char *Bank::AccountNotFoundException::what() const throw()
{
	return ("Account not found");
}

const char *Bank::NotEnoughLiquidityException::what() const throw()
{
	return ("Not enough liquidity");
}

const char *Bank::NotEnoughBalanceException::what() const throw()
{
	return ("Account does not have enough balance");
}

const char *Bank::AccountHasUnpaidLoanException::what() const throw()
{
	return ("Account has unpaid loan");
}

const char *Bank::NoDebtFoundException::what() const throw()
{
	return ("No debt found");
}

// BANK CLASS

Bank::Bank() : liquidity(0)
{
	this->loanInterestRate = 10;
	std::cout << "Bank created" << std::endl;
}

Bank::Bank(const int &p_liquidity) : liquidity(p_liquidity)
{
	this->loanInterestRate = 10;
	std::cout << "Bank created" << std::endl;
}

Bank::~Bank()
{
	for (std::map<int, Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); ++it)
		delete it->second;

	std::cout << "Bank destroyed" << std::endl;
}

const int &Bank::getLiquidity() const
{
	return (this->liquidity);
}

void Bank::setLiquidity(const int &p_liquidity)
{
	this->liquidity = p_liquidity;
}

Bank::Account *Bank::createAccount()
{
	Account *newAccount = new Account();
	this->clientAccounts.insert(std::pair<int, Account *>(newAccount->getId(), newAccount));
	return (newAccount);
}

void Bank::DeleteAccount(int account_id)
{
	Account *account = (*this)[account_id];

	if (account->getDebtValue() > 0)
		throw Bank::AccountHasUnpaidLoanException();

	delete this->clientAccounts[account_id];
	this->clientAccounts.erase(account_id);
}

void Bank::makeDeposit(int account_id, int p_amount)
{
	if ((*this)[account_id])
	{
		this->clientAccounts[account_id]->balance = (this->clientAccounts[account_id]->getBalance() + p_amount * 0.95);
		this->liquidity += p_amount * 0.05;
	}
}

void Bank::transferMoney(int p_from, int p_to, int p_amount)
{
	if ((*this)[p_from] && (*this)[p_to])
	{
		if (this->clientAccounts[p_from]->getBalance() < p_amount)
			throw Bank::NotEnoughBalanceException();
		this->clientAccounts[p_from]->balance -= p_amount;
		this->clientAccounts[p_to]->balance += p_amount;
	}
}

void Bank::giveLoan(int account_id, int p_amount)
{
	if ((*this)[account_id])
	{
		if (this->clientAccounts[account_id]->getDebtValue() > 0)
			throw Bank::AccountHasUnpaidLoanException();

		if (this->liquidity < p_amount)
		{
			throw Bank::NotEnoughLiquidityException();
		}
		this->clientAccounts[account_id]->balance += p_amount;
		this->clientAccounts[account_id]->debt_value += (p_amount + (p_amount * this->loanInterestRate / 100));
		this->liquidity += p_amount;
	}
}

void Bank::payLoan(int account_id, int p_amount)
{
	if ((*this)[account_id])
	{
		if (this->clientAccounts[account_id]->getDebtValue() < 0)
			throw Bank::NoDebtFoundException();
		if (this->clientAccounts[account_id]->getBalance() < this->clientAccounts[account_id]->getDebtValue())
			throw Bank::NotEnoughBalanceException();
		this->clientAccounts[account_id]->balance -= p_amount;
		this->clientAccounts[account_id]->debt_value -= p_amount;
		this->liquidity += p_amount;
	}
}

Bank::Account *Bank::operator[](int account_id) const
{
	std::map<int, Bank::Account *>::const_iterator iter = this->clientAccounts.find(account_id);
	if (iter == this->clientAccounts.end())
		throw Bank::AccountNotFoundException();
	return (iter->second);
}

std::ostream &
operator<<(std::ostream &p_os, const Bank &p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "|- Liquidity : " << p_bank.getLiquidity() << std::endl;
	p_os << "|- Accounts : " << std::endl;
	for (std::map<int, Bank::Account *>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
	{
		p_os << "  |--- " << *(it->second) << std::endl;
	}
	return (p_os);
}
