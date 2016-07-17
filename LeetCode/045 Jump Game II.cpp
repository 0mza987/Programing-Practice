//https://leetcode.com/problems/jump-game-ii/
// greedy algo

class Solution {
public:
    int jump(vector<int>& nums) {
        int size=nums.size(), lastmax=0, currmax=0,i=0, res=0;
        while(currmax<size-1){
            lastmax=currmax;
            for(; i<=lastmax; ++i){
                currmax = max(currmax, i+nums[i]);
            }
            res++;
            if(currmax==lastmax) return -1;
        }
        return res;
    }
};