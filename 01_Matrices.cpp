#include<iostream>
using namespace std;


class DMatrix
{
    int *arr;
    int size;
public:

    DMatrix( int x)
    {
        size=x;
        if(size<=0)
        {
            cout<<"\nWrong size";
            exit(0);
        }

        else
        {
            arr=new int[size];
        }
    }
    void set(int i,int j,int x)
    {
        if(i==j)
        {
            arr[i]=x;
        }
    }

    int get(int i,int j)
    {
        if(i==j)
        {
            return arr[i];
        }
        else
        {
            return 0;
        }
    }
};

class TDiagonal
{
    int *arr;
    int size;
public:
    TDiagonal(int x)
    {
        size=x;
        if(size<=0)
        {
            cout<<"\nWrong size";
            exit(0);
        }

        else
        {
            arr=new int[3*size-2];
        }
    }
    void set(int i,int j,int x)
    {
        if(i==j)
        {
            arr[size+i-2]=x;
        }
        else if(i-j==1)
        {
            arr[i-2]=x;
        }
        else if(i-j==-1)
        {
            arr[2*size+i-2]=x;
        }
    }
    int get(int i,int j)
    {
        if(i==j)
        {
            return arr[size+i-2];
        }
        else if(i-j==1)
        {
            return arr[i-2];
        }
        else if(i-j==-1)
        {
            return arr[2*size+i-2];
        }
        else
            return 0;
    }
};

class symmetric
{
    int *arr;
    int size;
public:
    symmetric(int x)
    {
        size=x;
        if(size<=0)
        {
            cout<<"\nWrong size";
            exit(0);
        }

        else
        {
            arr=new int[(size*(size+1))/2];
        }
    }
    void set(int i,int j,int x)
    {
    if(i<=j)
        {
            arr[(((j-1)*j)/2)+(i-1)]=x;
        }
         
    }
    int get(int i,int j)
    {
        if(i<=j)                      		//if need 0 at i=j then remove = ;
        {
           return arr[(((j-1)*j)/2)+(i-1)];
        }
		else if(i>j)
        {
           return arr[(((i-1)*i)/2) + (j-1)];
        }
        else
           return 0;
    }
};

class LTriangular
{
    int *arr;
    int size;
public:
    LTriangular(int x)
    {
        size=x;
        if(size<=0)
        {
            cout<<"\nWrong size";
            exit(0);
        }

        else
        {
            arr=new int[(size*(size+1))/2];
        }
    }
    void set(int i,int j,int x)
    {
        if(i>=j)
        {
            arr[(((i-1)*i)/2)+(j-1)]=x;
        }
    }
    int get(int i,int j)
    {
        if(i>=j)
        {
            return arr[(((i-1)*i)/2)+(j-1)];
        }
        else
            return 0;
    }
};

class UTriangular
{
    int *arr;
    int size;
public:
    UTriangular(int x)
    {
        size=x;
        if(size<=0)
        {
            cout<<"\nWrong size";
            exit(0);
        }

        else
        {
            arr=new int[(size*(size+1))/2];
        }
    }
    void set(int i,int j,int x)
    {
        if(i<=j)
        {
            arr[(((j-1)*j)/2)+(i-1)]=x;
        }
    }
    int get(int i,int j)
    {
        if(i<=j)    
        {
            return arr[(((j-1)*j)/2)+(i-1)];
        }
        else
            return 0;
    }
};



int main()
{
        int ch,n,x;
    char y;
    do{
    cout<<"1 . Diagonal Matrix"<<endl
        <<"2 . Lower-Triangular Matrix"<<endl
        <<"3 . Upper-Triangular Matrix"<<endl
        <<"4 . Symmetric Matrix"<<endl 
        <<"5 . Tri-Diagonal Matrix"<<endl<<endl
        <<"Enter your choice : ";

    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        cout<<"Enter the Size of Matrix"<<endl;
        cin>>n;
        if(n<=0)
        {
            cout<<"\nWrong input";
            exit(0);
        }
        DMatrix obj1(n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                {
                    cout<<"Enter "<<i<<","<<j<<" th Index Value : ";
                    cin>>x;
                    obj1.set(i,j,x);
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout<<obj1.get(i,j)<<" ";
            }
            cout<<endl;
        }
        break;
    }

    case 2:
    {
        cout<<"Enter the Size of Matrix"<<endl;
        cin>>n;
        if(n<=0)
        {
            cout<<"\nWrong input";
            exit(0);
        }
        LTriangular obj2(n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i>=j)
                {
                    cout<<"Enter "<<i<<","<<j<<" th Index Value : ";
                    cin>>x;
                    obj2.set(i,j,x);
                }
            }
        }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cout<<obj2.get(i,j)<<" ";
                }
                cout<<endl;
            }
break;
        }
       
    

    case 3:
    {
        cout<<"Enter the Size of Matrix"<<endl;
        cin>>n;
        if(n<=0)
        {
            cout<<"\nWrong input";
            exit(0);
        }
        UTriangular obj3(n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i<=j)
                {
                    cout<<"Enter "<<i<<","<<j<<" th Index Value : ";
                    cin>>x;
                    obj3.set(i,j,x);
                }
            }
        }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cout<<obj3.get(i,j)<<" ";
                }
                cout<<endl;
            }
break;
        }
    

    case 4:
    {
        cout<<"Enter the Size of Matrix"<<endl;
        cin>>n;
        if(n<=0)
        {
            cout<<"\nWrong input";
            exit(0);
        }
        symmetric obj4(n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)				//j can also start from i for optimization
            {
                 if(i<=j)
                {
                    cout<<"Enter "<<i<<","<<j<<" th Index Value : ";
                    cin>>x;
                    obj4.set(i,j,x);
                }
            }
        }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cout<<obj4.get(i,j)<<" ";
                }
                cout<<endl;
            }
break;
        }
        
    case 5:
    {
        cout<<"Enter the Size of Matrix"<<endl;
        cin>>n;
        if(n<=0)
        {
            cout<<"\nWrong input";
            exit(0);
        }
        TDiagonal obj5(n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j || i-j==-1 || i-j==1)
                {
                    cout<<"Enter "<<i<<","<<j<<" th Index Value : ";
                    cin>>x;
                    obj5.set(i,j,x);
                }
            }
        }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cout<<obj5.get(i,j)<<" ";
                }
                cout<<endl;
            }
break;
        }    
         
    default :
        cout<<"/nWrong Choice"<<endl;
    }
    cout<<"/nEnter y to Continue : ";
    cin>>y;
    }while(y=='y');

    return 0;
}
