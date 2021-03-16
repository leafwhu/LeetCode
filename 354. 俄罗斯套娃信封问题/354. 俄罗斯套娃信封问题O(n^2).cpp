#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    	int seq_len = envelopes.size();
    	sort(envelopes.begin(), envelopes.end(), [](const auto& vec1, const auto& vec2){
			// put envelope with wider front of envelope with smaller width of the same height
			if(vec1[0] < vec2[0] || vec1[0] == vec2[0] && vec1[1] > vec2[1])
				return true;
			else
				return false;
		});
		vector<int> layers(seq_len, 1);
		for(int i = 0; i < seq_len; i++){
			for(int j = 0; j < i; j++){
				if(envelopes[i][1] > envelopes[j][1]){
					layers[i] = max(layers[j] + 1, layers[i]);
				}
			}
		}
		for (int i = 0; i < seq_len; i++)
			cout << layers[i] << ' ';
		cout << endl;
        return *max_element(layers.begin(), layers.end());
    }
};


int main(){
	Solution *s = new Solution;
	vector<vector<int>> envelopes;
	// vector<vector<int>> envelopes{vector<int>{1, 1}, vector<int>{1, 1}, vector<int>{1, 1}};
	vector<vector<int>> envelopes{vector<int>{5, 4}, vector<int>{6, 4}, vector<int>{6, 7}, vector<int>{2, 3}};
	cout << s->maxEnvelopes(envelopes) << endl;
    return 0;
}