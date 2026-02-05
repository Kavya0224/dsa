class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string,int> myMap;
        return help(expression,myMap);
    }

    int help(string expression, unordered_map<string,int> myMap) {

        // number
        if ((expression[0] == '-') || isdigit(expression[0]))
            return stoi(expression);

        // variable
        if (expression[0] != '(')
            return myMap[expression];

        // remove outer ()
        string s = expression.substr(1, expression.size()-2);
        int start = 0;

        string word = parse(s,start);

        if (word == "let") {
            while (true) {
                string variable = parse(s,start);

                if (start >= s.size())
                    return help(variable,myMap);

                string temp = parse(s,start);
                myMap[variable] = help(temp,myMap);
            }
        }

        else if (word == "add")
            return help(parse(s,start),myMap)
                 + help(parse(s,start),myMap);

        else if (word == "mult")
            return help(parse(s,start),myMap)
                 * help(parse(s,start),myMap);

        return 0;   // safety
    }

    // split expression
    string parse(string &s, int &start) {
        int end = start+1;
        int temp = start;
        int count = 1;

        if (s[start] == '(') {
            while (end < s.size() && count != 0) {
                if (s[end] == '(') count++;
                else if (s[end] == ')') count--;
                end++;
            }
        }
        else {
            while (end < s.size() && s[end] != ' ')
                end++;
        }

        start = end + 1;
        return s.substr(temp, end-temp);
    }
};
