//https://leetcode.com/problems/n-queens/


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allStr;
        vector<string> str;
        if(n==0) return allStr;
        vector<vector<int>> res;
        vector<int> sample(n,-1);
        ancillary(res,sample,0,n);
        for(int i=0; i<res.size(); ++i){
            str.clear();
            for(int j=0; j<res[i].size(); ++j){
                string temp(res[i].size(),'.');
                temp[res[i][j]] = 'Q';
                str.push_back(temp);
            }
            allStr.push_back(str);
        }
        return allStr;
    }
    
    bool isconf(vector<int>& sample, int nth, int location){
        for(int i=0; i<nth; ++i){
            if(sample[i]==location || location-sample[i]==nth-i || location-sample[i]==i-nth) return true;
        }
        return false;
    }

    void ancillary(vector<vector<int>>& res, vector<int>& sample, int nth, int num){
        if(nth==num){
            res.push_back(sample);
            return;
        }
        for(int i=0; i<num; ++i){
            if(!isconf(sample,nth,i)&&sample[nth]<0){
                sample[nth] = i;
                ancillary(res,sample,nth+1,num);
                sample[nth] = -1;
            }
        }
        return;
    }
};