#include <iostream>
#include<vector>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;

            start++;
            end--;
        }
    }
};

int main() {
	return 0;
}