#include "pimpl.h"
#include "display.h"
#include <iostream>
#include <memory>

class Adapter::AdapterImpl
{
public:
  std::vector<std::string> submit(const std::vector<std::string>& task_names);

private:
  std::vector<std::string> vaild_tasks{ "RUN", "STOP", "START" };
};

std::vector<std::string> Adapter::AdapterImpl::submit(const std::vector<std::string>& task_names)
{
  std::cout << task_names << std::endl;
  return task_names;
}

std::vector<std::string> Adapter::submit(const std::vector<std::string>& task_names)
{
  return impl->submit(task_names);
}

Adapter::Adapter()
{
  impl = std::make_unique<AdapterImpl>();
}

int main(int argc, char* argv[])
{
  Adapter adapter;
  auto result = adapter.submit({ "START" });
  return 0;
}
