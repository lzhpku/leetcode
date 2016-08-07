class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        for(int i = 0; i < s.length(); i ++) {
        	if(s[i] == ' ')
        	    continue;
            if(s[i] == ')') {
            	int sum = 0;
                while(op.top() != '(') {
                    int num1 = num.top();
                    num.pop();
                    char op1 = op.top();
                    op.pop();
                    if(op1 == '+')
                        sum = sum + num1;
                    else
                        sum = sum - num1;
                }
                sum = sum + num.top();
                num.pop();
                num.push(sum);
                op.pop();
            }
            else {
                if(s[i] == '+' || s[i] == '-' || s[i] == '(')
                    op.push(s[i]);
                else {
                	int number = 0;
                	while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                		number = number * 10 + s[i] - '0';
                		i ++;
                	}
                    num.push(number);
                    i --;
                }
            }
        }
        int sum = 0;
        while(num.size() > 1) {
        	int num1 = num.top();
        	num.pop();
        	char op1 = op.top();
        	op.pop();
        	if(op1 == '+')
        		sum = sum + num1;
        	else
        		sum = sum - num1;
        }
        return num.top() + sum;
    }
};