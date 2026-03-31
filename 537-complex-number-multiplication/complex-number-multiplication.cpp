class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int plus1 = num1.find('+');
        int plus2 = num2.find('+');
        int a = stoi(num1.substr(0, plus1));
        int b = stoi(num1.substr(plus1 + 1, num1.size() - plus1 - 2));
        int c = stoi(num2.substr(0, plus2));
        int d = stoi(num2.substr(plus2 + 1, num2.size() - plus2 - 2));

        int realPart = (a * c) - (b * d);
        int imagPart = (a * d) + (b * c);
        
        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
};