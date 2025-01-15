class Solution {
public:

    string toBinary(int num) {
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num >>= 1;
        }
        return binary;
    }

    int minimizeXor(int num1, int num2) {
        string num1_binary = toBinary(num1);
        string num2_binary = toBinary(num2);

        int bitcount = 0;
        for (int i = 0; i < num2_binary.size(); i++) {
            if (num2_binary[i] == '1') {
                bitcount++;
            }
        }
        string result_str(num1_binary.size(), '0');
        for (int i = 0; i < num1_binary.size(); i++) {
            if (bitcount == 0) {
                break;
            }
            // 이걸 헷갈렸다. num1의 1 비트를 찾아야 한다.
            if (num1_binary[i] == '1') {
                result_str[i] = '1';
                bitcount--;
            }
        }
        std::cout << "CONSOLE | " << "num1_binary : " << num1_binary << endl;
        cout << "CONSOLE | " << "result_str : " << result_str << endl;
        for (int i = result_str.size() - 1; i >= 0; i--) {
            if (bitcount == 0) {
                break;
            }
            if (result_str[i] == '0') {
                result_str[i] = '1';
                bitcount--;
            }
        }
        if (bitcount > 0) {
            result_str = string(bitcount, '1') + result_str;
        }
        return stoi(result_str, nullptr, 2);
    }
};