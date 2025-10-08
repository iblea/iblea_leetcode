class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        // key: 호수 번호, value: 마지막으로 비가 온 날
        unordered_map<int, int> lake_map;
        // 물을 뺄 수 있는 날
        set<int> dry_days;
        vector<int> result(rains.size(), 1);

        for (int i = 0; i < rains.size(); ++i) {
            int lake = rains[i];

            // 비가 안옴.
            if (lake == 0) {
                // 물을 뺄 수 있는 날로 추가
                dry_days.insert(i);
                continue;
            }

            // 비가 옴.
            result[i] = -1;
            if (lake_map.find(lake) != lake_map.end()) {
                // 이미 비가 온 적이 있는 호수라면, 물을 뺄 날을 찾아야 함
                auto it = dry_days.lower_bound(lake_map[lake]);
                if (it == dry_days.end()) {
                    // 물을 뺄 날이 없음 -> 홍수 발생
                    return {};
                }

                // 해당 날에 물을 빼는 것으로 처리하고, 물 뺀 날 제거
                result[*it] = lake;
                dry_days.erase(it);
            }
            lake_map[lake] = i;
        }

        return result;
    }
};