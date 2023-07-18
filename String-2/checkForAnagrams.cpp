class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
    
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mp1[t[i]]--;
        }

        for(auto it:mp1){
            if(it.second != 0)
            return false;
        }

       return true; 
    }
};