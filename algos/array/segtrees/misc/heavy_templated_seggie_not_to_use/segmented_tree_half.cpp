#include<bits/stdc++.h>
#define ui unsigned int
#define here cout<<"here "

using namespace std;

template<class var_inp,class var_seg=var_inp>
class seg_tree{
    public:
    var_seg arr[100];
    int base,size;
    int counter;//debugg

    /*
    *size = size of your array
    *base is base of your array
    */
    public: void make_tree(var_inp *st,int size,int base=0){
        counter=0;
        this->size=size;
        if(base==1){
           base=1;
           make_tree(st,1,size,1);
        }
        else{
            base=0;
            make_tree(st,0,size-1,1);
        }

    }
    /*
    *lower=lower bound of your array
    *upper=upper bound of your array
    */
    private: void make_tree(var_inp *st,int lower,int upper,int loc){
        if(lower==upper){
            //base value
            arr[loc]=set_base(st[lower]);
            return;
        }
        int mid = (lower+upper)/2;
        make_tree(st,lower,mid,2*loc);//left
        make_tree(st,mid+1,upper,2*loc+1);//right

        //merge
        arr[loc]=merge(arr[2*loc],arr[2*loc+1]);
    }

    /*
    *left = left query,right = right query
    *lower=lower bound of your array
    *upper=upper bound of your array
    */
    public: var_inp get_query(int left,int right){

        if(base==0)
            return get_query(left,right,0,size-1,1);
        else
            return get_query(left,right,1,size,1);
    }
    private: var_inp get_query(int left,int right,int lower,int upper,int l){
        var_inp a,b;
        if(left==lower&&right==upper)
            return arr[l];

        int mid = (lower+upper)/2;

        if(right<=mid){//search in left side
            return get_query(left,right,lower,mid,2*l);
        }

        else if(left>mid){//search in right side
            return get_query(left,right,mid+1,upper,2*l+1);
        }

        else{
            a=get_query(left,mid,lower,mid,2*l);//left branch
            b=get_query(mid+1,right,mid+1,upper,2*l+1);//right branch

            //merge
            return merge(a,b);
        }
    }

    //method to be changed accordingly how to merge sub nodes
    private: var_seg merge(var_seg a,var_seg b){//modify this accodingly
        return a + b;
    }

    //method to be changed accordingly how to set base value in seg_tree
    private: var_seg set_base(var_inp a){//modify this accodingly
        return a;
    }

};//end seg class

int main()
{
    int t=1;
//  cin>>t;
    while(t--)
    {
        ui aray[]={0,5,4,3,2,1};
        seg_tree<ui> seg;
        seg.make_tree(aray,sizeof(aray)/sizeof(aray[0]));
        cout<<"ans : "<<seg.get_query(1,3)<<"\n";
    }
    return 0;
}
