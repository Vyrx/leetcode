#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<unordered_map<char, int>> row(9, unordered_map<char, int>());
        vector<unordered_map<char, int>> col(9, unordered_map<char, int>());;
        vector<vector<unordered_map<char, int>>> grid(3, vector<unordered_map<char, int>>(3, unordered_map<char, int>()));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row[j].count(board[i][j]) > 0) return false;
                    else row[j][board[i][j]] = 1;

                    if (col[i].count(board[i][j]) > 0) return false;
                    else col[i][board[i][j]] = 1;

                    if (grid[i / 3][j / 3].count(board[i][j]) > 0) return false;
                    else grid[i / 3][j / 3][board[i][j]] = 1;
                }
            }
        }

        return true;
    }
};