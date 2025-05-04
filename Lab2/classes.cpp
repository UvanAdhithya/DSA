#include <iostream>
using namespace std ;

class shape
{
  private :
       int len,bre,hei,area ;     
  public : 
    shape ()
    {
     len = 1 ;
     bre = 1 ;
     hei = 1 ; 
    }
    void setlen(int l)
    {
            len = l;
    }
    void setbre(int b)
    {
            bre = b;
    }
    void sethei(int h)
    {
            hei = h;
    }
    int square()
    {
            area = len * len;
            return area;
    }
    int rectangle()
    {
            area = len * bre;
            return area;
    }
    int cube()
    {
            area = 6 * len * len;
            return area;
    }
    int cuboid()
    {
            area = 2 * (len * bre + bre * hei + hei * len);
            return area;
    }    
};
 
int main ()
{
 shape s;
    cout << "Menu\n1. Square\n2. Rectangle\n3. Cube\n4. Cuboid\nEnter your choice: ";
    int ch;
    int l, b, h;
    cin >> ch;
    switch(ch){
        case 1:
            cout << "Enter the side of the square: ";
            cin >> l;
            s.setlen(l);
            cout << "Area of the square is: " << s.square();
            break;
        case 2:
            cout << "Enter the length and breadth of the rectangle: ";
            cin >> l >> b;
            s.setlen(l);
            s.setbre(b);
            cout << "Area of the rectangle is: " << s.rectangle();
            break;
        case 3:
            cout << "Enter the side of the cube: ";
            cin >> l;
            s.setlen(l);
            cout << "Area of the cube is: " << s.cube();
            break;
        case 4:
            cout << "Enter the length, breadth and height of the cuboid: ";
            cin >> l >> b >> h;
            s.setlen(l);
            s.setbre(b);
            s.sethei(h);
            cout << "Area of the cuboid is: " << s.cuboid();
            break;
        default:
            cout << "Invalid choice";
    }
    return 0;
} 





