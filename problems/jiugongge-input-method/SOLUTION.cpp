
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	string run(string& input)
	{
		vector<string> keyboard = { "0 ", "1,.?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ" };

		string ans = "";
		stringstream ss(input);
		string letter;
		while (ss >> letter)
		{
			string key = keyboard[letter[0] - '0'];
			char c = key[(letter.size() - 1) % key.size()];
			ans += c;
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
//string _solution_run(stringstream &ss)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.run(ss);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
	string str = tc.get<string>();

	Solution sln;
	return sln.run(str);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
