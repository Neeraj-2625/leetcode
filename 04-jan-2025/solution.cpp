class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        unordered_set<char> st;

        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }

        int ans = 0;

        for(auto c:st){
            int start = -1;
            int end = 0;
            for(int i=0;i<n;i++){
                if(s[i] == c){
                    if(start == -1){
                        start = i;
                    }

                    end = i;
                }
            }
            unordered_set<char> bt;

            for(int i=start+1;i<end;i++){
                bt.insert(s[i]);
            }
            ans += bt.size();
        }

        return ans;
    }
};