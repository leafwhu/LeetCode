#include<cstdio>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Automation{
	string state = "start";
	unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

public:
	int get_string(string str){
		// LeetCode don't allow overflow
		long long int ans = 0;
		int sign = 1;
		for (int i = 0; i < str.length(); i++){
			if(str[i] <= '9' && str[i] >= '0'){
				state = table[state][2];
			}
			else if(str[i] == '+'){
				state = table[state][1];
			}
			else if(str[i] == '-'){
				state = table[state][1];
			}
			else if(str[i] == ' '){
				state = table[state][0];
			}
			else{
				state = table[state][3];
			}
		
			if(state == "in_number"){
				if(sign*ans > 214748364 || sign*ans == 214748364 && str[i] - '0' > 7)
					return (1 << 31) - 1;
				else if(sign*ans < -214748364 || sign*ans == -214748364 && str[i] - '0' > 8)
					return -1 << 31;
				else
					ans = ans * 10 + str[i] - '0';
			}
			else if(state == "signed" && str[i] == '-'){
				sign = -1;
			}
		}
		return sign * ans;
	}
};

class Solution {
public:
    int myAtoi(string s) {
        Automation a;
	    return a.get_string(s);
    }
};

int main()
{
	Solution s;
	cout << s.myAtoi("21474836460");
	return 0;
}