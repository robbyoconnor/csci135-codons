/******************************************************************************
Title: AminoAcid.h
Author: Robert O'Connor
Created on: July 21, 2012
Description: Represents an Amino Acid
*******************************************************************************/
#ifndef AMINOACID_H
#define	AMINOACID_H
#include <string>
#include <vector>

class AminoAcid{
  public:
    // default constructor
    AminoAcid();

    // allows for easy initialization of all class members
    AminoAcid(const std::string name, const std::string threeLetterName, const double molarMass, const std::vector<std::string> codons);

    // accessor functions

    /**
     * Returns the name of the amino acid
     * @return the name
     */
    std::string getName();

    /**
     * Returns the three letter name of the amino acid
     * @return the three letter name
     */
    std::string getThreeLetterName();

    /**
     * Returns the molar mass of the given amino acid
     * @return the molar mass in units: g/mol
     */
    double getMolarMass();

    /**
     * Returns a vector containing the codon(s) for this amino acid.
     * @return a vector containing the amino acid.
     */
    std::vector<std::string> getCodons();

    //mutator functions

    /**
     * Set the amino acid name
     * @param name the name
     */
    void setName(const std::string name);

    /**
     * Set the three leter name for the amino acid
     * @param threeLetterName the three letter name
     */
    void setThreeLetterName(const std::string threeLetterName);

    /**
     * Sets the molar mass.
     * Units: g/mol     *
     */
    void getMolarMass(const double molarMass);

    /**
     * Set the codon(s) for the amino acid
     * @param codons the codons for this amino acid.
     */
    void setCodons(const std::vector<std::string> codons);

  private:
    std::string name;
    std::string threeLetterName;
    double molarMass;
    std::vector<std::string> codons;

};
#endif
