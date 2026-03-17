class Solution {
private:
    set<int> top3;
    void insert_top3(int value) {
        top3.insert(value);
        if (top3.size() > 3) {
            top3.erase(top3.begin());
        }
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // 1. kmax 계산
        int kmax = min(m, n) / 2;
        top3 = set<int>();

        // 2. k = 0 일 때의 마름모 (셀 자체) 계산
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                this->insert_top3(grid[y][x]);
            }
        }

        // 3. k >= 1 일 때의 마름모 변을 더해 top3에 추가
        for (int k = 1; k <= kmax; k++) {
			int center_y_max = m - k;
			int center_x_max = n - k;
            for (int y = 0 + k; y < center_y_max; y++) {
                for (int x = 0 + k; x < center_x_max; x++) {
                    // TODO: 마름모 변 더하기
					int sum = 0;
					for (int i = 0; i < k; i++) {
						// 상
						sum += grid[y - k + i][x - i];
						// 좌
						sum += grid[y + i][x - k + i];
						// 하
						sum += grid[y + k - i][x + i];
						// 우
						sum += grid[y - i][x + k - i];
					}
					this->insert_top3(sum);
                }
            }
        }

        // 4. top3 vector로 변환해 리턴 (내림차순 반환)
        return vector<int>(this->top3.rbegin(), this->top3.rend());
    }
};
