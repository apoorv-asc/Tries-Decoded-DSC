struct TrieNode{
    bool isWord;
    TrieNode *next[26];
    TrieNode(){
        isWord = false;
        for(int x=0;x<26;x++)
            next[x]=NULL;
    }
};
class Solution {
public:
    TrieNode *root;
    TrieNode dummy;
    Solution(){
        root = &dummy;
    }
    void insert(string &word){
        TrieNode *curr = root;
        for(int x=0;x<word.size();x++){
            if(!curr->next[word[x]-'a'])
                curr->next[word[x]-'a']=new TrieNode();
            curr = curr->next[word[x]-'a'];
        }
        curr->isWord = true;
    }
    void find(TrieNode *curr,vector<vector<char>>& board,int x,int y,string &s,vector<string> &res){
//         Base Cases
        if(x>=board.size() || y>=board[0].size()|| x<0 || y<0 || board[x][y]=='#')
            return;
        // cout<<x<<" "<<y<<endl;
        if(!curr->next[board[x][y]-'a']){
            // cout<<x<<" <--> "<<y<<endl;
            return;
        }
        curr = curr->next[board[x][y]-'a'];
        if(curr->isWord){
            res.push_back((s+board[x][y]));
        }
        
//         Recursive Cases
        char q = board[x][y];
        string s2=s+q;
        board[x][y] = '#';
        
        find(curr,board,x,y+1,(s2),res);
        find(curr,board,x,y-1,(s2),res);
        find(curr,board,x+1,y,(s2),res);
        find(curr,board,x-1,y,(s2),res);
        
        board[x][y]=q;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int x,y;
        vector<string> res;
        string s="";
        TrieNode *curr=root;
        
        for(x=0;x<words.size();x++){
            insert(words[x]);
        }
        for(x=0;x<board.size();x++){
            for(y=0;y<board[x].size();y++){
                find(curr,board,x,y,s,res);
            }
        }
        set<string> res2;
        for(string s:res)
            res2.insert(s);
        vector<string> res3;
        for(string s:res2)
            res3.push_back(s);
        return res3;
    }
};