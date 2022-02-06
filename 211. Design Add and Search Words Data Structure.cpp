struct TrieNode{
    TrieNode(){
        isWord = false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
    bool isWord;
    TrieNode *next[26];
};
class WordDictionary {
public:
    TrieNode *root;
    TrieNode dummy;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = &dummy;
    }
    
    void addWord(string word) {
        int n=word.size(),i;
        TrieNode *curr = root;
        
        for(i=0;i<n;i++){
            if(!curr->next[word[i]-'a'])
                curr->next[word[i]-'a'] = new TrieNode;
            
            curr = curr->next[word[i]-'a'];
        }
        curr->isWord = true;                
    }
//     Finds word[id....(n-1)] in subtree rooted at "root"
    bool searchHelper(string &word,int id,TrieNode *root){
//         Base cases
        if(id==word.size() && root)
            return root->isWord;
        if(!root)
            return false;
        
//         Recursive part
        bool temp;
        if(word[id]=='.'){
            for(int j=0;j<26;j++){
                temp = searchHelper(word,id+1,root->next[j]);
                if(temp)
                    return true;
            }
            return false;
        }else{
            if(!root->next[word[id]-'a'])
                return false;
            return searchHelper(word,id+1,root->next[word[id]-'a']);
        }
        
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */