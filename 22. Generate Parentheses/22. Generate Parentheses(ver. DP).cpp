# include<cstdio>
# include<iostream>
# include<vector>
# include<set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> Parenthesis;
        vector<string> tmp;
        tmp.push_back("");
        Parenthesis.push_back(tmp);
        tmp.clear();
        tmp.push_back("()");
        Parenthesis.push_back(tmp);
        for (int i = 2; i <= n; i++)
        {
            tmp.clear();

            for (int j = 0; j <= i - 1; j++)
            {
                /*
                for (vector<string>::iterator it1 = Parenthesis[j].begin(); it1 != Parenthesis[j].end(); it1++){
                    for (vector<string>::iterator it2 = Parenthesis[i - j - 1].begin(); it2 != Parenthesis[i - j - 1].end(); it2++){
                        tmp.push_back("(" + *it1 + ")" + *it2);
                    }
                }
                */
                for (auto left : Parenthesis[j]){
                    for (auto right : Parenthesis[i - j - 1]){
                        tmp.push_back("(" + left + ")" + right);
                    }
                }   
            }
            Parenthesis.push_back(tmp);
        }
        vector<string> ans = Parenthesis.back();
        set<string> ans_set(ans.begin(), ans.end());
        ans.assign(ans_set.begin(), ans_set.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.generateParenthesis(5);
    for (vector<string>::iterator it = ans.begin(); it != ans.end(); ++it){
        cout << *it << ',';
    }
    cout << endl << ans.size();
    getchar();
    return 0;
}