class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If already computed, return from memo
        if (memo.count(expression))
            return memo[expression];

        vector<int> result;

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            // If operator found, split
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine results
                for (int a : left) {
                    for (int b : right) {
                        if (ch == '+') result.push_back(a + b);
                        else if (ch == '-') result.push_back(a - b);
                        else result.push_back(a * b);
                    }
                }
            }
        }

        // Base case: no operator → pure number
        if (result.empty())
            result.push_back(stoi(expression));

        memo[expression] = result;
        return result;
    }
};
