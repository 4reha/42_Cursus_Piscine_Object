#include <iostream>
#include "Bank.hpp"

int main()
{

	//  Create a bank
	Bank cih = Bank(20000);

	//  Create 2 accounts
	Bank::Account *accountA = cih.createAccount();
	Bank::Account *accountB = cih.createAccount();

	//  Deposit N on each account
	try
	{
		cih.makeDeposit(accountA->getId(), 100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		cih.makeDeposit(accountB->getId(), 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		//  Transfer 50 from account B to account A
		cih.transferMoney(accountB->getId(), accountA->getId(), 100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//  Display the bank
	std::cout << cih << std::endl;

	//  Delete account A
	try
	{
		cih.DeleteAccount(accountA->getId());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//  Display the bank
	std::cout << cih << std::endl;

	// give loan to account B
	try
	{
		cih.giveLoan(accountB->getId(), 100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// try to delete account B, with unpaid loan
		cih.DeleteAccount(accountB->getId());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// create account C
	Bank::Account *accountC = cih.createAccount();

	try
	{
		cih.makeDeposit(accountC->getId(), 1000);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// transfer money from account C to account B
		cih.transferMoney(accountC->getId(), accountB->getId(), accountB->getDebtValue());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// pay debt from account B
		cih.payLoan(accountB->getId(), accountB->getDebtValue());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// try to delete account B, after paying his debt
		cih.DeleteAccount(accountB->getId());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//  Display the bank
	std::cout << cih << std::endl;

	return (0);
}