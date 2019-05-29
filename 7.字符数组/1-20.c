#include <stdio.h>

#define TABINC 10 
/*replace tabs with the proper number of blanks*/
main()
{
    int c,nb,pos;

    nb=0; /*number of neccessary*/
    pos=1;
    while((c=getchar())!=EOF){
        if(c=='\t'){
            nb=TABINC-(pos-1)%TABINC;
            while(nb>0){
                putchar(' ');
                ++pos;
                --nb;
            }
        }else if(c=='\n'){
            putchar(c);
            pos=1;
        }else{
            putchar(c);
            ++pos;
        }
    }
}
