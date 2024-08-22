#include <iostream>
#include <cstdlib>
#include <locale.h>
using namespace std;

int numeroAleatorio(int minimo,int maximo){
    srand(time(nullptr));  // semilla para generación de numeros random
    int numero = minimo + (rand() % (maximo - minimo + 1));
    
    return numero;
}


int main(){
    setlocale(LC_ALL, ""); //Para soportar caracteres especiales como acentos
    //Inicialización de variables
    int limite_inferior =0;
    int limite_superior = 0;
    int intentos_maximos = 0;
    int numero_usuario = 0;
    int numero_misterioso = 0;
    
    //Comienzo del programa
    cout << "Hola! Antes comenzar ingresa primero el limite inferior de la adivinanza: ";
    cin >> limite_inferior; //Ingreso por terminal del usuario
    cout << "Ahora ingresa el limite superior: ";
    cin >> limite_superior;
    
    //Validar que el limite superior sea mas grande que el inferior
    while (limite_inferior >= limite_superior) {

        cout << "El limite superior debe ser mayor al inferior, ingrese los datos nuevamente.";
        cout << "\nIngrese límite inferior: ";
        cin >> limite_inferior;
        cout << "\nIngrese límite superior: ";
        cin >> limite_superior;        
    } 

    cout << "Por ultimo te solicito la cantidad de intentos maximos ";
    cin >> intentos_maximos;

    //Validar que la cantidad de intentos maximos sea mayor o igual a 1
    while (intentos_maximos < 1) {
        cout << "La cantidad de intentos debe ser de al menos 1.\n";
        cout << "Ingrese nuevamente la cantidad de intentos máximos: ";
        cin >> intentos_maximos;
    }

    cout << "Generando numero misterioso";
    numero_misterioso = numeroAleatorio(limite_inferior,limite_superior); // se genera el numero misterioso con la funcion de numero aleatorio
    cout << "\nAhora si! "<< "Tenés "<< intentos_maximos << " intentos\n" << "Ingresá un numero y vamos a ver si es el numero misterioso: ";
    cin >> numero_usuario; // Pedimos la primer entrada del numero

    int i = 0; //Inicializamos el contador
    while (i < intentos_maximos - 1) { //Ya que i arranca en 0 elegimos que sea menor estricto del maximo de intentos. ya que el primer intento ya lo pedimos le restamos uno al maximo
        
        while ((numero_usuario < limite_inferior) || (numero_usuario > limite_superior)) {

            cout << "Por favor ingresa un numero entre "<<limite_inferior << " y " << limite_superior;
            cout << "\nIngrese nuevamente un numero: ";
            cin >> numero_usuario;

        }
         
        if (numero_usuario == numero_misterioso) { //Caso de que el usuario acierte

            cout << "Felicidades, el numero misterioso era: " << numero_misterioso;
            cout << "\nLo realizaste en " << i+1 << " intentos";

            return 0; //Se da retorno y se termina el programa
        }
        else if (numero_usuario>numero_misterioso) { //Caso de que el numero ingresado es mayor al objetivo
            cout << "El numero es menor al ingresado.";            
        }
        else { //Caso de que el numero ingresado es menor al objetivo
            cout << "El numero es mayor al ingresado.";            
        }
        
        //Muestra de informacion sobre los intentos al usuario
        cout << "\nEse fue tu intento numero " << i+1;
        cout << "\nQuedan " << intentos_maximos-1-i << " intentos.";
        cout << "\nPor favor intentalo nuevamente: "; 
        
        cin >> numero_usuario; // Pedimos la entrada del numero siguiente  
        i++; //aumento del contador en 1
    }

    cout << "Parece que te quedaste sin intentos! Mejor suerte la proxima\nEl numero era: "<< numero_misterioso << "\n";

    return 0;
}