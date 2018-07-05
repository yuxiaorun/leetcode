class Solution {
public:
    int myAtoi(string str) {
        if (str.size() < 1) return 0;
        int i = 0, sign = 1;
        long retNum = 0;
        while(str[i] == ' ') ++i; // skip white spaces
        if (i >= str.size()) return 0;
        if (str[i] == '+' || str[i] == '-' || isdigit(str[i])) {
            sign = str[i] == '-' ? -1 : 1; // preserve sign
            if (!isdigit(str[i])) ++i;
            while(i < str.size() && isdigit(str[i])) {
                retNum = retNum*10 + (str[i++] - '0'); // add number to return value
                if (retNum > INT_MAX) return sign > 0 ? INT_MAX : INT_MIN; // handle large numbers
            }
        } else return 0; // not a valid number
        return int(retNum) * sign;
    }
};