lib="../../C"
src="src"
bin="bin"

g++ -Wall -I${lib} -c -o ${bin}/String.o ${lib}/String.c
g++ -Wall -I${lib} -o ${bin}/String ${bin}/String.o ${src}/String.c
