#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


class Solution {
public:
	const int MAX_ITEM = 1e7 + 1;

	struct Interval {
		int start, end;
		Interval(vector<int> &interv) {
			start = interv[0];
			end = interv[1];
		}
		bool operator == (Interval& rhs) {
			return (start == rhs.start && end == rhs.end);
		}
	};

	struct compInterval {
		bool operator() (Interval& lhs, Interval& rhs) {
			return (lhs.end - lhs.start > rhs.end - rhs.start); // > such that minimum of pq is in front
		}
	};

	struct QueryIndex {
		int query, index;
		bool operator < (QueryIndex& rhs) {
			return query < rhs.query;
		}
	};

	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	
		vector<int> ans(queries.size(), -1);

		// sort intervals
		sort(intervals.begin(), intervals.end());
		intervals.push_back({ MAX_ITEM, MAX_ITEM });

		priority_queue<Interval, vector<Interval>, compInterval> pq; // cur intervals that covers cur query, sorted ascending by length of query

		// sort queries while keeping track of the original index
		vector<QueryIndex> qi(queries.size());
		for (int i = 0; i < qi.size(); i++) {
			qi[i] = QueryIndex{ queries[i], i };
		}
		sort(qi.begin(), qi.end());

		int interval_in = 0;
		int query_in = 0;
		
		// cur interval: interval on top of pq
		// next interval: next interval in the intervals array
		for (int i = 0; i < qi.size(); i++) {

			// remove intervals that are out of range
			while (!pq.empty() && pq.top().end < qi[i].query)
				pq.pop();

			// add all intervals that can cover cur query

			// consider all intervals that begins before cur query
			while (qi[i].query >= intervals[interval_in][0]) {
				// only add them if the interval end after cur query. consider: (5,6) with query 7
				if (intervals[interval_in][1] >= qi[i].query)
					pq.push(Interval(intervals[interval_in]));
				interval_in++;
			}

			// pq.top() is optimal interval for current query
			int opt_len = !pq.empty() ? pq.top().end - pq.top().start + 1 : -1;
			ans[qi[i].index] = opt_len;
		}

		return ans;
	}
};

void main() {
	Solution S;
	vector<vector<int>> intervals{ {2,3},{2,5},{1,8},{20,25} };
	vector<int> queries{ 0, 2,19,5,22 };
	S.minInterval(intervals, queries);
	return;
}