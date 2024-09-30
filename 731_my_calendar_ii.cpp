#include<iostream>
#include<vector>
#include<string>

using namespace std;

class MyCalendarTwo {
public:

	vector<vector<int>> single_book; //front included, back not
	vector<vector<int>> double_book;

	MyCalendarTwo() {
	}

	int binarySearch(vector<vector<int>>& list, int start, int end, int low, int high) {
		while (low <= high) {
			int mid = (low + high) / 2;
			if (start == list[mid][0] && end == list[mid][1])
				return mid + 1;
			else if (start > list[mid][0] || (start == list[mid][0] && end > list[mid][1]))
				low = mid + 1;
			else
				high = mid - 1;
		}
		return low;
	}


	bool book(int start, int end) {

		if (single_book.size() == 0) {
			single_book.push_back(vector<int>({ start,end }));
			return true;
		}
		else {
			int loc_single = binarySearch(single_book, start, end, 0, single_book.size() - 1);
			// Don't insert yet, check for conflict

			int temp_loc_double, temp_start_conflict, temp_end_conflict;
			bool doubleInsertFront = false;

			// Check front
			if (loc_single > 0 && start < single_book[loc_single - 1][1]) {

				int start_conflict = start, end_conflict; 
				// Check for cases where the interval is contained within another interval
				if (end < single_book[loc_single - 1][1])
					end_conflict = end; // If interval is contained in another interval, end is also included
				else
					end_conflict = single_book[loc_single - 1][1];


				if (double_book.size() == 0) {
					double_book.push_back(vector<int>({ start_conflict, end_conflict }));
				}

				else {
					int loc_double = binarySearch(double_book, start_conflict, end_conflict, 0, double_book.size() - 1);

					// If there's conflict in front or back, dont insert
					if ((loc_double > 0 && start_conflict < double_book[loc_double - 1][1]) || (loc_double < double_book.size() && end_conflict > double_book[loc_double][0]))
						return false;

					// Don't insert yet, check if back is safe
					doubleInsertFront = true;
					temp_loc_double = loc_double;
					temp_start_conflict = start_conflict;
					temp_end_conflict = end_conflict;

				}
			}

			// Check back
			if (loc_single < single_book.size() && end >  single_book[loc_single][0]) {

				int start_conflict = single_book[loc_single][0], end_conflict;
				// Check for cases where the interval is contained within another interval
				if (end > single_book[loc_single][1])
					end_conflict = single_book[loc_single][1]; // If interval is contained in another interval, end is also included
				else
					end_conflict = end;

				if (double_book.size() == 0) {
					double_book.push_back(vector<int>({ start_conflict, end_conflict }));
				}

				else {
					int loc_double = binarySearch(double_book, start_conflict, end_conflict, 0, double_book.size() - 1);

					// If there's conflict in front or back, dont insert
					if ((loc_double > 0 && start_conflict < double_book[loc_double - 1][1]) || (loc_double < double_book.size() && end_conflict > double_book[loc_double][0]))
						return false;

					double_book.insert(double_book.begin() + loc_double, vector<int>({ start_conflict,end_conflict }));
				}
			}
			if (doubleInsertFront) {
				double_book.insert(double_book.begin() + temp_loc_double, vector<int>({ temp_start_conflict, temp_end_conflict }));
			}
			single_book.insert(single_book.begin() + loc_single, vector<int>({ start,end })); {
			}


			return true;
		}
	}
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main() {

	vector <vector<int>> cases({{69, 78}, {81, 86}, {80, 87}, {58, 66}, {40, 46}, {81, 88}, {40, 47}, {18, 25}, {52, 59}, {80, 88}, {58, 63}, {15, 21}, {79, 87}, {77, 83}, {9, 14}, {67, 76}, {39, 44}, {36, 45}, {11, 20}, {61, 69}, {51, 60}, {49, 57}, {48, 53}, {2, 8}, {8, 15}, {49, 57}, {8, 16}, {42, 51}, {94, 100}, {44, 50}, {1, 9}, {69, 78}, {47, 53}, {98, 100}, {56, 62}, {26, 31}, {3, 9}, {68, 75}, {85, 92}, {52, 57}, {51, 59}, {18, 26}, {60, 65}, {92, 99}, {90, 98}, {89, 97}, {39, 44}, {31, 39}, {90, 96}, {44, 49}, {44, 49}, {47, 54}, {24, 32}, {59, 68}, {29, 34}, {38, 43}, {3, 8}, {98, 100}, {48, 57}, {19, 24}, {65, 71}, {20, 29}, {18, 23}, {67, 76}, {78, 86}, {43, 48}, {30, 39}, {49, 56}, {48, 56}, {84, 91}, {13, 18}, {96, 100}, {31, 36}, {1, 8}, {90, 97}, {96, 100}, {20, 28}, {45, 52}, {1, 6}, {13, 22}} );

	MyCalendarTwo* myCalendarTwo = new MyCalendarTwo();

	for (auto &it : cases) {
		cout << myCalendarTwo->book(it[0], it[1]);
	}


	return 0;
}