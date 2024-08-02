class Solution {
public:
    int usingRecursion(vector<int> &nums,int index){
        if(index>=nums.size()) return 0;

        int include = nums[index] + usingRecursion(nums,index+2);
        int exclude = 0 + usingRecursion(nums,index+1);
        return max(include,exclude);
    }
    int memoization(vector<int> &nums,int index,vector<int> &dp){
        if(index>=nums.size()) return 0;
        //step-3
        if(dp[index]!=-1) return dp[index];
        //step-2
        int include = nums[index] + memoization(nums,index+2,dp);
        int exclude = 0 + memoization(nums,index+1,dp);

        return dp[index] = max(include,exclude);       
    }

    int tabulation(vector<int> &nums,int index){
        vector<int> dp(nums.size()+1,-1);


        // if(nums.size()==1) return nums[0];
        dp[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2; i>=0; i--){
            int temp = dp[i+2];
            if(i==nums.size()-2){
                temp = 0;
            }
            int include = nums[i] + temp;
            int exclude = 0 + dp[i+1];

            dp[i] = max(include,exclude);
        }

    return dp[0];
    }


    int tabulationSO1(vector<int> &nums){
        // vector<int> dp(nums.size()+1,-1);
        if(nums.size()==1) return nums[0];
        int size = nums.size();
        int next = nums[size-1];
        int prev = max(next,nums[size-2]);

        int curr;

        for(int i=nums.size()-3; i>=0; i--){
            int include = nums[i]+next;
            int exclude = prev;

            curr = max(include,exclude);

            next = prev;
            prev = curr;
        }

    return prev;
    }

    int rob(vector<int>& nums) {
        int ans;
        // ans = usingRecursion(nums,0);
        // vector<int> dp(nums.size(),-1);
        // ans = memoization(nums,0,dp);
        // ans = tabulation(nums,0);
        ans = tabulationSO1(nums);
        // ans = tabulationSO(nums,0);
        return ans;
    }
};