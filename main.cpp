#include <iostream>
#include <vector>
#include <string>
#include <map>

class CDCAccount()
{
	std::unordered_map<std::string, double> account_balance;

	public:
	void update_balance(std::string key, double value)
	{
		account_balance[key] = value;
	}
	void print_balance()
	{	
		for (auto const& [key, value]: account_balance){
			std::cout << key << ":\t" 
				  << value << "\n";
	}
};

struct Currency()
{
};



int main()
{
	int selection;
	bool condition {false};
	while(!condition){  // wait on user input before closing program
		std::cout << "Please enter a command:\n"
			<< "1: Check Balance\n"
			<< "2: Check Investment\n"
			<< "3: \n";
		std::cin >> selection;
		switch (selection){
			case 1:
				account.print_balance();
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				std::cout << "Input not recognised\n";
				break;
	}

	return 0;
}
