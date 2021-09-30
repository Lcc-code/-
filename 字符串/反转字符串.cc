// 151. 翻转字符串里的单词
// 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

// 请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

// 说明：

// 输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
// 翻转后单词间应当仅用一个空格分隔。
// 翻转后的字符串中不应包含额外的空格。
 

// 示例 1：

// 输入：s = "the sky is blue"
// 输出："blue is sky the"
// 示例 2：

// 输入：s = "  hello world  "
// 输出："world hello"
// 解释：输入字符串可以在前面或者后面包含多余的空格，但是翻转后的字符不能包括。

class Solution {
public:
    string reverseWords(string s) {
        removeExtraSpaces(s);// 去掉空格
        reverse(s, 0, s.size() - 1); // 全部反转
        int start = 0; // 反转单词起始位置
        int end = 0; // 反转单词终止位置
        bool entry = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (!entry)
            {
                start = i;
                entry = true;
            }
            // if (entry && s[i] == ' ' && s[i - 1] != ' ')
            if (entry && s[i] == ' ')
            {
                end = i - 1;
                entry = false;
                reverse(s, start, end);
            }
            if (entry && (i == (s.size() - 1)) && s[i] != ' ')
            {
                end = i;
                entry = false;
                reverse(s, start, end);

            }
        }
        return s;

    }
private:
    void removeExtraSpaces(string& s)
    {
        int slowIndex = 0, faseIndex = 0;
        while (s.size() > 0 && faseIndex < s.size() 
                && s[faseIndex] == ' ')
        { faseIndex++; }
        for (; faseIndex < s.size(); faseIndex++)
        {
            if (faseIndex - 1 > 0 &&
                s[faseIndex - 1] == s[faseIndex] &&
                s[faseIndex] == ' ')
            { continue; }
            else { s[slowIndex++] = s[faseIndex]; }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { s.resize(slowIndex - 1); }
        else { s.resize(slowIndex); } 
    }
    void reverse(string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
           swap(s[i], s[j]);
        }
    }
};