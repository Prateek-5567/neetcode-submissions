class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Better. : n*k time complexity 
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=k+i && j<n;j++){
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;
        // Optimal : Use Hash Map .
    }
};