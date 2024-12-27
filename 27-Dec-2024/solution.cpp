class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> maxi(n);
        int ans = 0;

        maxi[0] = values[0];


        for(int i=1;i<n;i++){
            int right = values[i]-i;

            ans = max(ans,right+maxi[i-1]);

            int left = values[i]+i;

            maxi[i] = max(maxi[i-1],left);
        }

        return ans;
    }
};