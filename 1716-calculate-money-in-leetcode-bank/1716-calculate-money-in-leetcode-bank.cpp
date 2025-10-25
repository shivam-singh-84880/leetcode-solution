class Solution {
public:
    int totalMoney(int n) {
        int q = n/7;
        int r = n%7;

        return (28 + 28 + (q-1) * 7) * q/2 + (q+1 + q+r)*r/2;
    }
};