// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/3sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // a + b + c = 0;
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                    right --;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left ++;
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right --;
                    while (right > left && nums[left] == nums[left + 1])
                        left ++;

                    // 找到答案，收缩双指针
                    right --;
                    left ++;
                }    
                

            }
        }
        return result;
    }

};