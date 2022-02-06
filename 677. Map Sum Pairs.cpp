struct TrieNode{
    bool isWord;
    TrieNode *next[26];
    int val;
    TrieNode(){
        isWord = false;
        val=-1;
        for(int i=0;i<26;i++)
            next[i] = NULL;
    }
};
class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode  *root;
    TrieNode dummy;
    MapSum() {
        root = &dummy;
    }
    
    void insert(string key, int val) {
        TrieNode *curr = root;
        for(int i=0;i<key.size();i++){
            if(!curr->next[key[i]-'a'])
                curr->next[key[i]-'a'] = new TrieNode();
            curr = curr->next[key[i]-'a'];
        }
        curr->isWord = true;
        curr->val = val;
    }
    
    void allSum(TrieNode *curr,int &res){
//         Base case
        if(curr->isWord){
            res += curr->val;
        }
        
//         Other cases
        for(int i=0;i<26;i++){
            if(!curr->next[i])
                continue;
            allSum(curr->next[i],res);
        }
            
    }
    
    int sum(string prefix) {
        TrieNode *curr = root;
        int res=0;
        
        for(int i=0;i<prefix.size();i++){
            if(!curr->next[prefix[i]-'a'])
                return 0;
            curr = curr->next[prefix[i]-'a'];
        }
        allSum(curr,res);
        return res;        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */