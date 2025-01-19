class Solution {
private:
    bool isPoss(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)
           return false;

        return true;   
    }    
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                  pq.push({height[i][j],{i,j}});
                  visited[i][j] = 1;
                }
            }
        }

        int ans = 0;
        int lvl = 0;
        

        while(!pq.empty()){
            pair<int,pair<int,int>> temp = pq.top();
            pq.pop();

            lvl = max(lvl,temp.first);
            int i = temp.second.first;
            int j = temp.second.second;

            if(isPoss(i,j+1,n,m) && !visited[i][j+1]){
                pq.push({height[i][j+1],{i,j+1}});
                visited[i][j+1] = 1;

                if(height[i][j+1] < lvl)
                  ans += lvl- height[i][j+1];
            }

            if(isPoss(i+1,j,n,m) && !visited[i+1][j]){
                pq.push({height[i+1][j],{i+1,j}});
                visited[i+1][j] = 1;

                if(height[i+1][j] < lvl)
                  ans += lvl- height[i+1][j];
            }

            if(isPoss(i,j-1,n,m) && !visited[i][j-1]){
                pq.push({height[i][j-1],{i,j-1}});
                visited[i][j-1] = 1;

                if(height[i][j-1] < lvl)
                  ans += lvl- height[i][j-1];
            }

            if(isPoss(i-1,j,n,m) && !visited[i-1][j]){
                pq.push({height[i-1][j],{i-1,j}});
                visited[i-1][j] = 1;

                if(height[i-1][j] < lvl)
                  ans += lvl- height[i-1][j];
            }
        }

        return ans;

    }
};