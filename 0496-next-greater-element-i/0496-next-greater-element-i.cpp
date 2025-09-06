class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m;
        stack<int> st;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                m[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            m[nums2[i]] = -1;
            st.push(i);
        }
        for(int num:nums1){
            ans.push_back(m[num]);
        }
        return ans;

        // vector<int> ans;
        // unordered_map<int,int> m;
        // stack<int> s;

        // for(int i=nums2.size()-1; i>=0; i--){
        //             while(!s.empty() && s.top() < nums2[i]){
        //                 s.pop();
        //             }
        //             if(s.empty()) m[nums2[i]] = -1;
        //             else m[nums2[i]] = s.top();
        //             s.push(nums2[i]);
        // }
        // for(int num:nums1){
        //     ans.push_back(m[num]);
        // }
        // return ans;
    }
};