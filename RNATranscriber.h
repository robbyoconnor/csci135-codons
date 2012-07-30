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

class RNATranscriber {
	public:
		/**
		 * Default constructor
		 */
		RNATranscriber();

		/**
		 * Simply sets the dna sequence, after this no other access is given to this class member.
		 */
		RNATranscriber(std::string dnaSequence);

		/**
		 * Returns the RNA Sequence
		 */
		std::string getRNASequence();

		/**
		 * Transcribes the DNA sequence to RNA.
		 */
		void transcribe();

	private:
		std::string dnaSequence; // not exposed once set
		std::string rnaSequence; // is exposed.
};

#endif
