class Solution {
    // key - color, value - balls
    unordered_map<int, set<int>> color_map;
    unordered_map<int, int> balls;
private:
    void add_color(int x, int y) {
        if (this->balls.find(x) != this->balls.end()) {
            int ago_color = this->balls[x];
            this->color_map[ago_color].erase(x);
            if (this->color_map[ago_color].size() == 0) {
                this->color_map.erase(ago_color);
            }
        }
        this->color_map[y].insert(x);
        this->balls[x] = y;
    }
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result = vector<int>(queries.size());
        this->balls = unordered_map<int, int>();
        this->color_map = unordered_map<int, set<int>>();

        for (int i = 0; i < queries.size(); i++) {
            this->add_color(queries[i][0], queries[i][1]);
            result[i] = this->color_map.size();
        }
        return result;
    }
};