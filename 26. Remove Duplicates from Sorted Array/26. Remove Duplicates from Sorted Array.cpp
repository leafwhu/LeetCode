#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int tmp = nums[0];
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++){
            if(*it == tmp){
                nums.erase(it--);
            }
            else{
                tmp = *it;
            }
        }
        return nums.size();
    }
};

int main(){
    Solution s;
    int x[] = {1, 1, 2};
    vector<int> vec(x, x + sizeof(x)/sizeof(x[0]));
    s.removeDuplicates(vec);
    for(auto x : vec)
        cout << x << endl;
    return 1;
}