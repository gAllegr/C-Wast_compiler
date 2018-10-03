#include <stdio.h>

int int_res;
float float_res;
char letter = 'a', hello[13] = "Hello World!", word[5] = {'w', 'o', 'r', 'd'};

int int_op(int choose, int left, int right)
{
    int res;

    if(choose == 1)
        res = left + right;
    else res = left - right;

    return res;
}

float float_op(int choose, float left, float right)
{
    float res;

    if(choose == 1) res = left * right;
    else res = left/right;

    return res;
}

int main()
{
    int a = 2, b = 5;
    float c = 1.5, d = 4.5;
    int op1 = 1;

    // say hello
    printf("%s", hello);

    // do some integer math
    printf("Add 2 and 5");
    int_res = int_op(op1, a, b);
    printf("%d", int_res);

    b--;

    printf("Subtract 2 and 4");
    int_res = int_op(a, a, b);
    printf("%d", int_res);

    // do some float math
    printf("Multiply 1.5 by 4.5");
    float_res = float_op(op1, c, d);
    printf("%f", float_res);

    printf("Divide 1.5 by 4.5");
    float_res = float_op(a, c, d);
    printf("%f", float_res);

    // say one word
    printf("%s", word);

    // print one letter
    printf("%s", letter);

    return 0;
}