#define ALPHABET_SIZE 26
class Solution {
private:
    int parent[ALPHABET_SIZE];

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // 더 작은 문자를 root로 만들기
            if (rootX < rootY) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
            }
        }
    }

public:
    // union-find 알고리즘 이용하면 매우 쉽게 풀 수 있는 문제
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < s1.length(); i++) {
            int idx1 = s1[i] - 'a';
            int idx2 = s2[i] - 'a';
            unionSet(idx1, idx2);
        }

        string result = "";
        for (char c : baseStr) {
            int idx = c - 'a';
            int root = find(idx);
            result += (char)('a' + root);
        }

        return result;
    }
};