#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline1(char s[], int lim)
//��һ�ж��뵽s�У��������䳤��
{
    int i;
    char c;

    for (i = 0 ; i < lim - 1 && (c = getchar()) != EOF && c != '\n' ; i++ ) {
        s[i] = c;
    }
    if (c == '\n') {
    //���������ʱ\n����ͬ��������¼��s���飬����֮��\0
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}


/*--------  find��������ӡ���һ������ָ����ģʽƥ�����  --------*/
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
    //������������������һ�������find���ڶ�����һ���ַ����������ַ�������Ҫ�ҵ��ַ�
        printf("Usage: find pattern\n");
    }
    else {
        while (getline1(line, MAXLINE) > 0) {//�����������ѭ����
            if(strstr(line, argv[1]) != NULL){
                //��������line���к͵�һ������һ�����ַ������ӡ��line����
                printf("%s",line);
                found++;
            }
        }
    }
    return found;
}
