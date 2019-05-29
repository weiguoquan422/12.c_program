#include <stdio.h>
#define IN 1
#define OUT 0

main()
{
    int c,state;
    state=OUT;
    c=getchar();
    while(c!=EOF){
        if(c!=' '&&c!='\n'&&c!='\t'){
            state=IN;putchar(c);
        }
        else{
            if(state==IN){
                state=OUT;putchar('\n');
            }
            else if(state==OUT)
                ;
        }
        c=getchar();
    }
}
