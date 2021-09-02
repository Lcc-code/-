/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() < k)
            return -1;
        int sum = 0;
        
        
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        double max = sum;
        for (int i = k; i < nums.size(); i++)
        {
            sum = sum - nums[i - k] + nums[i];
            max =  sum > max ? sum : max;
        }
        return max / k;
        

    }
};