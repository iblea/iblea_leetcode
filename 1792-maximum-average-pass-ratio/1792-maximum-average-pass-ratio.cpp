
struct ClassInfo {
    int pass;
    int total;
    double agoRatio;
    double newRatio;
    double diffRatio;

    bool operator<(const ClassInfo& other) const {
        return diffRatio < other.diffRatio;
    }
    bool operator>(const ClassInfo& other) const {
        return diffRatio > other.diffRatio;
    }
};

struct cmp {
    // priority queue 를통해 가장 큰 값을 우선으로 리턴하도록 하기 위해
    bool operator()(const ClassInfo& a, const ClassInfo& b) const {
        return a.diffRatio < b.diffRatio;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int pass = 0;
        int total = 0;
        double agoRatio = 0;
        double newRatio = 0;
        double diffRatio = 0;

        // diff ratio 기준으로 가장 큰 값부터 리턴하는 우선순위 큐
        // priority_queue<ClassInfo, vector<ClassInfo>, cmp> pq;
        priority_queue<ClassInfo> pq;
        for (auto& c : classes) {
            pass = c[0];
            total = c[1];
            agoRatio = (double)(pass) / (double)(total);
            newRatio = (double)(pass + 1) / (double)(total + 1);
            diffRatio = newRatio - agoRatio;
            pq.push({pass, total, agoRatio, newRatio, diffRatio});
        }

        for (int i = 0; i < extraStudents; i++) {
            ClassInfo c = pq.top();
            pq.pop();
            pass = c.pass + 1;
            total = c.total + 1;
            agoRatio = c.newRatio;
            newRatio = (double)(pass + 1) / (double)(total + 1);
            diffRatio = newRatio - agoRatio;
            pq.push({pass, total, agoRatio, newRatio, diffRatio});
        }

        double sumRatio = 0;
        while (!pq.empty()) {
            ClassInfo c = pq.top();
            pq.pop();
            sumRatio += c.agoRatio;
        }
        return sumRatio / classes.size();
    }
};

