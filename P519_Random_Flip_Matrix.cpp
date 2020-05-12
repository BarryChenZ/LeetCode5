class Solution {
private:
    int rows, cols, total;
    unordered_set<int> v;
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = rows * cols;
    }
    
    vector<int> flip() {
        if(v.size() == total) return{};
        int r = rand() % total;
        while(v.count(r)){
            r = (++r) % total;
        }
        v.insert(r);
        return {r / cols, r % cols};
    }
    
    void reset() {
        v = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
