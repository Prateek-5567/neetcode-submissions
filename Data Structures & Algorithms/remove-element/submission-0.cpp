class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        // it is same as move zeros to end.
        // here it is move val to end.

        int i=0,j=0; // i is the index pointing at val
        int n=arr.size();
        // it j is at Val swap with i  ; i is at starting indexes.
        while(j<n){
            if(arr[j]!=val){ // using this code i would eventually reach at first val index.
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else if(arr[j]==val) j++;
        }

        // i is currently pointing at k only.
        return i;
    }
};