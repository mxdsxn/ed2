#include "./node.hpp"

int main()
{
     Node<char> *treeChar = nullptr;
     char arrayChar[] = {'Q', 'Z', 'B', 'Y', 'T', 'M', 'E', 'W', 'X', 'S', 'F', 'G', 'A', 'H', 'N', 'O', 'P', 'R'};
     for (const char i : arrayChar)
     {
          tree = tree->inserir(i);
     }

     Node<int> *treeInt = nullptr;
     int arrayInt[] = {14, 5, 28, 2, 8, 18, 33, 1, 3, 6, 11, 15, 20, 30, 38, 4, 7, 10, 12, 16, 19, 21, 29, 31, 35, 39, 13, 22, 32, 34, 36, 40, 37};
     for (const int i : arrayInt)
     {
          tree = tree->inserir(i);
     }

     return 0;
}
