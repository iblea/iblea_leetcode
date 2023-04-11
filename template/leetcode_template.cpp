#include <iostream>
#include <string>

using namespace std;

/*
 *
 */

class Solution {
public:
	string template_function() { return "template_function"; };
};

int main()
{
	Solution s = Solution();

	cout << s.template_function() << endl;
}