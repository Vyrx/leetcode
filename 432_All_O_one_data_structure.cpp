#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

class AllOne {
public:
    vector<string> max_strings, min_strings;
    int max_count, min_count;
    unordered_map<string, int> umap;

    AllOne() {
        max_count = min_count = 0;
        max_strings = min_strings = vector<string>({ "" });
    }

    void update(string key) {
        if (umap[key] == max_count) max_strings.push_back(key);
        if (umap[key] > max_count) vector<string>({ key });
        else if (umap[key] < max_count) {
            // if it's the only in the vector
            if (max_strings.size() == 1 && max_strings[0] == key) {

            }
        }

    }

    void inc(string key) {

        if (umap.count(key) > 0) {
            umap[key] += 1;
        }
        else {
            umap[key] = 1;
        }

        update(key);
    }

    void dec(string key) {

        umap[key] -= 1;

        update(key);
    }

    string getMaxKey() {
        return max_strings[0];
    }

    string getMinKey() {
        return min_strings[0];
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne* obj = new AllOne();
	return 0;
}