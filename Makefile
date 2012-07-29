CC=g++
FILES=RNATranscriber.cc RNATranslator.cc AminoAcid.cc main.cc

codons: 	
	${CC} -g ${FILES} -o codons 
	./codons
	
clean: 
	rm -rf codons*	