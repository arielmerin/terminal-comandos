#include <stdio.h>
#include <stdlib.h>


/*
Utilizaremos cada que use el mismo tipo de mememoria
*/
int main()
{
    float *arr;
    int size;

    printf("Hello world!\n");
    printf("Ingresa el número de materias:  ");
    scanf("%i", &size);
    //int arreglo_elementos[size];

    /*
    El casteo es parte importante de las buenas prácticas,
    en las nuevas versiones del c el compilador  lo hace por sí mismo

    Aquí estamos declarando un arregle, al parecere es exclusiva para esto pero no estoy seguro
    */
    //arr = (int*)malloc(sizeof(int) * size);
    arr = (float*)calloc(sizeof(float), size);


    /*
    Una vez creado el espacio, vamos a confirmarlo con esta parte del código
    44Apuntador dirección de memoria de otra variable
    */
    if( arr ==  NULL){
        printf("Oh oh, memoria insuficiente. Terrible, oremos");
        //Es una convención que sirve para mensaje de error interno,
        //es importante porque para programas posteriores podríamos identificarlos
        return -1;
    }

    //Asignar o guardar ios datos
    for (int i = 0; i< size; i++){
        printf("Ingresa la calificación número %i de tu tira de materias: ", i+1);
        /*Hay dos maneras de hacer esto, esta es una manera de hacerlo, la primera está silenciada, pero en general funcionan con
        la aritmtica de arreglos
        scanf("%i", arr[i] );
        También hay que ver que la dirección de los arreglos sea bien declarada
        poemos ocupar esto cuando haya problema con
        la obtención de los valores desde la terminsl
        etchar();
        */
        scanf("%f", (arr + i));
        //
    }

    /*Tulizar, hacer operaciones con los datos
    Recuerda siempre declarar bien el entero igual a i= 0 si no, no compilará

    Recuerda poner ambos en flotantes
    */
    float suma = 0.0;
    float promedio = 0.0;

    for(int i = 0; i < size; i++){
        suma += *(arr +i) ;
        promedio = suma/size;
    }

    printf("El promedio es : %f", promedio);
    //Para liberar memoria o terminar con el proceso
    free(arr);


    return 0;
}


/*

Malloc -> reserva el espacio en bytes
    cuando solo tenemos que reservar y en seguida podemos asignar
    DEbemos de enviarle un sizeof(tipo de variable) así que hay que multiplicarlos
    por buenas prácticas, debemos de poner una especificación
    estos valores reglresan un

calloc -> reserva nmero de elemento sy tambien los limpia (com con un 0 o null)
    Nos conviene cuando tenemos una agenda teleófinca,
    ejemplo si lo hiciéramos con malloc tendría basura

realloc -> cambair la asignación (tamaño)

free solo sirve para liberar

---- MANERAS DE ASIGNAR VALORES EN UN ARRGLO USANDO LOS APUNTADORES

*/
