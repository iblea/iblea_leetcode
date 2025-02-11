class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int part_size = part.size();

        for (char c : s) {
            result.push_back(c);
            if (result.size() >= part_size && result.substr(result.size() - part_size) == part) {
                result.erase(result.size() - part_size);
            }
        }
        return result;
    }
};