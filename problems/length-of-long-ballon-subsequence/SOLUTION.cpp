
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void f(vector<int>& nums, stack<int>& st, vector<int>& cnt, int i)
    {
        if (!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
        cnt[i] += st.size();
    }

    int lengthOfLongBallonSubsequence(vector<int>& nums)
    {
        stack<int> st_inc;
        stack<int> st_dec;
        vector<int> inc(nums.size(), 0);
        vector<int> dec(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            f(nums, st_inc, inc, i);
            f(nums, st_dec, dec, nums.size() - i - 1);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = (inc[i] != 1 && dec[i] != 1) ? max(ans, inc[i] + dec[i] - 1) : ans;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.lengthOfLongBallonSubsequence(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
