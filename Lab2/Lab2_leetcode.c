#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

bool isValid(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else
        {
            if (top == -1)
                return false;

            char open = pop();

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
            {
                return false;
            }
        }
    }

    return top == -1;
}

int main()
{
    char s[MAX];

    printf("Enter brackets: ");
    scanf("%s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
