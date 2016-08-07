class Solution {
public:
    int calculate(string s) {
        stack<char> op;
	        stack<int> num;
	        for(int i = 0; i < s.length(); i ++) {
	            if(s[i] == ' ')
	                continue;
	            if(s[i] >= '0' && s[i] <= '9') {
	                int number = 0;
	                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
	                    number = number * 10 + s[i] - '0';
	                    i ++;
	                }
	                if(op.size() > 0 && (op.top() == '*' || op.top() == '/')) {
	                    int preNumber = num.top();
	                    num.pop();
	                    if(op.top() == '*')
	                        number = preNumber * number;
	                    else
	                        number = preNumber / number;
	                    op.pop();
	                }
	                num.push(number);
	                i --;
	            }
	            else
	                op.push(s[i]);
	        }
	        int ret = 0;
	        while(num.size() > 1) {
	            int num1 = num.top();
	            num.pop();
	            if(op.top() == '-')
	                ret = ret - num1;
	            else
	                ret = ret + num1;
	            op.pop();
	        }
	        return ret + num.top();
    }
};