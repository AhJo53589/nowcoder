

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void printNum(vector<int>& nums, vector<int>& ans)
    {
        for (auto idx : ans)
        {
            cout << nums[idx] << ",";
        }
        cout << endl;
    }

    vector<int> getMidNum(vector<int>& nums)
    {
        vector<int> ans;
        int maxn = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            cout << endl << "i = " << i << endl;
            while (!ans.empty() && !(nums[ans.back()] < nums[i]))
            {
                ans.pop_back();

                cout << "\t[pop]" << endl;
                cout << "\tans:\t";
                printNum(nums, ans);
            }

            if (nums[i] > maxn)
            {
                ans.push_back(i);

                cout << "\t[push]" << endl;
                cout << "\tans:\t";
                printNum(nums, ans);
            }

            maxn = max(maxn, nums[i]);
            cout << "\tmaxn = " << maxn << endl;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
    int caseNo = 1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    Solution sln;
    return sln.getMidNum(nums);
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
