/*
华为社会招聘 - 软件类开发类机考题


输入一个字符串
包含各种字符甚至可能包含空格，需要读取一整行

返回最长的合法数字字符串，如果长度相同就返回后面的

合法数字包只能包含 . + - 和 0-9 ，并且 . 左右必须有数字， +- 必须在最开始


例子：
输入：
123+1.23

输出：
+1.23

*/


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isDot(char c) {
        return c == '.';
    }

    bool isPlus(char c) {
        return c == '+' || c == '-';
    }

    bool isNum(char c) {
        return c >= '0' && c <= '9';
    }

    bool checkStart(char c) {
        return (isNum(c) || isPlus(c));
    }

    string getLonggestNum(string& str) {
        int len = 0;
        int start = 0;

        for (int i = 0; i < (int)str.size(); i++) {

            if (!checkStart(str[i])) continue;

            bool dotFlag = false;
            int j = i + 1;
            for (; j < (int)str.size(); j++) {
                if (isNum(str[j])) continue;
                if (isPlus(str[j])) break;
                if (isDot(str[j])) {
                    if (dotFlag) break;
                    dotFlag = true;
                    continue;
                }
                break;
            }

            if (len <= j - i) {
                start = i;
                len = j - i;
            }

            i = j - 1;
        }

        return str.substr(start, len);
    }

    int main()
    {
        string str;
        while (getline(cin, str)) {
            cout << getLonggestNum(str);
        }
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
//string _solution_run(string s1)
//{
//    //int caseNo = -1;
//    //static int caseCnt = 0;
//    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//    Solution sln;
//    return sln.run(s1);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    FILE* ssin;
    freopen_s(&ssin, "C:\\AhJo53589\\nowcoder\\problems_test\\202005200001\\1.in", "r", stdin);

    FILE* ssout;
    freopen_s(&ssout, "C:\\AhJo53589\\nowcoder\\problems_test\\202005200001\\1.out", "w", stdout);

    Solution sln;
    sln.main();

    freopen_s(&ssout, "CON", "w", stdout);

    //FILE* ssout;
    //freopen_s(&ssout, "C:\\AhJo53589\\nowcoder\\problems_test\\0\\1.out", "r", stdin);
    //char c;
    //while ((c = getchar()) != EOF && c != '\n') putchar(c);
    //cout << endl;

    return {};
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
