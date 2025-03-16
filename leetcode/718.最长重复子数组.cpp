// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem718.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // int findLength(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     vector<vector<int>> dp(n, vector<int>(m, 0));
    //     int result = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (nums1[i] == nums2[0])
    //         {
    //             dp[i][0] = 1;
    //             result = 1;
    //         }
    //     }
        
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (nums1[0] == nums2[j])
    //         {
    //             dp[0][j] = 1;
    //             result = 1;
    //         }
    //     }
        
    //     for (int i = 1; i < n; i++)
    //     {
    //         for (int j = 1; j < m; j++)
    //         {
    //             if (nums1[i] == nums2[j])
    //             {
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             }
    //             result = max(result, dp[i][j]);
    //         }
    //     }
        
    //     return result;
    // }

    // int findLength(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //     int result = 0;        
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= m; j++)
    //         {
    //             if (nums1[i - 1] == nums2[j - 1])
    //             {
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             }
    //             result = max(result, dp[i][j]);
    //         }
    //     }
        
    //     return result;
    // }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m + 1, 0);
        int result = 0;        
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                }
                else
                {
                    dp[j] = 0;
                }
                result = max(result, dp[j]);
            }
        }
        
        return result;
    }
};
// @lc code=end

