#include <iostream>
#include <math.h> //para formulas matemáticas
#include <conio.h> //gets()
#include <cstring> //strcpy strcmp
#include <string> //string 
//clases
#include "controles.cpp"
#include "posicion.cpp"
#include "obstaculo.cpp"
#include "comida.cpp"
#include "poder.cpp"
#include "tablero.cpp"

//Este archivos contiene funciones que llamaremos en nuestro main para ejecutar nuestro juego.
//Las funciones llaman a todas las clases necesarias.
//Optamos por crear este tipo  de archivos para tener un mejor manejo de todas nuestras clases y mejor organización en nuestro archivo main

using namespace std;

void variables_rango(int &n, int mayor, int menor) //Funcion con la cual el jugador podra determinar el tamaño del tablero en el cual desea jugar. Dentro de un rango anteriormente establecido.
{
  cout << "\n  Ingrerse el valor entre " << menor  << " y "<< mayor<<": ";
  cin >> n;
  while(true) //verifica si el ingreso de la variable es correcto
  {
    if (n<menor) 
    {
      cout << "  ingrese un valor mayor igual a " << menor<< ": ";
      cin >> n;
    }
    else if (n>mayor) 
    { 
      cout << "  ingrese un valor menor igual a " << mayor<< ": ";
      cin >> n;
    }
    else 
    {
      break;
    }    
  }
  return;
}

void tablero() //Función que, despues de establecer el tamaño del tablero, llama a todas las clases necesarias y comienza el juego.
{
    bool game = true,menu = true;
    while(menu)
    {
        int size=0;
        int tecla=0;
        game = true;
        cout << "Ingrece el tamaño de su tablero: ";
        variables_rango(size,50,10);

        Tablero *tabla;
        tabla = new Tablero(size); 
        tabla->generarMuros();
        tabla->setControlGusanoDos();
        tabla->setControlGusanoUno();
        
        while(game)
        {
          tabla->movimientoGusano(); //Actualiza los movimientos del gusano
          tabla->imprimirRegistro();
          tabla->imprimirMatriz();
          
          for (double time = 0; time < 600-tabla->poder.getVelocidadJuego();time+=0.05)  //tiempo para imprimir y capturar la tecla
          {
              tabla->mandoGusanoUno();
              tabla->mandoGusanoDos();

              if (_kbhit()) //capturar las teclas para el menu
              {       
                  tecla = _getch();
                  if (tecla == 113 || tecla == 81) //si se presiona la letra q o Q
                  {
                      game = false;
                  }
              }
          }
          cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          
          if (game)
          {
              tabla->buscarObstaculo();
              tabla->lugaresVacios();              
              tabla->perderJuego(game);        
          }
        }
        
        // texto del menu 
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "----Desea continuar-----" << "\n";
        cout << "Presione: \n" << "   [space] ==> si desea salir\n" << "   [e]     ==> si desea reiniciar\n";
        while(true)
        {
            tecla = _getch();
            if (tecla == 32) // salir del juego
            {   
                delete tabla;
                menu = false;
                game = false;
                break;
            }
            else if (tecla == 101 || tecla == 69) //reiniciar el juego
            {
                delete tabla;
                game = false;
                tecla = 0;
                break;
            }
        }
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }


}
