
// >= --std=c++17

#include <iostream>
#include <vector>
#include <string>
#include <any>


using namespace std;

int main()
{

    vector<any> v;

    v.push_back(10);
    v.push_back(10.5);
    v.push_back("10");
    v.push_back(true);
    v.push_back(std::pair<int, int>(1, 2));
    for (auto &item : v) {
        if (item.type() == typeid(int)) {
            int value = std::any_cast<int>(item);
            cout << "int: " << value << endl;
            continue;
        }
        if (item.type() == typeid(double)) {
            double value = std::any_cast<double>(item);
            cout << "double: " << value << endl;
            continue;
        }
        if (item.type() == typeid(std::string)) {
            string value = std::any_cast<std::string>(item);
            cout << "string: " << value << endl;
            continue;
        }
        if (item.type() == typeid(char *)) {
            char *value = std::any_cast<char *>(item);
            cout << "char *: " << value << endl;
            continue;
        }
        if (item.type() == typeid(const char *)) {
            const char *value = std::any_cast<const char *>(item);
            cout << "const char *: " << value << endl;
            continue;
        }
        if (item.type() == typeid(bool)) {
            bool value = std::any_cast<bool>(item);
            cout << "bool: " << value << endl;
            continue;
        }
        if (item.type() == typeid(pair<int, int>)) {
            pair<int, int> value = std::any_cast<pair<int, int>>(item);
            cout << "pair: " << value.first << ", " << value.second << endl;
            continue;
        }
    }

}
