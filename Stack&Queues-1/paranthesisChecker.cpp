class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,int>mp;
        mp['('] = 1;
        mp[')'] = -1;
        mp['['] = 2;
        mp[']'] = -2;
        mp['{'] = 3;
        mp['}'] = -3;

        for(int i=0;i<s.length();i++){

            if(mp[s[i]] > 0)
            st.push(s[i]);

            else{
            if(st.empty())
            return false;
            int top = st.top();
            st.pop();
            if((mp[top] + mp[s[i]] != 0)){
                return false;
             }
            }
            
        }

        if(st.empty())return true;
        return false;
    }
};