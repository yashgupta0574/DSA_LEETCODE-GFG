class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &T)
        {
            int n = T.size();
            stack<int> s;
            vector<int> ans(n);
            for (int i = n - 1; i >= 0; i--)
            {
                while (!s.empty() && T[s.top()] <= T[i]) s.pop();
                if (s.empty()) ans[i] = 0;
                else ans[i] = s.top() - i;
                s.push(i);
            }
            return ans;
        }
};