.c.o:
	gcc -c -Wall -DRPC_SVC_FG $<

all: client server

client: eleicaoClient.o programaEleicao_clnt.o programaEleicao_xdr.o
	gcc -o client eleicaoClient.o programaEleicao_clnt.o programaEleicao_xdr.o -lnsl

server: eleicaoServer.o programaEleicao_svc.o programaEleicao_xdr.o
	gcc -o server eleicaoServer.o programaEleicao_svc.o programaEleicao_xdr.o -lrpcsvc -lnsl

programaEleicao.h: programaEleicao.x
	rpcgen -C programaEleicao.x

clean:
	rm *.o programaEleicao.h programaEleicao_clnt.* programaEleicao_svc.* programaEleicao_xdr.*

eleicaoClient.c: programaEleicao.h
eleicaoServer.c: programaEleicao.h
