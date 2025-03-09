// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> set(wordDict.begin(), wordDict.end());
    //     vector<bool> dp(s.size() + 1, false);
    //     dp[0] = true;
    //     for (int i = 0; i <= s.size(); i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             string sub_str = s.substr(j, i - j);
    //             if (set.find(sub_str) != set.end() && dp[j])
    //             {
    //                 dp[i] = true;
    //             }
    //         }
    //     }
    //     return dp[s.size()];
    // }


    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        for(int i = 1;i <= s.size(); i++)
        {
            for(int j = 0;j < wordDict.size(); j++)
            {
                if(wordDict[j].size() <= i)
                {
                    string tmp = s.substr(i - wordDict[j].size(), wordDict[j].size());   
                    dp[i] = (dp[i-wordDict[j].size()] && wordDict[j] == tmp) || dp[i];   
                }
            }
        }      
        return dp[s.size()];
    }
};
// @lc code=end

