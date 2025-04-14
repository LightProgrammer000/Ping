#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char comando[100];

        for (int i = 1; i < 255; i++)
        {
            snprintf(comando, sizeof(comando), "ping -c 1 -W 1 %s.%d > /dev/null 2>&1", argv[1], i);
            int resp = system(comando);

            if (resp == 0)
                printf("Host: %s.%d Ativo\n", argv[1], i);

            else
                printf("Host: %s.%d Desativado\n", argv[1], i);
        }
    }

    else
    {
        printf("=-= PING ARG =-=\n");
        printf("<Uso> ./ping_arg <192.168.0>\n");
    }

    return 0;
}
