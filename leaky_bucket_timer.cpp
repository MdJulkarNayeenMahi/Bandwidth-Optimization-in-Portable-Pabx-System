#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("a.txt", "r", stdin);
    //freopen("ab.txt", "w", stdout);
deque < pair < int, int > > Q[10000];
int orate,drop=0,cap,x,count=0,inp[10]={0},i=0,j,nsec,ch;
int bucketCount = 1, buckets[10000]={0};
printf("\n enter bucket size : ");
scanf("%d",&cap);
printf("\n enter output rate :");
scanf("%d",&orate);
do{
    printf("\n enter number of packets coming at second %d :",i+1);
    scanf("%d",&inp[i]);i++;
    printf("\n enter 1 to contiue or 0 to quit..........");
    scanf("%d",&ch);
}while(ch);
nsec=i;
printf("\n second \t recieved \t sent \t dropped \t remained \n");
int totalIn = 0, totalOut = 0;
int lastout[100] = {0};
for(i=0;totalIn > totalOut || i<nsec;i++) {
printf(" %d",i+1);
printf(" \t%d\t ",inp[i]);
int totalSent = 0;
totalIn += inp[i];
for(j = 1; j <= bucketCount; j++){
    if(cap - buckets[j] >= inp[i]){
        Q[j].push_back(make_pair(i+1, inp[i]));
        buckets[j] += inp[i];
        inp[i] = 0;
    } else {
        Q[j].push_back(make_pair(i+1, cap - buckets[j]));
        inp[i] -= cap - buckets[j];
        buckets[j] = cap;
    }
}
while(inp[i] > 0){
    bucketCount++;
    if(inp[i] <= 0) {
        inp[i] = 0;
        break;
    }
    if(cap >= inp[i]){
        Q[bucketCount].push_back(make_pair(i + 1, inp[i]));
        buckets[ bucketCount ] = inp[i];
        inp[i] = 0;
    } else {
        Q[bucketCount].push_back(make_pair(i + 1, cap));
        buckets [ bucketCount ] = cap;
        inp[i] -= cap;
    }
}
for(j = 1; j <= bucketCount; j++){
    if(buckets[j] == 0){
        bucketCount = j - 1;
        break;
    }
    if(buckets[j] > orate) {
        buckets[j] -= orate;
        totalSent += orate;
    }
    else {
        totalSent += buckets[j];
        buckets[j] = 0;
    }
    int tmp = 0;
    while(Q[j].size() > 0 && tmp < orate){
        pair < int, int > p = Q[j].front();
        if(tmp + p.second <= orate){
            Q[j].pop_front();
            lastout[p.first] = i + 1;
            tmp += p.second;
        } else {
            Q[j][0].second -= orate - tmp;
            tmp = orate;
        }
    }
}
totalOut += totalSent;
printf(" \t %d \t %d \n",bucketCount,totalSent);
}
puts("");
for(int i = 1; i <= nsec; i++) printf("%d ", lastout[i]);
puts("");
return 0;
}

