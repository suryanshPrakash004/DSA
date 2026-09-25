class Solution {
public:
     vector<string> ans;
    void generate(string curr, int open, int closed, int n){
       

        if(open == n && closed == n) {
            ans.push_back(curr);
            return;
        };

        if(open < n) {
             generate(curr + "(", open + 1, closed, n);
        }

        if(closed < open) {
             generate(curr + ")", open, closed+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {

         generate("", 0, 0, n);
         return ans;

    }
};