#include <bits/stdc++.h>
using namespace std;

int main()
{
    int item_count;
    cout << "Enter the number of items: ";
    cin >> item_count;
    int w[item_count], val[item_count];
    int W;
    cout << "Enter the max weight of the knapsack: ";
    cin >> W;
    cout << "Enter the item weights: " << endl;
    for (int i = 0; i < item_count; i++)
    {
        cin >> w[i];
    }
    cout << "Enter the item value: " << endl;
    for (int i = 0; i < item_count; i++)
    {
        cin >> val[i];
    }

    int t[item_count + 1][W + 1];
    // for (int i = 0; i <= item_count; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         if (i == 0 || j == 0)
    //             t[i][j] = 0;
    //     }
    // }
    for (int i = 0; i <= item_count; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else
            {
            if (w[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - w[i - 1]], t[i - 1][j]);
                // W=W-w[i-1];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
            }
        }
    }
    cout << "Max profit is: " << t[item_count][W];
    return 0;
}