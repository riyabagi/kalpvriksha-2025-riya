#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LEN 100

#define ADD_OP '+'
#define SUB_OP '-'
#define MUL_OP '*'
#define DIV_OP '/'

typedef enum {
    NO_ERROR,
    DIVISION_BY_ZERO,
    INVALID_EXPRESSION
} ErrorType;

typedef struct {
    int value;
    ErrorType error;
} Result;

int is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int parse_integer(char **expr) {
    int result = 0;
    while (is_digit(**expr)) {
        result = result * 10 + (**expr - '0');
        (*expr)++;
    }
    return result;
}

Result checkFactorValidity(char **expr) {
    Result res = {0, NO_ERROR};

    if (is_digit(**expr)) {
        res.value = parse_integer(expr);
    } else {
        res.error = INVALID_EXPRESSION; 
    }
    return res;
}

Result calculateMulDiv(char **expr) {
    Result res = checkFactorValidity(expr);
    if (res.error != NO_ERROR) return res; 

    while (**expr == MUL_OP || **expr == DIV_OP) {
        char op = **expr;
        (*expr)++;
        Result nextRes = checkFactorValidity(expr);
        if (nextRes.error != NO_ERROR) return nextRes; 

        if (op == MUL_OP) {
            res.value *= nextRes.value;
        } else if (op == DIV_OP) {
            if (nextRes.value == 0) {
                res.error = DIVISION_BY_ZERO; 
                return res;
            }
            res.value /= nextRes.value;
        }
    }
    return res;
}

Result calculateSum(char **expr) {
    Result res = calculateMulDiv(expr); 
    if (res.error != NO_ERROR) return res; 

    while (**expr == ADD_OP || **expr == SUB_OP) {
        char op = **expr;
        (*expr)++;
        Result nextRes = calculateMulDiv(expr); 
        if (nextRes.error != NO_ERROR) return nextRes;

        if (op == ADD_OP) {
            res.value += nextRes.value;
        } else if (op == SUB_OP) {
            res.value -= nextRes.value;
        }
    }
    return res;
}

Result calculateSumFromString(const char *expression) {
    char expr[MAX_EXPR_LEN];
    strncpy(expr, expression, MAX_EXPR_LEN - 1);
    expr[MAX_EXPR_LEN - 1] = '\0';

    char *p = expr;
    while (*p != '\0') {
        if (*p == ' ' || *p == '\t' || *p == '\n') {
            memmove(p, p + 1, strlen(p));
        } else {
            p++;
        }
    }

    p = expr; 
    Result res = calculateSum(&p); 

    if (*p != '\0') {
        res.error = INVALID_EXPRESSION;
    }
    return res;
}

int main() {
    char input[MAX_EXPR_LEN];

    printf("Enter a mathematical expression: ");
    if (fgets(input, MAX_EXPR_LEN, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = 0;

    Result res = calculateSumFromString(input);

    if (res.error == DIVISION_BY_ZERO) {
        printf("Error: Division by zero.\n");
    } else if (res.error == INVALID_EXPRESSION) {
        printf("Error: Invalid expression.\n");
    } else {
        printf("Result: %d\n", res.value);
    }

    return 0;
}