#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool password_checker(const std::string& password)
{
    boost::regex pattern("^(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[*#+@])(?!.*\\s).{4,6}$");
    return boost::regex_match(password, pattern);
}

int main()
{
    std::string input;
    std::vector<std::string> password_list;

    cout << "Enter a password or multiple passwords separated by commas.\n";
    cout << "Here: ";
    getline(cin, input);

    std::stringstream ss(input);
    std::string password;
    while (getline(ss, password, ','))
    {
        password.erase(0, password.find_first_not_of(' '));
        password.erase(password.find_last_not_of(' ') + 1);
        password_list.push_back(password);
    }

    for (const auto& password : password_list)
    {
        if (password_checker(password))
        {
            std::cout << password << " ";
        }
    }

    return 0;
}
