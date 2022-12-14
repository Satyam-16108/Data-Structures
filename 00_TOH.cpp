#include <iostream>
using namespace std;

void toh(char src,char dest,char helper,int n){
 if(n==0){
    return;
 }
 toh(src,helper,dest,n-1);
 cout<<"Move from "<<src<<"to"<<dest<<endl;
  toh(helper,dest,src,n-1);

}
int main()
{
    int n;
    cout<<"Enter the no of disks"<<endl;
    cin>>n;
 toh('A','B','C',n);
    return 0;
}