class Solution {
public:
    string reverseWords(string s) {
		stringstream stream;
		string split_word;
		string answer = "";

		cout << s << endl;
		stream.str(s);
		while (stream >> split_word) {
			answer = (split_word + " ") + answer;
		}
		if (answer.empty() == false) {
			answer.erase(answer.size() - 1);
		}
		return answer;
    }
};