class Solution {
   public:
    vector<int> topKFrequentBrute(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }

        vector<pair<int, int>> vec;
        for (auto& pair : mp) {
            vec.push_back({pair.second, pair.first});  // count , element
        }

        sort(vec.begin(), vec.end(),
             [](const auto& a, const auto& b) { return a.first > b.first; });

        vector<int> topK;
        int i = 0;
        while (k) {
            topK.push_back(vec[i].second);
            i++;
            k--;
        }
        return topK;

        // Time Complexity : O(n) + O(n) + O(nLogn) + O(k) => very bad
    }

    // Using MinHeap.
    vector<int> topKFrequentBetter(vector<int>& arr, int k){
        unordered_map<int, int> count;
        for (auto i : arr) {
            count[i]++;
        }
        // no sorting or custom sort required.

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minHeap;

        for(auto& pair : count){
            minHeap.push({pair.second,pair.first}); // push {frequency , element } into minheap
            if(minHeap.size()>k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }

    vector<int> topKFrequentOptimal(vector<int>& arr, int k){
        // Bucket Sort Approach. 
        unordered_map<int,int> count;
        for(auto i:arr){
            count[i]++;
        }
        int n=arr.size();
        vector<vector<int>> bucket(n+1);

        for(auto& pair:count){
            // pair = {element,frequency}
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> ans;
        // bucket is prepared.
        for(int i=n;i>0;i--){
            for(auto el:bucket[i]){
                ans.push_back(el);
                if(ans.size()==k)return ans;
            }
        }
        return ans;

    }

    
    
    vector<int> topKFrequent(vector<int>& arr, int k){
        return topKFrequentOptimal(arr,k);
    }


};
