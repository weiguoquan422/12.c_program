#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline1(char s[], int lim)
//��һ�ж��뵽s�У��������䳤��
{
    int i;
    char c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        //���������ʱ\n����ͬ��������¼��s���飬����֮��\0
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/*--------  find -x -n  --------*/
int main(int argc, char const *argv[])//argv[]ʱָ������
{
    char line[MAXLINE];
    long lineno = 0;
    char c;
    int except = 0, number = 0, found = 0;


/*--------  ��ͨ��while�Կ�ѡ�������н���������¼��number��except��  --------*/
//Ϊ�˸�����⣬����find -xn am������ӷ����ó������ȣ�argv��ָ��argv[0]�ģ����汣��ָ��find��ָ��
    while (--argc > 0 && (*++argv)[0] == '-')//������++argv��argvָ����argv[1]�����汣����ָ��-xn��ָ�룻����ǰ��ӡ���ȡ����������ݣ���ȡ��ָ��-xn�׵�ַ��ָ�룻Ȼ��[0]Ҳ��ȥָ��ָ������ݣ�ȡָ��-xn�ĵ�һ���ַ����� - 
    {
        while (c = *++argv[0])//��������ע��һ�㣺�����Ѿ�++argv���������û�ӵĻ���argv[0]����argv[0],����������ˣ���ʱargv[0]ʵ������argv[1]�������ˣ���ʵ��õķ���������Ҳ��ָ���˼άȥ��⣡argv[0]����argvָ��ָ��ĵ�ַ�洢�����ݣ�argv[1]����argv+1ָ���ַ�洢�����ݣ�������������������argv[0]:�����Ѿ�++argv�ˣ���argv+1��argvָ���Ԫ�ش�argv����ĵ�0������˵�һ������ʱ����argv[0]����ǰargvָ��ĵ�ַ�����ݣ���argv�����һ��Ԫ�ص����ݣ�ָ��-xn�׵�ַ��ָ�룩������++��ָ�룬ָ��ָ��x��Ȼ���ȡ��x�ַ�����Ϊx��=0������while����switch��䣻����֮����++��ָ�룬ȡ��n����������while����switch��䣻������++��ָ�룬��ʱָ��\0��,�˳�ѭ����   �����find -n -x am����������Ҫ�����һ��while��++argv����һ�β�����
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
            lineno++;//��¼������û����һ���س���lineno++
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
