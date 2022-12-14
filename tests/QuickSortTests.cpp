#include <gtest/gtest.h>
#include <QuickSort.hpp>
#include <random>

TEST(Sorts, QuickSort) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(v.begin(), v.end(), g);
  utils::quickSort(v.begin(), v.end(), std::less<int>());
  EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}