#include <stdio.h>
main()
{
    int c,n1,n2,n3;
    /* n1,n2,n3都为标志数，n3=n1×n2,当n3=1时，不进行putchar */
    n1=n2=0;
    c=getchar();
    while(c!=EOF)
    {
        if(c==' ')
            n1=1;
        else
            n1=0;
        n3=n1*n2;
        if(n3==1)
            ;
        else
            putchar(c);


        c=getchar();
        if(c==' ')
            n2=1;
        else
            n2=0;
        n3=n1*n2;
        if(n3==1)
            ;
        else
            putchar(c);


        c=getchar();
    }
}
