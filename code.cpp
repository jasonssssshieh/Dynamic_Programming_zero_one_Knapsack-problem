//这是最基础的背包问题，特点是：每种物品仅有一件，可以选择放或不放。
//有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。
/*如果重量w1, ..., wn和W都是非负数，那么用动态规划，可以用伪多项式时间解决背包问题。
 我们同样假定w1, ..., wn和W都是正整数。我们将在总重量不超过Y的前提下，前j种物品的总价格所能达到的最高值定义为A(j, Y)。
 A(j, Y)的递推关系为：
 A(0, Y) = 0
 A(j, 0) = 0
 如果wj > Y, A(j, Y) = A(j - 1, Y)
 如果wj ≤ Y, A(j, Y) = max { A(j - 1, Y), pj + A(j - 1, Y - wj)}
 状态转移方程：c[i][j] = max{c[i-1][j], c[i-1][j-w[i]]+v[i]}
 //状态转移方程的解释：第i件物品要么放，要么不放
 //                 如果第i件物品不放的话,就相当于求前i-1件物体放入容量为j的背包获得的最大价值
 //                 如果第i件物品放进去的话,就相当于求前i-1件物体放入容量为j-w[i]的背包获得的最大价值
 
 */


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
    
    int dp[n+1][w+1];
    dp[0][0] = 0;
    for (int i = 0; i < n + 1; ++i){
        for (int j = 0; j < w + 1; ++j){//j代表目前的重量
            dp[i][j] = i==0 ? 0 : dp[i-1][j];// 说明第i件物品大于背包的重量，放不进去
            //说明第i件物品的重量小于背包的重量，所以可以选择第i件物品放还是不放
            if(i > 0 && j >= weight[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + price[i]);
                //这里之所以是用j - weight[i] 是因为这里我们选择了i, 所以重量由原来的j -》j - weight[i]，然后再加上这个weight[i] 跳到了现在的dp[i][j]
        }
    }
    int i = n, j = w;
    vector<int> chosen;
    while(dp[i][j] != 0){
        if(dp[i-1][j - weight[i]] + price[i] == dp[i][j]){
            chosen.push_back(i);
            j = j - weight[i];
        }
        --i;
    }
    
    for(auto num : chosen){
        cout<< "number is: " << num << " ,weight is:  " << weight[num] << " ,price is: " << price[num]<<endl;
    }
    
    return dp[n][w];
}
