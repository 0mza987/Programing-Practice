// https://leetcode.com/problems/implement-strstr/description/
// An easy class problem with an not-easy-at-all solution
// Thanks to this blog for KMP algorithm explanation: http://www.matrix67.com/blog/archives/115

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size(), j=-1;
        vector<int> match = KMPpreProcessing(needle);
        for(int i=0; i<n; ++i){
            while(j>=0 && needle[j+1]!=haystack[i]) j=match[j];
            if(needle[j+1]==haystack[i]) ++j;
            if(j==m-1) return i+1-m;
        }
        return -1;
    }
    
    vector<int> KMPpreProcessing(string& s){
        int n= s.length(), j=-1;
        vector<int> match(n,-1);
        for(int i=1; i<n; ++i){
            while(j>=0 && s[j+1]!=s[i]) j=match[j];
            if(s[j+1]==s[i]) ++j;
            match[i]=j;
        }
        return match;
    }
};