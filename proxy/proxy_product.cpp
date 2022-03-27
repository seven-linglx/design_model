/* 代理模式
 * 通常有三个角色，一个是抽象产品角色，一个是具体产品角色，另一个是代理产品角色，这个代理产品角色的作用是什么呢？引入了代理产品角色是为了给原始的具体产品附加功能。注意这里代理模式附加的是跟原始类无关的功能，附加的如果是跟原始类有关的功能那是装饰器模式，
 * 2022-03-27
 */
#include <memory>
#include <iostream>

using std::cout;
using std::endl;

class Product {
    public:
        Product() = delete;
        Product(const std::string& name) : m_name(name) {};
        virtual std::string GetName() = 0;

    protected:
        std::string m_name {};
};

class CheapProduct : public Product {
    public:
        CheapProduct(const std::string& name) : Product(name) {};
        virtual std::string GetName() override {
            cout << __PRETTY_FUNCTION__ << ": The name is " << m_name << &endl;
            return m_name;
        };
};

class CheapProductProxy : public Product {
    public:
        CheapProductProxy(const std::string& name) : Product(name) {};
        virtual std::string GetName() override {
            if (m_CheapProduct == nullptr) {
                m_CheapProduct = std::make_unique<CheapProduct>("CheapProduct");
            };
            // const std::string name = m_CheapProduct->GetName();
            // cout << __PRETTY_FUNCTION__ << ": The name is " << name << &endl;
            return m_CheapProduct->GetName();
        };

    private:
        std::unique_ptr<Product> m_CheapProduct {nullptr};
};

int main() {
    CheapProductProxy cheap_product_proxy("CheapProductProxy");
    cheap_product_proxy.GetName();
};
