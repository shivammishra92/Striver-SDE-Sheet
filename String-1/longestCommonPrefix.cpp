class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        int i=0,j=0;
        string ans = "";
        while(i < strs[0].length() and j < strs[n-1].length()){

            if(strs[0][i] != strs[n-1][j])
            break;

            ans += strs[0][i];
            i++;
            j++;
        }
        if(ans == "")
        return "";
        else
        return ans;
    }
};