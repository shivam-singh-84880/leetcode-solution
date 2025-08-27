class Solution {
public:
    int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }

    int gcdOfOddEvenSums(int n) {
        int ts = n*(2*n+1);
        int es = n*(n+1);
        int os = ts - es;
        return gcd(os,es);
    }
};