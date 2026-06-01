class Solution {
   public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }

        vector<pair<int, int>> vec;
        for (auto& pair : mp) {
            vec.push_back({pair.second, pair.first});  // count , element 
        }

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) 
                { return a.first > b.first; }
            );

        vector<int> topK;
        int i = 0;
        while(k) {
            topK.push_back(vec[i].second);
            i++;
            k--;
        }
        return topK;

// Time Complexity : O(n) + O(n) + O(nLogn) + O(k) => very bad
    }
};
