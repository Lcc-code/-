using namespace std;
#include <vector>
#include <set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;

        std::set<int> Set;
        int max = 1;
        for (const auto num : nums)
        {
            Set.insert(num);
        }
        int i = 0;
        while (!Set.empty())
        {
            int count = 1;
            int tmp = nums[i] - 1;
            while(Set.find(tmp) != Set.end())
            {
                count++;
                Set.erase(tmp);
                tmp --;
            }
            
            tmp = nums[i] + 1;
            while (Set.find(tmp) != Set.end())
            {
                Set.erase(tmp);
                count ++;
                tmp ++;
            }
            i++;
            max = std::max(count, max);
            if (i >= nums.size())
                return max;
            
        }
        return max;

    }
};