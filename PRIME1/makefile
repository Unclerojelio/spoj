CC     = g++
CFLAGS = -g -Wall
EXE    = PRIME1

all: ${EXE}

${EXE}: ${EXE}.o
	 ${CC} -o $@ $<

${EXE}.o: ${EXE}.cpp
	 ${CC} -c ${CFLAGS} $<
	 
run: ${EXE}
	 ./${EXE} < ${EXE}.in
     
clean:
	 -rm  -f *.o ${EXE} core