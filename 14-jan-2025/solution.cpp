class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        unordered_map<int,int> a,b;
        set<int> s;
        vector<int> ans;

        for(int i=0;i<n;i++){
            a[A[i]]++;
            b[B[i]]++;

            if(a.find(B[i])!=a.end())
               s.insert(B[i]);

            if(b.find(A[i])!=b.end())
               s.insert(A[i]);   


            ans.push_back(s.size());   
        }

        return ans;
    }
};