//Clase Obstaculo
//Esta clase se encarga de los obstaculos que los gusanos deben evitar. Tanto los bordes del tablero, cómo los que se generan tras el choque de dos gusanos.
//Métodos creados: 
//getSimbolo; getPosY; getPosX; setPosY; setPosX; setSimbolo

class Obstaculo {
    //Atributos
    public:
    Posicion pos;    //Llamamos nuestra clase Posicion
    char simbolo;

    //Constructor
    Obstaculo(int x =0, int y=0,  char simbolo = '#'){   //El constructor nos da valores iniciales para todos nuestro atributos
        pos = Posicion(x,y);       
        this -> simbolo = simbolo;
    }

    //Destructor de nuestra clase
    ~Obstaculo(){
    }
    
    //Métodos
    void setSimbolo(char _simbolo);
    void setPosX(int _x);
    void setPosY(int _y);
    
    void getPosX(int &_x);
    void getPosY(int &_y);
    int getPosX();
    int getPosY();
    void getSimbolo(char &_simbolo);
    char getSimbolo();
    
};
