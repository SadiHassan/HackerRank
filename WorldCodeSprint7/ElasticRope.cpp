#include<vector>
#include <iostream>
using namespace std;

struct Point
{
    double x;
    double y;
};

int N, a, b, a_ind, b_ind;
double x, y;
vector<Point> v , v1, v2;


bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main()
{

    //doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    double dist , ans ;

    cin>>N>>a>>b;
    a--; b--;

    for(int i=0; i<N; i++){
        if(i==a) a_ind = i;
        if(i==b) b_ind = i;

        cin>>x>>y;
        Point ob;
        ob.x = x;
        ob.y = y;

        v.push_back(ob);
    }

    int ind1=a_ind, ind2=b_ind;

    if(a_ind>b_ind){
        ind1 = b_ind;
        ind2 = a_ind;
    }

    if(ind1==ind2) cout<<"0"<<endl;

    else{

        int now_index = ind1;

        dist = 0;
        ans = -1;

        while(1){

            next_index = find_next_index_positive_direction(now_index);
            dist = dist + find_dist( now_index , next_index );

            if(next_index==ind2) break;

            now_index = next_index;
        }

    }

    return 0;
}
