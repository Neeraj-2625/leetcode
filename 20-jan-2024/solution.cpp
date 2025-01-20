class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int k = arr.size();

        unordered_map<int,pair<int,int>> mp;

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        for(int i=0;i<k;i++){
            pair<int,int> el =  mp[arr[i]];

            row[el.first]++;
            col[el.second]++;
            int ans = -1;
            if(row[el.first]==m)
                return i;

            if(col[el.second]==n)
                return i;   
        }

        return -1;
    }
};