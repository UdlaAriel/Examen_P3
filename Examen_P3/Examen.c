#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char archivoCSV[] = "alumnos.txt";

typedef struct
{
    char InformacionPersonal[100];
    int promedio;
}Estudiante;

int main(){

    int cantidadAlumnos = 5;
    int i;
    //Inicialización de arreglo de struct
    Estudiante *informacion = calloc(5, sizeof(Estudiante*));

    FILE *archivo;
    if((archivo = fopen(archivoCSV,"r"))==NULL) printf("Error al abrir el acrhivo. Seguramente no existe");

    while (!feof(archivo))
    {
        char linea[100];

        fgets(linea,100,archivo);
        //linea[strlen(linea)-1] = '\0';
        printf("%s\n", linea);

        strncpy(informacion[i].InformacionPersonal,linea,strlen(linea)-1);
    }

    for (int i=cantidadAlumnos; i>0; i--)
    {
        /* code */
    }
    

    return 0;
}