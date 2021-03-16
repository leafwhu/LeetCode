#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
        	return 0;
        vector<int> d(length, 1);
        vector<int> count(length, 0);
        

        // d[i] = max(d[j]+1) for 0 <= j < i and nums[j] < nums[i]
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    d[i] = max(d[j] + 1, d[i]);
            }
        }
        
        
        // count[i] = sum(count[j]) for 0 <= j < i and d[j] + 1 == d[i] and nums[j] < nums[i]
        for(int i = 0; i < length; i++)
        	if (d[i] == 1)
        		count[i] = 1;
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if(nums[j] < nums[i] && d[j] + 1 == d[i])
                    count[i] += count[j];
            }
        }

		cout << "d: ";
		for (int i = 0; i < length; i++)
			cout << d[i] << ' ';
		cout << endl;
		cout << "count: ";
		for (int i = 0; i < length; i++)
			cout << count[i] << ' ';	
		cout << endl;
		
		// sum the count of LIS of the same length
		int ans = 0;
		int LIS_len = *max_element(d.begin(), d.end());
		for(int i = 0; i < length; i++)
			if(d[i] == LIS_len)
				ans += count[i];
        return ans;
    }
};

int main(){
//    vector<int> nums{1,2,4,3,5,4,7,2};
	vector<int> nums{3, 1, 2};
    Solution *s = new Solution();
    cout << s->findNumberOfLIS(nums);
    return 0;
}