/*
------------------------------------------------------------------------
Nombres: Jesus David
Apellido: Machado Castillo
Cedula: 28553080
Programacion I
Proyecto III
Solucionador de Sudoku Samurai
Lenguaje C++
------------------------------------------------------------------------
                                  _______
                           _,,ad8888888888bba,_
                        ,ad88888I888888888888888ba,
                      ,88888888I88888888888888888888a,
                    ,d888888888I8888888888888888888888b,
                   d88888PP"""" ""YY88888888888888888888b,
                 ,d88"'__,,--------,,,,.;ZZZY8888888888888,
                ,8IIl'"                ;;l"ZZZIII8888888888,
               ,I88l;'                  ;lZZZZZ888III8888888,
             ,II88Zl;.                  ;llZZZZZ888888I888888,
            ,II888Zl;.                .;;;;;lllZZZ888888I8888b
           ,II8888Z;;                 `;;;;;''llZZ8888888I8888,
           II88888Z;'                        .;lZZZ8888888I888b
           II88888Z; _,aaa,      .,aaaaa,__.l;llZZZ88888888I888
           II88888IZZZZZZZZZ,  .ZZZZZZZZZZZZZZ;llZZ88888888I888,
           II88888IZZ<'(@@>Z|  |ZZZ<'(@@>ZZZZ;;llZZ888888888I88I
          ,II88888;   `""" ;|  |ZZ; `"""     ;;llZ8888888888I888
          II888888l            `;;          .;llZZ8888888888I888,
         ,II888888Z;           ;;;        .;;llZZZ8888888888I888I
         III888888Zl;    ..,   `;;       ,;;lllZZZ88888888888I888
         II88888888Z;;...;(_    _)      ,;;;llZZZZ88888888888I888,
         II88888888Zl;;;;;' `--'Z;.   .,;;;;llZZZZ88888888888I888b
         ]I888888888Z;;;;'   ";llllll;..;;;lllZZZZ88888888888I8888,
         II888888888Zl.;;"Y88bd888P";;,..;lllZZZZZ88888888888I8888I
         II8888888888Zl;.; `"PPP";;;,..;lllZZZZZZZ88888888888I88888
         II888888888888Zl;;. `;;;l;;;;lllZZZZZZZZW88888888888I88888
         `II8888888888888Zl;.    ,;;lllZZZZZZZZWMZ88888888888I88888
          II8888888888888888ZbaalllZZZZZZZZZWWMZZZ8888888888I888888,
          `II88888888888888888b"WWZZZZZWWWMMZZZZZZI888888888I888888b
           `II88888888888888888;ZZMMMMMMZZZZZZZZllI888888888I8888888
            `II8888888888888888 `;lZZZZZZZZZZZlllll888888888I8888888,
             II8888888888888888, `;lllZZZZllllll;;.Y88888888I8888888b,
            ,II8888888888888888b   .;;lllllll;;;.;..88888888I88888888b,
            II888888888888888PZI;.  .`;;;.;;;..; ...88888888I8888888888,
            II888888888888PZ;;';;.   ;. .;.  .;. .. Y8888888I88888888888b,
           ,II888888888PZ;;'                        `8888888I8888888888888b,
           II888888888'                              888888I8888888888888888b
          ,II888888888                              ,888888I88888888888888888
         ,d88888888888                              d888888I8888888888ZZZZZZZ
      ,ad888888888888I                              8888888I8888ZZZZZZZZZZZZZ
    ,d888888888888888'                              888888IZZZZZZZZZZZZZZZZZZ
  ,d888888888888P'8P'                               Y888ZZZZZZZZZZZZZZZZZZZZZ
 ,8888888888888,  "                                 ,ZZZZZZZZZZZZZZZZZZZZZZZZ
d888888888888888,                                ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZ
888888888888888888a,      _                    ,ZZZZZZZZZZZZZZZZZZZZ888888888
888888888888888888888ba,_d'                  ,ZZZZZZZZZZZZZZZZZ88888888888888
8888888888888888888888888888bbbaaa,,,______,ZZZZZZZZZZZZZZZ888888888888888888
88888888888888888888888888888888888888888ZZZZZZZZZZZZZZZ888888888888888888888
8888888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888
888888888888888888888888888888888888888ZZZZZZZZZZZZZZ888888888888888888888888
8888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888
88888888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888
8888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888
88888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888888
8888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888888
*/
#include <iostream>
#include <fstream>
using namespace std;
 
/*Definimos UNASSIGNED como 0 para marcar los espacios vacios en la matriz y 
SAMURAI como 21 la cual sera el tamaño de nuestra matriz*/
#define UNASSIGNED 0
#define SAMURAI 21


/*La funcion FindEmptyBox busca las casillas vacias del sudoku
-Ella recorre todas las casillas, busca las que tienen el valor UNASSIGNED (Definida como 0)
-Devuelve verdadero si encuetra alguna
-Devuelve la posicion de la casilla vacia mediante los variables pasadas por referencia "row" y "col"
-El recorrido comienza en initrow e initcol y termina en endrow y endcol para ir resolviendo por partes 
*/
bool FindEmptyBox(int Sudoku[SAMURAI][SAMURAI],int& row, int& col, int initrow, int endrow, int initcol, int endcol)
{
    for (row = initrow; row < endrow; row++){
    	for (col = initcol; col < endcol; col++){
    		if (Sudoku[row][col] == UNASSIGNED){
    			return true;
			}
		}
	}
    return false;
}
/*Funcion de printSudoku recorre la matriz y revisa los espacios en -1 en donde imprimirá dos espacios vacios
y el resto de espacios imprimirá el valor que ahí se encuentre*/
void printSudoku(int Sudoku[SAMURAI][SAMURAI])
{
    for (int row = 0; row < SAMURAI; row++)
    {
        for (int col = 0; col < SAMURAI; col++){
        	if(Sudoku[row][col]==-1){
        		cout<<"  ";
			}else{
				cout << Sudoku[row][col] << " ";
			}
		}
            
        cout << endl;
    }
    cout<<endl;
}
/*
Las funciones return_to() y return_from() acotan las verificaciones dependiendo 
de la posicion del elemento que el solucionador este colocando
-Divide la matriz en recuadros y dependiendo de en donde se posicione el elemento
devolvera la posicion maxima o la minima en donde verificaremos*/

int return_to(int i, int j){
	
	if( (j >=0 && j <= 5) || (j >= 15 && j <= 20) ){ //Aqui verificamos si esta en alguna esquina,
	    if(i <= 8){             //Si esta en la parte superior del sudoku devolveremos 8 como maximo
	    	return 8;
		}else{
			return 20;          //Si no quiere decir que estamos en los sudokus inferiores y devolveremos 20 como cota maxima
		}
	}else{
		if( (j >= 6 && j <= 8) || (j >= 12 && j <= 14) ){//Aqui verificamos si el elemento se encuentra en el sudoku central
			if(i <= 5){                  //Si esta muy por encima del sudoku central retornaremos 8 como maximo para las verificaciones
				return 8;
			}else{
				if(i >= 12){
					return 20;                 //aqui verificamos que tan bajo esta el elemento, si está en los sudokus inferiores devolveremos 20 como maximo
				}else{                         //si no, devolveremos 14
					return 14;                  
				}
			}
		}else{
			return 14;                       //si no entramos en ninguna quiere decir que estamos en el centro del sudoku central y devolveremos 14 como cota maxima
		}
	}
}
/*             _____
              /     \
              vvvvvvv  /|__/|
                 I   /O,O   |
                 I /_____   |      /|/|
                J|/^ ^ ^ \  |    /00  |    _//|
                 |^ ^ ^ ^ |W|   |/^^\ |   /oo |
                  \m___m__|_|    \m_m_|   \mm_|
*/
int return_from(int i, int j){
	
	if( (j >= 0 && j <= 5) || (j >=15 && j <= 20) ){     //Aqui verificamos si esta en alguna esquina,
		if(i <= 8){                      //Si esta en la parte superior del sudoku devolveremos 0 como cota inferior
			return 0;
		}else{
			return 12;                  //por el contrario quiere decir que estamos en los sudokus inferiores y devolveremos 12 como minimo
		}	
	}else{
		if( (j >= 6 && j <= 8) || (j >= 12 && j <= 14) ){//Aqui verificamos si el elemento se encuentra en el sudoku central
			if(i <= 8){                                 //Si esta muy por encima del sudoku central retornaremos 0 como inicio para las verificaciones
				return 0;
			}else{
				if(i >= 15){
					return 12;                          //aqui verificamos que tan bajo esta el elemento, si está en los sudokus inferiores devolveremos 12 como minimo
				}else{
					return 6;                          //si no, devolveremos 6
				}
			}
		}else{
			return 6;                                 //si no entramos en ninguna quiere decir que estamos en el centro del sudoku central y devolveremos 6 como cota minima
		}
	}
}
/*
La funcion isValid() retorna verdadero si el elemento no se encuentra en la misma fila o columna o cuadro que un elemento similar
-Primero acotara las verificaciones
-despues revisara filas y columnas
-de ultimo revisará el cuadro 
*/
bool isValid( int Sudoku[ SAMURAI ][ SAMURAI ], int row, int col, int num){
	int a, b, x, y;
	a = return_from(row,col);       //Buscamos la cota inferior
	b = return_to(row,col);         //Buscamos la cota superior
	for( a; a <= b; a++){
		if(a != row && Sudoku[ a ][ col ] == num){      //Comprobamos
			return false;                               //Si encontramos un elemento similar retornamos falso
		}
	}
	a = return_from(col,row);              //Acotamos inferiormente
	b = return_to(col,row);                //Acotamos superiormente
	for(a; a <= b; a++){
		if(a != col && Sudoku[ row ][ a ] == num){//Comprobamos
			return false;                         //Si encontramos un elemento igual retornamos falso
		}
	}
	y = ( row / 3 ) * 3;
	x = ( col / 3 ) * 3;               //Acotamos
	for(a = 0; a < 3; a++){
		for(b = 0; b < 3; b++){
			if(a != row && b != col && Sudoku[ y + a ][ x + b ] == num){   //Comprobamos
				return false;                                              //Retornamos falso si encontramos un elemento igual
			}
		}
	}
	return true;                    //Retornamos verdadero si no encontramos nada igual
}

/*La funcion SudokuSolution ser{a la encargada de llamar a las funciones que buscan y
comprueban elementos y se encargará de buscar la solucion o regresar
si no encontró solución y retornar falso
*/
bool SudokuSolution(int Sudoku[SAMURAI][SAMURAI])
{
    int row, col;
 
    if (!FindEmptyBox(Sudoku, row, col,12,21,0,9)){                  //Buscamos los espacios vacios ordenadamente 
    	if(!FindEmptyBox(Sudoku, row, col,0,9,0,9)){                 //separando los sudokus en 5  
    		if(!FindEmptyBox(Sudoku, row, col,0,9,12,21)){           //si al final no encuentra ningun espacio vacio
    			if(!FindEmptyBox(Sudoku, row, col,12,21,12,21)){     //en todos los recuadros completos
    				if(!FindEmptyBox(Sudoku, row, col,6,15,6,15)){   //devolveremos verdadero
    					return true;
					}
				}
    			
			}
		}
    
	}
    
    for (int num = 1; num <= 9; num++)         //Despues de buscar los espacios vacios
    {                                          //Usaremos el ciclo for para probar los numeros del 1 al 9
                                          
       
        if (isValid(Sudoku, row, col, num))   //si es valido colocaremos el numero y volveremos a llamar a la funcion
        {
             
            
            Sudoku[row][col] = num;
 
            
            if (SudokuSolution(Sudoku))      //si al final una llamada recursiva devuelve verdadero (La que no encuentra ningun espacio vacion alla arriba)
                return true;                 //retornaremos verdadero y todas las demas llamadas devolveran verdadero hasta salir de la funcion
 
           
            Sudoku[row][col] = UNASSIGNED;      //si no encontramos solucion por este camino marcaremos el elemento como vacio y probaremos el siguiente
        }
    }
    

    return false;     //Si no llegó al numero nueve y no encontro solucion retornara y volvera a buscar otra solucion hasta agotarlas
}
 
/*La funcion leer sudoku nos leerá el archivo y estructurará la matriz
-solo lee los elementos y los coloca ordenadamente por dos ciclos for
-si el archivo falla retornará falso
-si todo sale bien cerrará el archivo y retornará verdadero
*/

bool readsudoku(int Sudoku[SAMURAI][SAMURAI]){
	ifstream archivo("sudoku.txt");
	if(archivo.fail()){
		cout<<"El archivo no se encuentra o esta defectuoso"<<endl;
		return false;
	}else{
		for(int j=0; j<SAMURAI; j++){
			for(int k=0; k<SAMURAI; k++){
				archivo>>Sudoku[j][k];
			}
		}
	}
	archivo.close();
	return true;
}
/*Funcion principal*/
int main()
{
    int Sudoku[SAMURAI][SAMURAI];
	if(readsudoku(Sudoku)){
		cout<<"Sudoku Original: "<<endl;
		printSudoku(Sudoku);
		if(SudokuSolution(Sudoku)==true){
			cout<<"La solucion es:"<<endl;
			printSudoku(Sudoku);
		}else{
			cout<<"No existe Solucion"<<endl;
		}	
	}
	cout<<"Elaborado por Jesus Machado C.I:28553080"<<endl;
    return 0;
}
/*
                              !         !          
                             ! !       ! !          
                            ! . !     ! . !          
                               ^^^^^^^^^ ^            
                             ^             ^          
                           ^  (0)       (0)  ^       
                          ^        ""         ^       
                         ^   ***************    ^     
                       ^   *                 *   ^    
                      ^   *   /\   /\   /\    *    ^   
                     ^   *                     *    ^
                    ^   *   /\   /\   /\   /\   *    ^
                   ^   *                         *    ^
                   ^  *                           *   ^
                   ^  *                           *   ^
                    ^ *                           *  ^  
                     ^*                           * ^ 
                      ^ *                        * ^
                      ^  *                      *  ^
                        ^  *       ) (         * ^
                            ^^^^^^^^ ^^^^^^^^^*/
