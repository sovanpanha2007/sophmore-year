#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>   
using namespace std;
class Solution{
public:
    // To check if the token is numeric or a number
    bool isNumber(std::string s) {
        for (char c : s) 
            if (!isdigit(c)) return false;
        return true; 
    }


    bool areNumAscending(std::string s){
        // your code here ...
        stringstream ss(s);
        string token;
        vector<int> numbers;
        int count = 0;
        //To extract numeric tokens from string
        while(ss >> token) { //read one token at a time(return trure if token is read and return no if it not), it seperated by space  
            if (isNumber(token)) {
                numbers.push_back(stoi(token)); 
                count++;
            }
        }
        for (int i =0; i < count-1; i++) {
            if (numbers[i] >= numbers[i+1]) {
                return false;
            }
        }
        return true;
    }
};