class Solution {
private:
    std::string intToBinary(int n, int len) {
        if (n == 0) {
            return std::string(len, '0');
        }
        std::string result;
        while (n > 0) {
            result = (n % 2 ? '1' : '0') + result;
            n /= 2;
        }
        if (result.length() < len) {
            result = std::string(len - result.length(), '0') + result;
        }
        return result;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;

        int nlen = nums.size();
        int generated_limit = 17;
        if (nlen <= 4) {
            generated_limit = 1 << nlen;
        }
        std::cout << "generated_limit : " << generated_limit << std::endl;
        for (int i = 0; i < generated_limit; i++) {
            string str = intToBinary(i, nlen);
            std::cout << str << std::endl;
            s.insert(str);
        }
        for (auto& str : nums) {
            if (s.find(str) != s.end()) {
                s.erase(str);
            }
        }
        return *s.begin();
    }
};