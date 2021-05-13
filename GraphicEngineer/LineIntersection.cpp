/* idea: kiem tra xem 2 doan thang da cho co cat nhau hay khong,
        neu cat nhau, viet PT duong thang cho moi doan va dua
        vao PT duong thang de tim giao diem cua 2 doan thang.*/
#include <iostream>
using namespace std;

//dung pair de luu tru 1 diem
#define point pair<double, double>

//ham onSegment de kiem tra xem q co nam tren doan thang pr hay khong?
bool onSegment(point p, point q, point r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;

    return false;
}

int orientation(point p, point q, point r)	//orentation la ham xac dinh huong giua 3 diem
{
    int val = (q.second - p.second) * (r.first - q.first) -
        (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  // cung mot duong thang

    return (val > 0) ? 1 : 2;
    //=1 thi thu tu 3 diem theo chieu kim dong ho va =2 thi nguoc lai
}

bool doIntersect(point p1, point q1, point p2, point q2)
// doIntersect de kiem tra 2 doan thang tao boi 4 diem tren co cat nhau khong?															
{
    int o1 = orientation(p1, q1, p2);	//xac dinh huong di cua 3 diem p1,q1,p2
    int o2 = orientation(p1, q1, q2);	//xac dinh huong di cua 3 diem p1,q1,q2
    int o3 = orientation(p2, q2, p1);	//xac dinh huong di cua 3 diem p2,q2,p1
    int o4 = orientation(p2, q2, q1);	//xac dinh huong di cua 3 diem p2,q2,q1

    if (o1 != o2 && o3 != o4)	// hai doan thang nay cat nhau
        return true;

    // Truong hop dac biet
    // p2 nam tren doan thang p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // q2 nam tren doan thang p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p1 nam tren doan thang p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // q1 nam tren doan thang p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

void Display(point P)
{
    cout << "(" << P.first << ", " << P.second
        << ")" << endl;
}
// ham dung de hien thi diem giao cua 2 doan thang

point Intersect(point A, point B, point C, point D)
//ham Intersect de tim giao diem cua 2 DUONG THANG tao boi AB va CD
{
    // duong thang AB co phuong trinh la: a1x + b1y = c1
    //pt trong giao trinh:  (y2-y1)x - (x2-x1)y + (x2-x1)y1 = (y2-y1)x1 
    double a1 = B.second - A.second; //y2-y1
    double b1 = A.first - B.first;	//x1-x2
    double c1 = a1 * (A.first) + b1 * (A.second); //(y2-y1)*x1+(x1-x2)*y1

    // duong thang CD co PT: a2x + b2y = c2
    // tuong tu nhu PT duong thang AB
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2 * (C.first) + b2 * (C.second);
    double cal1 = a1 * b2 - a2 * b1;
    double cal2 = b1 * c2 - b2 * c1;
    double cal3 = a1 * c2 - a2 * c1;
    if (cal1 == 0) {	// neu a1/a2 = b1/b2
        if (cal2 == 0 && cal3 == 0) {	// a1/a2=b1/b2=c1/c2 -> 2 duong thang trung nhau
            return make_pair(FLT_MIN, FLT_MIN); //tra ve lim+(0)
        }
        return make_pair(FLT_MAX, FLT_MAX);	// -> 2 duong thang song song: tra ve vo cung
    }
    else {
        /* a1x+b1y =c1 (*)
           a2x+b2y =c2 (**)
           nhan (*) voi b2:  a1b2x + b1b2y = c1b2 (1)
           nhan (**) voi b1: a2b1x + b2b1y = c2b1 (2)
        tru (1)-(2)
        (a1b2 – a2b1) x = c1b2 – c2b1
        */
        double x = (b2 * c1 - b1 * c2) / cal1;
        double y = (a1 * c2 - a2 * c1) / cal1;
        return make_pair(x, y);
    }

}

void LineIntersectionMethod(){
    int t;
    cout << "Nhap so bo test: " << endl;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cout << "Toa do diem A la: " << endl;
        cin >> x1 >> y1;						//nhap diem A
        point A = make_pair(x1, y1);
        cout << "Toa do diem B la: " << endl;
        cin >> x2 >> y2;						//nhap diem B
        point B = make_pair(x2, y2);
        cout << "Toa do diem C la: " << endl;
        cin >> x3 >> y3;						//nhap diem C
        point C = make_pair(x3, y3);
        cout << "Toa do diem D la: " << endl;
        cin >> x4 >> y4;						//nhap diem D
        point D = make_pair(x4, y4);
        if (doIntersect(A, B, C, D)) {	//neu doan thang AB co giao voi doan thang CD
            point intersection = Intersect(A, B, C, D);
            if (intersection.first == FLT_MIN && intersection.second == FLT_MIN){
                cout << "AB trung CD \n";
            }
            else {
                cout << "Giao diem cua AB va CD la: " << endl;
                Display(intersection);
            }
        }
        else {
            cout << "Hai doan thang khong giao nhau." << endl;
        }

    }
}