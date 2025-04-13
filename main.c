#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_IP 255
#define CAR_IP 20
#define IP_BASE "192.168.0"

void ataque(char lista[NUM_IP][CAR_IP]);


int main(int argc, char * argv[])
{
    char ip[] = IP_BASE;
    char lista[NUM_IP][CAR_IP] = {};


    for (int i = 0; i < 255; i++)
    {
        // Montagem de lista
        snprintf(lista[i], sizeof(lista[i]), "%s.%d", ip, i);
    }

    ataque(lista);

    return 0;
}

void ataque(char lista [NUM_IP][CAR_IP])
{
    char comando[128];

    for (int i = 0; i < 255; i++)
    {
        // Montagem de comando
        snprintf(comando, sizeof(comando), "ping -c 1 %s > /dev/null 2>&1", lista[i]);
        int resp = system(comando);

        if (resp == 0)
        {
            printf("Host: %s Ativo\n", lista[i]);
        }

        else
        {
            printf("Host: %s Desativado\n", lista[i]);
        }
    }
}
