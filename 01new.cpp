//
//  main.cpp
//  01背包问题
//
//  Created by Zijian Xie on 2016/11/5.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class zero_one{
private:
    vector<int> weight;
    vector<int> value;
    int max_value;
public:
    zero_one(vector<int>& weights, vector<int>& values, int n){
        weight = weights;
        value = values;
        max_value = n;
    }
    
    int DProgamming(){
        vector<int> dp(max_value + 1, 0);
        for(int i = 0; i < (int)weight.size(); ++i){
            for(int j = max_value; j >= weight[i]; --j){//必须倒过来！！防止重复计算！！！
                if(j < weight[i]){
                    dp[j] = dp[j-1];
                }else{
                    dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);//注意这里既然压缩了空间，就是dp[j]不要写成dp[j-1]!!!!
                }
            }
        }
        return dp[max_value];
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> weights = {6,13,2,5};
    vector<int> values = {60,150,20,50};
    int n = 13;
    zero_one* test = new zero_one(weights, values, n);
    int res = test->DProgamming();
    std::cout <<res<<endl;
    return 0;
}

/*
在求最优解的背包问题中，一般有两种不同的问法：1、要求“恰好装满背包”时的最优解；2、求小于等于背包容量的最优解，即不一定恰好装满背包。

这两种问法，在初始化的时候是不同的。

1、要求“恰好装满背包”时的最优解：

在初始化时除了f[0]为0其它f[1..V]均设为-∞，这样就可以保证最终得到的f[N]是一种恰好装满背包的最优解。如果不能恰好满足背包容量，即不能得到f[V]的最优值，则此时f[V]=-∞，这样就能表示没有找到恰好满足背包容量的最优值。

2、求小于等于背包容量的最优解，即不一定恰好装满背包：

如果并没有要求必须把背包装满，而是只希望价值尽量大，初始化时应该将f[0..V]全部设为0。
*/
