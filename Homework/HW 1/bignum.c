#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bignum.h"

void readNumber(char* input, BIGNUMBER *a, BIGNUMBER *b)
{
    FILE* in;
    in = fopen(input, "r");
    char temp[40];
    //BIGNUMBER a
    fscanf(in, "%s", temp);
    if (temp[0] == '-')
    {
        a->length = strlen(temp) - 1;
        a->sign = -1;
    }
    else
    {
        a->length = strlen(temp);
        a->sign = 0;
    }
    a->data = malloc(sizeof(int) * 40);
    int idx;
    for (idx = 0;idx < a->length;idx++)
        a->data[idx] = temp[strlen(temp)-1-idx]-48;
    //BIGNUMBER b
    fscanf(in, "%s", temp);
    if (temp[0] == '-')
    {
        b->length = strlen(temp) - 1;
        b->sign = -1;
    }
    else
    {
        b->length = strlen(temp);
        b->sign = 0;
    }
    b->data = malloc(sizeof(int) * 40);
    for (idx = 0;idx < b->length;idx++)
        b->data[idx] = temp[strlen(temp)-1-idx]-48;
    fclose(in);
}

BIGNUMBER bigNumberOperation(BIGNUMBER a, BIGNUMBER b, char op)
{
    BIGNUMBER c;
    c.data = malloc(sizeof(int) * 40);
    int idx;
    int carry = 0;
    int lend = 0;
    switch (op)
    {
        case '+':
            for (idx = 0;idx < a.length || idx < b.length;idx++)
            {
                c.data[idx] = (a.data[idx] + b.data[idx] + carry) % 10;
                if (a.data[idx] + b.data[idx] + carry >= 10)
                    carry = 1;
                else 
                    carry = 0;
            }
            if (carry == 1)
            {
                c.data[idx] = 1;
                idx++;
            }
            c.length = idx;
            return c;
        case '-':
            for (idx = 0;idx < a.length || idx < b.length;idx++)
            {
                c.data[idx] = (a.data[idx] - b.data[idx] - lend + 10) % 10;
                if (a.data[idx] - b.data[idx] - lend < 0)
                    lend = 1;
                else 
                    lend = 0;
            }
            if (c.data[idx-1] == 0)
                idx--;
            c.length = idx;
            return c;
        default:
            printf("Wrong Operation\n");
    }
}

void writeResults(char* output, BIGNUMBER* result)
{
    FILE* out;
    out = fopen(output, "w");
    fprintf(out, "A + B = ");
    int idx;
    for (idx = result[0].length-1;idx >= 0;idx--)
        fprintf(out, "%d", result[0].data[idx]);
    fprintf(out, "\n");
    fprintf(out, "A - B = ");
    for (idx = result[1].length-1;idx >= 0;idx--)
        fprintf(out, "%d", result[1].data[idx]);
    fprintf(out, "\n");
    fclose(out);
}
