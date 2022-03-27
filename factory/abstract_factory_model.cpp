//
// Created by linglx on 18-4-13.
//

#include <iostream>

using namespace std;
class AbstractProduct {
  public:
  virtual void compute() = 0;
};

class FloatProduct : public AbstractProduct {
  public:
  void compute() { cout << "float" << endl;}
};

class StringProduct : public AbstractProduct {
  public:
  void compute() { cout << "string" << endl;}
};

class AbstractFactory {
  public:
  virtual AbstractProduct* createProduct() = 0;
};

class FloatFactory : public AbstractFactory {
  public:
  AbstractProduct* createProduct() {
    return new FloatProduct;
  }
};

class StringFactory : public AbstractFactory {
  public:
  AbstractProduct* createProduct() {
    return new StringProduct;
  }
};

class Client {
  private:
  AbstractFactory* abstract_factory;

  public:
  explicit Client(AbstractFactory* f) { abstract_factory = f;}

  void compute() {
    AbstractProduct* p = abstract_factory->createProduct();
    p->compute();
  }
};

int main() {
  AbstractFactory* float_factory = new FloatFactory;
  AbstractFactory* string_factory = new StringFactory;

  auto c = new Client(float_factory);
  c->compute();
  auto b = new Client(string_factory);
  b->compute();
}