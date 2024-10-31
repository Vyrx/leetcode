#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int r_len; int f_len;
    const long long max_cap = LLONG_MAX - 2e9; // max distance between robot and factory is 2e9

    // r = cur robot, f = cur factory
    long long helper(int r, int f, vector<int>& robot, vector<int> &unpacked_factory, vector<vector<long long>> &dp) {
        if (f < r) return max_cap;
        if (r < 0) return 0;
        if (dp[r][f] != -1) return dp[r][f];

        // either ignore f th factory or put the r th robot into f th factory
        return dp[r][f] = min(helper(r, f - 1, robot, unpacked_factory, dp), helper(r - 1, f - 1, robot, unpacked_factory, dp) + abs((long long)robot[r] - unpacked_factory[f]));
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        r_len = robot.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> unpacked_factory; // convert into factories with capacity 1, fac with multiple capacities get pushed multiple times
        for (auto it : factory) {
            for (int i = 0; i < it[1]; i++) {
                unpacked_factory.push_back(it[0]);
            }
        }

        f_len = unpacked_factory.size();

        // dp[r][f] = minimum distance to put 0 ~ rth robots into 0 ~ fth factories
        vector<vector<long long>> dp(r_len, vector<long long>(f_len, -1)); 
        
        // init condition: when  num of available robot == num of available factory
        // robot 0 goes to factory 0, ... , robot i goes to factory i

        dp[0][0] = abs((long long)robot[0] - unpacked_factory[0]);
        for (int i = 1; i < r_len; i++)
            dp[i][i] = dp[i - 1][i - 1] + abs((long long)robot[i] - unpacked_factory[i]);

        helper(r_len - 1, f_len - 1, robot, unpacked_factory, dp);
        return helper(r_len - 1, f_len - 1, robot, unpacked_factory, dp);

    }
};

void main() {
    Solution S;
    vector<int> robot = { 726554621,-235727278,-199823369 };
    vector<vector<int>> factory = {{612684362, 1}, {519972143, 1}, {759430060, 2}, {-76130291, 1}, {547454631, 2}, {47263647, 2}, {-79806151, 2}, {-329855292, 0}, {-954058831, 3}};

    cout << S.minimumTotalDistance(robot, factory);

}