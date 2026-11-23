
bool isValid(char* s)
{
    char stack[10001];
    int top = -1;
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            top++;
            stack[top] = s[i];
        }
        else
        {
            if (top == -1)
                return false;

            if (s[i] == ')' && stack[top] == '(')
                top--;
            else if (s[i] == '}' && stack[top] == '{')
                top--;
            else if (s[i] == ']' && stack[top] == '[')
                top--;
            else
                return false;
        }
    }

    if (top == -1)
        return true;
    else
        return false;
}

