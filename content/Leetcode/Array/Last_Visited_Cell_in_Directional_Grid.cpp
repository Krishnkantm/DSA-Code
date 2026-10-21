class Solution {
public:
    bool valid(int i, int j, char ch, vector<vector<char>>& visited) {
        // base case
        int n = visited.size();
        int m = visited[0].size();

        if (ch == 'L' && (j - 1 >= 0 && visited[i][j - 1] != '#')) {
            return true;
        }

        if (ch == 'R' && (j + 1 < m && visited[i][j + 1] != '#')) {
            return true;
        }

        if (ch == 'U' && (i - 1 >= 0 && visited[i - 1][j] != '#')) {
            return true;
        }

        if (ch == 'D' && (i + 1 < n && visited[i + 1][j] != '#')) {
            return true;
        }

        return false;
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int i = 0;
        int j = 0;

        // time -> O(n*m)
        // space -> O(1)

        while (true) {

            char ch = grid[i][j];
            grid[i][j] = '#';

            if (!valid(i, j, ch, grid))
                break;

            if (ch == 'L') {
                j--;
            } else if (ch == 'R') {
                j++;
            } else if (ch == 'U') {
                i--;
            } else if (ch == 'D') {
                i++;
            }
        }

        return {i, j};
    }
};
