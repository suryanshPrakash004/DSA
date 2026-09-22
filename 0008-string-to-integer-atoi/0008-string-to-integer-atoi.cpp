class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long long result = 0;
        int i = 0;

        while(i < s.length() && s[i] == ' '){
            i++;
        }

        if (i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        }

        else if (i < s.size() && s[i] == '+') {
            i++;
        } 

        

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');

            if (result > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;

            i++;
        }

        return result * sign;
    }
};