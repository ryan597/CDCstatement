#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "CDCAccount.h"

std::string split_line(std::string line);
std::vector<Transaction> process_csv(std::string file_path);


void CDCAccount::process_transactions(std::vector<Transaction> transactions)
{
    for (Transaction transaction : transactions){
        // identify the kind, then call appropriate function
        /* kinds:
            * viban_deposit, viban_purchase, viban_card_top_up, card_top_up
            * mco_stake_reward, crypto_exchange, dust_conversion_credited, dust_conversion_debited
            * referral_card_cashback, reimbursement, card_cashback_reverted, exchange_to_crypto_transfer
            * crypto_earn_interest_paid, crypto_earn_program_created, crypto_earn_program_withdrawn
            * supercharger_reward_to_app_credited, supercharger_deposit, recurring_buy_order
        */
        std::unordered_map<std::string, int> lookup_kind({
            {"viban_deposit", 1},  // add to balance
            {"viban_purchase", 2}, // subtract balance
            {"", 3},
            {"viban_card_top_up", 4}  // card
        });
        int kind = lookup_kind[transaction.kind];
        switch (kind){
            case 1:
            deposit(transaction.amount);
        }
    }
}
void CDCAccount::process_statement(std::string file_path)
{
    std::vector<Transaction> transactions = process_csv(file_path);
    process_transactions(transactions);
}
void CDCAccount::deposit(double amount)
{
    fiat_balance += amount;
    std::cout << fiat_balance << '\n';
}
void CDCAccount::purchase(){}
void CDCAccount::top_up_card(){}
void CDCAccount::cashback(){}
void CDCAccount::earn_reward(){}
void CDCAccount::stake_reward(){}
void CDCAccount::stake_reimbursement(){}
void CDCAccount::supercharger_reward(){}
void CDCAccount::supercharger_deposit(){}
void CDCAccount::supercharger_withdraw(){}
void CDCAccount::update_balance(std::string key, double value)
{
    account_balance[key] = value;
}
void CDCAccount::print_balance()
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


std::string split_line(std::string line)
{
    // Replace spaces with '_'
    std::replace(line.begin(), line.end(), ' ', '_');
    // Replace ',' with spaces, spaces are easy to split the input with >> later
    std::replace(line.begin(), line.end(), ',', ' ');
    return line;
}

std::vector<Transaction> process_csv(std::string file_path)
{
    std::string line;
    std::string value;
    std::string colname;
    std::ifstream csvfile(file_path);
    std::vector<Transaction> transactions;

    if (!csvfile.is_open())
        std::cout << "Could not open CSV file\n";

    Transaction transaction;
    int index {0};
    while(std::getline(csvfile, line)){
        line = split_line(line);
        std::stringstream ss(line);
        transactions.push_back(transaction);

        ss >> transactions[index].timestamp;
        ss >> transactions[index].description;
        ss >> transactions[index].currency;
        ss >> transactions[index].amount;
        ss >> transactions[index].to_currency;
        ss >> transactions[index].to_amount;
        ss >> transactions[index].native_currency;
        ss >> transactions[index].native_value;
        ss >> transactions[index].dollar_value;
        ss >> transactions[index].kind;
        index++;
    }
    csvfile.close();
    return transactions;
}