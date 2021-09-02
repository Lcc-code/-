/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

*/
class Solution {
public:
    int mySqrt(int x) {
        int index = -1;
        int l = 0, r = x;
        while (l <= r)
        {
            double mid = l + (r - l)/2;
            if (mid * mid <= x)
            {
                index = mid;
                l = mid + 1;
            } else
            {
                r = mid - 1;
            }
        }
        return index;        
    }
};