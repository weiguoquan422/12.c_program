#include <stdio.h>
main()
{
    int n1,n2,n3,c;
    /* 分别表示空格，制表符，换行符个数及输入字符 */

    n1=n2=n3=0;
    while((c=getchar())!=EOF)
    {
        if(c==' ')
            ++n1;
        if(c=='\t')
            ++n2;
        if(c=='\n')
            ++n3;
    }
    printf("n1=%d\n",n1);
    printf("n2=%d\n",n2);
    printf("n3=%d\n",n3);
}
