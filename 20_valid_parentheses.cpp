#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string& input)
{
  std::stack<int> bracketValidationStack;

  // Iterating over the entire string
  for (std::string::iterator iterator = input.begin(); iterator != input.end(); iterator++)
  {
    // If the iterator points to either a (, [ or { it gets pushed as an integer
    switch (*iterator)
    {
      case '(':
        bracketValidationStack.push(1);
      break;

      case '[':
        bracketValidationStack.push(2);
      break;

      case '{':
        bracketValidationStack.push(3);
      break;

      // If the top of the stack is the matching bracket pair, do nothing (pop the top of the stack)
      // Otherwise it's an invalid sequence
      case ')':
        if (bracketValidationStack.top() == 1)
        {
          bracketValidationStack.pop();
        }
        else
        {
          return false;
        }
      break;

      case ']':
        if (bracketValidationStack.top() == 2)
        {
          bracketValidationStack.pop();
        }
        else
        {
          return false;
        }
      break;

      case '}':
        if (bracketValidationStack.top() == 3)
        {
          bracketValidationStack.pop();
        }
        else
        {
          return false;
        }
      break;

      default:
      break;
    }
  }

  return true;
}

void test(const int testID, std::string input, const bool expected)
{
  bool result = isValid(input);

  if (result != expected)
  {
    std::cout << testID << " failed expected:" << expected << " got:" << result << '\n';
  }
  else
  {
    std::cout << testID << " passed" << '\n';
  }
}

int main()
{
  std::cout << '\n';

  // Tests from leetcode.com
  test(0, "()", true);
  test(1, "()[]{}", true);
  test(2, "(]", false);

  // Additional tests
  test(3, "as(lkj)jk", true);
  test(4, "asd(ds(sds(fREWNda)lOUTWlr]skI)lIS.", false);
  test(5, "A.r[lS#*)l+", false);
  test(6, "(/((/|))%*)([#0{(28{[09]}2920)}0923])", true);

  std::cout << '\n';

  return 0;
}
