#define VERSION_NUMBER 1

%#define OK 1
%#define FAIL 2

struct votos {
	int numCandidato;
	int idEleitor;
};

struct resultado {
  int numCandidato;
  int numVotos;
};

program ELEITORAL_PROG {
   version ELEITORAL_VERSION {
     int VOTAR(votos) = 1;
     resultado RESULTADOFINAL() = 2;
   } = VERSION_NUMBER;
} = 555555555;