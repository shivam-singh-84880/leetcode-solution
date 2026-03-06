class Solution {
public:
    int minOperations(string s) {

        int swaps0 = 0, swaps1 = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            
            if (s[i] != expected0)
                swaps0++;
            if (s[i] != expected1)
                swaps1++;
        }

        return min(swaps0, swaps1);
    }
};