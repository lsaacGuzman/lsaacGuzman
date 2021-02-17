/**
* @brief DNA Strand
* @name Gerardo Isaac Guzman
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
# include "DNAStrand.h"


DNAStrand::DNAStrand(int length){
    this->length = length;
    bases = new char[length];
}

DNAStrand::DNAStrand(const char* startingString){
    this->length = static_cast<int>(strlen(startingString));
    this->bases = new char[length];
    for (int i = 0;i<length;i++){
        bases[i] = startingString[i];
    }

}

DNAStrand::DNAStrand(const DNAStrand& other){

    length = other.length;

    bases = new char[length];
    for(int i = 0; i< length; i++){
        bases[i] = other.bases[i];
    }

}

DNAStrand& DNAStrand::operator=(const DNAStrand& other){
    if (this != &other){
        delete [] bases;
        length = other.length;


        bases = new char[length];
        for(int i = 0; i< length; i++){
            bases[i] = other.bases[i];
        }
    }
    return *this;
}

DNAStrand::~DNAStrand(){

    delete[] bases;
    bases = nullptr;
}

bool DNAStrand::operator==(const DNAStrand& other)const{
    if (length != other.length){
        return false;
    }

    for (int i = 0; i<length; i++){

        if (bases[i] != other.bases[i])
            return false;
    }
    return true;
}

char DNAStrand::operator[](int index)const{
    if (index < 0 || index >= length){

        throw out_of_range("Index out of Range");

    }

    return bases[index];

}

DNAStrand DNAStrand::operator+(const DNAStrand& other) const{

    int counter = 0;
    DNAStrand combo(this->getLength()+ other.getLength());


    for (int i = 0; i<this->getLength(); i++,counter++){
        combo.bases[counter] = bases[i];

    }
    for (int i = 0; i<other.getLength(); i++,counter++){
        combo.bases[counter] = other.bases[i];
    }

    return combo;
}

int DNAStrand::getLength() const{
    return this->length;
}
DNAStrand DNAStrand::getComplement() const{
    DNAStrand complement(length);

    for (int i = 0; i < length; i++){
        if (bases [i] == 'A'){
            complement.bases[i] = 'T';
        }
        else if (bases [i] == 'T'){
            complement.bases[i] = 'A';
        }
        else if (bases [i] == 'C'){
            complement.bases[i] = 'G';
        }
        else if (bases [i] == 'G'){
            complement.bases[i] = 'C';
        }

//                switch(bases[i])
//                {
//                case 'A': complement.bases[i] = 'T';
//                case 'T': complement.bases[i] = 'A';
//                case 'C': complement.bases[i] = 'G';
//                case 'G': complement.bases[i] = 'C';
//                }

    }
    return complement;

}

DNAStrand DNAStrand::substr(int start, int length)const{
    if (start < 0 || length < 0 || (start+length) > this->length){
        throw std::out_of_range ("Substring is invalid");
    }
    DNAStrand SubString(length);
    int counter = start;
    for (int i = 0; i < length; i++,counter++){
        SubString.bases[i] = this->bases[counter];
    }

    return SubString;

}
std::ostream& operator<<(std::ostream& dest, const DNAStrand& source){



    for (int i = 0; i <source.getLength();i++){
        dest << source.bases[i];
    }

    return dest;

}





