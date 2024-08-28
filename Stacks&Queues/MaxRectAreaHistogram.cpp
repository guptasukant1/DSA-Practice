#include<bits/stdc++.h>
using namespace std;

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

int main(){
    // $ Maximum Rectangular Area in Histogram


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


}