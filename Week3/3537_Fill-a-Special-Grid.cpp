class Solution {
public:
    void splitGrid(int n, int &count, int i, int j, std::vector<std::vector<int>> &ans){
        if(n == 0){
            ans[i][j] = count++;
            return;
        }

        int offset = (1 << n)/2;
        splitGrid(n-1, count, i, j + offset, ans);
        splitGrid(n-1, count, i + offset, j + offset, ans);
        splitGrid(n-1, count, i + offset, j, ans);
        splitGrid(n-1, count, i, j, ans);
    }

    vector<vector<int>> specialGrid(int n) {
        if(n == 0) return {{0}};

        int count = 0;
        int size = 1 << n;
        std::vector<std::vector<int>> ans(size, std::vector(size, 0));
        
        splitGrid(n, count, 0, 0, ans);
        
        return ans;
    }
};