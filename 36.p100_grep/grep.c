#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline1(char s[], int lim)
//将一行读入到s中，并返回其长度
{
    int i;
    char c;

    for (i = 0 ; i < lim - 1 && (c = getchar()) != EOF && c != '\n' ; i++ ) {
        s[i] = c;
    }
    if (c == '\n') {
    //如果最后读到时\n，则同样把它记录进s数组，并在之后补\0
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}


/*--------  find函数，打印与第一个参数指定的模式匹配的行  --------*/
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
    //参数必须是两个，第一个是命令即find，第二个是一行字符即从这行字符中找需要找的字符
        printf("Usage: find pattern\n");
    }
    else {
        while (getline1(line, MAXLINE) > 0) {//在这里进入死循环了
            if(strstr(line, argv[1]) != NULL){
                //如果输入的line中有和第一个参数一样的字符，则打印出line来；
                printf("%s",line);
                found++;
            }
        }
    }
    return found;
}
