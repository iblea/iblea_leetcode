class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        set<pair<int, int>> visited;

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (! q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a == target || b == target || a + b == target) {
                return true;
            }

            if (visited.count({a, b})) {
                continue;
            }
            visited.insert({a, b});

            q.push({x, b});
            q.push({a, y});
            if (a > 0 && visited.find({0, b}) == visited.end()) q.push({0, b});
            if (b > 0 && visited.find({a, 0}) == visited.end()) q.push({0, b});

            pair<int, int> a_to_b = {a - min(a, y - b), b + min(a, y - b)};
            pair <int, int> b_to_a = {a + min(b, x - a), b - min(b, x - a)};
            if (visited.find(a_to_b) == visited.end()) q.push(a_to_b);
            if (visited.find(b_to_a) == visited.end()) q.push(b_to_a);
        }

        return false;
    }
};

