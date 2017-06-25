typedef struct
{
    int *data;
    int length;
    int sign;
}BIGNUMBER;

void readNumber(char*, BIGNUMBER*, BIGNUMBER*);
BIGNUMBER bigNumberOperation(BIGNUMBER, BIGNUMBER, char);
void writeResults(char*, BIGNUMBER*);
