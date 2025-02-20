class Solution {
public:
    string getHappyString(int n, int k) {

        // 총 문자열 개수가 k개보다 적을 경우 빈 문자열 반환
        // k는 3*2^(n-1) 보다 클 수 없다.
        if (k > 3 * (1 << (n - 1))) {
            return "";
        }

        // 1
        // a b c
        // 2
        // ab ac ba bc ca cb
        // 3
        // aba abc aca acb bab bac bca bcb cab cac cba cbc
        // 4
        // abab abac abca abcb acab acac acba acbc ... 24개

        // 즉, n이 1개 늘어날 때 마다 2배씩 증가한다.
        // 즉, 3*2^(n-1) 개의 문자열이 생성된다.


        // n=3, k=5 -> bab(5), ba(3), b(2)
        // n=3, k=6 -> bac(6), ba(3), b(2)
        // n=3, k=9 -> cab(9), ca(5), c(3)
        // n=4, k=7 -> acba(7) acb(4), ac(2), a(1)

        int divide_count = n;
        stack<int> st;
        string result = "";
        int group = (k - 1) / (1 << (n - 1));
        result += ('a' + group);
        k = k - group * (1 << (n - 1));
        int curr = k;
        while(divide_count > 1) {
            if (curr == 1) {
                // std::cout << "tmp: " << 1 << std::endl;
                st.push(1);
                divide_count--;
                continue;
            }
            int tmp = curr % 2;
            st.push(tmp);
            // std::cout << "tmp: " << tmp << std::endl;
            if (tmp == 0) {
                curr /= 2;
            } else {
                curr = (curr / 2) + 1;
            }
            divide_count--;
        }
        while(!st.empty()) {
            int tmp = st.top();
            st.pop();
            if (tmp == 1) {
                if (result.back() == 'a') {
                    result += 'b';
                } else {
                    result += 'a';
                }
            } else {
                if (result.back() == 'c') {
                    result += 'b';
                } else {
                    result += 'c';
                }
            }
        }

        return result;
    }
};