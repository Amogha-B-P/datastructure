#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch;
    ch = stack[top];
    top--;
    return ch;
}

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int valid(char infix[])
{
    int i, count = 0;

    for(i = 0; infix[i] != '\0'; i++)
    {
        if(infix[i] == '(')
            count++;
        else if(infix[i] == ')')
        {
            count--;
            if(count < 0)
                return 0;
        }
    }

    if(count == 0)
        return 1;
    else
        return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;

    push('(');
    strcat(infix, ")");

    while(infix[i] != '\0')
    {
        symbol = infix[i];

        if(symbol == ' ')
        {
            i++;
            continue;
        }

        if(symbol == '(')
        {
            push(symbol);
        }
        else if(isalnum(symbol))
        {
            postfix[j] = symbol;
            j++;
        }
        else if(symbol == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while(precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
        }

        i++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    if(valid(infix) == 0)
    {
        printf("Invalid Expression\n");
        return 0;
    }

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
