#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline1(char s[], int lim)
//将一行读入到s中，并返回其长度
{
    int i;
    char c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        //如果最后读到时\n，则同样把它记录进s数组，并在之后补\0
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/*--------  find -x -n  --------*/
int main(int argc, char const *argv[])//argv[]时指针数组
{
    char line[MAXLINE];
    long lineno = 0;
    char c;
    int except = 0, number = 0, found = 0;


/*--------  先通过while对可选参数进行解析，并记录在number和except中  --------*/
//为了更好理解，我以find -xn am这个例子分析该程序；首先，argv是指向argv[0]的，里面保存指向find的指针
    while (--argc > 0 && (*++argv)[0] == '-')//这里先++argv，argv指向了argv[1]，里面保存着指向-xn的指针；接着前面加×，取出里面的内容，即取出指向-xn首地址的指针；然后，[0]也是去指针指向的内容，取指向-xn的第一个字符，即 - 
    {
        while (c = *++argv[0])//这里首先注意一点：上面已经++argv，如果上面没加的话，argv[0]就是argv[0],但是上面加了，此时argv[0]实际上是argv[1]的内容了；其实最好的方法是数组也按指针的思维去理解！argv[0]就是argv指针指向的地址存储的内容，argv[1]就是argv+1指向地址存储的内容；这样我们再理解上面的argv[0]:上面已经++argv了，即argv+1，argv指向的元素从argv数组的第0个变成了第一个，此时再求argv[0]即求当前argv指向的地址的内容，即argv数组第一个元素的内容（指向-xn首地址的指针）；接着++该指针，指针指向x，然后×取出x字符，因为x！=0，进入while进行switch语句；完了之后再++该指针，取出n，继续进入while进行switch语句；完了再++该指针，此时指向‘\0’,退出循环。   如果是find -n -x am这样，则需要进入第一层while再++argv进行一次操作。
        {
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find:illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }
    if (argc != 1)
    {
        printf("Usage: find -x -n pattern\n");
    }
    else
    {
        while (getline1(line, MAXLINE) > 0)
        {
            lineno++;//记录行数，没输入一个回车，lineno++
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number)
                {
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}
