#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <any>
#include <unordered_map>
#include <unordered_set>

using namespace std;



/* https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=daily-question&envId=2025-03-21
 * @lc app=leetcode id=2115 lang=cpp
 * [2115] Find All Possible Recipes from Given Supplies

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
Return a list of all the recipes that you can create. You may return the answer in any order.
Note that two recipes may contain each other in their ingredients.

n개의 서로 다른 레시피에 대한 정보가 있습니다. 문자열 배열 recipes와 2D 문자열 배열 ingredients가 주어집니다. i번째 레시피의 이름은 recipes[i]이며, ingredients[i]에 있는 모든 필요한 재료가 있으면 이 레시피를 만들 수 있습니다. 레시피는 다른 레시피의 재료가 될 수도 있습니다. 즉, ingredients[i]에는 recipes에 있는 문자열이 포함될 수 있습니다.
또한 처음에 가지고 있는 모든 재료를 담은 문자열 배열 supplies도 주어지며, 이 재료들은 무한히 공급받을 수 있습니다.
만들 수 있는 모든 레시피 목록을 반환하세요. 답은 어떤 순서로든 반환할 수 있습니다.
두 레시피가 서로의 재료로 포함될 수 있다는 점에 유의하세요.

Constraints:
n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.
 */

// @lc code=start
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // 레시피를 만들기 위해 필요한 재료 개수를 저장
        unordered_map<string, int> inDegree;
        // 각 재료가 어떤 레시피의 재료로 사용되는지 저장
        unordered_map<string, vector<string>> graph;
        // 결과를 저장할 set (중복 방지)
        unordered_set<string> result;

        // 초기 진입 차수 설정
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }

        // 초기 재료들을 큐에 추가
        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }

        // BFS로 위상 정렬 수행
        while (!q.empty()) {
            string current = q.front();
            q.pop();

            // 현재 재료로 만들 수 있는 레시피들 확인
            for (const string& recipe : graph[current]) {
                inDegree[recipe]--;
                if (inDegree[recipe] == 0) {
                    result.insert(recipe);
                    q.push(recipe);
                }
            }
        }

        // 결과를 vector로 변환하여 반환
        return vector<string>(result.begin(), result.end());
    }
};


// @lc code=end




#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
	clock_t t0;
	clock_t t1;
public:
	Solution s;
protected:
	CLASS_NAME() { this->s = Solution(); }
	~CLASS_NAME() override { }

	void SetUp() override { set_start_time(); }
	void TearDown() override { set_end_time(); get_duration_time(); }

	void set_start_time() {
		this->t0 = clock(); // or gettimeofday or whatever
	}
	void set_end_time() {
		this->t1 = clock(); // or gettimeofday or whatever
	}

	// 시간 관련 체크
	void get_duration_time() {
		double elapsedSec = (double)(this->t1 - this->t0) / (double)1000000;
		double elapsedMS = (double)(this->t1 - this->t0) / (double)1000;

		cout << setprecision(3) << fixed << endl << "Duration of Times : ";
		cout << elapsedMS << "ms, " << elapsedSec << "sec" << endl << endl;
	}

};

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 1:
    // Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
    // Output: ["bread"]
    // Explanation:
    // We can create "bread" since we have the ingredients "yeast" and "flour".

    vector<string> recipes = {"bread"};
    vector<vector<string>> ingredients = {{"yeast","flour"}};
    vector<string> supplies = {"yeast","flour","corn"};
    vector<string> expected = {"bread"};
    EXPECT_EQ(this->s.findAllRecipes(recipes, ingredients, supplies), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
    // Output: ["bread","sandwich"]
    // Explanation:
    // We can create "bread" since we have the ingredients "yeast" and "flour".
    // We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

    vector<string> recipes = {"bread","sandwich"};
    vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"}};
    vector<string> supplies = {"yeast","flour","meat"};
    vector<string> expected = {"bread","sandwich"};
    EXPECT_EQ(this->s.findAllRecipes(recipes, ingredients, supplies), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
    // Output: ["bread","sandwich","burger"]
    // Explanation:
    // We can create "bread" since we have the ingredients "yeast" and "flour".
    // We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
    // We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".

    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> supplies = {"yeast","flour","meat"};
    vector<string> expected = {"bread","sandwich","burger"};
    EXPECT_EQ(this->s.findAllRecipes(recipes, ingredients, supplies), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
