#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    char c[n][m];
    int i, j;
    for(i = 0; i < n; i++){
        scanf("%s\n", c[i]);
        printf("%d\n", i);
    }
    printf("%d\n",i);
    for(i = 0; i < n + 1; i++){
        for(j = 0; j < m; j++)
            printf("%c",c[i][j]);
        printf("\n");
    }
    // system("pause");
    return 0;
}
