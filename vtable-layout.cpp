http://stackoverflow.com/questions/15921372/c-virtual-table-layout-of-mimultiple-inheritance


class B1
{
public:
  void f0() {}
  virtual void f1() {}
  int int_in_b1;
};
 
class B2
{
public:
  virtual void f2() {}
  int int_in_b2;
};

class D : public B1, public B2
{
public:
  void d() {}
  void f2() {}  // override B2::f2()
  int int_in_d;
};

memory layout of B2

b2:
  +0: pointer to virtual method table of B2
  +4: value of int_in_b2

virtual method table of B2:
  +0: B2::f2() 
---------------------------------------------------------------
d:
  +0: pointer to virtual method table of D (for B1)
  +4: value of int_in_b1
  +8: pointer to virtual method table of D (for B2)
 +12: value of int_in_b2
 +16: value of int_in_d

Total size: 20 Bytes.

virtual method table of D (for B1):
  +0: B1::f1()  // B1::f1() is not overridden

virtual method table of D (for B2):
  +8: D::f2()   // B2::f2() is overridden by D::f2()
