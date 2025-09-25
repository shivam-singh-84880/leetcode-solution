class Solution {
public:
    int pivot(vector<int>& nums, int s, int e){
        int mid=0;
        while(s<e){
            mid = (s+e)/2;
            if(nums[mid]==nums[e]){
                if(e>0 && nums[e-1]>nums[e])return e;
                e = e-1;
            } 
            else if(nums[mid] > nums[e]){
                s = mid+1;
            }
            else e = mid;
        }
        return s;
    }

    bool search(vector<int>& nums, int target) {
        int p = pivot(nums,0,nums.size()-1);
        int s=0;
        int e=p-1;

        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid] < target){
                s = mid+1;
            }
            else e = mid-1;
        }

        s=p;
        e=nums.size()-1;

        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid] < target){
                s = mid+1;
            }
            else e = mid-1;
        }
        return false;
    }
};
