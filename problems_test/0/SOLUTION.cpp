
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> runTask(map<string, int>& inDegree, map<string, vector<string>>& lst)
    {
        queue<string> que;
        for (auto i : inDegree)
        {
            if (i.second == 0) que.push(i.first);    // 将入度为 0 的结点放入队列
        }

        vector<string> ans;
        while (!que.empty())
        {
            auto q = que.front();
            que.pop();
            ans.push_back(q);

            for (auto l : lst[q])
            {
                if (--inDegree[l] == 0) que.push(l);
            }
        }

        return ans;
    }

    int main() 
    {
        int n = 0;
        cin >> n;
        //cout << n << endl;

        map<string, int> inDegree;
        map<string, vector<string>> lst;
        stringstream tss;
        while (n-- != 0)
        {
            string str;
            cin >> str;

            str = str.replace(str.find("("), 1, " ");
            str = str.replace(str.find(")"), 1, " ");
            while (str.find(",") != string::npos)
            {
                str = str.replace(str.find(","), 1, " ");
            }

            tss.clear();
            tss << str;

            string sName;
            tss >> sName;
            inDegree[sName] = 0;
            while (tss >> str)
            {
                if (str == "NULL") break;
                inDegree[str]++;
                lst[str].push_back(sName);
            }
            //cout << sName << ": ";
            //cout << convert<string>(lst[sName]) << endl;
        }

        auto ans = runTask(inDegree, lst);
        for (auto s : ans)
        {
            cout << s << " ";
        }
        return {};
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
    freopen_s(&ssin, "C:\\AhJo53589\\nowcoder\\problems_test\\0\\1.in", "r", stdin);

    FILE* ssout;
    freopen_s(&ssout, "C:\\AhJo53589\\nowcoder\\problems_test\\0\\1.out", "w", stdout);

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
