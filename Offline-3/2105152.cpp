#include<iostream>
#include<cmath>
// your code
using namespace std;

class Point2D
{
    double x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();
    // your code

    Point2D operator+(const Point2D& t){
        Point2D add;
        add.x=this->x+t.x;
        add.y=this->y+t.y;
        return add;
    }

    Point2D operator*(double n ){
        Point2D multi;
        multi.x=this->x*n;
        multi.y=this->y*n;
        return multi;
    }

    bool  operator==(const Point2D& t){
        if(this->x==t.x && this->y==t.y){
            return true ;
        }
        else{
            return false;
        }
    }
    
    bool  operator!=(const Point2D& t){
        if(this->x!=t.x && this->y!=t.y){
            return true ;
        }
        else{
            return false;
        }
    }

    Point2D operator-(const Point2D& t) 
    {
        Point2D result;
        result.x =this-> x -t.x;
        result.y =this->y-t.y;
        return result;
    }
};

Point2D::Point2D(double argx,double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x=argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

// your code

class Circle
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(Point2D c, double r);
  
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();
    // your code

   
    Circle operator+(const Point2D& p) 
    {
        Point2D c = center + p;
        return Circle(c, radius);
    }

    Circle operator+(Circle &t){
        Circle add;
        double a=radius/(radius+t.radius);
        add.center=(center*a+t.center*(1-a));
        add.radius=radius+t.radius;
        return add;
    }

    Circle operator-(Circle &t){
        Circle min;
        double a=radius/(radius+t.radius);
        min.center=(center*a+t.center*(1-a));
        min.radius=abs(radius-t.radius);
        return min;
    }

    Circle operator*(double n){
        Point2D c=center*n;
        double r=radius*n;
        return Circle(c,r);
    }

    bool operator==(const Circle &t){
        if(center==t.center && radius==t.radius){
            return true;
        }
        return false;
    }

    bool operator>(const Circle &t){
        
       double area1=3.1415*radius*radius;
        double area2=3.1415*(t.radius)*(t.radius);
        if(area1>area2){
            return true;
        }
        else{
        return false;
        }
    }

    bool operator>=(const Circle &t){
        double area1=3.1415*radius*radius;
        double area2=3.1415*(t.radius)*(t.radius);
        if(area1>=area2){
            return true;
        }
        else{
        return false;
        }
    }

    bool operator<(const Circle &t){
        double area1=3.1415*radius*radius;
        double area2=3.1415*(t.radius)*(t.radius);
        if(area1<area2){
            return true;
        }
        else{
        return false;
        }
    }

    bool operator<=(const Circle &t){
        double area1=3.1415*radius*radius;
        double area2=3.1415*(t.radius)*(t.radius);
        if(area1<=area2){
            return true;
        }
        else{
        return false;
        }
    }

    Circle operator++(int){
        radius++;
        return *this;
    }

    Circle operator++(){
        ++radius;
        return *this;
    }

};


Circle:: Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius=r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius=r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout<<"]";
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

// your code

class Rectangle
{
    Point2D topRightPoint,bottomLeftPoint;
public:
    Rectangle();
    Rectangle(Point2D oneCorner,Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    // your code

    Rectangle operator+(const Point2D &p){
        Rectangle add;
        add.topRightPoint=topRightPoint+p;
        add.bottomLeftPoint=bottomLeftPoint+p;
        return add;
    }
    Rectangle operator*(double n){
        Rectangle multi;
        multi.topRightPoint=topRightPoint*n;
        multi.bottomLeftPoint=bottomLeftPoint*n;
        return multi;
    }
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner,Point2D anotherCorner)
{
    topRightPoint=oneCorner;
    bottomLeftPoint=anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint=oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint=anotherCorner;
}
Point2D Rectangle::getTopRightPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout<<"[Top Right Point: ";
    topRightPoint.print();
    cout<<"  Bottom left Point: ";
    bottomLeftPoint.print();
    cout<<"]";
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}

// your code

int main()
{
    Point2D p1(5,10),p2(15,10),p3;
    Circle c1(p1,10),c2,c3;
    Rectangle r1(p1,p2),r2;
    // your code

    p3=p1+p2;
    cout<<"p3=";
    p3.print();
    cout<<endl;
    
    p2=p1*2.0;
    cout<<"p2=";
    p2.print();
    cout<<endl;

    if(p1==p2){
        cout<<"Both are same"<<endl;
    }
    else if(p1!=p2){
        cout<<"Not same"<<endl;
    }

    c2=c1+p3;
    cout<<"c2=";
    c2.print();
    cout<<endl;

    c3=c1+c2;
    cout<<"c3=";
    c3.print();
    cout<<endl;

    c3=c1-c2;
    cout<<"c3=";
    c3.print();
    cout<<endl;

    c3=c1*3.0;
    cout<<"c3=";
    c3.print();
    cout<<endl;

    if(c1==c2){
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    if(c1>c2){
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    if(c1>=c2){
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    if(c1<c2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    if(c1<=c2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }


    ++c1;
    cout<<"pre-incerment c1=";
    c1.print();
    cout<<endl;


    c1++;
    cout<<"pre-incerment c1=";
    c1.print();
    cout<<endl;
     
    

    r2=r1+p3;
    cout<<"r2=";
    r2.print();
    cout<<endl;


    r2=r1*4.0;
    cout<<"r2=";
    r2.print();
    cout<<endl;


    return 0;
}
