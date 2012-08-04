/******************************************************************************
 Title: RNATranslator.cc
 Author: Robert O'Connor
 Created on: July 22, 2012
 Description:
 Modifications:
 *******************************************************************************/
#include "RNATranslator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include<map>

using namespace std;
RNATranslator::RNATranslator() {
	// this page intentionally left blank...
}

RNATranslator::RNATranslator(const RNATranscriber rnaTranscriber) :
		transcriber(rnaTranscriber) {
}

vector<string> RNATranslator::processSequence() {
	string rna = transcriber.getRNASequence();
	string codon;
	vector<string> codons;
	int i = 0;
	/* Take substrings of three characters at a time
	 * push them onto a vector and then remove those three characters
	 * do this until the string is empty.
	 * this allows us to break the string up into groups of three
	 * since the requirement that the length always be a multiple of 3
	 * this code will always work.
	 */
	while (i < 2 && !rna.empty()) {
		codon = rna.substr(i, i + 3);
		// this makes it easier when translating...the user need not be concerned
		transform(codon.begin(), codon.end(), codon.begin(), ::toupper);
		codons.push_back(codon);
		rna.replace(i, i + 3, "");
	}

	return codons;
}

void RNATranslator::printAminoAcids(vector<string> codons) {
	string sequence;
	cout << "The following proteins are encoded by the RNA sequence you entered:\n"<<endl;
	for(int i = 0;i < codons.size();i++) {
		string codon = codons[i];
		// check if it exists first.
		map<string, AminoAcid>::iterator it = this->aminoAcidsMap.find(codon);
		if (it != this->aminoAcidsMap.end()) {
			// okay it exists...this now returns a pair<string,AminoAcid>.
			// we can count on this so we return it.
			AminoAcid acid = it->second;
			cout << "Amino acid name: " << acid.getName() << " (" << acid.getThreeLetterName() << ")" << endl;
			cout << "Molar Mass of " << acid.getThreeLetterName() << ": " << acid.getMolarMass()<<" g/mol\n" << endl;
			sequence += acid.getThreeLetterName()+"-";
		} else {
			cout << "***Stop Codon encountered***" << endl;

		}
	}
	sequence.replace(sequence.size() - 1, sequence.size(), ""); // remove the trailing "-" from the sequence.
	cout << "The sequence you entered is encoded as: " << sequence << endl;
}

bool RNATranslator::processInputFile(const std::string fileName) {
	ifstream input(fileName.c_str());
	string longName, threeLetterName, trash;
	double molarMass;
	vector<string> codons;
	if (input.is_open()) {
		while (input.good()) {
			codons.clear(); // we need to clear it...
			input >> longName; // grab the first line since we know it's the name...
			input >> threeLetterName >> threeLetterName >> threeLetterName;
			input >> trash >> trash >> molarMass;
			string line;
			getline(input, line); // contains g/mol -- we don't care.
			getline(input, line); // contains what we want.
			line.replace(0, 9, ""); // get rid of "Codons: " (note the white space).
			stringstream ss(line);
			string token;
			while (ss >> token) {
				codons.push_back(token); // push it onto the vector
			}
			AminoAcid acid(longName, threeLetterName, molarMass, codons);
			// iterate through the codons array and add them to map which will be used for lookups.
			// codon information is still stored in the AminoAcid class but this provides an easier way to get data.
			for(vector<string>::iterator iter = codons.begin();iter < codons.end();iter++) {
				this->aminoAcidsMap.insert(pair<string, AminoAcid>(*iter, acid));
			}
		}
	} else {
		// barring unforeseen events since things are tightly controlled...will never reach here.
		cout << "Error opening file" << endl;
		return false;
	}
	return true;
}
