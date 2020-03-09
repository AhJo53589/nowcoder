
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool boyerMoore(string text, string pattern)
    {
        map<char, int> bmBc;
        vector<int> bmGs(pattern.size(), 0);
        int m = pattern.size();
        int n = text.size();

        preBmBc(pattern, bmBc);
        preBmGs(pattern, bmGs);

        int j = 0;
        int i;
        int count = 0;
        while (j <= n - m)
        {
            for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--) 
            {
                count++;
            }
            if (i < 0) 
            {
                cout << "one position is:" << j << endl;
                j += bmGs[0];
            }
            else 
            {
                j += max(bmGs[i], getBmBc(text[i + j], bmBc, m) - m + 1 + i);
            }
        }
        cout << "count:" << count << endl;
		return false;
    }

    void preBmBc(string pattern, map<char, int>& bmBc)
    {
        cout << "bmBc start process..." << endl;
        for (int i = 0; i < pattern.size(); i++) 
        {
            bmBc[pattern[i]] = i;
        }
        for (auto& p : bmBc)
        {
            cout << p.first << "\t" << p.second << endl;
        }
    }

    void preBmGs(string pattern, vector<int>& bmGs)
    {
        int patLength = pattern.size();
        int i, j;
        vector<int> suffix(patLength);
        preSuffix(pattern, suffix);
        //模式串中没有子串匹配上好后缀，也找不到一个最大前缀
        for (i = 0; i < patLength; i++) 
        {
            bmGs[i] = patLength;
        }

        //模式串中没有子串匹配上好后缀，但找到一个最大前缀
        j = 0;
        for (i = patLength - 1; i >= 0; i--) 
        {
            if (suffix[i] == i + 1)
            {
                for (; j < patLength - 1 - i; j++) 
                {
                    if (bmGs[j] == patLength)
                    {
                        bmGs[j] = patLength - 1 - i;
                    }
                }
            }
        }

        //模式串中有子串匹配上好后缀
        for (i = 0; i < patLength - 1; i++)
        {
            bmGs[patLength - 1 - suffix[i]] = patLength - 1 - i;
        }
        cout << "bmGs: ";
        for (i = 0; i < patLength; i++) 
        {
            cout << bmGs[i] << ",";
        }
        cout << endl;
    }

    void preSuffix(string pattern, vector<int>& suffix) 
    {
        int patLength = pattern.size();
        for (int i = patLength - 2; i >= 0; i--) 
        {
            int q = i;
            while (q >= 0 && pattern[q] == pattern[patLength - 1 - i + q]) 
            {
                q--;
            }
            suffix[i] = i - q;
        }
        suffix[pattern.size() - 1] = pattern.size();
    }

    int getBmBc(char c, map<char, int>& bmBc, int m)
    {
        if (bmBc.count(c) == 0)
        {
            return m;
        }
        return bmBc[c];
    }

};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string text, string pattern)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	cout << text << endl << pattern << endl;
	Solution sln;
	return sln.boyerMoore(text, pattern);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases& tc)
//{
//    int n = tc.get<int>();
//    stringstream ss;
//    ss << n;
//    while (n-- != 0)
//    {
//		ss << tc.get<string>();
//        ss << " ";
//	}
//
//    Solution sln;
//    sln.run(ss);
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
