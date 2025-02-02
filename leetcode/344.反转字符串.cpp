/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // void reverseString(vector<char>& s) {
    //     int Left = 0;
    //     int Right = s.size() - 1;
    //     while (Left < Right)
    //     {
    //         char Temp = s[Left];
    //         s[Left] = s[Right];
    //         s[Right] = Temp;
    //         Left++;
    //         Right--;
    //     }
    // }

    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
        
    }
};
// @lc code=end

