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

    bool isStartChar(char c) {
        return (isStartNum(c) || isPlus(c));
    }
    
    bool checkValidNum(string& str, int i, int& j, int& nextPos) {
        nextPos = i + 1;
        if (!isStartChar(str[i])) return false;
           
        int dotPos = -1;
        j = i + 1;
        for (; j < (int)str.size(); j++) {
            if (isNum(str[j])) continue;
            if (isDot(str[j])) {
                if (dotPos != -1) break;  // second dot
                if (!isNum(str[j - 1])) break;  // not num before dot
                dotPos = j;
                continue;
            }
            break;
        }

        if (isPlus(str[j - 1])) {
            return false;  // plus only
        }
        
        if (isDot(str[j - 1]))
        {
            nextPos = j;
            j--;
            return true;  // dot at last
        }      
                    
        if (dotPos != -1 && isDot(str[j])) { 
            nextPos = dotPos + 1;
            return true;  // multi dot
        }

        nextPos = j;
        return true;
    }

    string getLonggestNum(string& str) {
        int len = 0;
        int start = 0;
        
        int nextPos = 0;
        for (int i = 0; i < (int)str.size(); i = nextPos) {
            int j = 0;
            if (!checkValidNum(str, i, j, nextPos)) continue;
            
            int newLen = j - i;
            if (len <= newLen) {
                start = i;
                len = newLen;
            }
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

vector<string> _getFileString(string file) {
    ifstream fs(file.c_str());
    string temp;
    vector<string> str;
    while (getline(fs, temp)) {
        str.push_back(temp);
    }
    fs.close();

    return str;
}

bool _checkAnswer(string dir_in, string dir_out, string dir_answer) {
    vector<string> strIn = _getFileString(dir_in);
    vector<string> strOut = _getFileString(dir_out);
    vector<string> strAnswer = _getFileString(dir_answer);

    int posStart = dir_answer.find_last_of("\\") + 1;
    int posEnd = dir_answer.find(".");
    string strNo = dir_answer.substr(posStart, posEnd - posStart);

    cout << "////////////////////////////////////////////////////////////" << " ## " << strNo << endl;
    cout << endl << "-- INPUT --" << endl;
    printVectorT(strIn, 1, ' ');
    cout << endl << "-- OUTPUT --" << endl;
    printVectorT(strOut, 1, ' ');
    cout << endl << "-- ANSWER --" << endl;
    printVectorT(strAnswer, 1, ' ');

    if (strOut != strAnswer) {
        cout << "\t\t\t\t\t\t\t\t\t\t\033[7m\033[1m## WRONG ANSWER ##\033[0m" << endl;
    }
    else {
        cout << endl;
    }
    cout << endl;

    return (strOut == strAnswer);
}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    string dir_out = "solution.out";


    string dir = "C:\\AhJo53589\\nowcoder\\problems_test\\202005200001\\testcase\\";
    string extension = "*.in";
    vector<string> files_in = findFiles(dir + extension);

    streambuf* backupcin = cin.rdbuf();
    streambuf* backupcout = cout.rdbuf();

    ifstream fanswer;
    ifstream fin;
    ofstream fout;

    for (auto f : files_in) {
        string dir_in = dir + f;
        f = f.replace(f.find(".in"), 3, ".answer");
        string dir_answer = dir + f;


        vector<string> strAnswer;
        fanswer.open(dir_answer.c_str());
        string temp;
        while (getline(fanswer, temp)) {
            strAnswer.push_back(temp);
        }
        fanswer.close();



        fin.open(dir_in.c_str());
        fout.open(dir_out.c_str());
        cin.rdbuf(fin.rdbuf());
        cout.rdbuf(fout.rdbuf());

        Solution sln;
        sln.main();

        cin.rdbuf(backupcin);
        cout.rdbuf(backupcout);

        fin.close();
        fout.close();

        _checkAnswer(dir_in, dir_out, dir_answer);
    }

    return {};
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
