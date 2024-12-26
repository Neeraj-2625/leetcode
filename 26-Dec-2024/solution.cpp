class Solution {
private:
    int solve(int index,vector<int> &nums,int n,int target,int sum,vector<vector<int>> &dp){
        if(index>=n){
            if(target==sum)
               return 1;
            else
              return 0;   
        }
       if(dp[index][sum+1000]!=-1)
          return dp[index][sum+1000];

       int a1 = solve(index+1,nums,n,target,sum+nums[index],dp);
       int a2 = solve(index+1,nums,n,target,sum-nums[index],dp);

       return dp[index][sum+1000]=a1+a2;
    }    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        

        vector<vector<int>> dp(n,vector<int>(2001,-1));

        int ans = solve(0,nums,n,target,0,dp);

        return ans;
    }
};