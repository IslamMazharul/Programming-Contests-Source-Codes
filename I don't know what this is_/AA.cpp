#include <bits/stdc++.h>
using namespace std;

const double eps=1e-8;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;

Vector operator + (Point a,Point b){ return Vector(a.x+b.x,a.y+b.y); }
Vector operator - (Point a,Point b){ return Vector(a.x-b.x,a.y-b.y); }
Vector operator * (Point a,double p){ return Vector(a.x*p,a.y*p); }
double dot(Vector a,Vector b){ return a.x*b.x+a.y*b.y; }//点积
double cross(Vector a,Vector b){ return a.x*b.y-a.y*b.x; }//叉积
double length(Vector a){ return sqrt(dot(a,a)); }//向量的模
double angle(Vector a,Vector b){ return acos(dot(a,b)/length(a)/length(b)); }//两向量夹角
Vector rotate(Vector a,double rad){ return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad)); }//将向量a逆时针旋转rad(弧度制)
Point get_line_intersection(Point P,Vector v,Point Q,Vector w){//求两直线交点(参数方程)
    Vector u=P-Q;
    double t=cross(w,u)/cross(v,w);
    return P+v*t;
}
Point get(Point A,Point B,Point C){//分别算DEF三个点的函数
    Vector v1=C-B;
    double a1=angle(A-B,v1);
    cout<<a1<<endl ;
    v1=rotate(v1,a1/3);
    Vector v2=B-C;
    double a2=angle(A-C,v2);
    v2=rotate(v2,-a2/3);
    cout<<a2<<endl ;
    return get_line_intersection(B,v1,C,v2);
}
int main(){
    int n;
    Point A,B,C,D,E,F;
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        D=get(A,B,C);//这里B,C不能写反,因为一个是逆时针转,另一个时顺时针转
        E=get(B,C,A);
        F=get(C,A,B);
      //  printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
    }
    return 0;
}
