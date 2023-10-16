class Solution
{
public:
    vector<int> getGreaterOrEqual(vector<int> height)
    {
        int n = height.size();
        stack<int> s;
        vector<int> res(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            int max = -1, maxIndex = -1;
            while (!s.empty() && height[s.top()] < height[i])
            {
                if (max < height[s.top()])
                {
                    max = height[s.top()];
                    maxIndex = s.top();
                }
                s.pop();
            }

            if (!s.empty())
            {
                res[i] = s.top();
            }
            else
            {
                res[i] = maxIndex;
            }

            s.push(i);
        }

        return res;
    }

    int trap(vector<int> &height)
    {
        int capacity = 0, n = height.size();
        vector<int> res = getGreaterOrEqual(height);
        int i = 0;
        while (i < n - 1)
        {
            int greaterIndex = res[i];
            int j = i + 1;
            int smallVal = min(height[i], height[greaterIndex]);
            while (j != greaterIndex)
            {
                capacity += smallVal - height[j];
                j++;
            }
            i = j;
        }

        return capacity;
    }
};

//TC: O(n);
//SC: O(n);