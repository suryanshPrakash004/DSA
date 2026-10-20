class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right])
            return false;

            left++;
            right--;
        }
        return true;
    }

    void backtrack(string &s, int idx, vector<string> &curr, vector<vector<string>> &result){

        if(idx == s.length()){
            result.push_back(curr);
        }

        for(int i = idx; i < s.length(); i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));

                backtrack(s,i+1, curr, result);

                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;

        backtrack(s, 0, curr, result);
        return result;
    }
};