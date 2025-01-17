class Solution {
public:
    bool doesValidArrayExist(vector<int>& arr) {
        int val = 0;
        int n = arr.size();

        for(int i=0;i<n;i++){
            val = val^arr[i];
        }

        return val==0;
    }
};