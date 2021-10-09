#include <string>
#include <vector>
#include <unordered_map>
#include "transaction.h"


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
    void deposit(double amount);
    void purchase();
    void top_up_card();
    void cashback();
    void earn_reward();
    void stake_reward();
    void stake_reimbursement();
    void supercharger_reward();
    void supercharger_deposit();
    void supercharger_withdraw();
    void update_balance(std::string key, double value);
    void print_balance();
};