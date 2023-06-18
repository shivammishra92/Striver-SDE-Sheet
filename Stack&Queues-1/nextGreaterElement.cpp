        class Solution {
        public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map; // map for next greater element
        stack<int> st;
        for (int num : nums2) {
            while (!st.empty() && st.top() < num){ 
                map[st.top()] = num;
                st.pop();
            }
            st.push(num); // Push current element onto stack
        }   
        for (int i = 0; i < nums1.size(); i++){ 
            nums1[i] = map.count(nums1[i]) ? map[nums1[i]] : -1;
        }

        return nums1;
    }
        };