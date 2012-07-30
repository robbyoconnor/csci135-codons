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
void help(int selection);

bool isValidDNASequence(string sequence);
void validateDNASequence(string &sequence);
void printMessage(string err);
void promptPhylogeneticDistanceInput(string &sequence1, string &sequence2);
int getPhylogeneticDistance(string dnaSequence1, string dnaSequence2);
void promptPalindromicSequence(string &sequence);
bool isPalindromicSequence(string dnaSequence);
string getComplement(string sequence);

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
			string sequence1, sequence2;
			promptPhylogeneticDistanceInput(sequence1, sequence2);
			//output it.
			cout << "Phylogenetic sequence of \""
				<< sequence1
				<< "\" and  \""
				<< sequence2
				<< "\" is: ";
			cout << getPhylogeneticDistance(sequence1, sequence2)
				<< endl;
			break;
		}
		case 2: {
			string sequence = "", complement = "";
			promptPalindromicSequence(sequence);
			cout << "\nThe sequence \""
				<< sequence
				<< " and its complement \""
				<< getComplement(sequence)
				<< "\" ";
			if (isPalindromicSequence(sequence)) {
				cout << "is palindromic."
					<< endl;
			} else {
				cout << "is not palindromic."
					<< endl;
			}
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
 * Prompt for checking for a Palindromic sequence
 * @param sequence a reference to the sequence.
 */
void promptPalindromicSequence(string &sequence) {
	cout << "To determine if a sequence of nucleotides is palindromic, a single sequence is required."
		<< endl
		<< "The constraints are as follows: "
		<< endl;
	cout << "1. The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\' (or their upper-case counterparts)."
		<< endl;
	cout << "2. Its length must be a multiple of three and 30 characters or less.\n\n"
		<< endl;
	cout << "Please enter the DNA sequence (no spaces, all on one line): ";
	cin >> sequence;
	validateDNASequence(sequence);
}

/**
 * Determines if a sequence of nucleotides is palindromic.
 * Pre-condition: valid sequence is passed...we know it is valid because it is checked long before it is passed.
 * Post-condition: a complement string (that is passed as an empty string by reference,
 * now contains the complementary sequence.
 * @param dnaSequence
 * @param complement used to pass back for display to the user.
 * @return true if the complement of the sequence is a palindrome, false otherwise.
 */
bool isPalindromicSequence(string sequence) {
	// first we need to find the complement.
	string complement = getComplement(sequence);
	string reversed(sequence.rbegin(), sequence.rend()); // reversed sequence
	return complement == reversed;
}

/**
 * Gets the complement for a given DNA sequence.
 * Wherein substitution will occur as follows: A=T, T=A, G=C, C=G.
 * Case is taken into consideration, that is: a!=A, this allows for consistency.
 * @param sequence the sequence
 * @return the complement of the given sequence.
 */
string getComplement(string sequence) {
	string complement = sequence;
	unsigned int i = 0;
	unsigned int size = (unsigned) complement.size();
	for(;i < size;i++) {
		if (complement[i] == 'A')
			complement[i] = 'T';
		else if (complement[i] == 'a')
			complement[i] = 't';
		else if (complement[i] == 'C')
			complement[i] = 'G';
		else if (complement[i] == 'c')
			complement[i] = 'g';
		else if (complement[i] == 'G')
			complement[i] = 'C';
		else if (complement[i] == 'g')
			complement[i] = 'c';
		else if (complement[i] == 'T')
			complement[i] = 'A';
		else if (complement[i] == 't')
			complement[i] = 'a';
	}
	return complement;
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
		<< "The constraints are as follows: "
		<< endl;
	cout << "1. The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\' (or their upper-case counterparts).\n\n"
		<< endl;
	cout << "2. Its length must be a multiple of three and 30 characters or less.\n\n"
		<< endl;

	cout << "Please enter the first sequemce (with no spaces and all on one line): ";
	cin >> sequence1;
	// first sequence validation.
	validateDNASequence(sequence1);
	cout << "Please enter the second sequence (with no spaces and all on one line): ";
	cin >> sequence2;
	validateDNASequence(sequence2);
	while (sequence1.size() != sequence2.size()) {
		cout << "\nThe two sequences must be of equal length."
			<< endl;
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

	// squashes the warning: "comparison between signed and unsigned integer expressions"
	unsigned int i = 0;
	unsigned int size = dnaSequence1.size();
	for(;i < size;i++) {
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
 * @return true if all characters contained in the string  are a, c, g, or t otherwise false
 */
bool isValidDNASequence(string sequence) {
	// squashes the warning: "comparison between signed and unsigned integer expressions"
	unsigned int i = 0;
	unsigned int size = (unsigned) sequence.size();
	for(;i < size;i++) {
		if (sequence[i] == 'a' || sequence[i] == 'A') {
			continue; // keep checking
		} else if (sequence[i] == 'c' || sequence[i] == 'C') {
			continue; // keep checking
		} else if (sequence[i] == 'g' || sequence[i] == 'G') {
			continue; // keep checking
		} else if (sequence[i] == 't' || sequence[i] == 'T') {
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
	bool isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
	while (tooBig || invalidDNA || isNotMultipleOfThree) {
		if (tooBig && invalidDNA && isNotMultipleOfThree) {
			printMessage("The sequence must be 30 letters or less.");
			printMessage(
					"The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\' (or their upper-case counterparts).");
			printMessage(
					"The sequence must be a multiple of three (e.g., groups of 3 letters (no spaces)) and 30 letters or less.");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			tooBig = dnaSequence.size() > 30;
			invalidDNA = !isValidDNASequence(dnaSequence);
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else if ((tooBig & invalidDNA)) { // compound cases.
			printMessage("The sequence must be 30 letters or less.");
			printMessage(
					"The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\' (or their upper-case counterparts).");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			tooBig = dnaSequence.size() > 30;
			invalidDNA = !isValidDNASequence(dnaSequence);
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else if (tooBig && isNotMultipleOfThree) {
			printMessage("The sequence must be 30 letters or less.");
			printMessage(
					"The sequence must be a multiple of three (e.g., groups of 3 letters (no spaces)).");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			tooBig = dnaSequence.size() > 30;
			invalidDNA = !isValidDNASequence(dnaSequence);
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else if (isNotMultipleOfThree && invalidDNA) {
			printMessage(
					"The sequence must be a multiple of three (e.g., groups of 3 letters (no spaces)).");
			printMessage(
					"The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\' (or their upper-case counterparts).");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			tooBig = dnaSequence.size() > 30;
			invalidDNA = !isValidDNASequence(dnaSequence);
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else if (tooBig) { // singular cases now...
			printMessage("The sequence must be 30 letters or less.");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			//reset the bools.
			tooBig = dnaSequence.size() > 30;
			invalidDNA = !isValidDNASequence(dnaSequence);
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else if (isNotMultipleOfThree) {
			printMessage(
					"The sequence you enter must be a multiple of 3 (e.g., must be groups of 3).");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			invalidDNA = !isValidDNASequence(dnaSequence);
			tooBig = dnaSequence.size() > 30;
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else if (invalidDNA) {
			printMessage(
					"The sequence must contain only the letters \'a\', \'c\', \'g\' or \'t\' (or their upper-case counterparts).");
			cout << "Please re-enter the sequence: ";
			cin >> dnaSequence;
			//reset the bools.
			invalidDNA = !isValidDNASequence(dnaSequence);
			tooBig = dnaSequence.size() > 30;
			isNotMultipleOfThree = dnaSequence.size() % 3 != 0;
		} else {
			return;
		}
	}
	return;
}

void help(int selection) {
}

/**
 * Prints out validation errors to the screen.
 *
 * Used by validateDNASequence().
 * @param err the error message to print.
 */
void printMessage(string err) {
	cout << err
		<< endl;
	return;
}
