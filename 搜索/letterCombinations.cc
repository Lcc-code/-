// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    vector<string> result;
    string s;
    void backtracking(const string &digits, int index)
    {
        if (index == digits.length())
        {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string leeters = letterMap[digit];
        for (int i = 0; i < leeters.size(); i++)
        {
            s.push_back(leeters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0)
        {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }

private:
    const string letterMap[10] = {
        "", //0
        "", // 1
        "abc", //2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", //7
        "tuv", // 8
        "wxyz", //9
    };


};