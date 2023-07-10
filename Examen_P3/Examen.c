#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

char archivoTXT[] = "alumnos.txt";

typedef struct{
    char informacionPersonal[100];
    char ID[5];
    char nombre[50];
    char carrera[50];
    float nota1;
    float nota2;
    float nota3;
    float promedio;
}informacion;

int main(){

    int cantidadAlumnos = 5;
    //Inicialización de arreglo de struct
    informacion *estudiante = calloc(cantidadAlumnos,sizeof(informacion*));

    FILE *archivo;
    FILE *escritura;
    if((archivo = fopen(archivoTXT,"r"))==NULL) printf("Error al abrir el acrhivo. Seguramente no existe");
    if((escritura = fopen(archivoTXT,"w"))==NULL) printf("Error al abrir el acrhivo. Seguramente no existe");

    char linea[100]; //Definición de cadena que almacena el contenido del fichero

    while (fgets(linea,100,archivo))
    {
        linea[strlen(linea)-1] = '\0';
        printf("%s\n", linea);
    }

    for (int i = 0; i < cantidadAlumnos; i++)
    {
    //    fprintf("%s",linea);
    }
    
    return 0;
}