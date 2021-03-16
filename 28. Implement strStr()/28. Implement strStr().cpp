#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> next;

    void get_next(string needle){
        int j = 0;
        next.push_back(0);
        for (unsigned int i = 1; i < needle.length(); i++){
            while(j > 0 && needle[j] != needle[i]){
                j = next[j-1];
            }
            if(needle[i] == needle[j]){
                j++;
            }
            next.push_back(j);
        }
    }

public:
    int strStr(string haystack, string needle) {
        get_next(needle);
        // for(auto x : next)
            // cout << x << ' ';
        // cout << endl;

        int ans = 0;
        int pp = 0, tp = 0;
        while(pp < needle.length() && tp < haystack.length()){
            if(haystack[tp] == needle[pp]){
                pp++;
                tp++;
            }
            else{
                if(pp == 0){
                    tp++;
                }
                else
                    pp = next[pp - 1];
                ans = tp - pp;
            }
        }
        if(pp == needle.length()){
            return ans;
        }
        else
            return -1;
    }

    int strStr1(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1]; // 这里要找j前一位的对应的回退位置了
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("hello", "ll");
    return 0;
}