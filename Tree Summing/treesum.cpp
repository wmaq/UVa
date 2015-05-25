#include <iostream>
#include <cstdlib>
using namespace std;
char arr[1<<14];
int check(int sum, int L, int R){
    if(L==R) return false;
    int p = 0;
    int ll, lr, rl, rr;
    int pos = atoi( &arr[L] );
    ll = L;
    while( arr[ll] != '(' ) ll++;
    lr = ll+1;
    p = 1;
    while( p ) {
        if(arr[lr]=='(') p++;
        else if(arr[lr]==')') p--;
        lr++;
    }
    rl = lr;
    rr = R;
    if( sum == pos && ll+1==lr-1 && rl+1 == rr-1 ) return 1;
    else return check(sum-pos,ll+1 , lr-1) || check(sum-pos,rl+1 , rr-1);
    return 0;
}
int main(void){
    char ch;
    int i, p, sum;
    while( cin >> sum ){
        cin >> ch;
        i = 0;
        arr[i++] = ch;
        p = 1;
        while( p ){
            cin >> ch;
            arr[i++] = ch;
            if(ch=='(') p++;
            else if(ch==')') p--;
        }
        if(i==2) cout << "no" << endl;
        else if( check( sum, 1, i-1 ) ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}