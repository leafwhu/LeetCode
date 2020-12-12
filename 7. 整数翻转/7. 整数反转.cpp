#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while(x != 0)
        {
        	if(y > INT_MAX / 10 || y == INT_MAX / 10 && (x%10) > 7 )
        		return 0;
        	if(y < INT_MIN/10 || y == INT_MIN / 10 && (x%10) < -8)
        		return 0;
            y *= 10;
            y += (x%10);
            x /= 10;
        }
        return y;
    }
    
    int sign(int x)
    {
    	if(x > 0)
    		return 1;
    	else if(x < 0)
    		return -1;
    	else if(x == 0)
    		return 0;
	}
};


int main()
{
//	printf("%d\n", INT_MIN);
	
	Solution s;
	printf("%d", s.reverse(2147483642));
	return 0;
}