class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(!s.contains('1') || !target.contains('1')){
            return s == target;
        }
        return true;
    }
};