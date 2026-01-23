class Solution {
public:
    typedef long long ll;
    //[2,2,-1,3,-2,2,1,1,1,0,-1]
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        set<pair<ll, int>> st;
        vector<int> next(n);
        vector<int> prev(n);
        vector<ll> temp(n);

        for(int i = 0; i < n; i++) {
            next[i] = i+1;
            prev[i] = i-1;
            temp[i] = nums[i];
        }

        int badPairs = 0;
        for(int i = 0; i < n-1; i++) {
            if(temp[i] > temp[i+1]) {
                badPairs++;
            }
            st.insert({temp[i] + temp[i+1], i});
        }

        int ans = 0;

        while(badPairs > 0) {
            int first  = st.begin()->second;
            int second = next[first];

            int first_left   = prev[first];
            int second_right = next[second];


            st.erase(begin(st));

            if(temp[first] > temp[second]) {
                badPairs--;
            }

            if(first_left >= 0) {
                if(temp[first_left] > temp[first] &&
                temp[first_left] <= temp[first] + temp[second]) {
                    badPairs--;
                } 
                else if(temp[first_left] <= temp[first] &&
                temp[first_left] > temp[first] + temp[second]) {
                    badPairs++;
                }
                st.erase({temp[first_left] + temp[first], first_left});
                st.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }

            if (second_right < n) {
                if (temp[second_right] >= temp[second] &&
                    temp[second_right] < temp[first] + temp[second]) {
                    badPairs++;
                }
                else if (temp[second_right] < temp[second] &&
                         temp[second_right] >= temp[first] + temp[second]) {
                    badPairs--;
                }
                st.erase({temp[second] + temp[second_right], second});
                st.insert({temp[first] + temp[second] + temp[second_right], first});
                prev[second_right] = first;
            }       
            
            next[first] = second_right;
            temp[first] += temp[second];

            ans++;
        }

        return ans;
    }
};