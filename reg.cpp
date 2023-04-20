#include <iostream>
#include <string>
#include <regex>
using namespace std;
bool recognize_string(string str) {
    regex pattern("^[a]*bb[a]*$");
    return regex_match(str, pattern);
}
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if (recognize_string(str)) {
        cout << "The string is in the language." << endl;
    } else {
        cout << "The string is not in the language." << endl;
    }
    return 0;
}
