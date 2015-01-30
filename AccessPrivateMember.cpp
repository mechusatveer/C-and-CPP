//access private member of an object without being friend
    +2  #include<iostream>
    +3  using namespace std;
    +4
    +5  class Base {
    +6          int i;
    +7          char j;
    +8          public:
    +9          Base(int one,char two):i(one),j(two)    {}
   +10  };
   +11  int main()
   +12  {
   +13          Base *b=new Base(1,'a');
   +14          void *v=(void*)b;
   +15          int m=*(int*)v;
   +16          cout<<"private member i="<<m<<endl;
   +17          return 0;
   +18
   +19  }
