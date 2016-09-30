#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define MM(a,x) memset(a,x,sizeof(a)) 
using namespace std;



unsigned gcd(unsigned x, unsigned y){
    unsigned wk;
    if(x<y){ wk=x;x=y;y=wk; }
    while(y){
        wk = x%y;
        x=y;
        y=wk;
    }
    return x;
}

int gcd_a(int n, int a[n]){
    if(n==1) return a[0];
    if(n==2) return gcd(a[0], a[1]);
    int h = n / 2;
    return gcd(gcd_a(h, &a[h-1]), gcd_a(n - h, &a[h]));
}

int main(void){
    int A[10]={112, 160, 180, 240, 288, 32, 480, 96, 60, 72};
    int size_A = sizeof(A)/sizeof(*A);
    int gcd = gcd_a(size_A, A);
    printf("%d\n", gcd);
    return 0;
}
