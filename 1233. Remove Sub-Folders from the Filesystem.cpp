struct TrieNode{
    bool end;
    TrieNode *next[26];
    TrieNode *slash;
    TrieNode(){
        end = false;
        slash = NULL;
        for(int i=0;i<26;i++)
            next[i] = NULL;
    }
};
class Solution {
public:
    void insert(TrieNode *curr,string &path){
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(!curr->slash)
                    curr->slash = new TrieNode();
                curr = curr->slash;
            }else{
                if(!curr->next[path[i]-'a'])
                    curr->next[path[i]-'a'] = new TrieNode();
                curr = curr->next[path[i]-'a'];
            }
        }
        curr->end = true;
    }
    
    void findAll(TrieNode *curr,string pathSoFar,vector<string> &result){
//         Base case
        if(curr->end){
            result.push_back(pathSoFar);
            curr->slash = NULL;
        }
//         Recursive cases
        if(curr->slash)
            findAll(curr->slash,pathSoFar+'/',result);
        else{
            for(int i=0;i<26;i++){
                if(curr->next[i] != NULL)
                    findAll(curr->next[i],pathSoFar+(char(97+i)),result);
            }
        }
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode *root;
        TrieNode dummy;
        root = &dummy;
        
        vector<string> result;
        
        for(int i=0;i<folder.size();i++)
            insert(root,folder[i]);
        
        findAll(root,"",result);
        return result;
    }
};