/*
    Nowadays, we all know that Computer College is the biggest department in HDU. But, maybe you don't know that Computer College had ever been split into Computer College and Software College in 2002.
    The splitting is absolutely a big event in HDU! At the same time, it is a trouble thing too. All facilities must go halves. First, all facilities are assessed, and two facilities are thought to be same if they have the same value. 
    It is assumed that there is N (0<N<1000) kinds of facilities (different value, different kinds).
    http://acm.hdu.edu.cn/showproblem.php?pid=1171
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

#define fr freopen("in.txt", "r", stdin)
#define fw freopen("out.txt", "w", stdout)
using namespace std;

int main(){
    int lines;
    while(cin>>lines){
        if(lines < 0)
            return 0;
        std::vector<int> values;
        int maxValue = 0;
        for(int i = 0; i < lines; i++){
            int v, m;
            cin>>v>>m;
            maxValue += (v * m);
            for(int j = 0; j < m; j++){
                values.push_back(v);
            }
        }
        std::vector<int> ans(maxValue/2 + 1, 0);
        for(int i = 0; i < values.size(); i++){
            for(int j = maxValue/2; j >= values[i]; j--){
                ans[j] = max(ans[j], ans[j - values[i]] + values[i]);
            }
        }
        cout<<maxValue - ans[maxValue/2]<<" "<<ans[maxValue/2]<<endl;
    }

}
