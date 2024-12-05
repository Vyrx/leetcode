#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canChange(string &start, string &target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ssize = start.size(), tsize = target.size();
        int s = 0, t = 0;
        while (t < tsize) {
            if (target[t] != '_') {
                while (start[s] == '_') {
                    s++;
                    if (s >= ssize) 
                        return false;
                }
                if (start[s] != target[t] || (start[s] == 'L' && s < t) || (start[s] == 'R' && s > t))
                    return false;
                s++;
            }
            t++;
        }
        while (s < ssize) {
            if (start[s] != '_') return false;
            s++;
        }
        return true;
    }
};

void main() {
    Solution  S;
    string start = "_L__R__R_";
    string target = "L______RR";
    cout << S.canChange(start, target);
}