#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


void printSolution(int *solution, int size)
{
 	for (int i = 0; i < size; i++) {
    printf("\n");
		for (int j = 0; j < size; j++)   
			if (solution[i] == j){
				printf(" %d ",1);  //Affiche un 1 qui représente un pion, ici la Reine
			}
			else{
				printf(" %d ",0); //Affiche un 0 qui représente une absence de pion, ici un 0
			}
	}
}   



void printSolution2(int **solution,int size) { 
     
    for(int i=0; i<8; i++){
            int test[]={0, 0, 0, 0, 0, 0, 0, 0};
            for(int j=0; j<size; j++){
                if (solution[1][j] == i){
                    int x = solution[0][j];
                    test[x] = 1;   
                }
            }
        for (int k=0;k<8;k++){
            printf("%d ",test[k]);
        }       
        printf("\n");
    }
}  



void saveSolution(int *solution, int size, char *fileName){
	FILE * outputFile = NULL ;
	outputFile = fopen("TP3_Aff.txt","a") ; // "a" car mode d'ajout de fichier qui ajoute à la fin du fichier

 	for (int i = 0; i < size; i++) {
		fprintf(outputFile,"\n");
		for (int j = 0; j < size; j++)
			if (solution[i] == j){
				fprintf(outputFile," %d ",1);  //Affiche Reine
			}
			else{
				fprintf(outputFile," %d ",0); //Affiche 0 (vide)
			}
	}
	fprintf(outputFile,"\n");
  	fclose(outputFile) ;        //Ferme le fichier après ouverture
} 



void saveSolution2(int **solution, int size, char *fileName){
	FILE * outputFile = NULL ;
	outputFile = fopen("TP3_Aff2.txt","a") ;
 
    for(int i=0; i<8; i++){     
            int test[]={0, 0, 0, 0, 0, 0, 0, 0};  //création d'une liste pour facilité l'affichage
            for(int j=0; j<size; j++){
                if (solution[1][j] == i){
                    int col = solution[0][j];
                    test[col] = 1;   
                }
            }
        for (int k=0;k<8;k++){
            fprintf(outputFile,"%d ",test[k]);
        }    
        fprintf(outputFile,"\n");   
    }
    fprintf(outputFile,"\n");
    fclose(outputFile) ;

} 




int queenIsSafe(int *solution,int x,int y){
  	for (int i = 1; i <= y  ; i++) {
		if (solution[y - i] == x - i){ 
        //Faux, il y a une reine sur une diagonal gauche 
			return 1;
		}
    }

	for (int i = 1; i <= y  ; i++){
		if (solution[y-i] == x){ 
        //Faux, il y a une reine sur la ligne haute
			return 1;
		}
    }

	for (int i = 1; i <= y  ; i++){
		if (solution[y - i] == x + i){ 
        //Faux, il y a une reine sur une diagonal droite
			return 1;
		}
     }
	return 0; // 0 reine détecté, queen safe
} 



int bishopIsSafe(int **solution, int x, int y){
    for(int i=0;i<14;i++){
        if(solution[0][i] == x-i){
            if(solution[1][i] == y-i){
                //bishop pas safe en haut à gauche
                return 1;
            }
        }
        if(solution[0][i] == x+1){
            if(solution[1][i] == y-1){
                //bishop pas safe en haut à droite
                return 1;
            }
        }        
    } 
    printf("bishop safe \n");
    return 0;    //Il y a aucun bishop donc 0 reine en vu : bishop safe
}





int kingIsSafe(int **solution, int x, int y){
    for(int i=0;i<16;i++){
        if(solution[0][i] == x-1){
            if(solution[1][i] == y-1){
                //King pas safe en haut à gauche
                return 1;
            }
        }
        if(solution[0][i] == x+1){
            if(solution[1][i] == y-1){
                //King pas safe en haut à droite
                return 1;
            }
        }        
        if(solution[0][i] == x-1){
            if(solution[1][i] == y){
                //King pas safe à gauche\n")
                return 1;
            }
        }
        if(solution[0][i] == x){
            if(solution[1][i] == y-1){
               //King pas safe en haut\n")
                return 1;
            }
        }
        if(solution[0][i] == x+1){
            if(solution[1][i] == y){
                //King pas safe à droite
                return 1;
            }
        }
    } 
    return 0;    //Il y a aucune reine donc 0 reine en vu : king safe
}





int knightIsSafe(int **solution, int x, int y){
    for(int i=0;i<32;i++){
        if(solution[0][i] == y-2){
            if(solution[1][i] == x-1){
                //Knight pas safe en haut gauche ")
                return 1;
            }
          }
        if(solution[0][i] == x-2){
            if(solution[1][i] == y-1){
				//Knight pas safe à gauche haut
                return 1;
            }
        } 
        if(solution[0][i] == x+2){
            if(solution[1][i] == y-1){
                //Knight pas safe à droite haut\n")
                return 1;
            }
        } 
        if(solution[0][i] == y-2){
            if(solution[1][i] == x+1){
				//Knight pas safe en haut à droite
                return 1;
            }
        }        
    } 
    return 0;    //Il y a aucun Knight donc 0 knight en vu : Knight safe
}





void search(int *solution,int size,int y,char * fileName){
	if (y < size){
		for(int i=0;i<size; i++)
		{
					
			if(queenIsSafe(solution,i,y) == 0){     //Si la reine est safe 
				solution[y] = i;                //On la place sur l'échiquier
				search(solution, size, y+1, fileName);    // on continue la recherche récursivement mais sur la ligne suivante	
				solution[y] = -1;     //Si jamais ce n'est pas bon, on revient sur la rangée initial en mettant 0 à l'indice des queens
			
			}
		}
	}
	else{
		saveSolution(solution,size,fileName); // On compte la taille quand il y a 8 reines dans l'échéquier (et que tout va bien donc .. )
		//Faire en sorte d'affiche le nombre de solution.
	}			
}



void search2(int ** solution, int size, int x, int y,char * filename, int tailleKnight){

    if(tailleKnight<8){
        for(int y; y<size; y++){
            for(int x; x<size; x++){
                if(knightIsSafe(solution, x, y) == 1){    //Vérifie si knight est safe
                    solution[0][tailleKnight]=x;          //Si oui on place sur l'échiquier
                    solution[1][tailleKnight]=y;

                    search2(solution, size, 0, y+1,filename, tailleKnight);    //On continue la recherche récusivement
                    solution[0][tailleKnight]=-1;               //Si ce n'est pas bon, on revient au point initial on enlevant les knights
                    solution[1][tailleKnight]=-1;
                }
            }
        }
    }
    else{
        saveSolution2(solution,size,"TP3.Aff2.txt");   //Sinon, on save la solution
    }
}







//*********  FONCTION TEST  *********//

int queenIsSafeTest(int *solution){
	if (queenIsSafe(solution,3,4) != 1){
		printf("Il y a un probleme sur la diagonal droite");
	}
	if (queenIsSafe(solution,2,2) != 1){
		printf("Il y a un probleme sur la ligne du haut");
	}
	if (queenIsSafe(solution,4,7) != 1){
		printf("Il y a un probleme sur la diagonal droite");
	}
}



int bishopIsSafeTest(int **solution){
    if (bishopIsSafe(solution,7,7) != 1)
        printf("Probleme lorsqu'il y a un pion en haut à gauche de fou");
    if (bishopIsSafe(solution,2,4) != 1)
        printf("Probleme lorsqu'il y a un pion en haut à droite de fou");
    if (knightIsSafe(solution,4,2) != 0)
        printf("Probleme lorsque bishop est safe \n");
}




int kingIsSafeTest(int **solution){
    if (kingIsSafe(solution,2,1) != 1)
        printf("Probleme lorsqu'il y a un pion à gauche de King");
    if (kingIsSafe(solution,2,2) != 1)
        printf("Probleme lorsqu'il y a un pion en haut à gauche de King");
    if (kingIsSafe(solution,1,2) != 1)
        printf("Probleme lorsqu'il y a un pion en haut de King");
    if (kingIsSafe(solution,0,2) != 1)
        printf("Probleme lorsqu'il y a un pion en haut à droite de King");
    if (kingIsSafe(solution,0,1) != 1)
        printf("Probleme lorsqu'il y a un pion à droite de King");
    if (kingIsSafe(solution,4,7) != 0)
        printf("Probleme lorsque king est safe \n");
}



int knightIsSafeTest(int **solution){
    if (knightIsSafe(solution,2,3) != 1)
        printf("Probleme lorsqu'il y a un pion en haut gauche \n");
    if (knightIsSafe(solution,7,4) != 1)
        printf("Probleme lorsqu'il y a un pion  à gauche haut \n");
    if (knightIsSafe(solution,3,4) != 1)
        printf("Probleme lorsqu'il y a un pion à droite haut \n");
    if (knightIsSafe(solution,2,5) != 1)
        printf("Probleme lorsqu'il y a un pion en haut à droite \n");
    if (knightIsSafe(solution,7,7) != 0)
        printf("Probleme lorsque knight est safe \n");		
}




//MAIN//
int main(){

	//***TABLEAU DE TEST QUEEN***//

    int solution[8] = {-1,-1,-1,-1,-1,-1,-1,-1};  
	int solution1[8] = {0,2,5,-1,-1,-1,4,5};
	int solution2[8] = {0,0,0,0,0,0,0,0};

	//***TABLEAU DE TEST QUEEN***//



    int size = 8;   
  	int x = 0;    //coordonnée colonne
  	int y =0;	//coordonnée rangée

// *****************APPEL FONCTION QUEEN***********************//

/*     printSolution(solution,size); 
	printf(" \n "); */
/* 	printSolution(solution1,size); 
	printf(" \n "); */
/* 	printSolution(solution1,size);  */
/* 	printSolution(solution1,size); 
	printf(" \n "); */


/*    queenIsSafe(solution1, x,y); */
	queenIsSafeTest(solution1);
/* 	search(solution,size,y,"TP3_Aff.txt"); */ 

// *****************APPEL FONCTION QUEEN***********************//

//*****************************************************************************************************//
//*****************************************************************************************************//

	int tailleKnight = 33;
	int tailleBishop = 15;
	int tailleKing = 17;



    int *solution4[2];

	//Solution Bishop//

    solution4[0] = malloc(tailleBishop*sizeof(int));
    solution4[1] = malloc(tailleBishop*sizeof(int));

    for(int a=0;a<tailleBishop;a++){
        solution4[0][a] = -1;
        solution4[1][a] = -1;
    }

	//Solution King//

/*     solution4[0] = malloc(tailleKing*sizeof(int));
    solution4[1] = malloc(tailleKing*sizeof(int));

    for(int a=0;a<tailleKing;a++){
        solution4[0][a] = -1;
        solution4[1][a] = -1;
    } */

	//Solution King//

/*     solution4[0] = malloc(tailleKnight*sizeof(int));
    solution4[1] = malloc(tailleKnight*sizeof(int));

    for(int a=0;a<tailleKnight;a++){
        solution4[0][a] = -1;
        solution4[1][a] = -1;
    } */


    solution4[0][0] = 3;
    solution4[1][0] = 3;

    solution4[0][1] = 1;
    solution4[1][1] = 1;    

    solution4[0][2] = 5;
    solution4[1][2] = 3;

    solution4[0][3] = 0;
    solution4[1][3] = 6;

//*****************************************************************************************************//
//*****************************************************************************************************//



// *****************APPEL FONCTION AUTRES***********************//
/*     printSolution2(solution,8);  */

/*     bishopIsSafe(solution4,x,y); */
    bishopIsSafeTest(solution4);

/*     kingIsSafe(solution4,x,y); */
    kingIsSafeTest(solution4);

/*     knightIsSafe(solution4,x,y); */
    knightIsSafeTest(solution4);


/* saveSolution2(solution,size,"TP3.Aff2.txt"); */



// *****************APPEL FONCTION AUTRES***********************//


	//Libère l'espace alloué par solution4[0] et solution4[1]
    free(solution4[0]);   
    free(solution4[1]);
	
    return 0;

}