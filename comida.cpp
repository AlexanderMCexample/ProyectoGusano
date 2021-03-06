#include <iostream>
#include "comida.h"

using namespace std; 

//Métodos de nuestra clase "Comida"

void Comida::setSimbolo(char _simbolo) //Este Método nos sirve para llamar al simbolo de nuestra comida
{
    simbolo = _simbolo; 
}
void Comida::setPosX(int _x) //Método que establece la posición X de nuestra comida
{
    pos_comida.setx(_x);
}
void Comida::setPosY(int _y) //Método que establece la posición X de nuestra comida
{
    pos_comida.sety(_y);
}
void Comida::getPosX(int &_x) //Método que llama la posición X de nuestra comida (Usada por otras clases)
{
    pos_comida.getx(_x);
}
void Comida::getPosY(int &_y)  //Método que llama la posición X de nuestra comida (Usada por otras clases)
{
    pos_comida.gety(_y);
}
int Comida::getPosX() //Return de la posición X de la comida
{
    return pos_comida.getx(); 
}
int Comida::getPosY() //Return de la posición Y de la comida
{
    return pos_comida.gety();
}
void Comida::generar_aleatorio(int *listaVaciaX, int *listaVaciaY, int size) //Escoge una ubicación vacía random por las listasvacías pasadas como parámetro
{
	srand(time(0));
	setPosX(listaVaciaX[rand()%(size-1)]);
    setPosY(listaVaciaY[rand()%(size-1)]);
}
char Comida::getSimbolo() //Return del simbolo de nuestra comida
{
    return simbolo;
}

