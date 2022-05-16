#include <vector>
#include <iostream>

/**
 * @brief Calculates all unique combinations of four numbers that add up to a target number
 *
 * @param numbers The numbers that can be used
 * @param target The number that should be the goal of the addition of the other numbers
 * @return std::vector<std::vector<int>> An array of all unique solution combinatinos
 */
std::vector<std::vector<int>> fourSum(std::vector<int>& numbers, int& target)
{
  if (numbers.size() < 4)
  {
    return {};
  }

  std::vector<std::vector<int>> solutionSet = {};

  // Naive solution: finds every possible solution
  // for (int one = 0; one < numbers.size(); one++)
  // {
  //   for (int two = 0; two < numbers.size(); two++)
  //   {
  //     if (two == one)
  //     {
  //       continue;
  //     }

  //     for (int three = 0; three < numbers.size(); three++)
  //     {
  //       if (three == two || three == one)
  //       {
  //         continue;
  //       }

  //       for (int four = 0; four < numbers.size(); four++)
  //       {
  //         if (four == three || four == two || four == one)
  //         {
  //           continue;
  //         }

  //         if (numbers[one] + numbers[two] + numbers[three] + numbers[four] == target)
  //         {
  //           solutionSet.push_back({numbers[one], numbers[two], numbers[three], numbers[four]});
  //         }
  //       }
  //     }
  //   }
  // }

  // More efficient variant
  int* one = &numbers[0];
  int* two = &numbers[1];
  int* three = &numbers[2];
  int* four = &numbers[3];

  // Iterating through 'numbers' to find the valid combinations
  while (one <= &numbers[numbers.size() - 4])
  {
    // Check if the number combination is a solution
    if (*one + *two + *three + *four == target)
    {
      solutionSet.push_back({*one, *two, *three, *four});
    }

    // Move pointers to the next combination (!! order matters !!)

    // If 'two' has reached its ending position, advance 'one'
    if (two >= &numbers[numbers.size() - 3])
    {
      one++;
      two = one + 1;
      three = one + 2;
      four = one + 3;
      continue;
    }

    // If 'three' has reached its ending position, advance 'two'
    if (three >= &numbers[numbers.size() - 2])
    {
      two++;
      three = two + 1;
      four = two + 2;
      continue;
    }

    // If 'four' has reached the end of the vector, advance 'three'
    if (four >= &numbers[numbers.size() - 1])
    {
      three++;
      four = three + 1;
      continue;
    }

    // If no other action has been taken, advance 'four'
    four++;
  }

  return solutionSet;
}

// Prints a level 1 nested vector completely
void printVector(std::vector<std::vector<int>> vector)
{
  std::cout << '[';

  for (int i = 0; i < vector.size(); i++)
  {
    std::cout << '[';

    for (int j = 0; j < vector[i].size(); j++)
    {
      std::cout << vector[i][j];

      // Print a comma for separating vector elements
      if (j < vector[i].size() - 1)
      {
        std::cout << ',' << ' ';
      }
    }

    std::cout << ']';

    // Print a comma for separating vector elements
    if (i < vector.size() - 1)
    {
      std::cout << ',' << ' ';
    }
  }

  std::cout << ']';
}

/**
 * @brief Tests the function and prints whether a test has passed
 *
 * @param testID
 * @param numbers
 * @param target
 * @param expected The function needs to return this value in order to pass the test
 */
void test(const int testID, std::vector<int> numbers, int target, const std::vector<std::vector<int>> expected)
{
  std::vector<std::vector<int>> result = fourSum(numbers, target);

  // Test failed
  if (result != expected)
  {
    std::cout << testID << " failed expected:";
    printVector(expected);
    std::cout << " got:";
    printVector(result);
    std::cout << '\n';
  }
  // Test succeeded
  else
  {
    std::cout << testID << " passed" << '\n';
  }
}

int main()
{
  std::cout << '\n';

  // Tests from leetcode.com
  test(0, {1, 0, -1, 0, -2, 2}, 0, {{1, 0, -1, 0},{1, -1, -2, 2},{0, 0, -2, 2}});
  // TODO: account for duplicate vectors
  test(1, {2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});

  // Additional tests
  test(2, {87, 25, -16, -30, 0}, 96, {{87, 25, -16, 0}});
  test(3, {1, 2, 3, 4, 5, 6, 7}, 20, {{2, 5, 6, 7}, {3, 4, 6, 7}});

  std::cout << '\n';

  return 0;
}
