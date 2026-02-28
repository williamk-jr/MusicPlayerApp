#pragma once
#include <vector>

#include "message.h"

namespace iamaprogrammer {
  enum MessageOperation {
    ADD,
    REMOVE
  };

  template <typename P, typename T>
  class OperationListMessage : public Message<P, std::vector<std::pair<MessageOperation, T>>> {
    public:
      OperationListMessage() {}

      void addOperation(MessageOperation operation, T value) {
        this->value.push_back({operation, value});
      }
  };
}