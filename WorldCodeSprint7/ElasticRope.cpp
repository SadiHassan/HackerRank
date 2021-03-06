//Wrong Answer --- Have to check again, interesting problem :)

#include<vector>
#include <iostream>
#include<cmath>
#include<stdio.h>
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

bool point_inside_polygon(Point p1){

    Point p2;

    p2.x = 2000;
    p2.y = p1.y;

    int total_intersect = 0;

    for(int i=0; i<v.size()-1; i++)
        if(doIntersect(p1,p2,v[i],v[i+1]) == true) total_intersect++;

    if(doIntersect(p1,p2,v[0],v[v.size()-1]) == true) total_intersect++;

    if(total_intersect%2==0) return false; //Point is OUTSIDE
    return true; //Point is INSIDE
}


bool is_a_valid_line_v1(int ind1, int ind2){

    Point midPoint;

    midPoint.x = (v1[ind1].x + v1[ind2].x)/2 ;
    midPoint.y = (v1[ind1].y + v1[ind2].y)/2 ;

    //cout<<"check for Mid-point inside..."<<endl;

    if(point_inside_polygon(midPoint)==true) return false;

    //cout<<"Mid-point outside outside"<<endl;

    for(int i=0; i<v.size()-1; i++){
        if( (i==ind1 && i+1==ind2) || (i==ind2 && i+1==ind1) ) continue; //continue
        if( doIntersect( v1[ind1] , v1[ind2] , v[i] , v[i+1]) == true) return false;
    }

    if( (ind1==0 && ind2==v.size()-1) || (ind2==0 && ind1==v.size()-1) ) return true;

    if( doIntersect( v1[ind1] , v1[ind2] , v[0] , v[v.size()-1]) == true) return false;

    return true;
}

bool is_a_valid_line_v2(int ind1, int ind2){

    Point midPoint;

    midPoint.x = (v2[ind1].x + v2[ind2].x)/2 ;
    midPoint.y = (v2[ind1].y + v2[ind2].y)/2 ;

    //cout<<"check for point inside..."<<endl;
    if(point_inside_polygon(midPoint)==true) return false;

    //cout<<"outside"<<endl;
    for(int i=0; i<v.size()-1; i++){
        if( (i==ind1 && i+1==ind2) || (i==ind2 && i+1==ind1) ) continue;
        if( doIntersect( v2[ind1] , v2[ind2] , v[i] , v[i+1]) == true) return false;
    }

    if( (ind1==0 && ind2==v.size()-1) || (ind2==0 && ind1==v.size()-1) ) return true;

    if( doIntersect( v2[ind1] , v2[ind2] , v[0] , v[v.size()-1]) == true) return false;

    return true;
}

int find_next_index_v1(int now_ind){

    int next_ind = now_ind + 1;
    //cout<<"hi : "<<now_ind<<" "<<next_ind<<" "<<v1.size()<<endl;
    if(next_ind==v1.size()-1) return next_ind;

    while(1) {
        bool res = is_a_valid_line_v1(now_ind,next_ind+1) ;

        if(res==false){
            cout<<"ami false mama..."<<endl;
            break;
        }

        cout<<"valid line : "<<v1[now_ind].x<<","<<v1[now_ind].y<<" <-->"<<v1[next_ind].x<<","<<v1[next_ind].y<<endl;
        next_ind++;
    }

    return next_ind;
}

int find_next_index_v2(int now_ind){

    int next_ind = now_ind + 1;
    if(next_ind==v2.size()-1) return next_ind;

    while(is_a_valid_line_v2(now_ind,next_ind+1)) next_ind++;

    return next_ind;
}

double find_dist(Point p1, Point p2){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

double calc_answer_v1(){

    int now_ind = 0, next_ind;
    double dist = 0;

    while(1){

        cout<<v1[now_ind].x<<" "<<v1[now_ind].y<<endl;

        next_ind = find_next_index_v1(now_ind);

        cout<<"--> "<<v1[next_ind].x<<" "<<v1[next_ind].y<<endl;

        dist += find_dist( v1[now_ind] , v1[next_ind] );
        now_ind = next_ind;

        if(now_ind == v1.size()-1) break;
    }

    return dist;
}


double calc_answer_v2(){

    int now_ind = 0, next_ind;
    double dist = 0;

    while(1){
        cout<<v2[now_ind].x<<" "<<v2[now_ind].y<<endl;
        next_ind = find_next_index_v2(now_ind);
        cout<<"--> "<<v2[next_ind].x<<" "<<v2[next_ind].y<<endl;
        dist += find_dist( v2[now_ind] , v2[next_ind] );
        now_ind = next_ind;
        if(now_ind == v2.size()-1) break;
    }

    return dist;

}


int main()
{

    //doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    double dist1 , dist2 ;
    freopen("in.txt","r",stdin);

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

    cout<<"points : "<<v[ind1].x<<","<<v[ind1].y<<" "<<v[ind2].x<<","<<v[ind2].y<<endl;

    if(ind1==ind2) cout<<"0"<<endl;

    else{

        for(int i=ind1; i<=ind2; i++) v1.push_back(v[i]);

        for(int i=ind1; i>=0; i--) v2.push_back(v[i]);
        for(int i=v.size()-1; i>=ind2; i--) v2.push_back(v[i]);

        dist1 = calc_answer_v1();
        cout<<"dist v1 : "<<dist1<<endl;

        dist2 = calc_answer_v2();
        cout<<"dist v2 : "<<dist2<<endl;

        if(dist1>=dist2) cout<<dist1<<endl;
        else cout<<dist2<<endl;
    }

    return 0;
}
