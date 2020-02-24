
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> runTask(map<string, int>& inDegree, map<string, vector<string>>& lst)
    {
		queue<string> que;
		for (auto i : inDegree)
		{
			if (i.second == 0) que.push(i.first);	// 将入度为 0 的结点放入队列
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

    string run(stringstream &ss) 
    {
        int n = 0;
        ss >> n;
        cout << n << endl;

        map<string, int> inDegree;
        map<string, vector<string>> lst;
        stringstream tss;
        while (n-- != 0)
        {
            string str;
            ss >> str;

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
            cout << sName << ": ";
            cout << convert<string>(lst[sName]) << endl;
        }

        auto ans = runTask(inDegree, lst);
		cout << convert<string>(ans) << endl;
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
//string _solution_run(string s1)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.run(s1);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    int n = tc.get<int>();
    stringstream ss;
    ss << n;
    while (n-- != 0)
    {
		ss << tc.get<string>();
        ss << " ";
	}

    Solution sln;
    sln.run(ss);
	return {};
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
