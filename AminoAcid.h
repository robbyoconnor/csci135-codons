/******************************************************************************
Title: AminoAcid.h
Author: Robert O'Connor
Created on: July 21, 2012
Description: Represents an Amino Acid
*******************************************************************************/
#ifndef AMINOACID_H
#define	AMINOACID_H
#include <string>

class AminoAcid{
  public:
    // default constructor
    AminoAcid();

    // allows for easy initialization of all class members
    AminoAcid(const std::string name, const std::string threeLetterName, const double molarMass);

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
    void setMolarMass(const double molarMass);

  private:
    std::string name;
    std::string threeLetterName;
    double molarMass;

};
#endif
