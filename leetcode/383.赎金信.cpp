/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include <string>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        
        array<int, 26> CharArr{};
        for (auto Char : magazine)
        {
            CharArr[Char - 'a']++;
        }
        for (auto Char : ransomNote)
        {
            int& Count = CharArr[Char - 'a'];
            if (Count == 0)
            {
                return false;
            }
            else
            {
                Count--;
            }
        }
        return true;
    }
};
// @lc code=end

