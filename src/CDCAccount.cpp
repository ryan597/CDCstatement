#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "CDCAccount.h"


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
            {"", 3},  // transfer funds from _ to _
            {"viban_card_top_up", 4}  // card
        });
        int kind = lookup_kind[transaction.kind];
        switch (kind){
            case 1:
                deposit(transaction);
                break;
            case 2:
                purchase(transaction);
                break;
            case 3:
                break;
            case 4:
                top_up_card(transaction);
                break;
            default:
                std::cout << "Transaction not recognised: " << transaction.kind;
                break;
        }
    }
}


void CDCAccount::process_statement(std::string file_path)
{
    std::vector<Transaction> transactions = process_csv(file_path);
    std::cout << "Description \tAmount \t\n"
              << "=====================================\n";
    process_transactions(transactions);
    std::cout << "=====================================\n\n";
}


void CDCAccount::deposit(Transaction transaction)
{
    fiat_balance += transaction.amount;
    std::cout << fiat_balance << '\n';
}


void CDCAccount::purchase(Transaction transaction)
{
    fiat_balance -= transaction.amount;
    std::cout << fiat_balance << '\n';
}


void CDCAccount::top_up_card(Transaction transaction){}


void CDCAccount::cashback(Transaction transaction){}


void CDCAccount::earn_reward(Transaction transaction){}


void CDCAccount::stake_reward(Transaction transaction){}


void CDCAccount::stake_reimbursement(Transaction transaction){}


void CDCAccount::supercharger_reward(Transaction transaction){}


void CDCAccount::supercharger_deposit(Transaction transaction){}


void CDCAccount::supercharger_withdraw(Transaction transaction){}


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
    std::ifstream csvfile("statements/" + file_path + ".csv");
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