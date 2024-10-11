#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end());

        int last_chair = 0; // use this chair when none is vacant
        priority_queue<int, vector<int>, greater<int>> vacant; // keep track of vacant chairs, smallest always on top
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> leaveTime; // [leaving, chair_occupied], smallest leaving time on top

        for (int i = 0;; i++) {
            // Clear up vacant chairs
            while (!leaveTime.empty() && leaveTime.top()[0] <= times[i][0]) { // clear chairs smaller or equal to arrival time
                vacant.push(leaveTime.top()[1]);
                leaveTime.pop();
            }

            // Friend sits
            if (vacant.empty()) {
                if (times[i][0] == targetArrival) return last_chair;
                leaveTime.push(vector<int>({ times[i][1], last_chair }));
                last_chair++;
            }
            else {
                if (times[i][0] == targetArrival) return vacant.top();
                leaveTime.push(vector<int>({ times[i][1], vacant.top() }));
                vacant.pop();
            }
        }

        return -1;
    }
};

void main() {
    Solution Sol;
    vector<vector<int>> times({ {1, 4} ,{2, 3},{4, 6} });
    int targetFriend = 1;
    Sol.smallestChair(times, targetFriend);
}
