/******************************************************************************
Title: AminoAcid.cc
Author: Robert O'Connor
Created on: July 21, 2012
Description: Represents an Amino Acid
Modifications:
*******************************************************************************/
#include "AminoAcid.h"
#include <vector>
using namespace std;

AminoAcid::AminoAcid(){
}

AminoAcid::AminoAcid(string name, string threeLetterName, string molecularFormula, vector<string> codons) {
    this->name = name;
    this->threeLetterName = threeLetterName;
    this->molecularFormula = molecularFormula;
    this->codons = codons;
}

string AminoAcid::getName() {
    return this->name;
}

void AminoAcid::setName(string name) {
    this->name = name;
}

string AminoAcid::getThreeLetterName() {
    return this->threeLetterName;
}

void AminoAcid::setThreeLetterName(string threeLetterName) {
    this->threeLetterName = threeLetterName;
}

string AminoAcid::getMolecularFormula() {
    return this->molecularFormula;
}

void AminoAcid::setMolecularFormula(string molecularFormula) {
    this->molecularFormula = molecularFormula;
}

vector<string> AminoAcid::getCodons() {
    return this->codons;
}

void AminoAcid::setCodons(vector<string> codons) {
    this->codons = codons;
}
