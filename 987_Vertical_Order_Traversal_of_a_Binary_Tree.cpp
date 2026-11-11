
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = get<0>(curr);
            int row = get<1>(curr);
            int col = get<2>(curr);

            nodes.push_back({col, row, node->val});

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        // Sort by column, row and then node value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int prevCol = INT_MIN;

        for (auto it : nodes) {
            int col = get<0>(it);
            int val = get<2>(it);

            if (col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};
