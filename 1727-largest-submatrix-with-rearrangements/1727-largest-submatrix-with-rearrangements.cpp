class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> arr(m, vector<int>(n, 0));
		int result = 0;
		for (int i = 0; i < n; i++) {
			arr[0][i] = matrix[0][i];
		}

		// 높이 계산
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1) {
					// 위의 열 중에 1이 연속된 개수를 구한다.
					arr[i][j] = arr[i - 1][j] + 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			sort(arr[i].begin(), arr[i].end(), greater<int>());
			for (int j = 0; j < n; j++) {
				// 높이 * (j + 1) = 넓이
				// arr[i][j] = 해당 열까지에 대해 1로 만들 수 있는 최대 높이
				// (j+1) = 해당 너비까지를 사용했을 때
				// arr[i][j] * (j+1) -> 넓이
				result = max(result, arr[i][j] * (j + 1));
			}
		}
        return result;
    }
};
