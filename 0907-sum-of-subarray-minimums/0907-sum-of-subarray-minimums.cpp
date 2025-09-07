class Solution {
public:
    // vector<int> nsef(vector<int> &arr){
    //     int n = arr.size();
    //     stack<int> st;
    //     vector<int> ans(n,-1);
    //     for(int i=n-1; i>=0; i--){
    //         while(!st.empty() && arr[st.top()] > arr[i]){
    //             st.pop();
    //         }
    //         ans[i] = st.empty() ? n : st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }

    vector<int> nsef(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> psef(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    // vector<int> psef(vector<int> &arr){
    //     int n = arr.size();
    //     stack<int> st;
    //     vector<int> ans(n,-1);
    //     for(int i=0; i<n; i++){
    //         while(!st.empty() && arr[st.top()] >= arr[i]){
    //             st.pop();
    //         }
    //         ans[i] = st.empty() ? -1 : st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nsef(arr);
        vector<int> pse = psef(arr);
        int n = arr.size();
        int mod = 1e9+7;
        int sum=0;
        for(int i=0; i<n; i++){
            int l = i - pse[i];
            int r = nse[i] - i;
            sum = (sum + (l * r * 1ll * arr[i])%mod)%mod;
        }
        return sum;
    }
};