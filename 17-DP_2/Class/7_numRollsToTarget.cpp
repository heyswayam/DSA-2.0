// Number of Dice Rolls with target Sum
*/
class Solution {
public:
//Memoization
 const unsigned int M = 1000000007;
int solve(int n,int k,int target, vector<vector<int>>&dp){
        if(target<0)return 0;
        if(target==0 && n==0)return 1;
        if(n==0 && target!=0)return 0;
        if(n!=0 && target==0)return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        unsigned long long int  ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,target-i,dp)%M)%M;
        }
        return dp[n][target]=(ans%M);
}
int solveUsingTabu(int n, int k, int target) {
    // dp creation
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // base case analysis
    dp[n][target] = 1;

    for (int dice = n - 1; dice >= 0; dice--) {
        for (int sum = target; sum >= 0; sum--) {
            int ans = 0;
            for (int face = 1; face <= k; face++) {
                if (sum + face <= target) {
                    ans = (ans + dp[dice + 1][sum + face]) % M;
                }
            }
            dp[dice][sum] = ans;
        }
    }

    return dp[0][0];
}
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    //    return solve(n,k,target,dp);
    return solveUsingTabu(n,k,target);
    }
};