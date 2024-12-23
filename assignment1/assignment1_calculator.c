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

int is_digit(char digit) {
    return (digit >= '0' && digit <= '9');
}

int extractIntegerFromExpression(char **expression) {
    int result = 0;
    while (is_digit(**expression)) {
        result = result * 10 + (**expression - '0');
        (*expression)++;
    }
    return result;
}

Result checkFactorValidity(char **expression) {
    Result result = {0, NO_ERROR};

    if (is_digit(**expression)) {
        result.value = extractIntegerFromExpression(expression);
    } else {
        result.error = INVALID_EXPRESSION;
    }
    return result;
}

int getStringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

Result calculateMultiplicationDivision(char **expression) {
    Result result = checkFactorValidity(expression);
    if (result.error != NO_ERROR) return result;

    while (**expression == DIV_OP) {
        (*expression)++;
        Result nextResult = checkFactorValidity(expression);
        if (nextResult.error != NO_ERROR) return nextResult;

        if (nextResult.value == 0) {
            result.error = DIVISION_BY_ZERO;
            return result;
        }
        result.value /= nextResult.value;
    }

    while (**expression == MUL_OP) {
        (*expression)++;
        Result nextResult = checkFactorValidity(expression);
        if (nextResult.error != NO_ERROR) return nextResult;

        result.value *= nextResult.value;
    }

    return result;
}

Result calculateSum(char **expression) {
    Result result = calculateMultiplicationDivision(expression);
    if (result.error != NO_ERROR) return result;

    while (**expression == ADD_OP || **expression == SUB_OP) {
        char operation = **expression;
        (*expression)++;
        Result nextResult = calculateMultiplicationDivision(expression);
        if (nextResult.error != NO_ERROR) return nextResult;

        if (operation == ADD_OP) {
            result.value += nextResult.value;
        } else if (operation == SUB_OP) {
            result.value -= nextResult.value;
        }
    }
    return result;
}

void removeWhiteSpaces(char *expression) {
    int readIndex = 0, writeIndex = 0;

    while (expression[readIndex] != '\0') {
        if (expression[readIndex] == ' ' || expression[readIndex] == '\t' || expression[readIndex] == '\n') {
            readIndex++; 
        } else {
            expression[writeIndex++] = expression[readIndex++];
        }
    }

    expression[writeIndex] = '\0';
}

Result calculateSumFromString(const char *inputExpression) {
    char expression[MAX_EXPR_LEN];
    strncpy(expression, inputExpression, MAX_EXPR_LEN - 1);
    expression[MAX_EXPR_LEN - 1] = '\0';

    removeWhiteSpaces(expression);

    char *expressionPointer = expression;
    Result result = calculateSum(&expressionPointer);

    if (*expressionPointer != '\0') {
        result.error = INVALID_EXPRESSION;
    }
    return result;
}

int main() {
    char input[MAX_EXPR_LEN];

    printf("Enter a mathematical expression: ");
    if (fgets(input, MAX_EXPR_LEN, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = 0;

    Result result = calculateSumFromString(input);

    if (result.error == DIVISION_BY_ZERO) {
        printf("Error: Division by zero.\n");
    } else if (result.error == INVALID_EXPRESSION) {
        printf("Error: Invalid expression.\n");
    } else {
        printf("Result: %d\n", result.value);
    }

    return 0;
}