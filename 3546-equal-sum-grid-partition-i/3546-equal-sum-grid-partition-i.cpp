class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
		long long total = 0;
		int ysize = grid.size();
		int xsize = grid[0].size();
		vector<long long> row_total(ysize, 0);
		vector<long long> column_total(xsize, 0);

		for (int y = 0; y < ysize; ++y) {
			for (int x = 0; x < xsize; ++x) {
				row_total[y] += grid[y][x];
				column_total[x] += grid[y][x];
				total += grid[y][x];
			}
		}

		// 가로 자르기
		long long tmp1 = 0;
		long long tmp2 = total;
		for (int y = 0; y < ysize - 1; ++y) {
			tmp1 += row_total[y];
			tmp2 -= row_total[y];
			if (tmp1 == tmp2) {
				return true;
			}
		}

		// 세로 자르기
		tmp1 = 0;
		tmp2 = total;
		for (int x = 0; x < xsize - 1; ++x) {
			tmp1 += column_total[x];
			tmp2 -= column_total[x];
			if (tmp1 == tmp2) {
				return true;
			}
		}
		return false;
    }
};
