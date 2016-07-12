//https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> res;
        vector<int> sample(n,-1);
        int cnt = 0;
        ancillary(res,sample,0,n,cnt);
        return cnt;
    }
    bool isconf(vector<int>& sample, int nth, int location){
        for(int i=0; i<nth; ++i){
            if(sample[i]==location || location-sample[i]==nth-i || location-sample[i]==i-nth) return true;
        }
        return false;
    }

    void ancillary(vector<vector<int>>& res, vector<int>& sample, int nth, int n, int& cnt){
        if(nth==n){
            ++cnt;
            return;
        }
        for(int i=0; i<n; ++i){
            if(!isconf(sample,nth,i)&&sample[nth]<0){
                sample[nth] = i;
                ancillary(res,sample,nth+1,n,cnt);
                sample[nth] = -1;
            }
        }
        return;
    }
};