class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0], max_val = arrays[0].back(), max_dist = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            max_dist = max({max_dist, arrays[i].back() - min_val, max_val - arrays[i][0]});
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }return max_dist;
    }
};