#include <stdio.h>
void swap(int& a, int& b) { a ^= b ^= a ^= b; }
int unsetBit(int a, int b)
{
    return a & ~(1 << b);
}
int setBit(int a, int b)
{
    return a | (1 << b);
}
int flapBit(int a, int b) { return a ^ (1 << b); }
int main()
{
    return 0;
}
