# include<cstdio>
# include<iostream>
# include<string>
# include<stack>

using namespace std;

class Solution{
public:
	bool isPair(char a, char b){
		if(a == '(' && b == ')' || a == ')' && b == '(')
			return true;
		if(a == '[' && b == ']' || a == ']' && b == '[')
			return true;
		if(a == '{' && b == '}' || a == '}' && b == '{')
			return true;
		return false;
	}
	
	bool isValid(string s){
		stack<char> st;
		for(char tmpChar:s){
			switch(tmpChar){
				case '(':
				case '[':
				case '{':
					st.push(tmpChar);
					break;	
				case ')'	:
				case ']'	:
				case '}'	:
					if(st.size() == 0)
						return false;
					else if(isPair(st.top(), tmpChar)){
						st.pop();
						continue;
					}
					else
						return false;
			}
		}
		if(st.size() == 0)
			return true;
		else
			return false;
	}
};

int main(){
	string s = "()[]{]";
	Solution so;
	cout << so.isValid(s);
	return 0;
}
