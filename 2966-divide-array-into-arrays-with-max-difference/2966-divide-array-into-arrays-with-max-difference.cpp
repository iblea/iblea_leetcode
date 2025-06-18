class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        vector<int> v;
        int v_size = m.size();
        for (pair<int, int> p : m) {
            v.push_back(p.first);
        }

        vector<vector<int>> result;
        int i = 0;
        while (i < v_size) {
            int count = 3;
            vector<int> temp;
            int limit = v[i] + k;
            while (count > 0 && i < v_size && v[i] <= limit) {
                if (m[v[i]] > count) {
                    m[v[i]] -= count;
                    for (int j = 0; j < count; j++) {
                        temp.push_back(v[i]);
                    }
                    count = 0;
                } else {
                    count -= m[v[i]];
                    for (int j = 0; j < m[v[i]]; j++) {
                        temp.push_back(v[i]);
                    }
                    m[v[i]] = 0;
                    i++;
                }
            }
            if (temp.size() != 3) {
                return {};
            }
            result.push_back(temp);
        }
        std::cout << "i: " << i << ", v_size: " << v_size
                  << ", m[v[v_size - 1]]: " << m[v[v_size - 1]] << std::endl;
        if (m[v[v_size - 1]] != 0) {
            return {};
        }
        return result;
    }
};