#include <stdio.h>

int main()
{
    /* Declaracion de variables */
    int edad, ipa, apa, porter, cantPrecio, ninguna, cantPersonas, edadesApa, contEdad;
    char preferencia[10];
    float precio, precioProm, max, min, prom;

    /* Inicializacion de variables */
    ipa = 0;
    apa = 0;
    porter = 0;
    ninguna = 0;
    cantPersonas = 0;
    edadesApa = 0;
    contEdad = 0;
    cantPrecio = 0;
    precioProm = 0;
    prom = 0;
    max = -99999;
    min = 99999;

    /* Ingreso por teclado */
    printf("INGRESE TU EDAD: \n");
    scanf("%d", &edad);
    printf("CUAL PREFERIS: \n IPA \n APA \n PORTER \n NINGUNA \n");
    scanf("%s", &preferencia);
    printf("INGRESE EL PRECIO QUE LE DARIAS A LA PINTA: \n");
    scanf("%f", &precio);

    /* Resolucion del problema */
    while ((edad <45) && (precio > 0))
    {
        /* PUNTO A*/
        cantPersonas += 1;      //Suma la cantidad de personas que respondieron la encuesta

        /* PUNTO B*/
        if (strcmp(preferencia, "APA"))     //Suma las edades para sacar el promedio de personas que respondieron la encuesta y les gusta la APA
        {
            edadesApa += edad;
            contEdad++;
        }

        /* PUNTO C*/
        if ((edad >= 18) && (edad <=25)){
            if (strcmp(preferencia, "IPA"))     //Guarda la cantidad de preferencias entre los jovenes
            {
                ipa++;
            } else if (strcmp(preferencia, "APA")){
                apa++;
            } else if (strcmp(preferencia, "PORTER")){
                porter++;
            } else
                ninguna++;

            /* PUNTO D*/
            if (precio > max){      //Saca el maximo, minimo
                max = precio;
            } else if (precio < min){
                min = precio;
            }
            precioProm += precio;       //Suma los precios para sacar el promedio
            cantPrecio += 1;
        }

        printf("INGRESE TU EDAD: \n");      // Ingreso por teclado (para no quedar en bucle infinito)
        scanf("%d", &edad);
        printf("CUAL PREFERIS: \n IPA \n APA \n PORTER \n NINGUNA \n");
        scanf("%s", &preferencia);
        printf("INGRESE EL PRECIO QUE LE DARIAS A LA PINTA: \n");
        scanf("%f", &precio);
    }
    printf("Tamaño de la muestra: %d \n", cantPersonas);        //imprime en pantalla la cantidad de personas que respondieron la encuesta

    prom = edadesApa / (float)contEdad;     //Saca el promedio de personas que respondieron la encuesta y les gusta la APA
    printf("Edad promedio con preferencia APA: %.2f \n", prom);     //Imprime el promedio

    if (ipa > apa && ipa > porter && ipa > ninguna) {       //Imprime la cerveza que mas prefieren los jovenes
        printf("Cerveza de mayor preferencia por los jóvenes: IPA\n");
    } else if (apa > ipa && apa > porter && apa > ninguna) {
        printf("Cerveza de mayor preferencia por los jóvenes: APA\n");
    } else if (porter > ipa && porter > apa && porter > ninguna) {
        printf("Cerveza de mayor preferencia por los jóvenes: Porter\n");
    } else if(ninguna > ipa && ninguna > apa && ninguna > porter){
        printf("No hay preferencia por ninguna cerveza\n");
    } else if (ipa == apa && apa == porter && porter == ninguna){
        printf("Todas las cervezas se prefieren por igual\n");
    }

    if (cantPersonas != 0){     //Saca el promedio de precios
        prom = precioProm / cantPrecio;
    }
    printf("Precio Maximo: %.2f ", max);        //Imprime el precio maximo
    printf("Precio Minimo: %.2f ", min);        //Imprime el precio minimo
    printf("Precio Promedio: %.2f ", prom);     //Imprime el precio promedio
    return 0;
}
