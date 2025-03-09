/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

#include <vector>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        array<int, 3> CurBillArr = {0};

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                CurBillArr[0]++;
            }
            else if(bills[i] == 10)
            {
                if (CurBillArr[0] > 0)
                {
                    CurBillArr[0]--;
                    CurBillArr[1]++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (CurBillArr[1] > 0 && CurBillArr[0] > 0)
                {
                    CurBillArr[0]--;
                    CurBillArr[1]--;
                    CurBillArr[2]++;
                }
                else if (CurBillArr[0] >= 3)
                {
                    CurBillArr[0] -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

