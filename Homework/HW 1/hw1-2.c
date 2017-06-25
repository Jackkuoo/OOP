#include "bignum.h"

int main(int argc, char *argv[])
{
    BIGNUMBER a, b;
    readNumber(argv[1], &a, &b);
    BIGNUMBER results[2];
    results[0] = bigNumberOperation(a,b,'+');
    results[1] = bigNumberOperation(a,b,'-');
    writeResults(argv[2], results);
    return 0;
}
