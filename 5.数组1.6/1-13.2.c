#include <stdio.h>

#define MAXHIST 15 /*max length of histogram*/
#define MAXWORD 11 /*max length of a word*/
#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

main()
{
    int c,i,j,nc,state;
    int len; /*length of each bar*/
    int maxvalue; /*maximum value for wl[]*/
    int overflow; /*number of overflow words*/
    int wl[MAXWORD]; /*word length counters*/

    state=OUT;
    nc=0; /*number of chars in a word*/
    overflow=0; /*number of words>=MAXWORD*/
    for(i=1;i<=MAXWORD;++i)
        wl[i]=0;
    while((c=getchar())!=EOF){
        if(c==' '||c=='\n'||c=='\t'){
            state=OUT;
            if(nc>0){
                if(nc<MAXWORD)
                    ++wl[nc];
                else
                    ++overflow;
            }
            nc=0;
        }else if(state==OUT){
            state=IN;
            nc=1; /*begining of a new word*/
        }else
            ++nc; /*inside a word*/

    }


    maxvalue=0;
    for(i=1;i<MAXWORD;++i)
        if(wl[i]>maxvalue)
            maxvalue=wl[i];

    for(i=MAXHIST;i>0;--i){
        for(j=1;j<MAXHIST;++j){
            if(wl[j]*MAXHIST/maxvalue>=i)
                printf("    *");
            else
                printf("     ");
        }
        putchar('\n');
    } 
    for(i=1;i<MAXWORD;++i)
        printf("%4d",wl[i]);
    putchar('\n');

}
