class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i + 1, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};
