#include <iostream>
#include <string>

using namespace std;

/*
1 <= s.length <= 10**5
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/

class Solution {
public:
    string removeStars(string s) {
		string res = "";
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == '*') {
				res.pop_back();
			}
			else {
				res += s[i];
			}
		}
		return res;
    }
};

int main()
{
	Solution s = Solution();

	cout << s.removeStars("leet**cod*e") << endl;
	cout << s.removeStars("erase*****") << endl;
}