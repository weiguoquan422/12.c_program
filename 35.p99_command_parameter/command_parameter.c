#include <stdio.h>

/*--------  ���������в���  --------*/

main(int argc, char *argv[])
{
    int i;

    for (i = 1 ; i < argc ; i++ ) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
        //�����û�����һ���������ڲ���֮��ӿո�������ˣ���ʲô������
    }
    printf("\n");
    return 0;
}