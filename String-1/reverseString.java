import java.util.StringTokenizer;  
class Solution {
    public String reverseWords(String s) {
    StringTokenizer st = new StringTokenizer(s);
    int n = st.countTokens();//4
    String ss = "",ans="",s2="";
    for(int i=0;i<n;i++){
        ss = st.nextToken();
        s2="";
        for(int j=0;j<ss.length();j++){
            s2 +=  ss.charAt(j);
        }
        ans = s2 + " " + ans;
      }
      String res = ans.trim();
     return res;
    }
}