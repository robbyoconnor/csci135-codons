/******************************************************************************
Title: RNATranslator.h
Author: Robert O'Connor
Created on: July 22, 2012
Description: Abstracts away the Translation step of reading each codon and then
associating and printing out the associated amino acid.
*******************************************************************************/
#ifndef RNATRANSLATOR_H
#define	RNATRANSLATOR_H

#include <vector>
#include <string>

#include "AminoAcid.h"
#include "RNATranscriber.h"


class RNATranslator{
  public:

    RNATranslator();
    
    RNATranslator(RNATranscriber rnaTranscriber);

    /**
     * Processes the sequence reading the codons and outputting the amino acids associated.
     * Pre-condition: It is assumed that it is a valid RNA sequence (e.g., thymine base has been converted to uracil.)
     * Post-condition: outputs amino acids from start codon to stop codon until it reaches the end of the string.
     */
    void processSequence();

    /**
     * Processes the input file and adds the data to the aminoAcids vector.
     * Pre-condition: file exists and is readable and in proper form
     * Post-condition: aminoAcids vector is populated and amino acids are in alphabetical order according to long name.
     * @param fileName
     * @return true if successful false otherwise.
     */
    bool processInputFile(std::string fileName);

  private:

    RNATranscriber transcriber;
    /**
     * Holds data on all of the Amino Acids represented in the text file.
     * Will be sorted alphabetically by full name.
     */
    std::vector<AminoAcid> aminoAcids;

    /**
     * Gets the next codon
     * Pre-condition: It is assumed that it is a valid RNA sequence (e.g., thymine base has been converted to uracil.
     * Post-condition: none.
     * @param rna the rna strand.
     * @return the next codon
     *
     */
    std::string getNextCodon(std::string rna);

    /**
     *  Utility function to check if it is a start codon.
     * @param codon the codon
     * @return true if it is: aug; otherwise false.
     */
    bool isStartCodon(std::string codon);

    /**
     *  Utility function to check if it is a stop codon.
     * @param codon the codon
     * @return true if it is: uaa, uag or uga otherwise false.
     */
    bool isStopCodon(std::string codon);
};

#endif