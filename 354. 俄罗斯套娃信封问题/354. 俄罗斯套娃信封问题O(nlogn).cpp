#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
private:
    static bool envelope_less(vector<vector<int>> vec1, vector<int> vec2){
        for (vector<int> tmp_vec1 : vec1){
            if(tmp_vec1[0] < vec2[0] && tmp_vec1[1] < vec2[1]){
                return true;
            }
        }
        return false;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // dp[i] is the smallest outmost envelope of i-layers Russian doll
        int seq_len = envelopes.size();
        if(seq_len == 0)
            return 0;
        int max_len = 1;
        vector<vector<int>> smallest_out_envelope;

        // 排序非常重要，注意第二维度是反向排序的
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
            if(e1[0] < e2[0] || e1[0] == e2[0] && e1[1] > e2[1])
                return true;
            else
                return false;
        });
        smallest_out_envelope.push_back(vector<int>{envelopes[0]});

        /* debug
        cout << "envelopes:\n";
        for(int i = 0; i < seq_len; i++){
            cout << envelopes[i][0] << ", " << envelopes[i][1] << endl;
        }
        */

        for(int i = 1; i < seq_len; i++){
            if(envelopes[i][1] > smallest_out_envelope[max_len-1][1]){
                smallest_out_envelope.push_back(envelopes[i]);
                max_len++;
            }
            else{
                auto it = lower_bound(smallest_out_envelope.begin(), smallest_out_envelope.end(), envelopes[i], [](const auto& e1, const auto& e2){
                    if(e1[0] < e2[0] && e1[1] < e2[1])
                        return true;
                    else
                        return false;
                });
                *it = envelopes[i];
            }
        }


        /* debug
        cout << "dp vector:\n";
        for(auto tmp_envelope : smallest_out_envelope){
            cout << "[" << tmp_envelope[0] << ", " << tmp_envelope[1] << "] ";
        }
        cout << endl;
        */
        
        cout << "ans: " << max_len << endl;
        return max_len;
    }
};

int main(){
    // vector<vector<int>> envelopes{vector<int>{1, 1}, vector<int>{1, 1}, vector<int>{1, 1}};
    // vector<vector<int>> envelopes{vector<int>{5, 4}, vector<int>{6, 4}, vector<int>{6, 7}, vector<int>{2, 3}};
    // vector<vector<int>> envelopes{vector<int>{30, 50}, vector<int>{12, 2}, vector<int>{3, 4}, vector<int>{12, 15}};
    vector<vector<int>> envelopes{vector<int>{2, 100}, vector<int>{3, 200}, vector<int>{4, 300}, vector<int>{5, 500}, vector<int>{5, 400}, vector<int>{5, 250}, vector<int>{6, 370}, vector<int>{6, 360}, vector<int>{7, 380}};
    Solution *s = new Solution();
    s->maxEnvelopes(envelopes);
    return 0;
}
