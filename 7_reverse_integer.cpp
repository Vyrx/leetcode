#include<iostream>
#include<bitset>

using namespace std;

class Solution {
public:
	int reverse(int x) {

		if (x == INT_MIN) return 0;

		double y = 0;
		bool negative = false;
		if (x < 0) {
			x *= -1;
			negative = true;
		}

		while (x > 0) {
			y = (y * 10) + (x % 10);
			x /= 10;
		}

		if (y > INT_MAX || y < INT_MIN) return 0;
		if (negative) return -y;
		return y;
	}
};

int main() {
	return 0;
}