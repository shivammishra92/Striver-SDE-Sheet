class Solution {
private:
bool isPalindrome(int s,int e,string str){
    bool flag = true;
    while(s<=e){
        if(str[s] != str[e]){
           flag = false;
           break; 
        }
        else{
            s++;
            e--;
        }
    }

    if(flag)return true;
    return false;
    
}
void findPossiblePartitions(int index,string s,vector<string>&path,
vector<vector<string>>&result){
    //base case
    if(index >= s.length()){
       result.push_back(path);
       return;
    }

    for(int i=index;i<s.length();i++){
        if(isPalindrome(index,i,s)){
            path.push_back(s.substr(index,i-index+1));
            findPossiblePartitions(i+1,s,path,result);
            path.pop_back();
        }
    }

}   

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>>result;
    int index = 0;
    vector<string>path;

    findPossiblePartitions(index,s,path,result);
    return result;

    }
};