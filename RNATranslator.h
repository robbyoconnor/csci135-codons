/******************************************************************************
	Title: RNATranslator.h
Author: Robert O'Connor
Created on: July 22, 2012
Description: Abstracts away the Translation step of reading each codon and then
associating and printing out the associated amino acid.
*******************************************************************************/
#ifndef RNATRANSLATOR_H
#define	RNATRANSLATOR_H

#include <map>
#include <string>

#include "AminoAcid.h"
#include "RNATranscriber.h"

class RNATranslator{
  public:

    RNATranslator();
    
    RNATranslator(const RNATranscriber rnaTranscriber);

    /**
     * Processes the sequence reading the codons and outputting the amino acids associated.
     * Pre-condition: It is assumed that it is a valid RNA sequence (e.g., thymine base has been converted to uracil.)
     * Post-condition: adds all codons found to a vector and returns it.
     * @return a vector containing all the codons.
     */
    std::vector<std::string> processSequence();

    /**
     * Determines all the amino acids.
     * @param codons the codons as parsed by processSequence().
     * @param position
     */
    void printAminoAcids(std::vector<std::string> codons);

    /**
     * Processes the input file and adds the data to the aminoAcids vector.
     * Pre-condition: file exists and is readable and in proper form
     * Post-condition: aminoAcids vector is populated and amino acids are in alphabetical order according to long name.
     * @param fileName
     * @return true if successful false otherwise.
     */
    bool processInputFile(const std::string fileName);

  private:

    RNATranscriber transcriber;

    /**
     * Allows for easy lookup of amino acids given a
     * codon.
     */
    std::map<std::string,AminoAcid> aminoAcidsMap; // not exposed.
};
#endif
