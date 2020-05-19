/*
��Ϊ�����Ƹ - ����࿪���������


����һ���ַ���
���������ַ��������ܰ����ո���Ҫ��ȡһ����

������ĺϷ������ַ��������������ͬ�ͷ��غ����

�Ϸ����ְ�ֻ�ܰ��� . + - �� 0-9 ������ . ���ұ��������֣� +- �������ʼ


���ӣ�
���룺
123+1.23

�����
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
