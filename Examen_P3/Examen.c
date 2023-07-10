#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    informacion *estudiante = calloc(5,sizeof(informacion*));

    //Definición de punteros para manejar los ficheros
    FILE *archivo;
    FILE *escritura;

    if((archivo = fopen(archivoTXT,"r"))==NULL) printf("Error al abrir el acrhivo. Seguramente no existe");
    if((escritura = fopen(archivoTXT,"w"))==NULL) printf("Error al abrir el acrhivo. Seguramente no existe");

    char linea[100]; //Definición de cadena que almacena el contenido del fichero

    //Lectura de lineas dentro del fichero
    for (int i = 0; i < cantidadAlumnos; i++){
        if (fgets(linea, sizeof(linea), archivo) != NULL){
            char *ID = calloc(5,sizeof(char));
            char *nombre = calloc(50,sizeof(char));
            char *carrera = calloc(50,sizeof(char));
            
            char *token = strtok(linea,";");
            int count = 0; //Definición de contador para guardar los TOKENS resultantes dentro de cada variable temporal.
            while (token != NULL) {
                if (count == 0) {
                    ID = token;
                    strcpy(estudiante[i].ID, token); //Copiar contenido de token a los atributos de cada persona.
                } else if (count == 1) {
                    nombre = token;
                    strcpy(estudiante[i].nombre, token);
                } else if (count == 2) {
                    carrera = token;
                    strcpy(estudiante[i].carrera, token);
                } else if (count == 3) {
                    estudiante[i].nota1 = atoi(token); //Transformación de strings a números
                } else if (count == 4) {
                    estudiante[i].nota2 = atoi(token); //Transformación de strings a números
                } else if (count == 5) {
                    estudiante[i].nota3 = atoi(token); //Transformación de strings a números
                }

                count++;
                token = strtok(NULL, ";");
            }
            estudiante[i].promedio = (estudiante[i].nota1 +estudiante[i].nota2 +estudiante[i].nota3)/300;
            printf("%.2f", estudiante[i].promedio);
        }
    }

    //Impresión de datos al revés
    /*for (int j = cantidadAlumnos; j > 0; j--){
        fprintf(escritura,"%s\n",estudiante[j].informacionPersonal);
    }*/
    
    return 0;
}