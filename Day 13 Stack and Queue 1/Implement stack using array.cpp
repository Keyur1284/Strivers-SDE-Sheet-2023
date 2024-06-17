// Problem Link :- https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

// Solved using array
// Time Complexity :- O(1)
// Space Complexity :- O(1)

//Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack :: push(int x)
{
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if( top >= 0){
        int x = arr[top];
        top--;
        return x;
    }
    else{
        return -1;
    }
}