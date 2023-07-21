public class Solution {
    public int myAtoi(String s) {
        int result = 0;
        int maxi = Integer.MAX_VALUE;
        int mini = Integer.MIN_VALUE;
        int sign = 1;
        int n = s.length();
        int i=0;
        
        //crossing over all whitespaces
        while(i<n && s.charAt(i) == ' ')
        i++;
        
        //crossing over the sign if present
        if(i<n && s.charAt(i) == '-'){
        sign = -1;
        i++;
        }
        else if (i<n && s.charAt(i) == '+'){
        sign = 1;
        i++;
        }

        while(i<n && s.charAt(i)-'0' >= 0 && s.charAt(i)-'0' <= 9){
            int digit = s.charAt(i)-'0';
            //if the number exceeds our upper and lower bound
            if(result > maxi/10 || (result == maxi/10 && digit > maxi%10))
            return sign == 1 ? maxi:mini;

            result = result*10 + digit;
            i++;
        }

        return result*sign;
    }
} 
