#ifndef INCLUDE_BIG_ARRAY_ACCESOR1_H_
#define INCLUDE_BIG_ARRAY_ACCESOR1_H_
#include <array_accessor.h>

#include <utility> // std::move

namespace big
{

  template <typename T>
  class ArrayAccessor<T, 1> final
  {
  public:
    ArrayAccessor();

    ArrayAccessor(std::size_t size, T *const data);

    ArrayAccessor(const ArrayAccessor &other);

    template <typename Callback>
    void forEach(Callback func) const;

    template <typename Callback>
    void forEachIndex(Callback func) const;

    template <typename Callback>
    void parallelForEach(Callback func) const;

    template <typename Callback>
    void parallelForEachIndex(Callback func) const;

    T &operator[](std::size_t i) const;

    const T &operator[](std::size_t i) const;

    ArrayAccessor &operator=(const ArrayAccessor &other);

    operator int() const;

  private:
    std::size_t _size;
    T *_data;
  };

  template <typename T>
  using ArrayAccessor1 = ArrayAccessor1<T, 1>;

  template <typename T>
  class ConstArrayAccessor<T, 1>
  {
  public:
    ConstArrayAccessor();

    ConstArrayAccessor(std::size_t size, const T *const data);
  };

} // namespace big

#endif