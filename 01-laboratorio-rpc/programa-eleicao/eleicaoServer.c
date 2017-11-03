/* Definition of the remote add and subtract procedure used by
   simple RPC example
   rpcgen will create a template for you that contains much of the code
   needed in this file is you give it the "-Ss" command line arg.
*/
#include <stdio.h>
#include "programaEleicao.h"

/* Here is the actual remote procedure */
/* The return value of this procedure must be a pointer to int! */
/* we declare the variable result as static so we can return a
   pointer to it */
int controleCandidatos[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int controleEleitores[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int *
votar_1_svc(votos *argp, struct svc_req *rqstp)
{	
	static int verdadeiro = 1;

	printf("Voto Secreto: Eleitor %d, Candidato %d\n",argp->idEleitor, argp->numCandidato);

	if(argp->numCandidato >= 1 && argp->numCandidato <= 15){
		if (argp->idEleitor >= 1 && argp->idEleitor <= 15){
			if(controleEleitores[argp->idEleitor] == 0){
				controleCandidatos[argp->numCandidato]++;
				controleEleitores[argp->idEleitor] = 1;
				
				return (&verdadeiro);
			}
		}
	}
	return 0;
}



resultado *
resultadofinal_1_svc(void * argp, struct svc_req *rqstp)
{
	static resultado result;

	result.numCandidato = 0;
	result.numVotos = 0;

	for(int i = 1; i <= 15; i++){
		if(result.numVotos < controleCandidatos[i]){
			result.numCandidato = i;
			result.numVotos = controleCandidatos[i];
		}
	}

	return (&result);
}