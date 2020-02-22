
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int game2(int n, int k = 3)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = (ans + k) % i;
		}
		return ans + 1;
	}

	vector<int> game(int n, int k = 3)
	{
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		for (int i = 0; i < n; i++)
		{
			cur->next = new ListNode(i + 1);
			cur = cur->next;
		}
		cur->next = dummy->next;
		delete dummy;

		vector<int> ans;
		int t = 0;
		while (cur->next != cur)
		{
			t = (t + 1) % k;
			if (t == 0)
			{
				ListNode* p = cur->next;
				ans.push_back(p->val);
				cur->next = p->next;
				delete p;
			}
			else
			{
				cur = cur->next;
			}
		}
		ans.push_back(cur->val);
		delete cur;

		return ans;
	}

    string run(string s1, string s2) 
	{
		int cnt = convert<int>(s1);
		while (cnt-- != 0)
		{
			int n = 0;
			n = convert<int>(s2);
			auto ans = game(n);
			printVectorT(ans);
			cout << game2(n) << endl;
		}
		return {};
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s1, string s2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.run(s1, s2);
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
