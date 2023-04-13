class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() == 1) {
			if (pushed[0] == popped[0]) return true;
			return false;
		}

		stack<int> st;
		st.push(pushed[0]);
		size_t i = 0, j = 1;

		while (i < popped.size()) {
			if (j >= pushed.size()) {
				return false;
			}

			if (st.empty()) {
				st.push(pushed[j]);
				j++;
			}

			while (st.top() != popped[i]) {
				if (j >= pushed.size()) {
					break;
				}
				st.push(pushed[j]);
				j++;
			}
			while (st.top() == popped[i]) {
				st.pop();
				i++;
				if (st.empty()) {
					break;
				}
			}
		}
		if (st.empty() == false) {
			return false;
		}
		return true;
	}
};