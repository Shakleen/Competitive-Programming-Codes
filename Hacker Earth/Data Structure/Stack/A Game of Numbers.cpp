#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-6
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define FORL(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            printf("Case %d:", z);
#define sz(a)               a.size()
#define all(x)              x.begin(),x.end()
#define SORT(a,n)           sort(a,a+n)
#define RSORT(a,n)          sort(a,a+n,greater<ll>())
#define VSORT(v)            sort(all(v))
#define VRSORT(v)           sort(all(v),greater<ll>())
#define pii                 pair <int, int>
#define pll                 pair <ll, ll>
#define pb                  push_back
#define pf                  push_front
#define pob                 pop_back()
#define pof                 pop_front()
#define ff                  first
#define ss                  second
#define mp                  make_pair
#define ms(x,n)             memset((x),n,sizeof(x))
#define fin                 freopen("in.txt", "r", stdin)
#define fout                freopen("out.txt", "w", stdout)
#define IT(it,x)            for(it=x.begin(); it != x.end(); it++)
#define sf1(x)              scanf("%d", &x)
#define sfl1(x)             scanf("%lld", &x)

//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    ll n=0, a[30000]={}, NGE[30000]={}, NSE[30000]={}, temp=0;
    stack<ll>stk;

    cin>>n;

    REP(i,n)    cin>>a[i];

    stk.push(0);
    REP(i,n){
        while(!stk.empty())
            if(a[stk.top()]<a[i])   NGE[stk.top()]=i, stk.pop();
            else                    break;
        stk.push(i);
    }

    while(!stk.empty()) NGE[stk.top()]=-1LL, stk.pop();

    stk.push(0);
    REP(i,n){
        while(!stk.empty()){
            if(a[stk.top()]>a[i])   NSE[stk.top()]=i,   stk.pop();
            else                    break;
        }
        stk.push(i);
    }

    while(!stk.empty()) NSE[stk.top()]=-1LL, stk.pop();

//    printf("NGE\t\tNSE\n");
//    REP(i,n){
//        printf("%d->%lld\t\t%d->%lld\n",i,NGE[i],i,NSE[i]);
//    }

    REP(i,n){
        temp = NGE[i];
        if(temp <= -1)              cout<<-1;
        else if(NSE[temp] <= -1)    cout<<-1;
        else                        cout<<a[NSE[temp]];
        cout<<' ';
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


