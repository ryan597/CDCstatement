#include <string>
#include <vector>
#include <unordered_map>
#include "transaction.h"


std::string split_line(std::string line);
std::vector<Transaction> process_csv(std::string file_path);


class CDCAccount
{
private:
    std::unordered_map<std::string, double> account_balance{};
    std::unordered_map<std::string, double> earn_balance{};
    double fiat_balance{};
    double supercharger_balance{};

public:
    void process_transactions(std::vector<Transaction> transactions);
    void process_statement(std::string file_path);
    void deposit(Transaction transaction);
    void purchase(Transaction transaction);
    void top_up_card(Transaction transaction);
    void cashback(Transaction transaction);
    void earn_reward(Transaction transaction);
    void stake_reward(Transaction transaction);
    void stake_reimbursement(Transaction transaction);
    void supercharger_reward(Transaction transaction);
    void supercharger_deposit(Transaction transaction);
    void supercharger_withdraw(Transaction transaction);
    void update_balance(std::string key, double value);
    void print_balance();
};