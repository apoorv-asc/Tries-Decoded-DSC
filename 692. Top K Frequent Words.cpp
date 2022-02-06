class Solution {
public:
    struct compareCount{
        bool operator()( pair<int,string> const& p1,pair<int,string> const& p2 ){
            // cout<<"p1 : "<<p1.second<<"\np2 : "<<p2.second<<endl;
            if(p1.first == p2.first){
                if(p1.second>p2.second)
                    return true;
                else
                    return false;
            }
            return p1.first < p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string,int> count;
        priority_queue<pair<int,string>,vector<pair<int,string> >,compareCount > q;
        int x;
        vector<string> res;
        for(x=0;x<words.size();x++){
            count[words[x]]++;
        }
        for(auto it=count.begin();it!=count.end();it++){
            cout<<"===============> "<<it->first<<endl;
            q.push(make_pair(it->second,it->first));
        }
        for(x=0;x<k;x++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};