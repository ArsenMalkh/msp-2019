#ifndef RECT_GRID
#define RECT_GRID

#include <iostream>

#include "../core/baseobject.hpp"
#include "../acoustic/acousticnode.hpp"

using namespace std;

class RectGrid : public BaseObject
{
public:
  RectGrid() : dx(0), dy(0), nx(0), ny(0), ox(0), oy(0) {
    data = NULL;
  }
  ~RectGrid() {
    if (data) {
      for (int i = 0; i < ny; i++)
        delete [] data[i];
      delete [] data;
    }
  }
  void allocateMemory() {
    data = new AcousticNode*[ny];
    for (int i = 0; i < ny; i++)
      data[i] = new AcousticNode[nx];
  }
  const char *getName();
  float getDx() const { return dx; }
  float getDy() const { return dy; }
  unsigned long getNx() const { return nx; }
  unsigned long getNy() const { return ny; }
  unsigned long getOx() const { return ox; }
  unsigned long getOy() const { return oy; }
  void stepX() {
    for (int i = 0; i < ny; i++) {
      for (int j = 0; j < nx; j++)
        // Call scheme with appropriate nodes here.
        cout << data[i][j].pressure() << " ";
      cout << endl;
    }
  }
  void stepY() {}
  void setNx(unsigned long n) { nx = n; }
  void setNy(unsigned long n) { ny = n; }
  float getPressure(int i, int j) {return data[i][j].pressure();}
private:
  float dx;
  float dy;
  unsigned long nx;
  unsigned long ny;
  float ox;
  float oy;
  AcousticNode **data;
};

#endif // RECT_GRID
