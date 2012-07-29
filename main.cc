/******************************************************************************
 Title: main.cc
 Author: Robert O'Connor
 Created on: July 22, 2012
 Description: Entry point for the application which transcribes a DNA strand
 to an RNA strand and provides for some other handy things.
 Usage: codons
 Build with: make
 Modifications:
 *******************************************************************************/

#include <iostream>

using namespace std;

// function protoypes
void displayMenu(bool &done);
bool isPalindromicSequence(string dnaSequence1, string dnaSequence2);
bool isValidDNASequence(string sequence);
void validateDNASequence(string &sequence);
void promptPhylogeneticDistanceInput(string &sequence1, string &sequence2);
int getPhylogeneticDistance(string dnaSequence1, string dnaSequence2);
void help(int selection);
int main(int argc, char* argv[]) {
	bool done = false;
	do {
		displayMenu(done);
	} while (!done);
}

/**
 * Displays the menu, processes user choices and sets the sentinel value to false/
 * @param done passed by reference, acts as the sentinel value..
 */
void displayMenu(bool& done) {
	cout << "\nWelcome! This program will:\n"
		<< endl;
	cout << "1. Find the Phylogenetic Distance of two equally sized DNA strands"
		<< endl;
	cout << "2. Determine if a sequence of nucleotides is palindromic"
		<< endl;
	cout << "3. Transcribe a DNA sequence to RNA"
		<< endl;
	cout << "4. Output the Amino Acids represented by each codon in the RNA"
		<< endl;
	cout << "------------------------------------------------------------------"
		<< endl;

	cout << "Make a selection (enter \"0\" (without quotes) to quit.): ";
	int choice;
	cin >> choice;
	switch (choice) {
		case 0:
			done = true;
			break;
		case 1: { // braces put in to limit scope.
			string sequence1,sequence2;
			promptPhylogeneticDistanceInput(sequence1,sequence2);
			//output it.
			cout<<"Phylogenetic sequence of \""<<sequence1<<"\" and  \""<<sequence2<<"\" is: ";
			cout<<getPhylogeneticDistance(sequence1,sequence2)<<endl;
			break;
		}
		case 2: {
			//TODO: complete this
			break;
		}
		case 3:
			//TODO: complete this
			break;
		case 4:
			//TODO: complete this
			break;
		default:
			cout << "Invalid input! please choose only numbers between 0 and 4! "
				<< endl;
			cout << "Please make a selection: ";
			cin >> choice;
			break;
	}
}

/**
 * Determines if a sequence of nucleotides is palindromic.
 * @param dnaSequence
 * @return
 */
bool isPalindromicSequence(string sequence, bool isRna = false) {
	return true;
}
/**
 * Prompt for phylogenetic distance.
 * Pre-condition: the two sequences are passed by reference
 * Post-condition: the inputs are stored in the reference passed.
 * @param sequence1 the first sequence
 * @param sequenc2 the second sequence
 *
 */
void promptPhylogeneticDistanceInput(string &sequence1, string &sequence2) {
	cout << "\nTo calculate the phylogentic distance, you will be required"
		<< " to enter two DNA sequences."
		<< endl
		<< "The sequence must be 30 letters or less and contain only the letters \'a\', \'c\', \'g\' or \'t\'."
		<< endl;

	cout << "Please enter the first sequemce (with no spaces and all on one line): ";
	cin >> sequence1;
	// first sequence validation.
	validateDNASequence(sequence1);
	cout << "Please enter the second sequence (with no spaces and all on one line): ";
	cin >> sequence2;
	validateDNASequence(sequence2);

	while(sequence1.size() != sequence2.size()) {
		cout<<"\nThe two sequences must be of equal length."<<endl;
		cout << "Please enter the first sequemce (with no spaces and all on one line): ";
		cin >> sequence1;
		// first sequence validation.
		validateDNASequence(sequence1);
		cout << "Please enter the second sequence (with no spaces and all on one line): ";
		cin >> sequence2;
		// second sequence validation...
		validateDNASequence(sequence2);
	}
}
/**
 * Calculates and returns the phylogenetic distance
 * Pre-condition: the two stands must be of equal length; less than or equal to 30 letters; and only contain the letters a,c,g and t.
 * @param dnaSequence1 the first sequence
 * @param dnaSequence2 the second sequence
 * @return -1 if not equal or the the phylogenetic distance of the two sequences.
 */
int getPhylogeneticDistance(string dnaSequence1, string dnaSequence2) {
	int numDifferent = 0; // this will increment as we find different values.
	for(int i = 0;i < dnaSequence1.size();i++) {
		if (dnaSequence1.size() != dnaSequence2.size()) {
			return -1; // this will never happen...but always good to check anyways...
		}
		if (dnaSequence1[i] != dnaSequence2[i]) {
			numDifferent++;
		}
	}
	return numDifferent / dnaSequence1.size();
}

/**
 * Utility function to check if the DNA sequence is valid or not.
 * @param sequence the DNA sequence
 * @return true if all characters contained in the string  are a, c, g, or t otherwise false.
 */
bool isValidDNASequence(string sequence) {
	for(int i = 0;i<sequence.size();i++) {
		if (sequence[i] == 'a') {
			continue; // keep checking
		} else if (sequence[i] == 'c') {
			continue; // keep checking
		} else if (sequence[i] == 'g') {
			continue; // keep checking
		} else if (sequence[i] == 't') {
			continue; // keep checking
		} else {
			return false;
		}
	}
	return true;
}

/**
 * Validates the DNA Sequence for both size and its properties which state it may only contain the letters: a,c,g and t.
 *
 * Pre-condition: dnaSequence is passed by reference
 * Post-condition: the valid DNA string is stored in the reference passed to this function.
 * @param dnaSequence the sequence to be checked
 *
 */
void validateDNASequence(string &dnaSequence) {
	// allows for me to more precisely determine what isn't valid.
	bool tooBig = dnaSequence.size() > 30;
	bool invalidDNA = !isValidDNASequence(dnaSequence);
	while (tooBig || invalidDNA) {
		if (tooBig) {
			cout << "The sequence must be 30 letters or less."
				<< endl;
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			//reset the bools.
			tooBig = dnaSequence.size() > 30;
			invalidDNA = !isValidDNASequence(dnaSequence);
		} else if (invalidDNA) {
			cout << "The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\'."
				<< endl;
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			//reset the bools.
			invalidDNA = !isValidDNASequence(dnaSequence);
			tooBig = dnaSequence.size() > 30;
		} else {
			return;
		}
	}
	return;
}

void help(int selection) {
}
