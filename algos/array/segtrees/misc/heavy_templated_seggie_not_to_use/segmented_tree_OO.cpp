#include<bits/stdc++.h>
#define ui unsigned int
#define here cout<<"here "

using namespace std;

/*
 *create object of this class using suitable data types
 *modify methods merge,update_diff,set_base accordingly
 *modify default lazy_default value accordingly
 *start with make_tree()....dont forget to mention base if you are using 1 based array
 */
template<class var_inp,class var_seg=var_inp>
class seg_tree{
    public:
    class node{
        public:
        var_seg data,lazy;
        int left_end,right_end;
    }arr[300000];
    var_inp orig_arr[300000];
    const static var_seg lazy_default=0;//modify accordingly
    int base,size;

    /*
     *size = size of your array
     *base is base of your array
     */
    public: void make_tree(var_inp *st,int size,int base=0){
        this->size=size;
        if(base==1){
           this->base=1;
           make_tree(st,1,size,1);
        }
        else{
            this->base=0;
            make_tree(st,0,size-1,1);
        }
    }
    /*lower=lower bound of your array
     *upper=upper bound of your array
     */
    private: void make_tree(var_inp *st,int lower,int upper,int loc){
        if(lower==upper){
            //set base value
            arr[loc].data=set_base(st[lower]);
            //set left right
            arr[loc].left_end=arr[loc].right_end=lower;
            //base vaue for lazy
            arr[loc].lazy=lazy_default;//its default value
            //save the orig one
            orig_arr[lower]=st[lower];
            return;
        }
        int mid = (lower+upper)/2;
        make_tree(st,lower,mid,2*loc);//left
        make_tree(st,mid+1,upper,2*loc+1);//right

        //merge
        arr[loc].data=merge(lower,upper,lower,upper,loc);
        arr[loc].left_end=arr[2*loc].left_end;
        arr[loc].right_end=arr[2*loc+1].right_end;
        arr[loc].lazy=lazy_default;
    }//end make_tree

    /*
    *left = left query,right = right query
    *lower=lower bound of your array
    *upper=upper bound of your array
    */
    public: var_seg get_query(int left,int right){
        if(base==0)
            return get_query(left,right,0,size-1,1);
        else
            return get_query(left,right,1,size,1);
    }
    private: var_seg get_query(int left,int right,int lower,int upper,int loc){
        //lazy task to be completed first
        if(arr[loc].lazy!=lazy_default){
            var_seg temp = arr[loc].lazy;
            if(lower!=upper){
                arr[2*loc].lazy+=temp;
                arr[2*loc+1].lazy+=temp;
            }
            arr[loc].data = update_diff(arr[loc].data,temp,upper-lower);
            arr[loc].lazy = lazy_default;
        }

        if(left==lower&&right==upper)
            return arr[loc].data;

        int mid = (lower+upper)/2;

        if(right<=mid){//search in left side
            return get_query(left,right,lower,mid,2*loc);
        }
        else if(left>mid){//search in right side
            return get_query(left,right,mid+1,upper,2*loc+1);
        }
        else{
            return merge(left,right,lower,upper,loc);
        }
    }//end get_query

    /*
     *diff = diff to be added
     */
    public: void update_query(int left,int right,var_inp diff){
        if(base==0)
            update_query(left,right,0,size-1,1,diff);
        else
            update_query(left,right,1,size,1,diff);
    }
    private: void update_query(int left,int right,int lower,int upper,int loc,int diff){
        int mid = (upper+lower)/2;
        var_seg a,b;
        if(left==lower && right==upper){
            //update_diff
            arr[loc].data=update_diff(arr[loc].data,diff,upper-lower);
            if(upper!=lower){
                arr[2*loc].lazy+=diff;
                arr[2*loc+1].lazy+=diff;
            }
            return ;
        }
        else if(right <= mid){
            update_query(left,right,lower,mid,2*loc,diff);
        }
        else if(left > mid){
            update_query(left,right,mid+1,upper,2*loc+1,diff);
        }
        else{
            update_query(left,mid,lower,mid,2*loc,diff);
            update_query(mid+1,right,mid+1,upper,2*loc+1,diff);
        }

        //intentionally lower and upper instead of left right
        arr[loc].data = update_merge(left,right,lower,upper,loc);
    }

    //method to be changed accordingly how to merge sub nodes
    private: var_seg merge(int left,int right,int lower,int upper,int loc){
        //modify this accodingly
        int mid = (upper+lower)/2;
        var_seg a,b;

        a=get_query(left,mid,lower,mid,2*loc);//left branch
        b=get_query(mid+1,right,mid+1,upper,2*loc+1);//right branch

        return a + b;
    }

    private: var_seg update_diff(var_seg a,var_inp b,int size){
        //modify it how you want to update it
        return a + b*(1+size);
    }

    //method to be changed accordingly how to merge sub nodes while update
    private: var_seg update_merge(int left,int right,int lower,int upper,int loc){
        int mid = (upper+lower)/2;
        var_seg a,b;

        a=get_query(lower,mid,lower,mid,2*loc);//left branch
        b=get_query(mid+1,upper,mid+1,upper,2*loc+1);//right branch

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
    while(t--)
    {
        ui aray[]={0,5,4,3,2,1};
        seg_tree<ui> seg;
        seg.make_tree(aray,sizeof(aray)/sizeof(aray[0]));
        cout<<"ans : "<<seg.get_query(1,3)<<"\n";
        seg.update_query(1,4,2);
        cout<<"ans : "<<seg.get_query(1,3)<<"\n";
        cout<<"ans : "<<seg.get_query(4,4)<<"\n";
        seg.update_query(3,5,3);
        cout<<"val : "<<seg.arr[13].data<<"\n";
        cout<<"ans : "<<seg.get_query(4,4)<<"\n";
        cout<<"val : "<<seg.arr[13].data<<"\n";
        cout<<"seg.arr[0].left : "<<seg.arr[1].left_end<<" "<<seg.arr[1].right_end<<"\n";
    }
    return 0;
}
