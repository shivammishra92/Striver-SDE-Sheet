class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        st.push(asteroids[0]);

        for(int i=1;i<asteroids.size();i++){
            int elem = asteroids[i];
            
                if(elem > 0){
                    st.push(elem);
                }
                else{
                    while(!st.empty() && abs(st.top()) < abs(elem) && st.top() > 0){
                        st.pop();
                    }
                    if(!st.empty() && st.top() == abs(elem)){
                        st.pop();
                    }
                    else{
                        if(st.empty() || st.top() < 0){
                            st.push(elem);
                        }
                    }
                }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};