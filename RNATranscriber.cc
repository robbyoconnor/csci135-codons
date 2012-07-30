/******************************************************************************
Title: RNATranscriber.h
Author: Robert O'Connor
Created on: July 22, 2012
Description: Acts as a means to encapsulate and abstract the act of transcribing DNA to RNA.
Modifications:
********************************************************************************/
#include "RNATranscriber.h"

using namespace std;

RNATranscriber::RNATranscriber(){
}

RNATranscriber::RNATranscriber(string dnaSequence) {
	this->dnaSequence = dnaSequence;
}

string RNATranscriber::getRNASequence() {
	return this->rnaSequence;
}

void RNATranscriber::transcribe() {
	this->rnaSequence = this->dnaSequence;
	unsigned int i = 0;
	unsigned int size = (unsigned)this->rnaSequence.size();
	for(;i<size;i++) {
		if(this->rnaSequence[i]=='t') {
			this->rnaSequence[i]='u';
		} else if(this->rnaSequence[i]=='T') {
			this->rnaSequence[i] = 'U';
		}
	}
}
