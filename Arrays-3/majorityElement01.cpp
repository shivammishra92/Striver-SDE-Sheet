class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size()-1;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            if(it.second > n/2)
            return it.first;
        }
        return -1;
    }
};

// Approach-02(Boyer Moore's Voting Algorithm)
int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int majElem; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            majElem = v[i];
        }
        else if (majElem == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == majElem) cnt1++;
    }

    if (cnt1 > (n / 2)) return majElem;
    return -1;
}