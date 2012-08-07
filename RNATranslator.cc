/******************************************************************************
 Title: RNATranslator.cc
 Author: Robert O'Connor
 Created on: July 22, 2012
 Description:
 Modifications:
 *******************************************************************************/
#include "RNATranslator.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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

	/* Take substrings of three characters at a time
	 * push them onto a vector and then remove those three characters
	 * do this until the string is empty.
	 * this allows us to break the string up into groups of three
	 * since the requirement that the length always be a multiple of 3
	 * this code will always work.
	 */
	while (!rna.empty()) {
		codon = rna.substr(0, 3); // codon....
		// this makes it easier when translating...since the codons are uppercase.
		transform(codon.begin(), codon.end(), codon.begin(), ::toupper);
		codons.push_back(codon);
		rna.replace(0, 3, ""); // remove the codon...
	}

	return codons;
}

void RNATranslator::printAminoAcids(vector<string> codons) {
	string sequence; // final protein sequence
	cout<<left;
	cout << "The following proteins are encoded by the RNA sequence you entered:\n" << endl;
	int i = 0;
	int size = codons.size();
	for(;i<size;i++) {
		string codon = codons[i];
		// check if iter exists first.
		map<string, AminoAcid>::iterator iter = this->aminoAcidsMap.find(codon);
		if (iter != this->aminoAcidsMap.end()) {
			// okay it exists...this now returns a pair<string,AminoAcid>.
			AminoAcid acid = iter->second;
			cout<<"Amino acid name: "<<acid.getName()<<" ("<<acid.getThreeLetterName()<<"); "<<"Molar Mass: "<<acid.getMolarMass()<<"."<<endl;
			sequence.append(acid.getThreeLetterName()).append("-");
		} else {
			cout << "***Stop Codon encountered***" << endl;

		}
	}
	// remove the trailing dash and print sequence.
	cout << "The following protein sequence has been translated: " << sequence.replace(sequence.size() - 1, sequence.size(), "") << endl;
}

bool RNATranslator::processInputFile(const std::string fileName) {
	ifstream input(fileName.c_str());
	string longName; // full name
	string threeLetterName; // abbrev.
	string trash; // used to simply skip over tokens...
	double molarMass; // the molecular mass.
	if (input.is_open()) {
		while (input.good()) {
			input >> longName; // grab the first line since it is known  that it's the name wanted..
			input >> threeLetterName >> threeLetterName >> threeLetterName;
			input >> trash >> trash >> molarMass;
			string line;
			getline(input, line); // contains g/mol -- don't care.
			getline(input, line); // contains what I want.
			line.replace(0, 9, ""); // get rid of "Codons: " (note the white space).
			stringstream ss(line);
			string token;
			/* Since the codons vector was not being used -- I opted to remove it.
			 * Instead the codons are in the map which allows for easy lookup.
			 * This has the added bonus of removing the need to iterate *AGAIN* to
			 * find the codons. Performance bonus I guess? Even if it is premature optimization...
			 */
			AminoAcid acid(longName, threeLetterName, molarMass);
			while (ss >> token) { // tokenize using stringstream...
				this->aminoAcidsMap.insert(make_pair(token, acid)); // codon->AminoAcid  mapping
			}
		}
	} else {
		// barring unforeseen events since things are tightly controlled...will never reach here.
		cout << "Error opening file" << endl;
		return false;
	}
	return true;
}
