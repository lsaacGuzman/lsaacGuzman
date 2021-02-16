//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef DNAStrand_H
#define DNAStrand_H

#include <iostream>

class DNAStrand {
public:

    /**
     * @brief DNAStrand Builds a DNAStrand using the given C-String
     * @param startingString A null terminated char array
     *
     * Throws a logic_error exception if the startingString contains anything but A, C, G, or T
     */
    DNAStrand(const char* startingString);

    /**
     * @brief DNAStrand Copy Ctor
     * @param other DNAStrand to copy
     */
    DNAStrand(const DNAStrand& other);

    /**
     * @brief operator = Assignment Operator for DNAStrand
     * @param other DNAStrand to duplicate
     * @return Reference to the string that was copied into
     */
    DNAStrand& operator=(const DNAStrand& other);

    /**
      * @brief Destructor
      */
    ~DNAStrand();

    /**
     * @brief operator == Check if two DNAStrands have same contents
     * @param other DNAStrand to compate to
     * @return true if identical, false if not
     */
    bool operator==(const DNAStrand& other) const;

    /**
     * @brief operator [] Access individual nucleotide from DNAStrand
     * @param index location to access
     * @return char value at index. Not returned by referece - no write access
     *
     * Throws an out_of_range exception if the index is less than 0 or too large
     */
    char operator[](int index) const;

    /**
     * @brief operator + Combine two DNAStrands
     * @param other DNAStrand to merge with this
     * @return DNAStrand with contents of current DNAStrand followed by contents of other
     */
    DNAStrand operator+(const DNAStrand& other) const;

    //Declare as friend... declared after class
    friend std::ostream& operator<<(std::ostream& dest, const DNAStrand& source);

    /**
     * @brief getLength gets length of string
     * @return length
     */
    int getLength() const;

    /**
     * @brief getComplement gets Complement of the DNAStrand
     * @return DNAStrand that is complement of this
     *
     * The complement is the DNAStrand that pairs with this one to make a double strand.
     * Any A's in originals must become T's in complement and vice verse
     * C's become G's and vice verse.
     *
     * Original:    ACCTG
     * Complement:  TGGAC
     */
    DNAStrand getComplement() const;

    /**
     * @brief substr Gets a DNAStrand that contains the requested portion of a DNAStrand
     * @param start index of first base to grab
     * @param length number of bases to include
     * @return DNAstrand
     *
     * Throws an out_of_range exception if the index or length are less than 0
     *      or start + length end up past the end of the array
     */
    DNAStrand substr(int start, int length) const;


private:
    /**
     * @brief DNAStrand Helper ctor - use in other functions to make a DNAStrand of given size that
     *          then can be modified
     * @param length Size DNA String to create
     */
    DNAStrand(int length);

    char* bases = nullptr;   ///Tracks array contining a char array
    int length = 0;         ///Length of the char array and DNAStrand
};

/**
 * @brief operator << Output a DNAStrand
 * @param dest stream to output to
 * @param source DNAStrand to output
 * @return dest stream returned by reference for chaining of <<
 */
std::ostream& operator<<(std::ostream& dest, const DNAStrand& source);

#endif
