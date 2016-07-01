//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        unordered_map<string,int> worddict,wordfound;
        int cnt=words.size(), wsize=words[0].length(), ssize=s.length(),i=0,j=0;
        
        for(auto each : words) worddict[each]++;
        for(i=0; i<=ssize-cnt*wsize; ++i){
            wordfound.clear();
            for(j=0; j<cnt; ++j){
                string word=s.substr(i+j*wsize,wsize);
                if(worddict.count(word)){
                    if(wordfound[word]++ ==worddict[word]) break;
                }
                else break;
            }
            if(j==cnt) res.push_back(i);
        }
        
        return res;
    }
};