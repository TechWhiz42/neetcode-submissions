class Solution {
   private:
    struct Node {
        Node* links[26] = {};
        bool flag = false;
        string word;

        bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

        void put(char ch, Node* node) { links[ch - 'a'] = node; }

        Node* get(char ch) { return links[ch - 'a']; }

        void setEnd(const string& word) {
            flag = true;
            this->word = word;
        }

        bool isEnd() { return flag; }
    };

    Node* root;
    vector<string> ans;

   public:
    Solution() { root = new Node(); }

    void insert(const string& word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) node->put(ch, new Node());

            node = node->get(ch);
        }

        node->setEnd(word);
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node) {
        char ch = board[i][j];

        if (!node->containsKey(ch)) return;

        node = node->get(ch);

        if (node->isEnd()) {
            ans.push_back(node->word);

            // Prevent duplicate answers
            node->flag = false;
        }

        board[i][j] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int m = board.size();
        int n = board[0].size();

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '#') {
                dfs(board, nx, ny, node);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) insert(word);

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};