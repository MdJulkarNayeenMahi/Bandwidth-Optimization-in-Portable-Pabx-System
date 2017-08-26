#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x<y)?x:y
int main()
{
int orate,drop=0,cap,x,count=0,inp[10]={0},i=0,j,nsec,ch;
int bucketCount = 1, buckets[100]={0};
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
int totalIn = 0, totalOut = 0, totalTime = 0;
for(i=0;totalIn > totalOut || i<nsec;i++) {
printf(" %d",i+1);
printf(" \t%d\t ",inp[i]);
printf(" \t %d\t ",MIN((inp[i]+count),orate));
int totalSent = 0;
totalIn += inp[i];
for(j = 1; j <= bucketCount; j++){
    if(cap - buckets[j] >= inp[i]){
        buckets[j] += inp[i];
        inp[i] = 0;
    } else {
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
        buckets[ bucketCount ] = inp[i];
        inp[i] = 0;
    } else {
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
}
//if((x=inp[i]+count-orate)>0)
//{
//if(x>cap)
//{
//count=x-cap;
//bucketCount++;
//}
//else
//{
//count=x;
//drop=0;
//}
//}
//else
//{
//drop=0;
//count=0;
//}
totalOut += totalSent;
printf(" \t %d \t %d \n",bucketCount,totalSent);
}
return 0;
}
