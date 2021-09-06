// 给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

// 如果不能形成任何面积不为零的三角形，返回 0

#include "lemonadeChange.cc"

class Solution1 {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), less<int>());
        for (int i = nums.size() - 1; i >= 2; i--)
        {
            if (nums[i - 1] + nums[i - 2] > nums[i])
                return nums[i - 1] + nums[i - 2] + nums[i];
        }

        return 0;
    }
}