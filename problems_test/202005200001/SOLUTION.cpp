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

    bool isStartNum(char c) {
        return c >= '1' && c <= '9';
    }

    bool checkStart(char c) {
        return (isStartNum(c) || isPlus(c));
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
                if (isDot(str[j])) {
                    if (dotFlag) break;
                    dotFlag = true;
                    continue;
                }
                break;
            }

            int newLen = j - i;
            if (newLen == 1 && isPlus(str[i])) continue;
            if (dotFlag && isDot(str[j - 1]))
            {
                i = j;
                continue;
            }

            if (len <= newLen) {

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

std::vector<std::string> findFiles(std::string dir) {
    std::vector<std::string> files;

    _finddata_t fileDir;
    intptr_t lfDir = 0;
    if ((lfDir = _findfirst(dir.c_str(), &fileDir)) == -1l) return {};
    do {
        files.push_back(fileDir.name);
    } while (_findnext(lfDir, &fileDir) == 0);
    _findclose(lfDir);

    return files;
}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    string dir = "C:\\AhJo53589\\nowcoder\\problems_test\\202005200001\\testcase\\";
    string extension = "*.in";
    vector<string> files_in = findFiles(dir + extension);

    streambuf* backupcin = cin.rdbuf();
    streambuf* backupcout = cout.rdbuf();
    ifstream fin;
    ofstream fout;
    for (auto f : files_in) {
        cout << f << endl;

        string strin = dir + f;
        fin.open(strin.c_str());
        //FILE* ssin;
        //freopen_s(&ssin, strin.c_str(), "r", stdin);

        f = f.replace(f.find(".in"), 3, ".out");
        cout << f << endl;

        string strout = dir + f;
        fout.open(strout.c_str());
        //FILE* ssout;
        //freopen_s(&ssout, strout.c_str(), "w", stdout);

        cin.rdbuf(fin.rdbuf());
        cout.rdbuf(fout.rdbuf());
        Solution sln;
        sln.main();

        cin.rdbuf(backupcin);
        cout.rdbuf(backupcout);
        fin.close();
        fout.close();
        //freopen_s(&ssout, "CON", "w", stdout);

        //f = f.replace(f.find(".out"), 4, ".ans");
        //cout << f << endl;

        //string strans = dir + f;
        //FILE* ssans;
        //freopen_s(&ssans, strans.c_str(), "r", stdin);
        //char c;
        //while ((c = getchar()) != EOF && c != '\n') putchar(c);
        //cout << endl;
    }

    return {};
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
