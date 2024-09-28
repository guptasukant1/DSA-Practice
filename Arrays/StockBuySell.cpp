#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Stock Buy Sell to Maximize Profit
// | Given an array of stock prices, find the maximum profit that can be earned by buying and selling stocks on different days.

// $ Brute-Force: maintain 2 loops, one for buying and one for selling, find the max profit from the values obtained
// $ Time complexity: O(n^2)

// $ Optimal: Maintain 2 variables, minPrice and maxProfit, iterate through the array and update the variables accordingly
// $ Time complexity: O(n)

int maxProfit(vi &prices)
{
    int maxProfit = 0, minPrice = INT_MAX;
    int n = prices.size();

    for (int i = 0; i < n; i++)
    {
        minPrice = min(prices[i], minPrice);
        // * To improve runtime, update the maxProfit only when it is less than the current Profit
        int currentProfit = prices[i] - minPrice;
        if (currentProfit > maxProfit)
            maxProfit = currentProfit;
        // maxProfit = max(prices[i] - minPrice, maxProfit);
    }
    return maxProfit;
}

int maxProfit1(vi &prices1)
{
    int maxCur = 0, maxSoFar = 0;
    for (int i = 1; i < prices1.size(); i++)
    {
        maxCur = max(0, maxCur += prices1[i] - prices1[i - 1]);
        maxSoFar = max(maxCur, maxSoFar);
    }
    return maxSoFar;
}

int main()
{
    vi prices = {2, 1, 5, 8, 6, 4};
    vi prices1 = {0, -1, 4, 3, 2, -2};
    int maxProf = maxProfit(prices);
    cout << "Maximum Profit: " << maxProf << endl;
    int maxProf1 = maxProfit1(prices1);
    cout << "Maximum Profit: " << maxProf1 << endl;
}