#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
    int n;
    bool flag = true;
    int coaches[1000];

    while (flag) {
        scanf("%d",&n);
        if (n == 0)
            flag = false;
        else {
            bool flag2 = true;
            while (flag2) {
                cin >> coaches[0];
                if (coaches[0] == 0){
                    printf("\n");
                    flag2 = false;
                }
                else {
					int i = 1;
					while(i<n){
                        cin >> coaches[i];
						++i;
                    }

                    int nCoachs = 1, ax = 0;
                    stack<int> station;
                    while(nCoachs <= n && ax < n){
                        station.push(nCoachs);

                        while(!station.empty() && station.top() == coaches[ax]){
                            station.pop();
                            ++ax;
                        }

                        ++nCoachs;
                    }

                    if(ax == n && station.empty())
                        printf("Yes\n");
                    else
                        printf("No\n");
                }
            }
        }
    }

    return 0;
}
