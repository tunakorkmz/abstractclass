#include <iostream> // abstract class abs func
using namespace std;

class Shapes{ //abstract class
protected:
    double surfaceArea,volume;
public:
    virtual void whichshape() = 0; //abstract function
    virtual void surfaceareaCalculation() = 0; //abstract function
    virtual void volumeCalculation() = 0; //abstract function
    double getSurfaceArea()const { return surfaceArea; }
    double getVolume()const { return volume; }
};

class spheres:public Shapes {
    double r;  
public:
    spheres (double r) : r (r) {}
    void whichshape() { cout << "\t\tSPHERE" << endl; }
    void surfaceareaCalculation() { 
        surfaceArea = 4 * 3.14 * r * r ; 
    }
    void volumeCalculation() {
        volume = 4* 3.14 * r * r *r / 3;
    }
};
class cones:public Shapes{
    double height,r,sideLength;
public:
    cones (double height,double r,double sideLength) : height (height) , r (r) , sideLength(sideLength) {}
    void whichshape() { cout << "\t\tCONE"<< endl ;}
    void surfaceareaCalculation() {
        surfaceArea = 3.14* r * sideLength + 3.14*r*r ;
    }
    void volumeCalculation() {
        volume = 3.14*r*r*height/3;
    }
};
 class sylinder:public Shapes{
    double r,height;
public:
    sylinder (double r,double height) : r (r) , height (height) {}
    void whichshape() { cout << "\t\tSYLINDER" << endl ;}
    void surfaceareaCalculation() {
        surfaceArea = 2 * 3.14 * r * r + 2* 3.14 * r * height;
    }
    void volumeCalculation() {
        volume = 3.14 * r * r *height;
    }
 };
class rectangularPrism:public Shapes{
    double length,width,height;
public:
    rectangularPrism (double length,double width, double height) : length (length) , width(width) , height (height) {}
    void whichshape() { cout<< "\t\tRECTANGULAR PRISM"<< endl ;}
    void surfaceareaCalculation() {
        surfaceArea = (width*length + length*height + width*height) * 2;
    }
    void volumeCalculation() {
        volume = length * width * height ;
    }
};
class pyramids:public Shapes{
    double height,base,sideLength;
public:
    pyramids ( double height,double base, double sideLength) : height (height) , base (base) , sideLength (sideLength) {}
    void whichshape() { cout << "\t\tPYRAMID"<< endl ;}
    void surfaceareaCalculation() {
        surfaceArea = 2 * base * sideLength + base * base ;
    }
    void volumeCalculation() {
        volume = base * base * height / 3 ;
    }
};
class triangularPrism:public Shapes{
    double base,height,sideLength,length;
public:
    triangularPrism ( double base,double height,double sideLength,double length ) : base (base) ,height (height) , sideLength (sideLength), length (length) {}
    void whichshape() { cout << "\t\tTRIANGULAR PRISM"<< endl ;}
    void surfaceareaCalculation() {
        surfaceArea = base * height +2 * length*sideLength + base * length ;
    }
    void volumeCalculation() {
        volume = base * height * length / 2;
    }
};
int main() {

    Shapes* arr[6];
   arr[0] = new spheres(1);
   arr[1] = new cones(10,3,10);
   arr[2] = new sylinder(5,8);
   arr[3] = new rectangularPrism (2,4,5);
   arr[4]= new pyramids(3,5,9);
   arr[5] = new triangularPrism(2,3,5,7);
//    arr[0] = new spheres(1);
    for(int i=0 ; i<6 ; i++) {
        arr[i] -> whichshape();
        arr[i] -> surfaceareaCalculation();
        arr[i] -> volumeCalculation();
    cout << "\t\tSurface Area : " << endl ;
    cout << "\t\t" <<arr[i] -> getSurfaceArea() << endl ;
    cout << "\t\tVolume : " << endl ;
    cout << "\t\t" <<arr[i] -> getVolume() << endl << endl ;
    }
   return 0;
}