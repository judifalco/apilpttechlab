#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <array>
using namespace std;

int numeroAleatorio(int minimo,int maximo){
    srand(time(nullptr));  // semilla para generación de numeros random
    int numero = minimo + (rand() % (maximo - minimo + 1));
    
    return numero;
}



//Función para imprimir por pantalla un array
void recorridaArray(int array[], int tamanoArray){
    cout << "[ ";
    for(int i=0;i<tamanoArray;i++) {
        //Imprimimos cada uno de los elementos
        std::cout << array[i] << " ";
    }
    cout << "]";
}


//Funcion para evaluar si dentro de un array existe el numero buscado
//De estar el numero devuelve True
//De no estar el numero devuelve False
bool encontradoEnArray(int arrayUsuario[], int tamanoArray, int numeroUsuario){
    for (int i=0; i<tamanoArray;i++){
        //Si el array tiene 8 elementos recorrerá hasta el [7] (o sea array ompleto)
        if (arrayUsuario[i] == numeroUsuario ) {
            return true;
            //Se encontró el numero y se termina la funcion
            //devolviendo un 1 o True
        }           
    }
    return false;
    //Se recorrió todo el array sin encontrar el numero
    //Se devuelve 0 o False
}


int main(){
    setlocale(LC_ALL, ".utf-8"); //Para soportar caracteres especiales como acentos
    //Inicialización de variables
    int limite_inferior =0;
    int limite_superior = 0;
    int intentos_maximos = 0;
    int numero_usuario = 3;
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
    

    //Creamos un array del tamaño de los intentos maximos
    int array_usuario[intentos_maximos];
    int i = 0; //Inicializamos el contador

    while (i < intentos_maximos) { //Ya que i arranca en 0 elegimos que sea menor estricto del maximo de intentos
        
        cin >> numero_usuario; // Pedimos la primer entrada del numero


        while ((numero_usuario < limite_inferior) || (numero_usuario > limite_superior)) {

            cout << "Por favor ingresa un numero entre "<<limite_inferior << " y " << limite_superior;
            cout << "\nIngrese nuevamente un numero: ";
            cin >> numero_usuario;

        }

        while (encontradoEnArray(array_usuario, i, numero_usuario)){
        //Verificamos si el numero está en el array usando el intento actual - 1 como tamaño máximo
        //ya que estaremos verificando solo desde el primer turno hasta el anterior a este
        //De estar, la condición será 1(True) y el bucle seguira corriendo
        //En el momento que se ingrese un numero que no este la condición dará 0(False)
        //y se pasara al siguiente segmento del programa
            cout << "El numero ya ha sido ingresado anteriormente, por favor ingrese otro: ";
            cin >> numero_usuario;
        
        }

        array_usuario[i] = numero_usuario; //Añadimos al array el numero del usuario

        
        if (numero_usuario == numero_misterioso) { //Caso de que el usuario acierte

            cout << "Felicidades, el numero misterioso era: " << numero_misterioso;
            cout << "\nLo realizaste en " << i+1 << " intentos\n" << "Tus intentos fueron: ";
            recorridaArray(array_usuario,i+1);//se recorre el array hasta el ultimo intento

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
        
        switch (intentos_maximos-1-i){
            //Ponemos una condición para que en caso de ser el ultimo intento del usuario
            //no se muestre esta leyenda
            case 0:
                break;
            
            default:
                cout << "\nPor favor intentalo nuevamente: ";
                break; 
        }
        i++; //aumento del contador en 1
    }

    cout << "\nParece que te quedaste sin intentos! Mejor suerte la proxima\nEl numero era: "<< numero_misterioso << "\n";
    cout << "Tus intentos fueron: ";
    recorridaArray(array_usuario,intentos_maximos);//recorremos con los intentos maximos ya que los agotamos

    return 0;
}
