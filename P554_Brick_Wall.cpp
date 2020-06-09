class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        for(auto row : wall){
            for(int i = 0, width = 0; i < row.size()-1; i++){// (row.size() - 1) is keypoint
                width += row[i];
                edges[width] += 1;
            }
        }
        
        auto minBricks = wall.size();
        for(auto i : edges) minBricks = min(minBricks, wall.size() - i.second);
        return minBricks;
    }
};
