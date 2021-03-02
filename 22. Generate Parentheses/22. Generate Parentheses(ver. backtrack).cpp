#include<iostream>
#include<stack>
#include<vector>
#include<tuple>

using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string current;
        unsigned int num_left, num_right;
        stack<tuple<string, unsigned int, unsigned int>> st;
        st.push(tuple<string, unsigned int, unsigned int>("", 0, 0));
        while(!st.empty()){
            // current = st.top().first;
            // balance = st.top().second;
            std::tie(current, num_left, num_right) = st.top();
            st.pop();
            if(current.length() < (unsigned int)2*n){
                if(num_left < (unsigned int) n)
                    st.push(tuple<string, unsigned int, unsigned int>(current + "(", num_left + 1, num_right));
                if(num_left > num_right)
                    st.push(tuple<string, unsigned int, unsigned int>(current + ")", num_left, num_right + 1));
            }
            else if(current.length() == (unsigned int)2*n){
                ans.push_back(current);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> ans = s.generateParenthesis(5);
    for(string str : ans)
        cout << str << endl;
    cout << ans.size() << endl;

    getchar();
    return 0;
}