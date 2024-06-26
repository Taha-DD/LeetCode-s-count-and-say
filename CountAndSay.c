#include<stdio.h>

void zero(int v[][10], int index)
{
    for (int i = 0; i < 10; i++)
        v[index][i] = 0;
}

void say(int *number)
{
    int c[1000][10], index = 0, in = 1;
    int len = number[0];
    zero(c, index);

    for (int i = 1; i <= len; i++)
    {
        int j = i;
        
        while (j <= len && number[j] == number[i])
            j++;
        
        c[index][0] = j - i;
        c[index][1] = number[i];
        
        index++;
        i = j - 1;
    }

    
    for (int i = 0; i < index; i++)
    {
        number[in++] = c[i][0];
        number[in++] = c[i][1];
    }
    number[0] = in - 1;
}

void CountAndSay(int num, int *number)
{
    number[0] = 1;
    number[1] = 1;
    
    for (int i = 2; i <= num; i++)
        say(number);
}

int main()
{
    int num;
    
    printf("Welcome to count-and-say program. Please enter a number: ");
    scanf("%d", &num);

    int number[1000] = {0};

    printf("Count and Say for %d is ", num);
    
    CountAndSay(num, number);
    
    for (int i = 1; i <= number[0]; i++)
        printf("%d", number[i]);

    return 0;
}