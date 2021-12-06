/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Pramukh Nadig
 * Date        : 09/25/2021
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

bool is_all_lowercase(const string &s) {
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] < 'a' || s[i] > 'z'){
            return false;
        }
    }
    return true;
}

bool all_unique_letters(const string &s) {
    unsigned int vector = 0;
    unsigned int setter;
    size_t len = s.length();
    for(size_t i = 0; i < len; i++){
        setter = 1 << (s[i]-'a');
        if((vector&setter)!=0){
            return false;
        }
        vector = vector | setter;
    }
    return true;
}

int main(int argc, char * const argv[]) {
    if(argc != 2){
        cerr << "Usage: ./unique <string>";
        return 1;
    }

    string s;
    istringstream iss;

    iss.str(argv[1]);
    if (!(iss >> s))
    {
        cerr << "Error: Value argument must be a string.";
        return 1;
    }

    if(!is_all_lowercase(s)){
        cerr << "Error: String must contain only lowercase letters.";
        return -1;
    }
    iss.clear();

    if(all_unique_letters(s)){
        cout << "All letters are unique.";
    }else{
        cout << "Duplicate letters found.";
    }
    return 0;
}
