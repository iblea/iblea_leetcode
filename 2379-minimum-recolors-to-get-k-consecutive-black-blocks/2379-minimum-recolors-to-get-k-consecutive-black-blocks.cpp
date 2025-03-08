class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // k개의 공간 중 검은색 블록이 얼마나 많은지를 체크하면 될 듯?
        // 0~6 -> B 몇개?
        // 1-7 -> B 몇개?
        // 2-8 -> B 몇개?
        // ...
        // n~(k-1)+n -> B 몇개?
        // 이중 검은색 블록이 가장 많은 곳을 찾아 (k - (검은색 블록 수))를 반환하면 될 듯
        int max_black = count(blocks.begin(), blocks.begin() + k, 'B');
        int black_count = max_black;
        int check_size = blocks.size() - k;
        for (int i = 1; i <= check_size; i++) {
            if (blocks[i-1] == 'B') {
                black_count--;
            }
            if (blocks[i+k-1] == 'B') {
                black_count++;
            }
            max_black = max(max_black, black_count);
        }
        return k - max_black;
    }
};