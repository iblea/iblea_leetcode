class Solution {
public:
    int flipLights(int n, int presses) {
        // 6개 이상의 전구는 패턴이 반복됨
        n = min(n, 6);

        // presses가 0인 경우
        if (presses == 0) {
            return 1;
        }

        // n이 1인 경우
        if (n == 1) {
            return 2;  // 켜짐/꺼짐 두 가지 상태만 가능
        }

        // n이 2인 경우
        if (n == 2) {
            return presses >= 2 ? 4 : 3;
        }

        // n >= 3인 경우
        if (presses == 1) {
            return 4;
        }
        else if (presses == 2) {
            return 7;
        }
        else {  // presses >= 3
            return 8;
        }
    }
};

