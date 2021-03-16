#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution{
    bool Valid(string str){
        int balance = 0;
        for(auto x:str){
            switch(x){
                case '(':
                    balance += 1;
                    break;
                case ')':
                    balance--;
                    break;
            }
            if(balance < 0)
                return false;
        }
        if(balance == 0)
            return true;
        else
            return false;
    }
public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string current;
        stack<string> st;
        st.push("");
        while(!st.empty()){
            current = st.top();
            st.pop();
            if(current.length() < (unsigned int)2*n){
                st.push(current + "(");
                st.push(current + ")");
            }
            else if(current.length() == (unsigned int)2*n){
                if(Valid(current)){
                    ans.push_back(current);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> ans = s.generateParenthesis(4);
    for(string str : ans)
        cout << str << endl;
    cout << ans.size() << endl;

    getchar();
    return 0;
}