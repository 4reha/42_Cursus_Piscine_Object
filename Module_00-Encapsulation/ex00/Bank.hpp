#pragma once
#include <iostream>
#include <map>

class Bank
{

public:
	class Account
	{
	private:
		static int lastId;

		int id;
		int balance;
		int debt_value;

		Account();
		~Account();

	public:
		const int &getId() const;
		const int &getBalance() const;
		const int &getDebtValue() const;

		friend class Bank;
	};

	class AccountNotFoundException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NotEnoughLiquidityException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NotEnoughBalanceException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class AccountHasUnpaidLoanException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NoDebtFoundException : public std::exception
	{
	public:
		const char *what() const throw();
	};

public:
	Bank();
	Bank(const int &p_liquidity);
	~Bank();

	const int &getLiquidity() const;

	void setLiquidity(const int &p_liquidity);

	Account *createAccount();
	void DeleteAccount(int account_id);

	void makeDeposit(int account_id, int p_amount);
	void transferMoney(int p_from, int p_to, int p_amount);

	void giveLoan(int account_id, int p_amount);
	void payLoan(int account_id, int p_amount);

	Account *operator[](int account_id) const;

	friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
	friend std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account);

private:
	int liquidity;
	int loanInterestRate;
	std::map<int, Account *> clientAccounts;
};