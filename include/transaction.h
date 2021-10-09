#include <string>

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