class Solution {
private:
    // 00: 북, 1: 동, 2: 남, 3: 서
    int direction;
    pair<int, int> current_position;
    void distance_change(int change_direction) {
        this->direction = (this->direction + 4 + change_direction) % 4;
    }
    void move_distance() {
        switch (this->direction) {
            case 0: this->current_position.second++; break;
            case 1: this->current_position.first++; break;
            case 2: this->current_position.second--; break;
            case 3: this->current_position.first--; break;
        }
    }
    void move_distance_reverse() {
        switch (this->direction) {
            case 0: this->current_position.second--; break;
            case 1: this->current_position.first--; break;
            case 2: this->current_position.second++; break;
            case 3: this->current_position.first++; break;
        }
    }

    int get_euclidean_distance() {
        return (this->current_position.first * this->current_position.first) + (this->current_position.second * this->current_position.second);
    }

    long long coord_hash(int x, int y) {
        return (long long)x * 60001 + y;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        this->direction = 0;
        this->current_position = {0, 0};
        int max_distance = 0;

        unordered_set<long long> obstacle_set;
        for (auto &obstacle : obstacles) {
            obstacle_set.insert(coord_hash(obstacle[0], obstacle[1]));
        }

        for (auto command : commands) {
            if (command == -2) {
                this->distance_change(-1);
                continue;
            } else if (command == -1) {
                this->distance_change(1);
                continue;
            }

            int move_count = command;
            while (move_count--) {
                this->move_distance();
                if (obstacle_set.count(coord_hash(this->current_position.first, this->current_position.second))) {
                    this->move_distance_reverse();
                    break;
                }
            }
            max_distance = max(max_distance, get_euclidean_distance());
        }
        return max_distance;
    }
};
