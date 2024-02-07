/*
* Parition Equal Subset Sum
*/
class Solution {
public:
bool solve(vector<int>&nums,int index,int currSum,int target){
if(currSum==target)return 1;
if(index==nums.size())return 0;
if(currSum>target)return 0;
bool include=solve(nums,index+1,currSum+nums[index],target);
bool exclude=solve(nums,index+1,currSum,target);
return (include || exclude);
}
// memoization
bool solveMemo(vector<int>&nums,int index,int currSum,int target,vector<vector<int>>&dp){
if(currSum==target)return 1;
if(index==nums.size())return 0;
if(currSum>target)return 0;
if(dp[index][currSum]!=-1)return dp[index][currSum];
bool include=solveMemo(nums,index+1,currSum+nums[index],target,dp);
bool exclude=solveMemo(nums,index+1,currSum,target,dp);
dp[index][currSum]=(include || exclude);
return dp[index][currSum];
}
//tabulation
bool solveUsingTabu(vector<int>&nums,int n,int &target){
    vector<vector<int>>dp(n+2,vector<int>(target+1,0));
    //base case analysis
    for(int row=0;row<=n;row++){
        dp[row][target]=1;
    }
    for(int index=n-1;index>=0;index--){
        for(int s=target;s>=0;s--){
            bool include=0;
            if(s+nums[index]<=target)
             include=dp[index+1][s+nums[index]];
            bool exclude=dp[index+1][s];
            dp[index][s]=(include || exclude);
        }
    }
    return dp[0][0];
}
//space opti
bool solveOpti(vector<int>&nums,int n,int &target){
    // vector<vector<int>>dp(n+2,vector<int>(target+1,0));
    vector<int>curr(target+1,0);
    vector<int>next(target+1,0);
    //base case analysis
   curr[target]=1;
   next[target]=1;
    for(int index=n-1;index>=0;index--){
        for(int s=target;s>=0;s--){
            bool include=0;
            if(s+nums[index]<=target)
             include=next[s+nums[index]];
            bool exclude=next[s];
           curr[s]=(include || exclude);
        }
        next=curr;
    }
    return next[0];

}
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        int index=0;
        int currSum=0;
        if(totalSum&1)return 0;
        int target=totalSum/2;
        // return solve(nums,index,currSum,target);
        // vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        // return solveMemo(nums,index,currSum,target,dp);
        return solveOpti(nums,nums.size(),target);
    }
};
/*
