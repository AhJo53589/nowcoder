
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int calc(int n)
	{
		bool s[10] = { false };

		int ans = 0;
		bool b = (n > 0);
		while (n != 0)
		{
			int t = n % 10;
			n /= 10;
			if (s[t]) continue;
			s[t] = true;
			ans *= 10;
			ans += t;
		}

		return b ? ans : -ans;
	}

    string run(string s1) 
	{
		int n = convert<int>(s1);
		int ans = calc(n);
		return convert<string>(ans);
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s1)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.run(s1);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
