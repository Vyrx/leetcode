#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	typedef long long ll;
	const int MODVAL = 1e9 + 7;
	ll binPow(ll a, ll b) {
		if (b == 0) return 1;
		ll res = binPow(a, b / 2) % MODVAL; // a ^ (b/2)
		if (b % 2)
			return ((res * res) % MODVAL * a) % MODVAL; // odd
		else
			return (res * res) % MODVAL;
	}

	int countGoodNumbers(long long n) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		// primeCount = 4 (2 3 5 7)
		// evenCount = 5 (0 2 4 6 8)

		// process only n - 2 digits
		ll res = binPow(20, (n - 1) / 2);
		if (n % 2)
			res = res * 5 % MODVAL;
		else
			res = res * 20 % MODVAL;
		
		return res;
	}
};

// 5 4 5 4 5 4 5 4

