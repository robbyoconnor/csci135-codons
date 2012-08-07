/******************************************************************************
 Title: main.h
 Author: Robert O'Connor
 Created on: July 30, 2012
 Description: Function prototypes for the main file.
 Modifications:
 *******************************************************************************/


#ifndef MAIN_H_
#define MAIN_H_

/**
 * Displays the menu, processes user choices and sets the sentinel value to false/
 * @param done passed by reference, acts as the sentinel value..
 */
void displayMenu(bool &done);


/**
 * Utility function to check if the DNA sequence is valid or not.
 * @param sequence the DNA sequence
 * @return true if all characters contained in the string  are a, c, g, or t otherwise false
 */
bool isValidDNASequence(std::string sequence);

/**
 * Validates the DNA Sequence for both size and its properties which state it may only contain the letters: a,c,g and t.
 *
 * Pre-condition: dnaSequence is passed by reference
 * Post-condition: the valid DNA string is stored in the reference passed to this function.
 * @param dnaSequence the sequence to be checked
 *
 */
void validateDNASequence(std::string &sequence);

/**
 * Prints out validation errors to the screen.
 *
 * Used by validateDNASequence().
 * @param err the error message to print.
 */
void printErrorMessage(std::string err);

/**
 * Prompt for phylogenetic distance.
 * Pre-condition: the two sequences are passed by reference
 * Post-condition: the inputs are stored in the reference passed.
 * @param sequence1 the first sequence
 * @param sequenc2 the second sequence
 *
 */
void promptPhylogeneticDistanceInput(std::string &sequence1, std::string &sequence2);

/**
 * Calculates and returns the phylogenetic distance
 * Pre-condition: the two stands must be of equal length; less than or equal to 30 letters; and only contain the letters a,c,g and t.
 * @param dnaSequence1 the first sequence
 * @param dnaSequence2 the second sequence
 * @return -1 if not equal or the the phylogenetic distance of the two sequences.
 */
double getPhylogeneticDistance(std::string dnaSequence1, std::string dnaSequence2);

/**
 * Prompt for DNA sequence.
 * @param sequence a reference to the sequence.
 */
void promptForDNASequence(std::string &sequence);

/**
 * Determines if a sequence of nucleotides is palindromic.
 * Pre-condition: valid sequence is passed...we know it is valid because it is checked long before it is passed.
 * Post-condition: a complement string (that is passed as an empty string by reference,
 * now contains the complementary sequence.
 * @param dnaSequence
 * @param complement used to pass back for display to the user.
 * @return true if the complement of the sequence is a palindrome, false otherwise.
 */
bool isPalindromicSequence(std::string dnaSequence);

/**
 * Gets the complement for a given DNA sequence.
 * Wherein substitution will occur as follows: A=T, T=A, G=C, C=G.
 * Case is taken into consideration, that is: a!=A, this allows for consistency.
 * @param sequence the sequence
 * @return the complement of the given sequence.
 */
std::string getComplement(std::string sequence);

#endif /* MAIN_H_ */
