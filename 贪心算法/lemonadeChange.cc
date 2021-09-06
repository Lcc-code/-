// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

// 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

// 注意，一开始你手头没有任何零钱。

// 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/lemonade-change
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() == 0)
            return 1;
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five ++;
            } else if (bills[i] == 10)
            {
                if (five != 0)
                {
                    five --;
                    ten ++;
                } else
                {
                    return false;
                }
            } else if (bills[i] == 20)
            {
                if (five == 0)
                    return false;
                else if (five != 0 && ten != 0)
                {
                    five--; ten --;
                } else if (ten == 0 && five >= 3)
                {
                    five -= 3;
                } else if (ten == 0 && five < 3)
                {
                    return false;
                }
            }

        }
        return true;
    }
};