#include <iostream>

using namespace std;

int main()
{
   struct interval
    {
        int id,lower,upper,f,cf;
        double mid,fm;
    };
    interval *arr;
    int num;
    cout<<"Enter number of intervals :\n";
    cin>>num;
    arr=new interval[num];
    cout<<"\t \t Lower \t Upper \t Frequency \n";
    for(int i=0; i<num; i++)
    {
        arr[i].id=i+1;
        cout<<"interval: "<<arr[i].id<<"\t";
        cin>>arr[i].lower>>arr[i].upper>>arr[i].f;
    }



    for(int i=0; i<num; i++)
    {
        arr[i].mid=(arr[i].lower+arr[i].upper)/2;

    }

    for(int i=0; i<num; i++)
    {
        arr[i].fm=arr[i].f*arr[i].mid;

    }

    arr[0].cf=arr[0].f;
    for(int i=1; i<num; i++)
    {
        arr[i].cf=arr[i-1].cf+arr[i].f;

    }

    cout<<"---------------------------------------------------------------------- \n";

    cout<<"\t \t Lower \t Upper \t Frequency \t Mid Point \t Frequency*Mid \t Cumulative Frequency \n";
    for(int i=0; i<num; i++)
    {
        cout<<"interval: "<<arr[i].id<<" \t"<<arr[i].lower<<" \t"<<arr[i].upper<<"\t \t"<<arr[i].f<<" \t \t"<<arr[i].mid<<" \t \t"<<arr[i].fm<<" \t \t \t"<<arr[i].cf<<"\n";

    }
    cout<<"---------------------------------------------------------------------- \n";

    double sum_fm =0;
    double sum_f =0;
    for(int i=0; i<num; i++)
    {
        sum_fm+=arr[i].fm;
        sum_f+=arr[i].f;
    }
    cout<<"\n";
    cout<<"==> Mean = sum_fm /sum_f = "<<sum_fm<<"/"<<sum_f<<" = "<<sum_fm/sum_f<<"\n \n";

    double y= sum_f/2;
    int h=0;
    for(int i=0; i<num; i++)
    {
       if(arr[i].cf>y)
       {
           h= arr[i].upper-arr[i].lower;
           cout<<"==> median = L+((sum_f/2-cf)/f)*h = "<< arr[i].lower<<"+"<<"("<<y<<"-"<<arr[i-1].cf<<")/"<<arr[i].f<<"*"<<h<<" = "<<arr[i].lower+((y-arr[i-1].cf)/arr[i].f)*h<<"\n \n";
           break;
       }
    }

    int max_f=arr[0].f;
    h=0;
    int x=0;
    for(int i=1;i<num;i++)
    {
        if( max_f< arr[i].f )
        {
            max_f=arr[i].f;
           x=i;

        }

    }
          h= arr[x].upper-arr[x].lower;
           cout<<"==> mode = L+((Fm-Fp) / (2Fm-Fp-Fn))*h = "<<arr[x].lower<<"+"<<h<<"*(( "<<arr[x].f<<"-"<<arr[x-1].f<<")/("<<"2*"<<arr[x].f<<"-"<<arr[x-1].f<<"-"<<arr[x+1].f<<")) = "
           <<arr[x].lower+h*((double)(arr[x].f-arr[x-1].f)/(2*arr[x].f-arr[x-1].f-arr[x+1].f))<<"\n";
           //mode=3*median-2*mean;

    return 0;
}
