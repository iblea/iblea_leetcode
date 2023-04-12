class Solution {
public:
	void path_check(string* path, vector<string> *result) {
		if (path->empty()) {
			return ;
		}
		if ((*path) == ".") {
			return ;
		}
		if ((*path) == "..") {
			if (result->empty() == false) {
				result->pop_back();
			}
			return ;
		}
		result->push_back((*path));
	}
	string simplifyPath(string path) {
		if (path.length() == 0) {
			return "";
		}
		vector<string> result{};
		string tmp;
		for (size_t i = 1; i < path.length(); ++i) {
			if (path[i] == '/') {
				this->path_check(&tmp, &result);
				tmp.clear();
				continue;
			}
			tmp += path[i];
		}
		if (tmp.empty() == false) {
			path_check(&tmp, &result);
		}
		string res = "";
		if (result.empty()) {
			return "/";
		}
		for (size_t i = 0; i < result.size(); i++) {
			res += ("/" + result[i]);
		}
		return res;
	}
};