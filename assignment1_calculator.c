// Kalpvriksha Program | Batch-2025: C Programming Assignments covering Calculator.

// assignment 1: Calculator, input format :- 3+5

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 100

typedef enum {
    NO_ERROR,
    DIVISION_BY_ZERO,
    INVALID_EXPRESSION
} ErrorType;

ErrorType error = NO_ERROR;

char* skip_whitespace(char *expr) {
    while (*expr == ' ') expr++;
    return expr;
}

int evaluate_term(char **expr);

int evaluate_expression(char **expr);

int parse_integer(char **expr) {
    *expr = skip_whitespace(*expr);
    int result = 0;
    while (isdigit(**expr)) {
        result = result * 10 + (**expr - '0');
        (*expr)++;
    }
    return result;
}

int evaluate_factor(char **expr) {
    *expr = skip_whitespace(*expr);
    if (isdigit(**expr)) {
        return parse_integer(expr);
    } else {
        error = INVALID_EXPRESSION;
        return 0;
    }
}

int evaluate_term(char **expr) {
    int value = evaluate_factor(expr);

    while (**expr == '*' || **expr == '/') {
        char op = **expr;
        (*expr)++;
        int next_value = evaluate_factor(expr);

        if (op == '*') {
            value *= next_value;
        } else if (op == '/') {
            if (next_value == 0) {
                error = DIVISION_BY_ZERO;
                return 0;
            }
            value /= next_value;
        }
    }

    return value;
}

int evaluate_expression(char **expr) {
    int value = evaluate_term(expr);

    while (**expr == '+' || **expr == '-') {
        char op = **expr;
        (*expr)++;
        int next_value = evaluate_term(expr);

        if (op == '+') {
            value += next_value;
        } else if (op == '-') {
            value -= next_value;
        }
    }

    return value;
}

int evaluate(const char *expression) {
    char expr[MAX_EXPR_LEN];
    strncpy(expr, expression, MAX_EXPR_LEN - 1);
    expr[MAX_EXPR_LEN - 1] = '\0';

    char *p = expr;
    int result = evaluate_expression(&p);
    
    if (*skip_whitespace(p) != '\0') {
        error = INVALID_EXPRESSION;
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

    int result = evaluate(input);

    if (error == DIVISION_BY_ZERO) {
        printf("Error: Division by zero.\n");
    } else if (error == INVALID_EXPRESSION) {
        printf("Error: Invalid expression.\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
