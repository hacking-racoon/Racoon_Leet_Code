#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>& leftRunningSum = nums;
        vector<int> rightRunningSum(nums);
        
        for (int i = 1; i < nums.size(); ++i)
            leftRunningSum[i] += leftRunningSum[i-1];
        
        for (int i = nums.size()-2; i>=0; --i)
            rightRunningSum[i] += rightRunningSum[i+1];
        
        int leftSum, rightSum, ret;
        for (ret = 0; ret < nums.size(); ++ret)
        {
            if (ret == 0) leftSum = 0;
            else leftSum = leftRunningSum[ret-1];
            
            if (ret == nums.size()-1) rightSum = 0;
            else rightSum = rightRunningSum[ret+1];
            
            cout << leftSum << ' ' << rightSum << endl;

            if (leftSum == rightSum) break;
            
        }
        
        return (leftSum == rightSum ? ret : -1 );
    }
};