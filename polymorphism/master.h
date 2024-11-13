#ifndef _MASTER_H_
#define _MASTER_H_

// abstract class
class master{

 public:
  master(){};
  virtual void fun()=0; //pure virtual function
  virtual void fun2(){std::cout << "Running fun2 in master" << std::endl;}; // virtual function
  ~master(){};

};

class slave1 : public master{
 
  public:
   slave1(){}; 
    virtual void fun(){
        std::cout << "running fun in slave1" << std::endl;
    }
    virtual void fun2(){
        std::cout << "running fun2 in slave1" << std::endl;
    }
   ~slave1(){};

};





#endif