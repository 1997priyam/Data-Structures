#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0, digit = 0;
        
        while(x != 0) {
            digit = x % 10;
            x = x / 10;
            if (ans > INT32_MAX/10 || (ans == INT32_MAX / 10 && digit > 7)) return 0;
            if (ans < INT32_MIN/10 || (ans == INT32_MIN / 10 && digit < -8)) return 0;
            ans = (ans * 10) + digit;
        }
        return ans;
    }
};