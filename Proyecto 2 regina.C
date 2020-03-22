
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char vuelo[5];
char *reservados[6][32] = {
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}};

char *cortar_string(char str[], int slice_from, int slice_to)
{
    // if a string is empty, returns nothing
    if (str[0] == '\0')
        return NULL;

    char *buffer;
    size_t str_len, buffer_len;

    // for negative indexes "slice_from" must be less "slice_to"
    if (slice_to < 0 && slice_from < slice_to)
    {
        str_len = strlen(str);

        // if "slice_to" goes beyond permissible limits
        if (abs(slice_to) > str_len - 1)
            return NULL;

        // if "slice_from" goes beyond permissible limits
        if (abs(slice_from) > str_len)
            slice_from = (-1) * str_len;

        buffer_len = slice_to - slice_from;
        str += (str_len + slice_from);

        // for positive indexes "slice_from" must be more "slice_to"
    }
    else if (slice_from >= 0 && slice_to > slice_from)
    {
        str_len = strlen(str);

        // if "slice_from" goes beyond permissible limits
        if (slice_from > str_len - 1)
            return NULL;

        buffer_len = slice_to - slice_from;
        str += slice_from;

        // otherwise, returns NULL
    }
    else
        return NULL;

    buffer = calloc(buffer_len, sizeof(char));
    strncpy(buffer, str, buffer_len);
    return buffer;
}
int convertir(char letra)
{
    if (&letra == "A")
    {
        return 0;
    }
    else if (&letra == "B")
    {
        return 1;
    }
    else if (&letra == "C")
    {
        return 2;
    }
    else if (&letra == "D")
    {
        return 3;
    }
    else if (&letra == "E")
    {
        return 4;
    }
    else if (&letra == "F")
    {
        return 5;
    }
    else
    {
        return 0;
    }
}
void clearscreen()
{
    system("@cls||clear");
}
void resumen()
{
    char *wait;
    clearscreen();
    int reservado;
    int libres;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            char* pool = reservados[j][i];
            if (pool == "X")
            {
                reservado++;
            }
        }
    }
    printf("### RESUMEN\n");
    printf("Reservados: %d/32\n", reservado);
    printf("Libres: %d/32", 32 - reservado);
    scanf("%s", wait);

}
void disponibles()
{
    char *wait;
    clearscreen();
    printf("|\t|A\t|B\t|C\t|D\t|E\t|F\t|\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < 32; i++)
    {
        printf("|%d\t", i + 1);
        printf("|%s\t", reservados[0][i]);
        printf("|%s\t", reservados[1][i]);
        printf("|%s\t", reservados[2][i]);
        printf("|%s\t", reservados[3][i]);
        printf("|%s\t", reservados[4][i]);
        printf("|%s\t", reservados[5][i]);
        printf("|\t\n");
    }
    printf("---------------------------------------------------------\n");
    scanf("%s", wait);
}
void reservar()
{
    char *wait;
    char peticion[3];
    clearscreen();
    printf("Vuelo: %s\n\n", vuelo);
    printf("Ingrese asiento a reservar: ");
    scanf("%s", peticion);
    int columna = convertir(peticion[0]);
    char *linea = cortar_string(peticion, 1, 3);
    char *lugar = reservados[columna][(int)*linea-1];

    if (lugar == "0")
    {
        clearscreen();
        reservados[columna][(int)*linea - 1] = "X";
        printf("Asiento '%s' reservado exitosamente!!\n\n", peticion);
        printf("Presione 'Enter'\n");
        scanf("%s", wait);
    }
    else
    {
        clearscreen();
        printf("Asiento '%s' ya reservado, ingrese otro asiento\n\n", peticion);
        printf("Presione 'Enter'\n");
        scanf("%s", wait);
    }
    clearscreen();
}