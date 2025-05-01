#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        // binary search the solution space
        // check if k tasks can be completed -> take k smallest tasks and k strongest workers

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size());
        int res = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            int cur_pills = pills;
            bool canAssign = true;
            deque<int> dq; // sort worker in ascending order
            for (int j = workers.size() - mid; j < workers.size(); j++) {
                dq.push_back(workers[j]);
            }
            for (int i = mid - 1; i >= 0; i--) {
                // try to assign each tasks[i] to the strongest worker
                if (dq.back() >= tasks[i]) {
                    dq.pop_back();
                }
                else {
                    if (cur_pills == 0) {
                        canAssign = false;
                        break;
                    }
                    // find the smallest worker when given pill can solve the task
                    auto it = lower_bound(dq.begin(), dq.end(), tasks[i] - strength);
                    if (it == dq.end()) {
                        canAssign = false;
                        break;
                    }
                    dq.erase(it);
                    cur_pills--;
                }
            }
            if (canAssign) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

void main() {
    Solution S;
    vector<int> tasks = { 1943,2068,4077,7832,8061,6939,6263,8917,8008,5348,8837,4753,4607,7638,9000,7222,4552,1123,9225,6896,4154,6303,3186,2325,9994,5855,8851,7377,1930,1187,5094,2689,8852,1507,1567,9575,1193,1557,8840,9075,5032,3642,6917,7968,5310,2315,7516,4776,3091,7027,1788,2007,2651,6112,4264,5644,3585,9408,7410,9605,8151,1538,6905,6759,4518,3444,5036,1589,3902,3037,1468,9179,3000,5339,6805,7394,9418,9262,2888,4708,3402,5554,8714,7393,2848,5946,9808,4301,6675,8564,6300,4359,9506,1946,9673,7412,1164,2986,2198,5144,3763,4782,8835,6994,8035,3332,2342,5243,3150,9084,6519,9798,7682,9919,7473,7686,9978,8092,9897,3985,9874,5842,9740,2145,2426,7069,8963,9250,4142,9434,1895,6559,3233,8431,6278,6748,7305,4359,2144,8009,4890,6486,7464,8645,1704,5915,9586,1394,7504,2124,3150,2051,5026,7612,3715,5757,4355,6394,3202,2777,3949,2349,7398,3029,3081,5116,5078,8048,9934,4348,8518,5201,1203,7935,5006,6388,8680,3427,6048,1957,4026,4618,4080 };
    vector<int> workers = { 875,2347,939,3664,3926,4555,1947,4406,4601,3502,4964,1307,4232,2968,4572,3139,2788,1847,1208,2019,4184,1664,1747,3690,4333,891,686,1959,2218,4972,806,741,1490,4529,2909,925,2040,1234,1264,1135,3640,1455,2933,3699,2856,3074,4579,2458,2090,833,4140,4534,2336,4363,1948,4546,4155,3735,3577,2780,4874,1747,4844,3482,3053,3534,549,4500,2237,2128,1554,3210,4161,2211,950,3732,2182,1148,4368,4050,1452,1015,3192,4318,3908,2590,1103,2811,2821,690,2718,3360,2659,3315,579,3108,2979,3903,4367,1906,4964,889,4803,825,2270,4794,4825,4485,4461,1639,3857,1330,3169,2425,3694,1980,2268,3002,2177,3225,2499,2517,1916,2844,760,2167,1786,3179,3222,1432,3775,4747,1764,690,3223,4684,890,2701,1045,3034,1381,1011,2150,4798,2247,1334,3058,934,2895,1484,2784,3341,4412,1748,625,2610,3488,4810,669,4275,4929,1014,2104,3111 };
    int pills = 122;
    int strength = 3131;
    S.maxTaskAssign(tasks, workers, pills, strength);
}