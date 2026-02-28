#pragma once

namespace iamaprogrammer {
  template<typename P, typename T>
  class Message {
    public:

      const T get() const {
        return this->value;
      }

      // const P getPoster() const {
      //   return this->poster;
      // }

    protected:
      //const P poster;
      T value;
  };
}