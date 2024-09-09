#include <iostream>
#include <string>
using namespace std;

int main(){
    int numero_actual = 0;
    int suma_potencias = 0;
    int potencia_actual = 0;
    int resultado = 0;
    char seguir = 's';



    do {
        cout << "Ingrese un numero: ";
        cin >> numero_actual;
        cout << "\nIngrese a que potencia quiere elevar ese numero: ";
        cin >> potencia_actual;

        resultado = 1;
        for (int i=1; i<=potencia_actual; i++){
            resultado = resultado * numero_actual;            
        }

        cout << numero_actual << " elevado a " << potencia_actual << " es: " <<resultado;

        suma_potencias = suma_potencias + resultado;

        cout << "\nQuiere introducir otro numero?(y/n): ";
        cin >> seguir;
    } while (seguir != 'n' && seguir != 'N');

    cout << "La suma de todas las potencias fue: " << suma_potencias;





    return 0;
}