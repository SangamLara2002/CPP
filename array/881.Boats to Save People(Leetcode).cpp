//https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30
Soltuion:
class CustomStack {
public:
    vector<int> stack;
    int top;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top < (int)stack.size() - 1) {
            top++;
            stack[top] = x;
        }
    }

    int pop() {
        if (top != -1) {
            return stack[top--];
        }
        return -1;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, top + 1); i++) {
            stack[i] += val;
        }
    }
};

/*
if (top < stack.size() - 1) this will be always false because top is of int type and stack.size() is unsigned int type so internally type conversion occur and top will type cast to unsigned int and -1 will converted to a large +ve value(4294967285 in 32bit processor).
** Example : **
 int main() {
int a = -9;
cout<<a<<endl;
cout<<(unsigned int)a;
return 0;
}
So to get the proper result you need to write** if (top < (int)stack.size() - 1)**

Explaination : 
1. During the comparison, if one of the operands is signed (e.g., top is int), and the other is unsigned (e.g., the result of stack.size() is of type size_t), the signed integer is converted to an unsigned integer.
1. If the signed integer is negative (like -1), it is converted to a large unsigned value because unsigned integers cannot represent negative numbers. For example, on a typical 32-bit system, -1 would convert to 4294967295 (the maximum value for a 32-bit unsigned integer).
*/