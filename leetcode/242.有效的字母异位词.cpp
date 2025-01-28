/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <string>
#include <unordered_map>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     unordered_map<char, int> Map;
    //     for (auto c : s)
    //     {
    //         if (Map.find(c) == Map.end())
    //         {
    //             Map.insert({c, 1});
    //         }
    //         else
    //         {
    //             Map[c] += 1;
    //         }
    //     }
    //     for (auto c : t)
    //     {
    //         if (Map.find(c) == Map.end())
    //         {
    //             return false;
    //         }
    //         else
    //         {
    //             if (--Map[c] == 0)
    //             {
    //                 Map.erase(c);
    //             }
    //         } 
    //     }

    //     return Map.empty();
    // }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        
        array<int, 26> Map = {0};
        for (auto c : s)
        {
            Map[c - 'a']++;
        }
        for (auto c : t)
        {
            Map[c - 'a']--;
        }
        for (auto Count : Map)
        {
            if (Count != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

