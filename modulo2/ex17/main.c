#include <stdio.h>
#include "asm.h"

char operator;
int op1, op2, resSum, resSub, resMul, resDiv, resMod, resPot2, resPot3;

int main()
{

    printf("Enter an operator (+, -, *, /, |, 2, 3): ");
    scanf("%c", &operator);

    switch (operator)
    {
    case '+':
        printf("Insert 1st number: ");
        scanf("%d", &op1);

        printf("Insert 2nd number: ");
        scanf("%d", &op2);

        resSum = sum(op1, op2);
        printf("%d + %d = %d\n", op1, op2, resSum);
        break;

    case '-':
        printf("Insert 1st number: ");
        scanf("%d", &op1);

        printf("Insert 2nd number: ");
        scanf("%d", &op2);

        resSub = subt(op1, op2);
        printf("%d - %d = %d\n", op1, op2, resSub);
        break;

    case '*':
        printf("Insert 1st number: ");
        scanf("%d", &op1);

        printf("Insert 2nd number: ");
        scanf("%d", &op2);

        resMul = mult(op1, op2);
        printf("%d * %d = %d\n", op1, op2, resMul);
        break;

    case '/':
        printf("Insert 1st number: ");
        scanf("%d", &op1);

        printf("Insert 2nd number: ");
        scanf("%d", &op2);

        resDiv = divi(op1, op2);
        printf("%d / %d = %d\n", op1, op2, resDiv);
        break;

    case '|':
        printf("Insert 1 number: ");
        scanf("%d", &op1);

        resMod = mod(op1);
        printf("|%d| = %d\n", op1, resMod);
        break;

    case '2':
        printf("Insert 1 number: ");
        scanf("%d", &op1);

        resPot2 = pot2(op1);
        printf("%d ^2 = %d\n", op1, resPot2);
        break;

    case '3':
        printf("Insert 1 number: ");
        scanf("%d", &op1);

        resPot3 = pot3(op1);
        printf("%d ^3 = %d\n", op1, resPot3);
        break;

    default:
        printf("Error! operator is not correct\n");
    }

    return 0;
}
