#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int64;

struct Point{
    double x, y;
    Point(){

    }
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
};

Point sub(Point &A, Point &B){
    return Point(A.x - B.x, A.y - B.y);
}

int main(){
	fastIO
	int n;
	cin >> n;
	vector<Point> polygon(n);
	for (int i = 0; i < n; i++){
        Point p;
        cin >> p.x >> p.y;
        polygon[i] = p;
	}
	if (n % 2 != 0){
        cout << "No";
	}
	else{
        Point center(0, 0);
        for (Point p : polygon){
            center.x += p.x;
            center.y += p.y;
        }
        center.x /= n;
        center.y /= n;
        bool aerodynamic = true;
        for (int i = 0; i < n / 2; i++){
            Point A = polygon[i];
            Point B = polygon[n / 2 + i];
            Point OA = sub(A, center);
            Point OB = sub(B, center);
            if (OA.x != -OB.x || OA.y != -OB.y){
                aerodynamic = false;
                break;
            }
        }
        if (aerodynamic)
            cout << "Yes";
        else
            cout << "No";
	}
	return 0;
}
