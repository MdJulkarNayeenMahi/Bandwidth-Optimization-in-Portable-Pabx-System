#include<bits/stdc++.h>

using namespace std;

int main(){
    int bucket_size,event=0,total=0;
    int time_arrival,packet_num;
    int have=0,previous_time=0;
    cout<<"Enter bucket size: "<<endl;
    cin>>bucket_size;
    while(true){
        cout<<"Enter time of arrival & packet size"<<endl;
        cin>>time_arrival>>packet_num;
        int interval=time_arrival-previous_time;
        packet_num+=have;
        total+=packet_num;
        have=(packet_num%bucket_size);
        previous_time=time_arrival;
        total-=have;
        cout<<"Time interval between "<<event<<"th packet & "<<event+1<<"th packet is = "<<interval<<endl;
        cout<<"Total packet send upto "<<time_arrival<<" = "<<total<<endl;
        event++;
    }
    return 0;
}
