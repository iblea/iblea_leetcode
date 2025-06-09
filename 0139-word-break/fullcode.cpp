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

using namespace std;



/* https://leetcode.com/problems/word-break
 * @lc app=leetcode id=139 lang=cpp
 * [139] Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

문자열 s와 문자열 사전 wordDict가 주어졌을 때, s가 하나 이상의 사전 단어들의 공백으로 구분된 시퀀스로 분할될 수 있으면 true를 반환하라.
사전의 같은 단어가 분할에서 여러 번 재사용될 수 있음에 주의하라.

Constraints:
- 1 <= s.length <= 300
- 1 <= wordDict.length <= 1000
- 1 <= wordDict[i].length <= 20
- s and wordDict[i] consist of only lowercase English letters.
- All the strings of wordDict are unique.
 */
// @lc code=start
class Solution {
private:
    set<string> wordSet;
    // 시간 단축을 위해 실패한 문자열 세트도 저장해 중복 계산을 피함
    set<string> failSet;

    bool is_not_in_wordset(string s) {
        return this->wordSet.find(s) == this->wordSet.end();
    }

    bool is_in_wordset(string s) {
        return this->wordSet.find(s) != this->wordSet.end();
    }

    bool dp(string s) {
        // std::cout << "s: " << s << std::endl;
        if (s.length() == 0) {
            return true;
        }
        for (int i = 1; i <= s.length(); i++) {
            // "catsadsa" -> "c" , "ca", "cat" .. 해서 해당 단어가 set에 있는지부터 확인해야 함.
            string sub = s.substr(0, i);
            if (this->is_not_in_wordset(sub)) {
                continue;
            }

            string remain = s.substr(i);
            if (remain.length() == 0) {
                return true;
            }
            if (this->is_in_wordset(remain)) {
                return true;
            }
            if (this->failSet.find(remain) != this->failSet.end()) {
                continue;
            }
            if (this->dp(remain)) {
                this->wordSet.insert(s);
                return true;
            } else {
                this->failSet.insert(s);
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->wordSet.clear();
        this->failSet.clear();
        // sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b) {
        //     if (a.length() == b.length()) {
        //         return a < b;
        //     }
        //     return a.length() < b.length();
        // });
        for (auto& word : wordDict) {
            this->wordSet.insert(word);
        }

        bool res = this->dp(s);
        return res;
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
    // Input: s = "leetcode", wordDict = ["leet","code"]
    // Output: true
    // Explanation: Return true because "leetcode" can be segmented as "leet code".

    vector<string> wordDict = {"leet", "code"};
    EXPECT_EQ(this->s.wordBreak("leetcode", wordDict), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "applepenapple", wordDict = ["apple","pen"]
    // Output: true
    // Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
    // Note that you are allowed to reuse a dictionary word.
    // 설명: "applepenapple"은 "apple pen apple"로 분할될 수 있기 때문에 true를 반환한다.
    // 참고: 사전 단어를 재사용할 수 있다.

    vector<string> wordDict = {"apple", "pen"};
    EXPECT_EQ(this->s.wordBreak("applepenapple", wordDict), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    // Output: false

    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    EXPECT_EQ(this->s.wordBreak("catsandog", wordDict), false);
}

TEST_F(CLASS_NAME, __LINE__)
{

    // catsadsa -> catsads 'a' 이 성립되는가?
    // catsadsa -> catsad 'sa' 이 성립되는가?
    // catsadsa -> catsa 'dsa' 이 성립되는가?
    // catsadsa -> cats 'adsa' 이 성립되는가?
    // catsadsa -> cat 'sadsa' 이 성립되는가?

    // 반대로

    // catsadsa -> 'c' atsadsa 이 성립되는가?
    // catsadsa -> 'ca' tsadsa 이 성립되는가?
    // catsadsa -> 'cat' sadsa 이 성립되는가?
    // catsadsa -> 'cats' adsa 이 성립되는가? (그리고, adsa가 성립한다면, 이걸 전부 set에 넣어)
    // 그리고 리턴값은 set에 전체 문자열이 있는지 없는지 확인하면 된다.

    vector<string> wordDict = {"cats", "sads", "cat", "ad", "sa" };
    EXPECT_EQ(this->s.wordBreak("catsadsa", wordDict), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    EXPECT_EQ(this->s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaab", wordDict), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    // EXPECT_EQ(this->s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict), false);
}

TEST_F(CLASS_NAME, __LINE__)
{

    string s = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami";
    vector<string> wordDict= {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};

    EXPECT_EQ(this->s.wordBreak(s, wordDict), true);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
