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
