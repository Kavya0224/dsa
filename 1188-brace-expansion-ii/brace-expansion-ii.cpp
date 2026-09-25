class Solution {
    set<string> multiply(const set<string>& set1, const set<string>& set2) {
        set<string> result;
        for (const string& s1 : set1) {
            for (const string& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

    set<string> combine(const set<string>& set1, const set<string>& set2) {
        set<string> result = set1;
        result.insert(set2.begin(), set2.end());
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int index = 0;
        set<string> resultSet = parseExpression(expression, index);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> parseExpression(const string& expr, int& i) {
        set<string> currentUnion;
        set<string> currentProduct = {""};

        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == ',') {
                currentUnion = combine(currentUnion, currentProduct);
                currentProduct = {""};
                i++;
            } 
            else if (expr[i] == '{') {
                i++;
                set<string> innerSet = parseExpression(expr, i);
                i++;
                currentProduct = multiply(currentProduct, innerSet);
            } 
            else {
                string word = "";
                while (i < expr.length() && isalpha(expr[i])) {
                    word += expr[i++];
                }
                currentProduct = multiply(currentProduct, {word});
            }
        }

        return combine(currentUnion, currentProduct);
    }
};