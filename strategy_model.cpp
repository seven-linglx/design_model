#include<iostream>
#include<memory>

using std::cout;
using std::endl;

class SortAlgorithm
{
 public:
  virtual void sort() const = 0;
};

class Bubble : public SortAlgorithm
{
 public:
  void sort() const { cout << "Bubble" << endl;}
};

class Fast : public SortAlgorithm
{
 public:
  void sort() const { cout << "Fast" << endl;}
};

class Context
{
 public:
  Context(){};
  Context(const std::shared_ptr<SortAlgorithm> &p) : p(p) {};
  void setAlgorithm(const std::shared_ptr<SortAlgorithm> &a){p = a;}
  void sort(){p->sort();}
 private:
  std::shared_ptr<SortAlgorithm> p = nullptr;
};

int main()
{
  auto intance = std::shared_ptr<Context>(new Context);
  intance->setAlgorithm(std::shared_ptr<SortAlgorithm>(new Bubble));
  intance->sort();
  intance->setAlgorithm(std::shared_ptr<SortAlgorithm>(new Fast));
  intance->sort();
  return 0;
}
