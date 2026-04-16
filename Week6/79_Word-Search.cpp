class Solution {
public: 
    using pii = std::pair<int, int>;
    std::vector<pii> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(int i, int j, int m, int n, int pos, vector<vector<char>>& board, std::string str){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != str[pos])
            return false;
        
        if(pos == str.length()-1)
            return true;
        else
            pos++;

        char tmp = board[i][j];
        board[i][j] = '.';

        for(auto [x, y] : moves){
            if(dfs(i+x, j+y, m, n, pos, board, str))
                return true;
        }

        board[i][j] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        unordered_map<char, int> freq;
        for (auto& row : board)
            for (char& c : row)
                freq[c]++;
        if (freq[word.front()] > freq[word.back()])
            reverse(word.begin(), word.end());

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, m, n, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};