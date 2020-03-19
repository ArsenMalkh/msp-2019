#include <iostream>

#include "./core/basesaver.hpp"
#include "./core/matrix.hpp"
#include "./core/vector.hpp"
#include "./core/Interpolator.hpp"

#include "./structured/rectgrid.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cout << "Please, specify the name of the config file as: ./msp my_task.cfg" << endl;
    return 2;
  }
  cout << "This program calculates wave propagation in acoustic media." << endl;
  // Config cfg(argv[1]);
  // Solver solver(cfg);
  // Saver saver(cfg);
  unsigned long steps = 101; // Bring from cfg like stoul(cfg.get("steps"));
  for (unsigned long i = 0; i < steps; i++) {
    cout << "Step: " << i << endl;
    //saver.save();
    //solver->step();
  }
  Interpolator s1;
  cout<<s1.liniar(10,20,5,40,80)<<endl;
  //BaseSaver bs1;
  //cout << bs1.getName() << endl;
  //bs1.save();
  Matrix m1;
  Vector v1;
  RectGrid rg1;
  rg1.setNx(10);
  rg1.setNy(20);
  rg1.allocateMemory();
  rg1.stepX();
  cout << "Program finished." << endl;
  return 0;
}
