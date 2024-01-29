// $ Operations
// ! 1 -> Push: To push an element in the Stack.
// ! 2 -> Pop: To pop the topmost element from Stack.
// ! 3 -> Peek: Views the Topmost element and selects it.
// ! 4 -> isEmpty: Checkswhether the string is empty or not.

#include <bits/stdc++.h>
using namespace std;

// ? Stack Ops
/*
class stacksol{

    public:

    int top;
    int size;
    int *arr;

    stacksol(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // ! O(1)
    int push(int el){
        if(size-top>1){
            top++;
            arr[top] = el;
        }
        else{
            cout << "Stack Overflow" << endl;
            return 0;
        }
    }
    // ! O(1)
    void pop(){
        if(top>=0){
            top--;
        }
        else cout << "Stack Underflow" << endl;
    }
    // ! O(1)
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout << "Stack Empty" << endl;
            return 0;
        }
    }
    // ! O(1)
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else return false;
    }

};
*/

/*
class twoStacks1Array{
    // Space optimization of array is there.
    // $ let there be 2 tops, 1 from -1 and the other from size of array. push into 1 from L->R
    // $ push into 2 from R->L. Both stacks use a single array and so 1 and 2 refer to the same array but from different top.
    // $ Pop reduces top in 1 but increases in 2. Number of queries for while loop, stack no and query type for stacks.

    public:
        int top1, top2, size, *arr;

        twoStacks1Array(int size=100)
        {
            this->size = size;
            arr = new int[size];
            top1 = -1;
            top2 = size;
        }

        void push1(int a){
            if(top2-top1>1){
                top1++;
                arr[top1] = a;
            }
        }
        void push2(int a){
            if(top2-top1>1){
                top2--;
                arr[top2] = a;
            }
        }

        int pop1(){
            if(top1 == -1) return -1;
            else {
                top1--;
                return arr[top1 + 1];
            }
        }
        int pop2(){
            if(top2 == -1) return -1;
            else {
                top2++;
                return arr[top2 - 1];
            }
        }
};
*/

/*
class deleteMiddleElement
{
    // $ Delete middle element via recursion. Iterative method not able to handle large data.
    // $ Correct the iterative method
    public:

    // void solve(stack<int> &s, int count, int sizeOfStack){
    //     if (count == sizeOfStack / 2)
    //     {
    //         s.pop();
    //         return;
    //     }

    //     int x = s.top();
    //     cout << "TOP: " << s.top()<<endl;
    //     s.pop();
    //     cout<<"count: " << count << endl;
    //     solve(s, count + 1, sizeOfStack);
    //     cout << "x: " << x <<endl;
    //     s.push(x);
    //     cout << "pushed"<<endl;
    // }

    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        stack<char> s1;
        int count = 0;
        int mid = sizeOfStack / 2;
        while (count < mid)
        {
            char x = s.top();
            s.pop();
            s1.push(x);
            count++;
        }
        s.pop();
        while (!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
        // int count = 0;
        // solve(s, count, sizeOfStack);
    }

};
*/

/*
class insertAtEnd{
    public:
    // $ Insert element at end of stack

    void solve(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int num = st.top();
        st.pop();
        solve(st, x);
        st.push(num);
    }

    stack<int> insert(stack<int> &st, int x){
        solve(st, x);
        return st;
    }
};
*/

/*
class reverseStack{
    public:
    // $ t=1; n=5; St={3 7 8 4 1}
    // $ The Reverse function pops the elements from the stack till base case reached.
    // $ Then the insertAtBottom function is called which first pushes the top element (1) into the now empty stack
    // $ Now, (4) will enter and will store the top element (1) in num, then it (4) itself gets pushed into the stack which was made empty
    // $ This continues for all remaining elements which reverses the order and stores them in num for each recursive call.
    // $ They then get pushed into the stack.

    void insertAtBottom(stack<int> &St, int x){
        if(St.empty()){
            St.push(x);
            return;
        }
        int num = St.top();
        St.pop();

        insertAtBottom(St, x);
        St.push(num);
    }

    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        int x = St.top();
        St.pop();

        Reverse(St);
        insertAtBottom(St, x);
    }
};

*/

/*
class sortStack{
    // $
    public:

    void sortedInsert(stack<int> &s, int num){
        if(s.empty() || ( !s.empty() && s.top()<num )){
            s.push(num);
            return;
        }
        int n = s.top();
        s.pop();

        sortedInsert(s, num);
        s.push(n);
    }


    void sorting(stack<int> &s){
        if(s.empty()) return;

        int num = s.top();
        s.pop();

        sorting(s);
        sortedInsert(s, num);
    }

};
*/

/*
class redundantBrackets{
    // $
    public:
    bool findBrackets(string s){
        stack<char> st;
        for (int i = 0; i<s.length(); i++){
            char ch = s[i];
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true) return true;
                st.pop();
            }
        }
        return false;
    }
};
*/

/*
class Solution
{
public:
    // $ Next larger (first larger to the right) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> nextLargerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && abc[i] >= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }
    // $ Previous larger (first larger to the left) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> previousLargerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && abc[i] >= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }

    // $ Next smaller (first smaller to the right) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> nextSmallerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && abc[i] <= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }

    // $ Previous smaller (first smaller to the left) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> previousSmallerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = 0; i <= n-1; i++)
        {
            while (st.top() != -1 && abc[i] <= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }
};
*/

/*
int countRev(string s){
    if(s.length()%2!=0) return -1;

    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch == '{') st.push(ch);

        else {
            if(st.top()=='{' && !st.empty()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    int closing = 0, opening = 0;
    while(!st.empty()){
        if(st.top() == '{') opening++;
        else closing++;

        st.pop();
    }
    int ans = (closing + 1) / 2 + (opening + 1) / 2;
    return ans;
}
*/


// ? Maximum Rectangular Area in a Histogram
/*
class maxAreaHistogram{
    // $ Deduce the Previous smaller and next first smaller element, that can be used to find the width of the rectangle.
    // $ A special condition will be there if the previous and next have -1 (i.e. all the elements are of same size), then the width
    public:
    vector<long long> nextSmaller(long long arr[], int n)
        {
            stack<long long int> st;
            vector<long long int> ans(n);
            st.push(-1);
            for (int i = n - 1; i >= 0; i--)
            {
                while (st.top() != -1 && arr[i] <= arr[st.top()])
                {
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }

    vector<long long> prevSmaller(long long arr[], int n){
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = 0; i < n ; i++ )
        {
            while (st.top() != -1 && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long getMaxArea(long long arr[], int n){
        vector<long long> next(n);
        next = nextSmaller(arr, n);
        vector<long long> prev(n);
        prev = prevSmaller(arr, n);

        long long area = INT_MIN;
        for(int i =0; i<n; i++){
            int l = arr[i];
            if(next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;
            long long newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};

 */


int main()
{

/*
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.size() << endl;


    int n;
    cout << "Enter the number of terms for stack: ";
    cin >> n;
    stacksol st(n);
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        st.push(v);
    }
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;
    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else cout << "Stack is not empty" << endl;
*/

// $ Two Stacks in an Array.

/*
    int t;
    cin >> t;
    while(t--){
        twoStacks1Array *st = new twoStacks1Array();

        int query;
        cin >> query;
        while(query--){
            cout << "queryno: "<< query<<endl;
            int stackno;
            int querytype=0;
            cin >> stackno;
            cin >> querytype;

            if(querytype == 1){
                int a;
                cin >> a;
                cout << "push"<< stackno << ": " << a<<endl;
                if(stackno == 1 ) st->push1(a);
                else if(stackno == 2 ) st->push2(a);
            }
            if(querytype == 2){
                if(stackno==1) cout << st->pop1() << endl;
                else if(stackno==2) cout << st->pop2() << endl;
            }
        }
    }
*/

// $ Reversing a string without stack

/*
    // ? Reversing a string using Stack TC: O(N) SC: O(N)
    // ? better approach to reverse a string is without using Stack but instead two pointers from start and from end.

    string s;
    cin >> s;
    // for( int i=0; (i<=s.length()/2 && j>s.length()/2 ); (i++ && j--) ){
    for( int i=0; i<s.length()/2; i++){
        swap(s[i], s[s.length()-i-1]);
        // char temp;
        // temp = ch2;
        // ch2 = ch;
        // ch = temp;
    }
    cout << "Reversed String: " << s << endl;
*/

// $ Reversing a string using stack

/*
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0;i<s.length(); i++){
        char ch = s[i];
        st.push(ch);
    }
    string ans = "";
    while(!st.empty()){
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout << "Reversed String: " << ans << endl;

*/

// $ Deleting middle element

/*
    int t;
    cin >> t;

    while (t--)
    {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++)
        {
            int x;
            cin >> x;
            myStack.push(x);
        }

        deleteMiddleElement dme;
        dme.deleteMid(myStack, myStack.size());
        while (!myStack.empty())
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
*/

// $ Insert Element at end of Stack

/*
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin >> n;
        cin >> x;
        stack<int> st;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            st.push(a);
        }
        insertAtEnd ob1;
        stack<int> tmp = ob1.insert(st, x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            cout << v[i];
            if(i!=v.size()-1) cout << "";
        }
        cout << endl;
    }
*/

// $ Reverse the Elements of a stack.

/*
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        reverseStack ob;
        ob.Reverse(St);
        vector<int> res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }
}
*/

// $ Sort the elements of a stack

/*
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        sortStack ob;
        ob.sorting(St);
        while (!St.empty())
        {
            printf("%d ", St.top());
            St.pop();
        }
        printf("\n");
        cout << endl;
    }
*/

// $ Check for Redundant Brackets

/*
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        redundantBrackets obj;
        int res = obj.findBrackets(s);

        cout << res << endl;
    }
*/

// $ Next/previous larger and smaller elements of each element

/*
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> abc(n);
        for (int i = 0; i < n; i++)
            cin >> abc[i];
        Solution obj;
        vector<long long> res = obj.nextLargerElement(abc, n);
        vector<long long> res1 = obj.nextSmallerElement(abc, n);
        vector<long long> res2 = obj.previousSmallerElement(abc, n);
        cout << "next larger: " << endl;
        for (long long i : res)
            cout << i << " ";
        cout << endl;
        cout << "next smaller: " << endl;
        for (long long i : res1)
            cout << i << " ";
        cout << endl;
        cout << "previous smaller: " << endl;
        for (long long i : res2)
            cout << i << " ";
        cout << endl;
    }
    return 0;
*/

// $ Count curly braces reversals

/*
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
*/

// $ Maximum Rectangular Area in Histogram

/*
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        maxAreaHistogram ob;
        cout<<ob.getMaxArea(arr, n)<<endl;

    }
    return 0;

*/

}


// *


// $
// !!!!!!!!!!!!!!!!!!!!

// $ STACK IMPLEMENTATION USING LINKED LIST

// !!!!!!!!!!!!!!!!!!!!

