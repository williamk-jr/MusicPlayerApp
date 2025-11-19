#pragma once
#include <memory>

namespace iamaprogrammer {
  template <typename ManagedType>
  using WidgetPointer = std::unique_ptr<ManagedType>;

  template <typename Class,typename... ArgsT>
  std::unique_ptr<Class> Create(ArgsT&&... args){
    return std::make_unique<Class>(std::forward<ArgsT>(args)...);
  };
}