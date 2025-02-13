class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long,vector<long long>,greater<long long>> pq;
            int n = nums.size();
    
            for(int i=0;i<n;i++){
                pq.push(nums[i]);
            }
    
            int ans = 0;
    
            while(!pq.empty()){
                long long x = pq.top();
                pq.pop();
    
                if(x>=k)
                  return ans;
    
                long long y = pq.top();
                pq.pop();
    
                long long val = max(x,y) + min(x,y)*2;
                ans++;
                pq.push(val);
            }
            return ans;
        }
    };