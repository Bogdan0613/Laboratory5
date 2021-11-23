#include <iostream>
using namespace std;

void count_expression(char* exit, int len){ // exit-запис виразу в ОПН, len його довжина
    int answer[100];
    float stack1[100];
    int n = 0, i = 0;
    float number=0;
    int counter = 1;
    for (int j = 0; j < len; j++) {
        if (exit[j] == ' ' || exit[j] == '\n' || exit[j] == NULL)
            continue;

        else if (exit[j] == '+') {
            stack1[n - 2] = stack1[n - 2] + stack1[n - 1];
            n--;
            continue;
        }
        else if (exit[j] == '-') {
            stack1[n - 2] = stack1[n - 2] - stack1[n - 1];
            n--;
            continue;
        }
        else if (exit[j] == '*') {
            stack1[n - 2] = stack1[n - 1] * stack1[n - 2];
            n--;
            continue;
        }
        else if (exit[j] == '/') {
            stack1[n - 2] = stack1[n - 2] / stack1[n - 1];
            n--;
            continue;
        }

        else {
            for (int y = j; y < len; y++) {// пошук всіх цифр числа
                if (isdigit(exit[y]) ) {
                    answer[i] = (int)exit[y]-48;
                    i++;
                }
                else {
                    j = y;
                    break;
                }
            }
            for( int a = i-1; a>=0;a--){
                number+=answer[a]*counter;

                counter*=10;
            }
            stack1[n] = number;
            n++;
            number = 0;
            counter = 1;
            i = 0;
        }
    }
    cout << endl << "Result = " << stack1[n - 1] << endl;
}

int main()
{
    int s = 0, e = 0;
    int length = 0;
    char expression[100], stack[100], exit[100];

    cin >> expression;
    for (int i = 0; expression[i] != '\0'; i++)
        switch (expression[i])
        {
            case '+':
                while ((s != 0) && (stack[s - 1] != '('))
                {
                    exit[e] = stack[s - 1]; // на вихід
                    e++;
                    s--;
                }
                stack[s] = '+'; // поміщаємо в стек
                s++;
                break;

            case '-':
                while ((s != 0) && (stack[s - 1] != '('))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '-';
                s++;
                break;
            case '*':

                while ((s != 0) && (stack[s - 1] != '(') && (stack[s - 1] != '+') && (stack[s - 1] != '-'))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '*';
                s++;
                break;
            case '/':

                while ((s != 0) && (stack[s - 1] != '(') && (stack[s - 1] != '+') && (stack[s - 1] != '-'))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '/';
                s++;

                break;
            case '(':
            {
                stack[s] = '(';
                s++;
                break; }
            case ')':

                while ((stack[s - 1] != '(') && (s != 0))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s - 1] = ' ';
                s--;
                break;


            default:

            {
                exit[e] = expression[i];
                e++;
                if ((expression[i + 1] == '+') ||
                    (expression[i + 1] == '-') ||
                    (expression[i + 1] == '*') ||
                    (expression[i + 1] == '/') ||
                    (expression[i + 1] == '(') ||
                    (expression[i + 1] == ')'))
                {
                    exit[e] = ' ';
                    e++;
                }
            }
        }

    exit[e] = ' ';
    e++;

    while (s != 0)
    {
        exit[e] = stack[s - 1];
        e++;
        s--;
    }
    cout << "Obernena polsaka notatsia: ";
    for (int i = 0; i < e; i++)
    {
        cout << exit[i];
        length++;
    }

    count_expression(exit, length); // обрахування виразу записаного в польскій нотації

}
