#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std; 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

void displayCover( string, string, string, string, string, string );
bool verifyPair( int, int&, int, int, int, int, int, int, int, int, int );
int lastDigit( int, int& );
void showBoard( char&, int& );
int verifyWinner( int&, int, int, int, int, int, int, int, int, int ); 
void setDigits( int, int&, int&, int&, int&, int&, int&, int&, int&, int& );
void displayWinner( int );
void fillEmptyBox( int, int& );

int main(int argc, char *argv[])
{
	int turno = 1, intentos = 1, max_intentos = 9, player = 1, num=10, winner=3, player_count = 0, state_game = 0, random = 0, n_plays = 0, sum_player1 = 0, sum_player2 = 0;
	int digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9; 
	int menu = 0;
	bool star_in_mid = false;
  	char icon = 'x';

	displayCover("Universidad San Pablo", "Ciencias de la computación", "Nicolas Grupp", "Daniela Perales", "Rodrigo Silva", "María Vásquez");
  	srand(time(NULL));  
  	cout<<"Bienvenido al tres en raya, a continuacion veras el siguiente tablero,\nsolo deberas escoger el numero de los numeros disponibles para poder marcar las casillas."<<"\n\n";
	cout<<"Selecciona las opciones para empezar"<<"\n"; 
	cout<<"1) Empezar el juego"<<"\n";
	cout<<"2) Salir del juego."<<"\n";
	cout<<"Selecciona la opcion: ";cin>>menu;

	switch( menu ) {
		case 1:  
			system("clear");    
			cout<<"1) Jugar 1 vs 1\n";
			cout<<"2) Jugar contra la máquina. FACIL\n"; 
			cout<<"3) Jugar contra la máquina. MEDIUM\n"; 
			cout<<"4) Jugar contra la máquina. HARD\n"; 
			cout<<"Selecciona la opcion: ";cin>>state_game;

			for( turno; turno <= max_intentos; turno++ ) {  
				cout<<"\n\n*****El juego ha empezado !!!****"<<"\n\n";
				system("clear");
				showBoard(icon, player_count);

				if ( turno%2 == 0 ) player = 2;
				else player = 1;

				if( state_game == 1 ) {
					cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;
				} else if ( state_game == 2 ) {
					if ( player == 1 ) {
						cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;
					} 
					else if ( player == 2 ) num = 1 + rand() % 9;
				} else if( state_game == 3 ) {				
					if ( player == 1 ) {					
						cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;    
						sum_player1 += num;
					} else if ( player == 2 ) {
						if ( n_plays == 1 ) {
							if( num != 5 ) num = 5;
							else if ( num == 5 ) {
								num = 9;
								star_in_mid = true;
							}
						} else if ( n_plays > 1 ) {
							if( n_plays == 3 ) {
								if( sum_player1 % 2 == 0 ) {
									if( sum_player1 == 10 ) {
										if( (digito1 == 1 && digito9 == 1) || (digito3 == 1 && digito7 == 1 ) ) num = 8;
										else num = 9;
									} else{
										if( digito1 == 0 && digito3 == 0 && digito7 == 0 && digito9 == 0 ) num = sum_player1 - 5;
										else num = sum_player1 / 2;                  
									}
									if( digito5 == 1 ) {
										if( digito3 == 1 ) num = 7;
										else if( digito7 == 1 ) num = 3;
										else if( digito1 == 1 ) num = 7;
									}	  	
								} else {
									int hasPair1 = false;									
									hasPair1 = verifyPair(1, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);
									if(!hasPair1){
										if( digito1 == 1 && digito6 == 1 ) num = 3
										else if ( digito1 == 1 && digito8 == 1 ) num = 7;
										else if ( digito3 == 1 && digito8 == 1 ) num = 9;
										else if ( digito3 == 1 && digito4 == 1 ) num = 1;
										else if ( digito9 == 1 && digito2 == 1 ) num = 3;
										else if ( digito9 == 1 && digito4 == 1 ) num = 7;
										else if ( digito7 == 1 && digito2 == 1 ) num = 1;
										else if ( digito7 == 1 && digito4 == 1 ) num = 9;
									}
								}	
							}
							if( n_plays == 5 ) {
								bool hasPair1 = false, hasPair2 = false;
								hasPair1 = verifyPair(1, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);
								if (!hasPair1) hasPair2 = verifyPair(2, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);	
								if ( !hasPair1 && !hasPair2 ) fillEmptyBox(player_count, num);
							}   
							if(n_plays == 7){ 
								bool hasPair1 = false, hasPair2 = false;
								hasPair1 = verifyPair(1, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);
								if(!hasPair1) hasPair2 = verifyPair(2, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);	
								if( !hasPair1 && !hasPair2 ) fillEmptyBox(player_count, num);
							}           
						}  
						sum_player2 += num;
					} 		
				} else if(state_game == 4){
					if( player == 1 ) {
						num = 1;
						if( n_plays == 2 ) {
							if( digito5 == 2 ) {
								num = 8;
							} else if( digito2 == 2 || digito3 == 2 || digito8 == 2 || digito9 == 2 ) {
								num = 7;
							} else if( digito4 == 2 || digito7 == 2 || digito6 == 2 ) {
								num = 3;
							}						
						} else if( n_plays == 4 ) {
							bool hasPair1 = false, hasPair2 = false;
							hasPair1 = verifyPair(1, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);
							if(!hasPair1) hasPair2 = verifyPair(2, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);
							if( !hasPair2 && !hasPair1 ) {
								if ( digito5 == 2 ) {
									if ( digito3 == 2 || digito9 == 2 ) num = 7;
									else if ( digito2 == 2 ) num = 7;
								} else if ( digito5 == 0 ) {
									if( digito3 == 2 || digito7 == 2 ) num = 9;
									else if( digito9 == 2 ) num = 3;
									else num = 5;
								}
							}	
						} else if(n_plays == 6){
							bool hasPair1 = false, hasPair2 = false; 
							hasPair1 = verifyPair(1, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);
							if (!hasPair1) hasPair2 = verifyPair(2, num, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9);					
							if( !hasPair1 && !hasPair2 ) fillEmptyBox(player_count, num);		
						} else if(n_plays == 8){
							fillEmptyBox(player_count, num);
						}					
					} else {
						cout<<"\n\nEs el turno del jugador: "<<player<<"\n\n"; cout<<"Selecciona el numero de las casillas disponibles: ";cin>>num;    
						sum_player2 += num;
					}
				}

				int exponente = 9-num, potencia_diez=0, last_d;
				if( num > 9 || num < 1 ) {
					++turno; 
					max_intentos += 2;
				} else {  
					potencia_diez = pow(10,exponente);
					potencia_diez = potencia_diez * player;           
		
					if( turno == 1 ) {
						n_plays += 1;
						player_count += potencia_diez; 
					} else {
						int pow10 = pow(10,exponente);
						last_d = (player_count / pow10) % 10;
						
						if( last_d == 0 ) {
							player_count += potencia_diez; 
							n_plays += 1;	
						} else {
							++turno; 
							max_intentos += 2;
						}
					}  
				}
				setDigits(player_count, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9 );			
				int player_win = verifyWinner(winner, digito1, digito2, digito3, digito4, digito5, digito6, digito7, digito8, digito9 );
				
				if(player_win == 1 || player_win == 2) break;
			}			
						
			displayWinner(winner);
			showBoard(icon, player_count);				
			break;
		case 2:
			break;
		return 0;
	}
}
void displayWinner ( int winner ) {
	if ( winner == 3 ) cout<<YELLOW<<"\n\nGanador: Empate \n"<<RESET<<endl; 
	else {
		if( winner == 1 ) cout<<GREEN<<"\n\nGanador: Jugador "<<winner<<"\n"<<RESET<<endl;			
		else if( winner == 2 ) cout<<RED<<"\n\nGanador: Jugador "<<winner<<"\n"<<RESET<<endl;
	}
	return;
}
void setDigits(int player_count, int &digito1, int &digito2, int &digito3, int &digito4, int &digito5, int &digito6, int &digito7, int &digito8, int &digito9) {
	digito1 =  (player_count / 100000000) % 10;
	digito2 =  (player_count / 10000000) % 10;
	digito3 =  (player_count / 1000000) % 10;
	digito4 =  (player_count / 100000) % 10;
	digito5 =  (player_count / 10000) % 10;
	digito6 =  (player_count / 1000) % 10;
	digito7 =  (player_count / 100) % 10;
	digito8 =  (player_count / 10) % 10;
	digito9 =  (player_count / 1) % 10;
}
void displayCover(string uni, string course, string name1, string name2, string name3, string name4) {
	std::system("clear");            // Comando para borrar todo el contenido de la pantalla
	std::cout << "\x1B[H";         // Codigo para colocar el cursor en el canto superior izquierdo
	std::cout << "\x1B[3;34m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************/" << std::endl; 
	std::cout << "\x1B[m";             // Resetear color a valor por defecto
	std::cout << "\x1B[31;5;88m"<<uni<<"\x1B[m" << std::endl; 
	std::cout << "\x1B[33;5;88m"<<course<<"\x1B[m" << std::endl; 
	std::cout << "\x1B[38;5;46mIntegrantes: \x1B[m" << std::endl; 
	std::cout << "\x1B[38;5;46m"<<name1<<"\x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46m"<<name2<<"\x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46m"<<name3<<"\x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46m"<<name4<<"\x1B[m" << std::endl;
	std::cout << "Arequipa 2023 - I" << std::endl; 
	std::cout << "\x1B[3;34m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************/" << std::endl;	
	std::cout << "\x1B[m";             // Resetear color a valor por defecto 	
}
int lastDigit( int n, int &player_count ){
	int exp = 9-n, potencia_ten, last_digit;
	potencia_ten = pow( 10, exp );
	last_digit   = ( player_count / potencia_ten ) % 10;
	return last_digit;
}
void showBoard( char &icon, int &p_count ) {
	for( int i = 1; i <= 9; i++ ) { 
		if ( lastDigit(i, p_count) == 1 ) icon = 'x';
		else if ( lastDigit(i, p_count) == 2 ) icon = 'o';
		if( i % 3 != 0 ) {                        
			if ( lastDigit(i, p_count) == 0 ) cout<<i<<"|"; 
			else icon == 'x' ? cout<<GREEN<<icon<<RESET<<"|" : cout<<RED<<icon<<RESET<<"|"; 
		}else {                               
			if ( lastDigit(i, p_count) == 0 ) cout<<i; 
			else icon=='x' ? cout<<GREEN<<icon<<RESET : cout<<RED<<icon<<RESET;                         
		}
		if ( i == 3 || i == 6 ) cout<<"\n- - -"<<endl;
	}
}
bool verifyPair( int player, int &num, int digito1, int digito2, int digito3, int digito4, int digito5, int digito6, int digito7, int digito8, int digito9 ) {
	bool hasPair = false; 						
	if( digito1 == player && digito2 == player && digito3 == 0 ) {
		num = 3; hasPair = true;
	} else if( digito1 == player && digito2 == 0 && digito3 == player ) {
		num = 2; hasPair = true;
	} else if( digito1 == 0 && digito2 == player && digito3 == player ) {
		num = 1; hasPair = true;
	} else if( digito4 == player && digito5 == player && digito6 == 0 ) {
		num = 6; hasPair = true;
	} else if( digito4 == player && digito5 == 0 && digito6 == player ) {
		num = 5; hasPair = true;
	} else if( digito4 == 0 && digito5 == player && digito6 == player ) {
		num = 4; hasPair = true;
	} else if( digito7 == 0 && digito8 == player && digito9 == player ) {
		num = 7; hasPair = true;
	} else if( digito7 == player && digito8 == 0 && digito9 == player ) {
		num = 8; hasPair = true;
	} else if( digito7 == player && digito8 == player && digito9 == 0 ) {
		num = 9; hasPair = true;
	} else if( digito1 == 0 && digito4 == player && digito7 == player ) {
		num = 7; hasPair = true;
	} else if( digito1 == player && digito4 == 0 && digito7 == player ) {
		num = 4; hasPair = true;
	} else if( digito1 == player && digito4 == player && digito7 == 0 ) {
		num = 7; hasPair = true;
	} else if( digito2 == player && digito5 == player && digito8 == 0 ) {
		num = 8; hasPair = true;
	} else if( digito2 == player && digito5 == 0 && digito8 == player ) {
		num = 5; hasPair = true;
	} else if( digito2 == 0 && digito5 == player && digito8 == player ) {
		num = 2; hasPair = true;
	} else if( digito3 == 0 && digito6 == player && digito9 == player ) {
		num = 3; hasPair = true;
	} else if( digito3 == player && digito6 == 0 && digito9 == player ) {
		num = 6; hasPair = true;
	} else if( digito3 == player && digito6 == player && digito9 == 0 ) {
		num = 9; hasPair = true;
	} else if( digito1 == player && digito5 == player && digito9 == 0 ) {
		num = 9; hasPair = true;
	} else if( digito1 == player && digito5 == 0 && digito9 == player ) {
		num = 5; hasPair = true;
	} else if( digito1 == 0 && digito5 == player && digito9 == player ) {
		num = 1; hasPair = true;
	} else if( digito3 == 0 && digito5 == player && digito7 == player ) {
		num = 3; hasPair = true;
	} else if( digito3 == player && digito5 == 0 && digito7 == player ) {
		num = 5; hasPair = true;
	} else if( digito3 == player && digito5 == player && digito7 == 0 ) {
		num = 7; hasPair = true;
	}	
	return hasPair;
}
int verifyWinner( int &winner, int digito1, int digito2, int digito3, int digito4, int digito5, int digito6, int digito7, int digito8, int digito9 ) {
	if( digito1 == digito2 && digito1 == digito3 && digito1 != 0 ) winner = digito1; 
	if( digito4 == digito5 && digito4 == digito6 && digito4 != 0 ) winner = digito4; 
	if( digito7 == digito8 && digito7 == digito9 && digito7 != 0 ) winner = digito7; 
	if( digito1 == digito4 && digito1 == digito7 && digito1 != 0 ) winner = digito1; 
	if( digito2 == digito5 && digito2 == digito8 && digito2 != 0 ) winner = digito2; 
	if( digito3 == digito6 && digito3 == digito9 && digito3 != 0 ) winner = digito3; 
	if( digito1 == digito5 && digito1 == digito9 && digito1 != 0 ) winner = digito1; 
	if( digito3 == digito5 && digito3 == digito7 && digito3 != 0 ) winner = digito3; 		
	return winner;
}
void fillEmptyBox( int player_count, int &num ) {
	for ( int i = 1; i <= 9; i++ ) {
		int potencia = pow( 10, 9-i );
		int digit = ( player_count / potencia ) % 10;
		if( digit == 0 ){
			num = i;
			break;
		}
	}  	
}