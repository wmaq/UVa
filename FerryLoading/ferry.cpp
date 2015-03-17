#include <iostream>
#include <queue>
#include <string>

using namespace std;

template < typename T >
T maxi(T a, T b){
   return a > b ? a : b;
}
template < typename T >
T mini(T a, T b){
    return a < b ? a : b;
}

int main(void){
   const int MAXSIZE = 10005;
   queue <int> Que[2];
   int arrive[MAXSIZE], leave[MAXSIZE];
   int testNum, n, t, m, currentTime;
   string position = "";
   
   cin >> testNum;
   while(testNum--){
      int realTime = 0, sideValue = 0;
      cin >> n >> t >> m;
      for( int i = 0; i < m; i++){
         cin >> currentTime >> position;
         arrive[i] = currentTime;
         if(position == "left") Que[0].push(i);
         else Que[1].push(i);
      }
      while( !Que[0].empty() || !Que[1].empty() ){
         int count = 0;
         int checkNext = Que[0].empty() ? arrive[ Que[1].front() ] :
            Que[1].empty() ? arrive[ Que[0].front() ] : mini<int>( arrive[ Que[0].front() ], arrive[ Que[1].front() ]);
         realTime = maxi<int>( realTime, checkNext );
         while( !Que[sideValue].empty() && arrive[Que[sideValue].front()] <= realTime && count<n ){
            leave[ Que[sideValue].front() ] = realTime + t;
            Que[sideValue].pop();
            count++;
         }
         realTime += t;
         sideValue = (sideValue+1)%2;
      }
      for( int i = 0; i<m; i++) cout << leave[i] << endl;
      if (testNum != 0) cout << endl;
   }
   return 0;
}