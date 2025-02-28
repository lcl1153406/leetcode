/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:

    unordered_map<string, map<string, int>> TicketMap;
    vector<string> Path;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& Ticket : tickets)
        {
            TicketMap[Ticket[0]][Ticket[1]]++;
        }
        Path.push_back("JFK");
        BackTracking(tickets.size());
        return Path;
    }

    bool BackTracking(int TicketNum)
    {
        if (TicketNum + 1 == Path.size())
        {
            return true;
        }
        for (auto& [End, Count]: TicketMap[Path.back()])
        {
            if (Count == 0)
            {
                continue;
            }
            Path.push_back(End);
            Count--;
            bool bFlag = BackTracking(TicketNum);
            if (bFlag)
            {
                return true;
            }
            
            Count++;
            Path.pop_back();
        }
        return false;
    }
};
// @lc code=end

