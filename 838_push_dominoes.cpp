#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string pushDominoes(string &dominoes) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	
		int n = dominoes.size();
		vector<int> time_fall(n); // the time that the domino is falling
		bool isFalling = false; int counter = 0;

		for (int i = 0; i < n; i++) { // process all R from left to right
			if (dominoes[i] == 'R') {
				isFalling = true;
				counter = 0;
			}
			else if (isFalling && dominoes[i] == '.') {
				time_fall[i] = counter;
			}
			else if (dominoes[i] == 'L') {
				isFalling = false;
			}
			counter++;
		}

		isFalling = false; counter = 0;
		for (int i = n - 1; i >= 0; i--) { // process L from right to left
			if (dominoes[i] == 'L') {
				isFalling = true;
				counter = 0;
			}
			else if (isFalling && dominoes[i] == '.') {
				if (time_fall[i] == 0 || counter < time_fall[i])
					time_fall[i] = -counter; // time_fall[i] is negative if its falling to the left
				else if (counter == time_fall[i])
					time_fall[i] = 0; // if equal force then doesnt fall -> 0
			}
			else if (dominoes[i] == 'R') {
				isFalling = false;
			}
			counter++;
		}

		for (int i = 0; i < n; i++) {
			if (dominoes[i] == '.') {
				if (time_fall[i] > 0)
					dominoes[i] = 'R';
				else if (time_fall[i] < 0) {
					dominoes[i] = 'L';
				}
			}
		}

		return dominoes;
	}
};