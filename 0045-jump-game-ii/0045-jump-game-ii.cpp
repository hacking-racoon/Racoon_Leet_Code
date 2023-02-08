#define m1in(a, b) (a) > (b) ? (b) : (a)
#include <iostream>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<unsigned int>DP(nums.size(), 654321);
        DP[0] = 0;
        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            
            for(unsigned int j = 0; ((i + j < nums.size()) && (j <= nums[i])); ++j)
            {
                DP[i+j] = m1in(DP[i] + 1, DP[i+j]);

            }
        }
        return DP[nums.size()-1];
    }
};