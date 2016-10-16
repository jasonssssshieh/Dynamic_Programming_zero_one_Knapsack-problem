#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<int> weight;
    vector<int> price;
    cout<< "Please input the weight & price for each element, input -1 for end"<<endl;
    int wi = 0, p = 0, n = 0;
    while(true){
        cout << "weight" << " " + to_string(n+1) <<" = ";
        cin >> wi;
        if(wi != -1){weight.push_back(wi);}
        else{break;}
        cout<< "price" << " " + to_string(n + 1) <<" = ";
        cin >> p;
        price.push_back(p);
        ++n;
    }
    int w = 0;
    cout<< "Please input the legal maximal Weight"<<endl;
    cout<< "W = ";
    cin >> w;
    
    /*
    Now suppose we want to use O(w) space complexity, we can just use dp[w+1] to store the information.
    Because we have: f(i,V) = max(f(i-1,V), f(i-1,V-weight[i]) + price[i]);
    So each time we can just use dp[j] = max(f(V), f(V-weight[i]) + price[i]);
    But here is a new problem, suppose now you are in some certain [i] and [j], and we have finished above processures, now our dp vector has
    been updated from dp[i][j-1] to dp[i][j], however, next step is figure out the dp[i][j+1], this request the information of dp[i-1][j].
    Then what should we do?
    We can set j as w, we travese j from w to 0. Because after we have updated the from dp[i][j+1] to dp[i][j], next step is updating dp[i][j], this does not
    request the information from dp[i+1][j] but dp[i-1][j].
    */
    int dp[w+1];
    for(int i = 0; i < w+1; ++i){dp[i] = 0;}
    for(int i = 0; i < n+1; ++i){
        for (int j = w; j >= 0; --j){
            if(i > 0 && j >= weight[i]) dp[j] = max(dp[j], dp[j - weight[i]] + price[i]);
        }
    }
    return dp[w];
}
