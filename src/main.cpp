#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std; 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main(int argc, char *argv[])
{
  std::system("clear");            // Comando para borrar todo el contenido de la pantalla
  std::cout << "\x1B[H";         // Codigo para colocar el cursor en el canto superior izquierdo
  std::cout << "\x1B[3;34m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************/" << std::endl; 
	std::cout << "\x1B[m";             // Resetear color a valor por defecto
	std::cout << "\x1B[31;5;88mUniversidad Catolica San Pablo \x1B[m" << std::endl; 
	std::cout << "\x1B[33;5;88mEscuela Profesional de Ciencia de la Computacion I\x1B[m" << std::endl; 
	std::cout << "Curso de Ciencia de la Computacion I" << std::endl; 
	std::cout << "\x1B[38;5;46mIntegrantes: \x1B[m" << std::endl; 
	std::cout << "\x1B[38;5;46mNicolas Grupp\x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46mDaniela Perales\x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46mRodrigo Silva \x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46mAngeles Vasquez\x1B[m" << std::endl;
	std::cout << "Arequipa 2023 - I" << std::endl; 
	std::cout << "\x1B[3;34m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************/" << std::endl;	
	std::cout << "\x1B[m";             // Resetear color a valor por defecto 

  srand(time(NULL));
	int turno = 1, intentos = 1, max_intentos = 9, player = 1, num=10, winner=3, player_count = 0, state_game = 0, random = 0, n_plays = 0, sum_player1 = 0, sum_player2 = 0;
  char icon = 'x';
  
  
  cout<<"Bienvenido al tres en raya, a continuacion veras el siguiente tablero,\nsolo deberas escoger el numero de los numeros disponibles para poder marcar las casillas."<<"\n\n";

  int menu = 0;
  cout<<"Selecciona las opciones para empezar"<<"\n"; 
  cout<<"1) Empezar el juego"<<"\n";
  cout<<"2) Salir del juego."<<"\n";
  cout<<"Selecciona la opcion: ";cin>>menu;

  switch(menu){
    case 1:  
      system("clear");    
      cout<<"1) Jugar 1 vs 1\n";
      cout<<"2) Jugar contra la máquina. FACIL\n"; 
      cout<<"3) Jugar contra la máquina. MEDIUM\n"; 
      cout<<"4) Jugar contra la máquina. HARD\n"; 
      cout<<"Selecciona la opcion: ";cin>>state_game;

      for(turno; turno<=max_intentos; turno++) {  
        cout<<"\n\n*****El juego ha empezado !!!****"<<"\n\n";
        // system("clear");

        for(int i=1; i<=9; i++){  
          int exp = 9-i, potencia_ten;
          int last_digit;                    
          potencia_ten = pow(10,exp);
          last_digit = (player_count / potencia_ten) % 10;

          if(last_digit == 1){
              icon = 'x';
          }else if(last_digit == 2){
              icon = 'o';
          }
          
          if(i%3 != 0){                        
            if(last_digit == 0){
                cout<<i<<"|"; 
            }else{
              if(icon=='x'){
                cout<<GREEN<<icon<<RESET<<"|";  
              }else{
                cout<<RED<<icon<<RESET<<"|";  
              }
            }
          }else{                               
            if(last_digit == 0){
                cout<<i; 
            }else{
              if(icon=='x'){
                cout<<GREEN<<icon<<RESET;  
              }else{
                cout<<RED<<icon<<RESET;  
              }
            }                       
          }
          if(i == 3 || i == 6 ){
            cout<<"\n- - -"<<endl;
          }
        }
           
        if(turno%2 == 0){                    
            player = 2;
        }else{
            player = 1;
        }

        int digito1 =  (player_count / 100000000) % 10;
        int digito2 =  (player_count / 10000000) % 10;
        int digito3 =  (player_count / 1000000) % 10;
        int digito4 =  (player_count / 100000) % 10;
        int digito5 =  (player_count / 10000) % 10;
        int digito6 =  (player_count / 1000) % 10;
        int digito7 =  (player_count / 100) % 10;
        int digito8 =  (player_count / 10) % 10;
        int digito9 =  (player_count / 1) % 10;


        if(state_game == 1){
          cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;    
        } else if(state_game == 2){
          if(player == 1){
            cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;    
          }else if(player == 2){
            num=1 + rand() % 9;
          }
        } else if(state_game == 3){

        } else if(state_game == 4){
          if(player == 1){
            cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;    
            sum_player1 += num;
          }else if(player == 2){
            if(n_plays == 1){
              if(num != 5){
                num=5;
              }             

            }else if(n_plays > 1){
              if(n_plays == 3){
                if(sum_player1 % 2 == 0){
                  if(sum_player1 == 10){
                    if(digito6 == 1){
                      num = 8;
                    }else{
                      num = 6;
                    }
                  }else {
                    num = sum_player1 / 2;
                  }
                }else{

                }
              }

              if(n_plays == 5){                
                if(sum_player2 == 7 && digito8 == 0){
                  num= 8;
                }else if(sum_player2 == 9 && digito6 == 0){
                  num = 6;
                }
                else if(sum_player2 == 11 && digito4 == 0){
                  num = 4;
                }
                else if(sum_player2 == 13 && digito2 == 0){
                  num = 2;
                }
                
                if((digito1 == 1 && digito4 == 1 && digito9 == 1) || (digito1 == 1 && digito3 == 1 && digito8 == 1)){
                  num = 7;
                }else if(digito1 == 1 && digito6 == 1 && digito7 == 1){
                  num = 3;
                }else{
                  num = 1;
                }
                
                

              }
              
            }  
            sum_player2 += num;

          }
        }

        int exponente = 9-num, potencia_diez=0, last_d;
        if(num > 9 || num < 1){
          ++turno; 
          max_intentos += 2;
        }else{  
          potencia_diez = pow(10,exponente);
          potencia_diez = potencia_diez * player;           
  
          if(turno == 1){
            n_plays += 1;
            player_count += potencia_diez; 
          }else{
            int pow10 = pow(10,exponente);
            last_d = (player_count / pow10) % 10;
            
            if(last_d == 0){
              player_count += potencia_diez; 
              n_plays += 1;
            }else{
              ++turno; 
              max_intentos += 2;
            }
          }   


          int digito1 =  (player_count / 100000000) % 10;
          int digito2 =  (player_count / 10000000) % 10;
          int digito3 =  (player_count / 1000000) % 10;
          int digito4 =  (player_count / 100000) % 10;
          int digito5 =  (player_count / 10000) % 10;
          int digito6 =  (player_count / 1000) % 10;
          int digito7 =  (player_count / 100) % 10;
          int digito8 =  (player_count / 10) % 10;
          int digito9 =  (player_count / 1) % 10;
          
    
          if(digito1 == digito2 && digito1 == digito3 && digito1 != 0){
            winner = digito1;
            break;
          }
          if(digito4 == digito5 && digito4 == digito6 && digito4 != 0){
            winner = digito4;
            break;
          }
          if(digito7 == digito8 && digito7 == digito9 && digito7 != 0){
            winner = digito7;
            break;
          }
          if(digito1 == digito4 && digito1 == digito7 && digito1 != 0){
            winner = digito1;
            break;
          }
          if(digito2 == digito5 && digito2 == digito8 && digito2 != 0){
            winner = digito2;
            break;
          }
          if(digito3 == digito6 && digito3 == digito9 && digito3 != 0){
            winner = digito3;
            break;
          }
          if(digito1 == digito5 && digito1 == digito9 && digito1 != 0){
            winner = digito1;
            break;
          }
          if(digito3 == digito5 && digito3 == digito7 && digito3 != 0){
            winner = digito3;
            break;
          }
        }
      }
      if (winner==3 ){
        cout<<GREEN<<"\nGanador: Empate \n"<<RESET<<endl;
      }
      else {
        cout<<GREEN<<"\nGanador: Jugador "<<winner<<"\n"<<RESET<<endl;
      }



      break;
    case 2:
      return 0;
  }
}
