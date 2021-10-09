#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>


class CDCAccount
{
private:
    std::unordered_map<std::string, double> account_balance{};
    std::unordered_map<std::string, double> earn_balance{};
    double fiat_balance{};
    double supercharger_balance{};

public:
    Statement statement;
    void process_statement(std::string file_path)
    {
        std::vector<std::pair<std::string, std::vector<std::string>>> transactions = read_csv(file_path);

    }
    void deposit(){}
    void purchase(){}
    void top_up_card(){}
    void cashback(){}
    void earn_reward(){}
    void stake_reward(){}
    void stake_reimbursement(){}
    void supercharger_reward(){}
    void supercharger_deposit(){}
    void supercharger_withdraw(){}
    void update_balance(std::string key, double value)
    {
        account_balance[key] = value;
    }
    void print_balance()
    {
        std::cout << "-------------------------------------"
                  << "Account Balance: \nCurrency: \tValue";
        for (auto const& [key, value]: account_balance){
            std::cout << key << ":\t"
                  << value << "\n";
        }
        std::cout << "-------------------------------------"
                  << "Earn Balance: \nCurrency: \tValue";

    }
};

/*
struct Transaction
{
    std::string timestamp;
    std::string description;
    std::string currency;
    double amount;
    std::string to_currency;
    double to_amount;
    std::string native_currency;
    double native_value;
    double dollar_value;
    std::string kind;
};
*/

struct Statement
{
    std::string file_name;
    int length;
    //std::vector<Transaction> transactions;
};


std::vector<std::pair<std::string, std::vector<std::string>>> read_csv(std::string file_path)
{
    std::string line;
    std::string value;
    std::string colname;
    std::ifstream csvfile(file_path);
    // Each column gets stored as a pair of its name and all its values
    std::vector<std::pair<std::string, std::vector<std::string>>> transactions;

    if (!csvfile.is_open())
        std::cout << "Could not open CSV file\n";

    if (csvfile.good()){
        std::getline(csvfile, line);
        std::stringstream ss(line);
        while(std::getline(ss, colname, ',')){
            transactions.push_back({colname, std::vector<std::string>{}});
        }
    }

    while(std::getline(csvfile, line)){
        std::stringstream ss(line);
        int colindex = 0;
        while(ss >> value){
            transactions.at(colindex).second.push_back(value);
            colindex++;
        }
    }
    csvfile.close();
    return transactions;
}

Statement process_transactions()
{
    Statement statement;
    return statement;
}


int main(int argc, char* argv[])
{
    std::string csv_path;
    if (argc == 1){
        std::cout << "Please enter the path to a Crypto.com csv statement\n";
        std::cin >> csv_path;
    }
    else
        csv_path = argv[1];

    int selection;
    bool condition {false};

    CDCAccount account;
    account.process_statement(csv_path);

    while(!condition){  // wait on user input before closing program
        std::cout << "Please enter a command:\n"
            << "1: Check Balance\n"
            << "2: Check Investment\n"
            << "3: New Statement\n"
            << "4: Exit\n";
        std::cin >> selection;
        switch (selection){
            case 1:
                account.print_balance();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                condition = true;
                break;
            default:
                std::cout << "Input not recognised\n";
                break;
        }
    }
    return 0;
}
