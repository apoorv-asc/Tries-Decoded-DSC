struct TrieNode{
    bool isWord = false;
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
    void insert(TrieNode *curr,string &word){
        int n=word.size(),i=0;
        while(i<n){
            if(!curr->next[word[i]-'a'])
                curr->next[word[i]-'a']=new TrieNode();
            curr = curr->next[word[i]-'a'];
            i++;
        }
        curr->isWord = true;
    }
    
    void search(TrieNode *root,string &word,int pos,int &val){
        TrieNode *curr = root;
        if(val>1)
            return;
        while(pos<word.size()){
            if(!curr->next[word[pos]-'a'])
                return;
            curr = curr->next[word[pos]-'a'];
            if(curr->isWord && pos+1 != word.size())
                search(root,word,pos+1,val);
            pos++;
        }
        if(curr->isWord && pos==word.size()){
            val++;
            return;
        }
        return;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words){
        vector<string> res;
        set<string> skipped;
        int x,n=words.size();
        int val;
        for(x=0;x<n;x++){
            val=0;
            search(root,words[x],0,val);
            if(val>=1){
                skipped.insert(words[x]);
                continue;
            }
            insert(root,words[x]);
        }
        
        for(x=0;x<n;x++){
            val=0;
            search(root,words[x],0,val);
            if(skipped.find(words[x]) != skipped.end())
                res.push_back(words[x]);
            else if(val>1)
                res.push_back(words[x]);
        }
        return res;
    }
};