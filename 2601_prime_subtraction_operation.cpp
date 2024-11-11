#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:

	bool primeSubOperation(vector<int>& nums) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int max_val = *max_element(nums.begin(), nums.end());

		vector<bool> isPrime(max_val + 1, 1);
		//vector<int> pr; // store all primes

		// Sieve
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i <= max_val; i++) {
			if (isPrime[i]) {
				//pr.push_back(i);
				for (int j = i * i; j <= max_val; j += i) { // mark all multiple of i as not prime
					isPrime[j] = false;
				}
			}
		}
		/*for (int i = sqrt(max_val) + 1; i < max_val; i++) {
			if (isPrime[i])
				pr.push_back(i);
		}*/
		// Sieve end

		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) continue;
			//// for each item find the smallest prime st when subtracted the result is less than next item
			//int left = 0; int right = pr.size() - 1;
			//int sub = 1001;
			//while (left <= right) {
			//	int mid = (left + right) / 2;
			//	if (nums[i] - pr[mid] < nums[i + 1]) {

			//		sub = pr[mid];
			//		right = mid - 1;
			//	}
			//	else {
			//		left = mid + 1;
			//	}
			//}
			//if (nums[i] - sub <= 0) return 0;
			//nums[i] -= sub;
			for (int sub = 2; sub < nums[i]; sub++) {
				if (isPrime[sub] && nums[i] - sub < nums[i + 1]) {
					nums[i] -= sub;
					break;
				}
			}
			if (nums[i] >= nums[i + 1]) return 0;
		}

		return 1;

	}
};

void main() {
	Solution S;
	vector<int> nums = { 8,11,16,13 };
	S.primeSubOperation(nums);
}