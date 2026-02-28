#pragma once
#include <functional>
#include <vector>

namespace iamaprogrammer {
  template<typename T>
  class Observable {
    public:
      Observable() = default;

      void setValue(T value) {
        if (value != this->value) {
          this->value = value;


          for (std::function<void(const T&)> observer : this->observers) {
            observer(this->value);
          }
        }
      }

      T getValue() {
        return this->value;
      }

      void observe(std::function<void(const T&)> observer) {
        this->observers.push_back(observer);
      }

    private:
      std::vector<std::function<void(const T&)>> observers;
      T value;
  };
}