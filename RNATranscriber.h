/******************************************************************************
Title: RNATranscriber.h
Author: Robert O'Connor
Created on: July 22, 2012
Description: Acts as a means to encapsulate and abstract the act of transcribing.
Modifications:
********************************************************************************/
#ifndef RNA_TRANSCRIBER_H
#define	RNA_TRANSCRIBER_H

#include <string>
#include <vector>

#include "RNATranscriber.h"

class RNATranscriber{
  public:
    RNATranscriber();

    RNATranscriber(std::string dnaSequence);

    void getRNASequence();

  private:
    std::string dnaSequence; // not exposed once set
    std::string rna_sequence; // is exposed.
};

#endif
