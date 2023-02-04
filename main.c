#include <stdio.h>
#include <string.h>
long long int len[60];
char str[] = "OuQ";
char f(int k, long long j);

int main(void) {
    int k;
    long long int l, r;
    while(scanf("%d%lld%lld", &k, &l, &r) == 3) {
        for(int i = 1; i <= k; i++) {
            if(i == 1) {
                len[1] = 3;
            }else {
                len[i] = 2*len[i-1] + 3;
            }
        }
        for(int j = l; j <= r; j++) {
            printf("%c", f(k, j));
        }
        printf("\n");
    }
}

char f(int k, long long j) {
    //Basis Step
    if(k == 1) {
        if(j == 0) return str[0];
        else if(j == 1) return str[1];
        else if(j == 2) return str[2];
    }
    //Recursive Step
    if(j < 1) return str[0];
    else if(j < 1+len[k-1]) return f(k-1, j-1);
    else if(j < 1+len[k-1]+1) return str[1];
    else if(j < 1+len[k-1]+1+len[k-1]) return f(k-1, j-(1+len[k-1]+1));
    else return str[2];
}