/* RPC client for simple addition example */

#include <stdio.h>
#include "programaEleicao.h"  /* Created for us by rpcgen - has everything we need ! */

/* Wrapper function takes care of calling the RPC procedure */

int votar(CLIENT *clnt, int x, int y) {

  votos voto;
  int *result;

  /* Gather everything into a single data structure to send to the server */
  voto.numCandidato = x;
  voto.idEleitor = y;

  /* Call the client stub created by rpcgen */
  result = votar_1(&voto,clnt);
  if (result==NULL) {
    fprintf(stderr,"Trouble calling remote procedure\n");
    exit(0);
  }
  return(*result);
}


/* Wrapper function takes care of calling the RPC procedure */

resultado resultadofinal(CLIENT *clnt) {
  resultado *result;

  // Call the client stub created by rpcgen 
  result = resultadofinal_1(NULL,clnt);
  if (result==NULL) {
    fprintf(stderr,"Trouble calling remote procedure\n");
    exit(0);
  }
  return (*result);
}


int main( int argc, char *argv[]) {
  CLIENT *clnt;
  if (argc!=2) {
    fprintf(stderr,"Usage: %s hostname\n",argv[0]);
    exit(0);
  }

  /* Create a CLIENT data structure that reference the RPC
     procedure SIMP_PROG, version SIMP_VERSION running on the
     host specified by the 1st command line arg. */

  clnt = clnt_create(argv[1], ELEITORAL_PROG, ELEITORAL_VERSION, "udp");

  /* Make sure the create worked */
  if (clnt == (CLIENT *) NULL) {
    clnt_pcreateerror(argv[1]);
    exit(1);
  }

  /* get the 2 numbers that should be added */
  int operacao; 
  int confirmacao;
  int idEleitor; 
  int numCandidato;  
  resultado result;

  
  printf("\nPara votar digite 1.");
  printf("\nPara apurar os resultados digite 2.");
  printf("\nOpcao: ");
  scanf("%d",&operacao);

  if(operacao == 1){
    printf("\nInsita o numero do Candidato: ");
    scanf("%d",&numCandidato);
    printf("\nInsita o ID do Eleitor: ");
    scanf("%d",&idEleitor);
    confirmacao = votar(clnt, numCandidato, idEleitor);      

    if(confirmacao == 1){
      printf("Voto coputado!\n\n");
    }

  }else if(operacao == 2){
    result = resultadofinal(clnt);

    printf("\nCandidato eleito: %d", result.numCandidato);
    printf("\nQuantidade de votos: %d\n", result.numVotos);
    printf("\n");  
  }

  return(0);
}



