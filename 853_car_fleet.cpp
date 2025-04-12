#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	struct Car {
		int position;
		int speed;
		//bool operator<(const Car& rhs) { 
		//    return position > rhs.position; 
		//}
	};

	/*static bool compCar(Car const&lhs, const Car &rhs) {
		return lhs.position > rhs.position;
	}*/

	struct compCar {
		bool operator() (const Car& lhs, const Car& rhs) {
			return lhs.position > rhs.position;
		}
	};

	bool willMerge(Car& c1, Car& c2, int target) { // Check if c2 (behind c1) will merge with c1
		// Conditions for merging: speed 1 < speed 2 and both cars meet at position <= target
		if (c1.speed >= c2.speed) return false;
		// final_pos = pos + speed * time  ...(I)
		// pos1 + speed1 * time = pos2 + speed2 * time
		// pos 1 - pos 2 = time (speed2 - speed1)
		// meeting time = (pos1 - pos2) / (speed2 - speed1)
		// substitute back to (I)
		return (c1.position + c1.speed * float(c1.position - c2.position) / (c2.speed - c1.speed)) <= target;
	}

	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n = position.size();
		vector<Car> cars(n);
		for (int i = 0; i < n; i++) {
			cars[i] = Car{ position[i], speed[i] };
		}

		// Sort by descending position
		std::sort(cars.begin(), cars.end(), compCar());

		int numCarFleet = 1;
		for (int i = 1; i < n; i++) {
			if (willMerge(cars[i - 1], cars[i], target)) {
				cars[i] = cars[i - 1];
				// if we have cars A B C, if B merges with A then C will merge with B iff C will merge with A
				// A will be the "bottleneck" here since itll be the slowest car in the fleet
			}
			else {
				numCarFleet++;
			}
		}

		return numCarFleet;
	}
};

void main() {
	Solution S;
	vector<int> position{ 10,8,0,5,3 };
	vector<int> speed{ 2,4,1,1,3 };
	cout << S.carFleet(12, position, speed);
}