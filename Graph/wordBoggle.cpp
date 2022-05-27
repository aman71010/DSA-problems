#include<bits\stdc++.h>
using namespace std;


// got TLE
class Solution {
public:
	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        int m = board.size(), n = board[0].size();
	    unordered_set<string> s;
        for(int i=0; i<dictionary.size(); i++)
            s.insert(dictionary[i]);
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        vector<string> res;
        string temp = "";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, s, visited, res, temp, i, j, m, n);
            }
        }
        return res;
	}

    void dfs(vector<vector<char>>& board, unordered_set<string> &s, vector<vector<bool>> &visited, vector<string> &res, string temp, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j])
            return;
        visited[i][j] = 1;
        temp += board[i][j];
        if(s.find(temp)!=s.end())
            res.push_back(temp);
        int x[8] = {0,-1,-1,-1,0,1,1,1};
        int y[8] = {-1,-1,0,1,1,1,0,-1};
        for(int d=0; d<8; d++)
            dfs(board, s, visited, res, temp, i+x[d], j+y[d], m, n);
        visited[i][j] = 0;
        temp.pop_back();
    }
};


//-----------------------------------------------------------------------------
// got TLE
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0; i<26; i++)
            children[i] = NULL;
        isEndOfWord = false;
    }
    void insert(TrieNode* root, string key){
        TrieNode* node = root;
        for(int i=0; i<key.length(); i++){
            if(!node->children[key[i]-'a'])
                node->children[key[i]-'a'] = new TrieNode();
            node = node->children[key[i]-'a'];
        }
        node->isEndOfWord = true;
    }
    bool search(TrieNode* root, string key){
        TrieNode* node = root;
        for(int i=0; i<key.length(); i++){
            if(!node->children[key[i]-'a'])
                return false;
            node = node->children[key[i]-'a'];
        }
        return node->isEndOfWord;
    }
};

class Solution {
public:
	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        int m = board.size(), n = board[0].size();
        TrieNode* root = new TrieNode();
        for(int i=0; i<dictionary.size(); i++)
            root->insert(root, dictionary[i]);
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        vector<string> res;
        string temp = "";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, root, visited, res, temp, i, j, m, n);
            }
        }
        return res;
	}

    void dfs(vector<vector<char>>& board, TrieNode* root, vector<vector<bool>> &visited, vector<string> &res, string temp, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j])
            return;
        visited[i][j] = 1;
        temp += board[i][j];
        if(root->search(root, temp));
            res.push_back(temp);
        int x[8] = {0,-1,-1,-1,0,1,1,1};
        int y[8] = {-1,-1,0,1,1,1,0,-1};
        for(int d=0; d<8; d++)
            dfs(board, root, visited, res, temp, i+x[d], j+y[d], m, n);
        visited[i][j] = 0;
        temp.pop_back();
    }
};

//---------------------------------------------------------------------------------------------
//accepted

class Solution {
public:
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
    
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        TrieNode* root = new TrieNode();
        for(int i=0; i<words.size(); i++)
            root->insert(root, words[i]);
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        vector<string> res;
        string str = "";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ci = board[i][j]-'A';
                if(root->children[ci]){
                    str += board[i][j];
                    searchWord(board, root->children[ci], visited, res, str, i, j, m, n);
                    str = "";
                }
            }
        }
        return res;
    }
    
    void searchWord(vector<vector<char>>& board, TrieNode* root, vector<vector<bool>> &visited, vector<string> &res, string& str, int i, int j, int m, int n){
        if(root->isEndOfWord){
            res.push_back(str);
            root->isEndOfWord = false; // to avoid duplicates
        }
        if(i>=0 && i<m && j>=0 && j<n && !visited[i][j])
            visited[i][j] = true;
        for(int k=0; k<26; k++){
            if(root->children[k]){
                char c = 'A'+k;
                for(int d=0; d<8; d++){
                    int x = i+dx[d];
                    int y = j+dy[d];
                    if(x >= 0 && y>= 0 && x<m && y<n && !visited[x][y] && board[x][y]==c){
                        str += c;
                        searchWord(board, root->children[k], visited, res, str, x, y, m, n);
                        str.pop_back();
                    }
                }
            }
        }
        visited[i][j] = false;
    }
};

