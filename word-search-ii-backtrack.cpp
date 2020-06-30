class Solution {
public:
    
    bool dfs(vector<vector<char>> &board, int idx, string w, int x, int y, vector<vector<bool>> &visited) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (idx == w.size()) return true;
        
        if(x < 0 || x >= rows || y < 0 || y >= cols) return false;
      
        if (board[x][y] != w[idx]) return false;
            
        if (visited[x][y] == true) return false;
        // char ch = board[x][y];
        // board[x][y] = '#';
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {

            int newX = x + dx[i];
            int newY = y + dy[i];
                
            if (dfs(board, idx + 1, w, newX, newY, visited)) return true;
            
        }
        
        visited[x][y] = false;
        // board[x][y] = ch;
        return false;
        
    }
    
    bool solve(vector<vector<char>> &board, string w) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (w[0] == board[i][j] && dfs(board, 0, w, i, j, visited)) {
                    // bool ans = dfs(board, 0, w, i, j, visited);
                    // cout << "ans = " << ans << endl;
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        int rows = board.size();
        if (rows == 0) return ans;
        int cols = board[0].size();
        if (cols == 0) return ans;
        
        for (string w: words) {
            if (solve(board, w)) {
                ans.push_back(w);
            }
        }
        
        return ans;
    }
};
