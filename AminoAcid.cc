/******************************************************************************
Title: AminoAcid.cc
Author: Robert O'Connor
Created on: July 21, 2012
Description: Represents an Amino Acid
Modifications:
*******************************************************************************/
#include "AminoAcid.h"
#include <string>

using namespace std;


AminoAcid::AminoAcid(){
    // do nothing.
}

AminoAcid::AminoAcid(const string name, const string threeLetterName, const double molarMass):
		name(name),threeLetterName(threeLetterName), molarMass(molarMass) {
	// this page left blank intentionally.
}

string AminoAcid::getName() {
    return this->name;
}

void AminoAcid::setName(const string name) {
    this->name = name;
}

string AminoAcid::getThreeLetterName() {
    return this->threeLetterName;
}

void AminoAcid::setThreeLetterName(const string threeLetterName) {
    this->threeLetterName = threeLetterName;
}

double AminoAcid::getMolarMass() {
    return this->molarMass;
}

void AminoAcid::setMolarMass(const double molarMass) {
    this->molarMass = molarMass;
}
