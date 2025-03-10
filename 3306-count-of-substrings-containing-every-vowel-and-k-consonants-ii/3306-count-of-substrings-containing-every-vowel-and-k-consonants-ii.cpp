class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        long long result = 0;

        // 모음 집합
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};

        // 각 위치별로 문자가 모음인지 자음인지 미리 계산
        vector<bool> isVowel(n);
        for (int i = 0; i < n; i++) {
            isVowel[i] = vowelSet.count(word[i]) > 0;
        }

        // 각 위치까지 5가지 모음의 누적 출현 횟수 계산
        vector<vector<int>> vowelCount(n + 1, vector<int>(5, 0));
        for (int i = 0; i < n; i++) {
            // 이전 값 복사
            for (int j = 0; j < 5; j++) {
                vowelCount[i + 1][j] = vowelCount[i][j];
            }

            // 현재 문자가 모음이면 해당 모음 카운트 증가
            if (isVowel[i]) {
                char c = word[i];
                if (c == 'a') vowelCount[i + 1][0]++;
                else if (c == 'e') vowelCount[i + 1][1]++;
                else if (c == 'i') vowelCount[i + 1][2]++;
                else if (c == 'o') vowelCount[i + 1][3]++;
                else if (c == 'u') vowelCount[i + 1][4]++;
            }
        }

        // 각 위치에서 시작하여 가능한 부분 문자열 계산
        for (int start = 0; start <= n - 5 - k; start++) {
            // 각 가능한 끝점에 대해 [start, end] 범위가 모든 모음을 포함하고 k개의 자음을 가지는지 확인
            int consonantCount = 0;
            int firstValid = -1, lastValid = -1;

            for (int end = start; end < n; end++) {
                // 자음이면 카운트 증가
                if (!isVowel[end]) {
                    consonantCount++;
                }

                // 자음이 k개를 초과하면 더 이상 유효하지 않음
                if (consonantCount > k) {
                    break;
                }

                // 모든 모음이 포함되어 있는지 확인
                bool hasAllVowels = true;
                for (int v = 0; v < 5; v++) {
                    if (vowelCount[end + 1][v] - vowelCount[start][v] == 0) {
                        hasAllVowels = false;
                        break;
                    }
                }

                // 모든 조건 만족 시 (모든 모음 포함 & 자음 k개)
                if (hasAllVowels && consonantCount == k) {
                    // 처음 유효한 위치 저장
                    if (firstValid == -1) {
                        firstValid = end;
                    }
                    // 마지막 유효한 위치 업데이트
                    lastValid = end;
                }
            }

            // 유효한 범위가 있으면 결과에 추가
            if (firstValid != -1) {
                result += (lastValid - firstValid + 1);
            }
        }

        return result;
    }
};