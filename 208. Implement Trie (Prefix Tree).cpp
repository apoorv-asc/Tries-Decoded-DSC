class Trie {
public:
    struct trieNode{
        bool isWord;
        trieNode *next[26];
        trieNode(){
            isWord = false;
            for(int x=0;x<26;x++)
                next[x]=NULL;
        }
    };
    trieNode *root;
    trieNode dummy;
    Trie() {
        root = &dummy;
    }
    
    void insert(string word) {
        trieNode *curr = root;
        for(int x=0;x<word.size();x++){
            if(!curr->next[word[x]-'a'])
                curr->next[word[x]-'a'] = new trieNode;
            curr = curr->next[word[x]-'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        trieNode *curr = root;
        for(int x=0;x<word.size();x++){
            if(!curr->next[word[x]-'a'])
                return false;
            curr = curr->next[word[x]-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        trieNode *curr = root;
        for(int x=0;x<prefix.size();x++){
            if(!curr->next[prefix[x]-'a'])
                return false;
            curr = curr->next[prefix[x]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */