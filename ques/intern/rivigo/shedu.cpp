#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;
int ow;

class Trip{
    public:
	int type; // 1 for left to right ; -1 for right to left ;
	int id,st,et;
    string sp,ep;
	bool imp,paired;

	Trip(int id_, string s_, string e_, int st_ , int et_){
		id = id_; st = st_; et = et_;
		if(et_ > ow) imp = false; else imp = true;
        if (s_ > e_) {
            type = -1;
            sp = e_; ep = s_;
        }
        else {
            type = 1;
            sp = s_; ep = e_;
        }
		paired = false;
	}

	bool operator < (Trip t) { return st < t.st; }
};
Trip off_trip(-1,"","",-1,-1);

class Rooute{
    public:
	string l,r;
	int t;
	vector<Trip> lr,rl;
	Rooute (string l_, string r_, int t_) { l = l_; r = r_; t = t_; }
	Rooute () { l = ""; r = ""; t = -1; }

	void add_trip(Trip t) {
		if(t.type == 1)	lr.push_back(t);
		else rl.push_back(t);
	}
    void sort_trips(){
        sort(lr.begin(),lr.end());
        sort(rl.begin(),rl.end());
    }
};
map <string,Rooute> route;

string get_route(string l, string r){
	if(l > r) return r+l;
	return l+r;
}

class Ans{
    public:
	int id0, id1,cost;
	string s,e,m;
	Ans(Trip & t1, Trip & t2){
		t1.paired = true; t2.paired = true;
		if(t2.id == -1) {//off trip
			m = "-1";
			id1 = -1;
			id0 = t1.id;
			s = t1.sp; e = t1.ep;
            cost = 0;
		} else {
			if ( t1 < t2) {
				id0 = t1.id; id1 = t2.id;
                s = t1.sp; e = t1.ep;
                m = e;
                cost = get_cost(t2.st - t1.et);
			} else {
				id0 = t2.id; id1 = t1.id;
                s = t2.sp; e = t2.ep;
                m = e;
                cost = get_cost(t1.st - t2.et);
			}
		}// end else
	}// end constructor
    int get_cost(int x){
        if ( x < 10 ) return x;
        return 10 + (x-10)*2;
    };
	int print_it(){
		cout << s << " " << e << " " << id0 << " " << id1 << " " << m << endl;
        return cost;
	}
};
vector<Ans> ans;

int main(){
    freopen("input","r",stdin);
	int t,s,time,id;
	string left,right,start,end;
	cin>>t>>s>>ow;

	for(int i=0;i<t;i++){
		cin>>left>>right>>time;
		string root = get_route(left,right);
		if(route.find(root) == route.end())
            route[root] = Rooute(left,right,time);
		else
            assert(route[root].t ==time);//assert if time changes
	}

	for(int i=0;i<s;i++){
		cin>>id>>start>>time>>end;
		string root = get_route(start,end);
		Trip trip(id,start,end,time,time+route[root].t);// make a trip
		route[root].add_trip(trip);
	}

	for (auto & aa: route) {
        auto a = aa.second;
        a.sort_trips();

		int ls=0,rs=0,lp =0, rp = 0;
		while(ls < (int)a.lr.size() and rs < (int)a.rl.size()) {
			if(a.lr[ls].paired){ ls++; continue; }
			if(a.rl[rs].paired){ rs++; continue; }

			if(a.lr[ls].st <= a.rl[rs].st) {
				if(rp < (int)a.rl.size()) {
					int ct = a.lr[ls].et;
					while(a.rl[rp].st < ct){
						rp++;
						if(rp >= (int)a.rl.size()) break;
					}
					if(rp >= (int)a.rl.size()) continue;
					ans.push_back(Ans(a.lr[ls],a.rl[rp]));
				} else	ans.push_back(Ans(a.lr[ls],off_trip));
				ls++;
				continue;
			}

			if(a.rl[rs].st <= a.lr[ls].st) {
				if(lp < (int)a.lr.size()) {
					int ct = a.rl[rs].et;
					while(a.rl[lp].st < ct){
						lp++;
						if(lp >= (int)a.rl.size()) break;
					}
					if(lp >= (int)a.rl.size()) continue;
					ans.push_back(Ans(a.lr[lp],a.rl[rs]));
				} else {
					ans.push_back(Ans(a.rl[rp],off_trip));
				}
				rs++;
				continue;
			}
			break;
		}// end deadly while

		while(ls< (int)a.lr.size()) {
			if(a.lr[ls].paired) { ls++; continue; }
			ans.push_back(Ans(a.lr[ls],off_trip));
			ls++;
		}
		while(rs<(int)a.rl.size()) {
			if(a.rl[rs].paired) { rs++; continue; }
			ans.push_back(Ans(a.rl[rs],off_trip));
			rs++;
		}
	}

    cout << ans.size() << endl;
    int cost = 0;
    for ( auto a : ans )
        cost += a.print_it();
    cout << cost << endl;
}

/* truck optimizing question */
