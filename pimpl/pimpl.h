#include <string>
#include <vector>
#include <memory>

class Adapter
{
public:
  Adapter();

public:
  std::vector<std::string> submit(const std::vector<std::string>& task_names);

private:
  class AdapterImpl;
  std::unique_ptr<AdapterImpl> impl;
};
