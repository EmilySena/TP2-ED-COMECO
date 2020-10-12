# Emily Oliveira Sena
#TP2 - Estrututa de Dados

CC=g++ # compilador
CFLAGS=-Wall -Wextra
EXEC=./tp2 # nome do executavel que sera gerado
TMPOUT=tp2.testresult

$(EXEC): main.cpp Civilizacao.o 
	$(CC) $(CFLAGS) main.cpp Civilizacao.o  -o $(EXEC)

Civilizacao.o: Civilizacao.cpp
	$(CC) $(CFLAGS) -c Civilizacao.cpp -o Civilizacao.o
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf Civilizcao.o
	
	


