#define ERROR_INDEX 0
class NumberContainers {
private:
    map<int, vector<int>> m;
    map<int, int> index_to_number;

    void sorted_insert(vector<int> *v, int value) {
        auto it = lower_bound(v->begin(), v->end(), value);
        v->insert(it, value);
    }
    void sorted_erase(vector<int> *v, int value) {
        auto it = lower_bound(v->begin(), v->end(), value);
        if (it != v->end() && *it == value) {
            v->erase(it);
        }
    }
public:
    NumberContainers() {
        this->m = map<int, vector<int>>();
        this->index_to_number = map<int, int>();
    }

    void change(int index, int number) {
        int ago_value = ERROR_INDEX;
        if (this->index_to_number.find(index) != this->index_to_number.end()) {
            ago_value = this->index_to_number[index];
        }
        std::cout << ago_value << std::endl;
        this->index_to_number[index] = number;
        if (ago_value == ERROR_INDEX) {
            this->sorted_insert(&this->m[number], index);
        } else {
            this->sorted_erase(&this->m[ago_value], index);
            this->sorted_insert(&this->m[number], index);

        }
    }

    int find(int number) {
        if (this->m.find(number) == this->m.end()) {
            return -1;
        }
        if (this->m[number].size() == 0) {
            return -1;
        }
        return this->m[number][0];
    }
};