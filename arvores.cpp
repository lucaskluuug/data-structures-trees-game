#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   struct nodoArv{
		char nome[50];
		char pais[50];
		int lat;
		int lon;
    	int jogadores;
    	struct nodoArv *esq;
    	struct nodoArv *dir;
    	struct nodoArv *pai;
   }elemento;
   
   struct nodoArv * raiz;
   struct nodoArv * auxPaises;
   struct nodoArv * auxJogadores;
   int contador;

	void insereNodoOrdemJogadores( struct nodoArv * aux, struct nodoArv * novo ){
		if(novo->jogadores<=aux->jogadores){
			if( aux->esq == NULL ){
				aux->esq = novo;
				aux->esq->pai = aux;
			} else
				insereNodoOrdemJogadores( aux->esq, novo);
		}
		else{
			if( aux->dir == NULL){
				aux->dir = novo;
				aux->dir->pai = aux;
			} else 
			insereNodoOrdemJogadores( aux->dir, novo );
		}
	}

	void insereJogador( char *nome, char *pais, int lat, int lon, int jogadores){
        struct nodoArv *novo;
        novo = (struct nodoArv *) malloc(sizeof(elemento));
        strcpy(novo->nome, nome);
		strcpy(novo->pais, pais);
		novo->lat = lat;
		novo->lon = lon;
		novo->jogadores = jogadores;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( auxJogadores == NULL )
		  	auxJogadores = novo;
		else
			insereNodoOrdemJogadores( auxJogadores, novo );	
	}

	void duplicaArvoreJogadores(struct nodoArv *raiz, struct nodoArv *aux){
		if( raiz == NULL )
			return;
			
		duplicaArvoreJogadores( raiz->esq, aux);
		insereJogador(raiz->nome, raiz->pais, raiz->lat, raiz->lon, raiz->jogadores);
		duplicaArvoreJogadores( raiz->dir, aux);
	}

	void insereNodoOrdemPais( struct nodoArv * aux, struct nodoArv * novo ){
		if( strcasecmp(novo->pais, aux->pais)==0){
			(aux->jogadores)++;
			novo=NULL;
		} else{ 
			if( strcasecmp(novo->pais, aux->pais)<0){
	  			if( aux->esq == NULL ){
	  				aux->esq = novo;
	  				aux->esq->pai = aux;
	  			} else
					insereNodoOrdemPais( aux->esq, novo);
	  		}
	  		else{
	  			if( aux->dir == NULL){
	  				aux->dir = novo;
	  				aux->dir->pai = aux;
	  			} else 
				insereNodoOrdemPais( aux->dir, novo );
			}
		}
	}
	  
   void inserePais( char *nome, char *pais, int lat, int lon){
        struct nodoArv *novo;
        novo = (struct nodoArv *) malloc(sizeof(elemento));
        strcpy(novo->nome, nome);
		strcpy(novo->pais, pais);
		novo->lat = lat;
		novo->lon = lon;
		novo->jogadores=1;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( auxPaises == NULL )
		  	auxPaises = novo;
		else
			insereNodoOrdemPais( auxPaises, novo );	
	}
	                
	void insereNodo( struct nodoArv * atual, struct nodoArv * novo ){
		if( strcasecmp(novo->nome, atual->nome)==0){
			(atual->jogadores)++;
			novo=NULL;
		} else{ 
			if( strcasecmp(novo->nome, atual->nome)<0){
	  			if( atual->esq == NULL ){
	  				atual->esq = novo;
	  				atual->esq->pai = atual;
	  			} else insereNodo( atual->esq, novo);
	  		}
	  		else{
	  			if( atual->dir == NULL){
	  				atual->dir = novo;
	  				atual->dir->pai = atual;
	  			} else insereNodo( atual->dir, novo );
	    	}
		}
	}
	  
   void insere(char *nome, char *pais, int lat, int lon){
        struct nodoArv *novo;
        novo = (struct nodoArv *) malloc(sizeof(elemento));
        strcpy(novo->nome, nome);
		strcpy(novo->pais, pais);
		novo->lat = lat;
		novo->lon = lon;
		novo->jogadores=1;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( raiz == NULL )
		  	raiz = novo;
		else
		  	insereNodo( raiz, novo );
	}

	void duplicaArvorePais(struct nodoArv *raiz, struct nodoArv *aux){
		if( raiz == NULL )
			return;
			
		duplicaArvorePais( raiz->esq, aux);
		inserePais(raiz->nome, raiz->pais, raiz->lat, raiz->lon);
		duplicaArvorePais( raiz->dir, aux);
	}

	void jogadores19( struct nodoArv *raiz ){
		if( raiz == NULL )
			return;

		jogadores19( raiz->esq );
		printf("Cidade: %s - Pais: %s - Latitutde: %d - Longitude: %d - Jogadores: %d\n", raiz->nome, raiz->pais, raiz->lat, raiz->lon, raiz->jogadores);
		jogadores19( raiz->dir );
	}

	void jogadores91( struct nodoArv *raiz ){
		if( raiz == NULL )
			return;

		jogadores91( raiz->dir );
		printf("Cidade: %s - Pais: %s - Latitutde: %d - Longitude: %d - Jogadores: %d\n", raiz->nome, raiz->pais, raiz->lat, raiz->lon, raiz->jogadores);
		jogadores91( raiz->esq );
	}

	void paisesAz( struct nodoArv *raiz ){
		if( raiz == NULL )
			return;

		paisesAz( raiz->esq );
		printf("Pais: %s\n", raiz->pais);
		paisesAz( raiz->dir );
	}

	void paisesZa( struct nodoArv *raiz ){
		if( raiz == NULL )
			return;

		paisesAz( raiz->dir );
		printf("Pais: %s\n", raiz->pais);
		paisesAz( raiz->esq );
	}

	void cidadesPais(struct nodoArv *raiz, char *pais){
		if( raiz == NULL )
			return;
			
		cidadesPais( raiz->esq, pais);
		if(strcasecmp(raiz->pais, pais) == 0){
			printf("%s\n", raiz->nome);
		}
		cidadesPais( raiz->dir, pais);
	}

	int jogadoresPais(struct nodoArv *raiz, char *pais){
		if( raiz == NULL )
			return 0;
			
		jogadoresPais( raiz->esq, pais);
		if(strcasecmp(raiz->pais, pais) == 0){
			contador+=raiz->jogadores;
		}
		jogadoresPais( raiz->dir, pais);

		return contador;
	}

	void consultaCidade( struct nodoArv *raiz, char *cidade){
		if( raiz == NULL )
			return;
			
		consultaCidade( raiz->esq, cidade);
		if(strcasecmp(raiz->nome, cidade) == 0){
			printf("Cidade: %s - Pais: %s - Latitutde: %d - Longitude: %d - Jogadores: %d\n", raiz->nome, raiz->pais, raiz->lat, raiz->lon, raiz->jogadores);
		}
		consultaCidade( raiz->dir, cidade);
	}

	void cidadeAz( struct nodoArv *raiz ){
		if( raiz == NULL )
		  	return;
		
		cidadeAz( raiz->esq );
		printf("Cidade: %s - Pais: %s - Latitutde: %d - Longitude: %d - Jogadores: %d\n", raiz->nome, raiz->pais, raiz->lat, raiz->lon, raiz->jogadores);
		cidadeAz( raiz->dir );
	}

	void cidadeZa( struct nodoArv *raiz ){
		if( raiz == NULL )
		  	return;
		
		cidadeZa( raiz->dir );
		printf("Cidade: %s - Pais: %s - Latitutde: %d - Longitude: %d - Jogadores: %d\n", raiz->nome, raiz->pais, raiz->lat, raiz->lon, raiz->jogadores);
		cidadeZa( raiz->esq );
	}

	struct nodoArv *pesq_arv_rec( struct nodoArv * raiz, char *nome ){		
        struct nodoArv *res = NULL;
		if( raiz != NULL ){
            
			if(strcasecmp(raiz->nome, nome)==0){
            	res = raiz;
        	}
        	else{
            	if(strcasecmp(nome, raiz->nome) < 0){
                	res = pesq_arv_rec( raiz->esq, nome);
            	} else{
                	res = pesq_arv_rec( raiz->dir, nome);
            	}
        	}
    	}
    	return res;
	}
	
	struct nodoArv *pesquisaRec(char *nome){
		struct nodoArv * res = pesq_arv_rec( raiz, nome);
		return res;
	}

	void limpaArvore(struct nodoArv * aux){
		if( aux == NULL )
		  	return;
		
		limpaArvore( aux->esq );
		limpaArvore( aux->dir );
		remove(aux->nome);
	}

    void removeFolha( struct nodoArv * atual){
		struct nodoArv * pai = atual->pai;
		if(pai==NULL){
			raiz = NULL;
		}
		else{
			if(pai->esq == atual){
				pai->esq = NULL;
			}
			else{
				pai->dir=NULL;
			}
		}
		free(atual);
	}

	void removeUmFilho( struct nodoArv * atual ){
		struct nodoArv * pai = atual->pai;
		if(pai==NULL){
			if(atual->esq != NULL){
				raiz = atual->esq;
			}
			else{
				raiz = atual->dir;
			}
			raiz->pai=NULL;
		}
		else{
			if(atual->esq == NULL){
				if(pai->dir == atual){
					pai->dir = atual->dir;
				}
				else{
					pai->esq=atual->dir;
				}
				atual->dir->pai = pai;
			}
			else{
				if(pai->dir==atual){
					pai->dir=atual->esq;
				}
				else{
					pai->esq=atual->esq;
				}
				atual->esq->pai = pai;
			}
            free(atual);	
		}
	}
	
    void removeDoisFilhos( struct nodoArv * atual ){
		struct nodoArv * aux=atual->esq;
		struct nodoArv * pai = NULL;
				
		while(aux->dir!= NULL){
			aux = aux->dir;
		}
		atual->jogadores = aux->jogadores;
		atual->lat = aux->lat;
		atual->lon = aux->lon;
		strcpy(atual->nome, aux->nome);
		strcpy(atual->pais, aux->pais);
		
		if((aux->esq == NULL) && (aux->dir == NULL)){
            removeFolha(aux);
		}
		else{
            removeUmFilho(aux);
		}				
	}

    void remove(char *nome){
    	struct nodoArv *atual;
    	
    	atual = pesquisaRec(nome);
    	if(atual == NULL){
    		printf("O Elemento %d Nao Esta Presente na Arvore\n", nome);
		}
		if((atual->esq == NULL) && (atual->dir == NULL))
    		removeFolha(atual);
    	else{
			if((atual->esq != NULL) && (atual->dir != NULL))
    			removeDoisFilhos( atual );
    		else
    			removeUmFilho( atual );
    	}
    }

void interfaceUsuario(){
	char nome[50], pais[50];
    int n, lat, lon;

    printf("\n0. Exit. \n1. Insere cidade. \n2. Remove cidade. \n3. Consulta cidade. \n4. Escreve cidades em ordem alfabética. \n5. Escreve cidades em ordem alfabética inversa. \n6. Escreve países em ordem alfabética. \n7. Escreve países em ordem alfabética inversa. \n8. Escreve cidades em ordem crescente da quantidade de jogadores. \n9. Escreve cidades em ordem decrescente da quantidade de jogadores.\n10. Consulta cidades por país.\n11. Consulta número de jogadores por país.\n");
    scanf("%d", &n);
	getchar();
    switch (n)
    {
    default:
        printf("Erro - Opção inválida.\n");
        break;
    case 0:
        exit(0);
    case 1:
		printf("Nome da cidade:\n");
		gets(nome);
		printf("País:\n");
		gets(pais);
		printf("Latitude:\n");
		scanf("%d", &lat);
		printf("Longitude:\n");
		scanf("%d", &lon);
		insere(nome, pais, lat, lon);
        break;

    case 2:
		printf("Nome da cidade:\n");
		gets(nome);
		remove(nome);
        break;

    case 3:		
		printf("Nome da cidade:\n");
		gets(nome);
		consultaCidade(raiz, nome);
        break;

    case 4:
		cidadeAz(raiz);
        break;

    case 5:
		cidadeZa(raiz);
        break;

    case 6:
		duplicaArvorePais(raiz, auxPaises);
		paisesAz(auxPaises);
		auxPaises=NULL;
		//limpaArvore(auxPaises);
        break;

    case 7:
		duplicaArvorePais(raiz, auxPaises);
		paisesZa(auxPaises);
		auxPaises=NULL;
		//limpaArvore(auxPaises);
        break;

    case 8:
		duplicaArvoreJogadores(raiz, auxJogadores);
		jogadores19(auxJogadores);
		auxJogadores=NULL;
		//limpaArvore(auxJogadores);
        break;

    case 9:
		duplicaArvoreJogadores(raiz, auxJogadores);
		jogadores91(auxJogadores);
		auxJogadores=NULL;
		//limpaArvore(auxJogadores);
        break;

    case 10:
		printf("Nome do pais:\n");
		gets(pais);
		cidadesPais(raiz, pais);
		break;

	case 11:
		printf("Nome do pais:\n");
		gets(pais);
		contador=0;
		printf("%s: %d jogador(es)\n", pais, jogadoresPais(raiz, pais));
		break;
    }

	interfaceUsuario();
}

int main(){
	interfaceUsuario();

    return 0;
}