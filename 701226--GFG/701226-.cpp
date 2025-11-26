class Solution {
  public:
    int mergeSort(int s, int mid, int e, vector<int>& arr){
        vector<int> temp;
        int i=s;
        int j=mid;
        int cnt=0;
        while(i<mid && j<=e){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                cnt += mid-i;
                j++;
            }
        }
        while(i<mid){
            temp.push_back(arr[i++]);
        }
        while(j<=e){
            temp.push_back(arr[j++]);
        }
        for(int i=s; i<=e; i++){
            arr[i] = temp[i-s];
        }
        
        return cnt;
    }
    
    int merge(int s, int e, vector<int>& arr){
        int cnt=0;
        if(s >= e)return cnt;
        
        int mid = (s+e)/2;
        cnt += merge(s,mid,arr);
        cnt += merge(mid+1,e,arr);
        cnt += mergeSort(s,mid+1,e,arr);
        
        return cnt;
    }
    
    int inversionCount(vector<int> &arr) {
       int n = arr.size();
       return merge(0,n-1,arr);
    }
};