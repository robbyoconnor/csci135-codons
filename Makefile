CC=g++
FILES=AminoAcid.cc main.cc

build-run: ${CC} -g ${FILES} -o codons
	./codons

clean: rm -rf codons*