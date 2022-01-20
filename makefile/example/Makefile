beispiel: beispiel.o
	gcc beispiel.o -o beispiel	# Runs third

beispiel.o: beispiel.c
	gcc -c beispiel.c -o beispiel.o	# Runs second

beispiel.c:
	echo "int main() {return 0; }" > beispiel.c	# Runs first
