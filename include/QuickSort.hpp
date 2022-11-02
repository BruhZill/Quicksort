#include <algorithm>

namespace utils {
template <typename RandomIt, typename Compare>
void quickSort(RandomIt first, RandomIt last, Compare cmp) {
  if (first != last) {
    auto left = first;
    auto right = last;
    auto pivot = left++;

    while (left != right) {
      if (cmp(*left, *pivot)) {
        ++left;
      } else {
        while ((left != --right) && cmp(*pivot, *right))
          ;
        std::iter_swap(left, right);
      }
    }

    --left;
    std::iter_swap(first, left);

    quickSort(first, left, cmp);
    quickSort(right, last, cmp);
  }
}
}  // namespace utils