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

enum class SORT_ALG_TYPE : size_t { BUBBLE, FAST, COUNT_OF_ALG };

class Context
{
 public:
  Context() = delete;
  Context(const SORT_ALG_TYPE alg_type) {
    switch (alg_type) {
        case SORT_ALG_TYPE::BUBBLE:
            p = std::make_shared<Bubble>();
            break;
        case SORT_ALG_TYPE::FAST:
            p = std::make_shared<Fast>();
            break;
        default:
            p = std::make_shared<Bubble>();
    }
  };
  Context(const std::shared_ptr<SortAlgorithm> &p) : p(p) {};
  void setAlgorithm(const std::shared_ptr<SortAlgorithm> &a){p = a;}
  void sort(){p->sort();}
 private:
  std::shared_ptr<SortAlgorithm> p = nullptr;
};

int main()
{
  auto intance = std::make_shared<Context>(SORT_ALG_TYPE::FAST);
  intance->sort();
  intance->setAlgorithm(std::shared_ptr<SortAlgorithm>(new Bubble));
  intance->sort();
  intance->setAlgorithm(std::shared_ptr<SortAlgorithm>(new Fast));
  intance->sort();
  return 0;
}
