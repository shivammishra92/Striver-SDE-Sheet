class Solution {
public:
    string longestPalindrome(string str) {
      //taking start and end pointer to store the index of the first 
      //and last index of the longest palindrome to print the longest palindromic substring
      int start = 0,end = 0,maxLen = 0;
      int n = str.length();
      for(int i=1;i<str.length();i++){
          //for odd length
          int s = i-1;
          int e = i+1;
          while((s>=0 && e<n) && (str[s] == str[e])){
              if(e-s+1 > maxLen){
                  maxLen = e-s+1;
                  start = s;
                  end = e;
              }
              s--;
              e++;
          }
          //for even length
          s = i-1;
          e = i;
          while((s>=0 && e<n) && (str[s] == str[e])){
              if(e-s+1 > maxLen){
                  maxLen = e-s+1;
                  start = s;
                  end = e;
              }
              s--;
              e++;
          }
      }
      string ans = "";
      for(int i=start;i<=end;i++){
          ans += str[i];
      } 

      return ans;   
    }
};