#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "CDCAccount.h"


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
