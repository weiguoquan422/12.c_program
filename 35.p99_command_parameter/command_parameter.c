#include <stdio.h>

/*--------  回显命令行参数  --------*/

main(int argc, char *argv[])
{
    int i;

    for (i = 1 ; i < argc ; i++ ) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
        //如果还没到最后一个参数，在参数之间加空格；如果到了，则什么都不加
    }
    printf("\n");
    return 0;
}