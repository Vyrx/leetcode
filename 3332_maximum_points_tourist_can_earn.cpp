#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	int dp[201][201]; // city, day

	int recur(int city, int day, int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
		if (dp[city][day] != -1) return dp[city][day];
		if (day == k) {
			return 0;
		}


		// choose to stay
		int score = stayScore[day][city] + recur(city, day + 1, n, k, stayScore, travelScore);

		// move to each neighbors
		for (int i = 0; i < n; i++) {
			if (i == city) continue;

			score = max(score, travelScore[city][i] + recur(i, day + 1, n, k, stayScore, travelScore));
		}

		return dp[city][day] = score;
	}

	int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		memset(dp, -1, sizeof(dp));
		int score = 0;
		for (int i = 0; i < n; i++) {
			score = max(score, recur(i, 0, n, k, stayScore, travelScore)); // start from city i on day 0
		}

		return score;
	}
};
