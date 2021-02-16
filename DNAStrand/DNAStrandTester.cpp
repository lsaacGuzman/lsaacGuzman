//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------
//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include <sstream>

//Include your .h files
#include "DNAStrand.h"

using namespace std;

TEST_CASE( "Basic Constructor, getLength" ) {
    cout << "1: Basic Contructor & getLength..." << endl;
    //This does NOT test to see if constructor stores the correct chars, just if it sets length

    DNAStrand str1("ACGTAGCT");
    REQUIRE( str1.getLength() == 8 );

    DNAStrand str2("AACC");
    REQUIRE( str2.getLength() == 4 );
}


//TEST_CASE( "Basic Constructor, ==" ) {
//    cout << "2: Basic Contructor & ==..." << endl;

//    //Verify constructor actually stores the correct data
//    DNAStrand str1("ACGTAGCT");

//    //If you put the == inside the REQUIRE it will not compile without <<
//    bool isMatch = (str1 == DNAStrand("ACGTAGCT"));
//    REQUIRE( isMatch );


//    DNAStrand str2("AACC");
//    bool isMatch2 = (str2 == DNAStrand("AACC"));
//    bool isMatch3 = (str2 == DNAStrand("AAGC"));
//    REQUIRE( isMatch2 );
//    REQUIRE( !isMatch3 );
//}


TEST_CASE( "==" ) {
    cout << "3: More == tests..." << endl;

    DNAStrand str("AACC");
    //Make sure unequal length stands don't cause == issues
    bool isMatch1 = (str == DNAStrand("AAC"));
    bool isMatch2 = (str == DNAStrand("AACCT"));
    REQUIRE( !isMatch1 );
    REQUIRE( !isMatch2 );

}


//TEST_CASE( "Copy constructor" ) {
//    cout << "4: Copy constructor..." << endl;
//    DNAStrand str1("ACGTAGCT");

//    {
//        //new scope
//        DNAStrand str2(str1);   //Call copy ctor
//        bool isMatch = (str1 == str2);
//        REQUIRE( isMatch );
//        //str2 goes away when we leave this block...
//    }

//    bool isMatch2 = (str1 == DNAStrand("ACGTAGCT"));
//    REQUIRE( isMatch2 );
//}

//TEST_CASE( "Assignment Operator" ) {
//    cout << "5: Assignment Operator..." << endl;
//    DNAStrand str1("ACGTAGCT");

//    {
//        //new scope
//        DNAStrand str2("AA");
//        str2 = str1;            //Use assignment op

//        bool isMatch = (str2 == DNAStrand("ACGTAGCT"));
//        REQUIRE( isMatch );
//        //str2 goes away when we leave this block...
//    }

//    //Make sure str1 was not changed
//    bool isMatch2 = (str1 == DNAStrand("ACGTAGCT"));
//    REQUIRE( isMatch2 );

//    //Verify self-assignment does no harm:
//    {
//        str1 = str1;
//    }
//    bool isMatch3 = (str1 == DNAStrand("ACGTAGCT"));
//    REQUIRE( isMatch3 );
//}

TEST_CASE( "operator[]" ) {
    cout << "6: Operator []..." << endl;
    DNAStrand str1("ACGTACGTACGT");
    REQUIRE( str1[0] == 'A' );
    REQUIRE( str1[5] == 'C' );

    DNAStrand str2("TTTT");
    REQUIRE( str2[0] == 'T' );
    REQUIRE( str2[2] == 'T' );

    //Check that excpetion is thrown if bad index provided
    int exceptionsCaught = 0;

    try {
        char c = str2[-1];
    } catch (out_of_range e) {
        exceptionsCaught++;
    }

    try {
        char c = str2[4];
    } catch (out_of_range e) {
        exceptionsCaught++;
    }

    REQUIRE( exceptionsCaught == 2 );
}


TEST_CASE( "operator+" ) {
    cout << "7: Operator +..." << endl;
    DNAStrand str1("AATT");
    DNAStrand str2("CCGG");
    DNAStrand str3 = str1 + str2;

    bool isMatch = (str3 == DNAStrand("AATTCCGG"));
    REQUIRE( isMatch );

    //Check originals aren't broken
    bool isMatch2 = (str1 ==  DNAStrand("AATT"));
    bool isMatch3 = (str2 ==  DNAStrand("CCGG"));
    REQUIRE( isMatch2 );
    REQUIRE( isMatch3 );
}


//TEST_CASE( "getComplement" ) {
//    cout << "8: getComplement..." << endl;
//    DNAStrand str1("ACTGG");
//    DNAStrand str2 = str1.getComplement();
//    bool isMatch1 = (str2 ==  DNAStrand("TGACC"));
//    REQUIRE( isMatch1 );

//    DNAStrand str3 = str2.getComplement();  //should be back where we started
//    bool isMatch2 = (str3 ==  DNAStrand("ACTGG"));
//    REQUIRE( isMatch2 );
//}


//TEST_CASE( "Operator <<" ) {
//    cout << "9: Operator <<..." << endl;
//    DNAStrand str1("AAC");
//    DNAStrand str2("GT");

//    stringstream result;
//    result << str1 << " " << str2;

//    REQUIRE( result.str() == "AAC GT" );
//}



//TEST_CASE( "substr" ) {
//    cout << "10: substr..." << endl;
//    DNAStrand str1("AACCGGTT");

//    DNAStrand str2 = str1.substr(0,1);
//    bool isMatch2 = (str2 ==  DNAStrand("A"));
//    REQUIRE( isMatch2 );

//    DNAStrand str3 = str1.substr(0,3);
//    bool isMatch3 = (str3 ==  DNAStrand("AAC"));
//    REQUIRE( isMatch3 );

//    DNAStrand str4 = str1.substr(2,4);
//    bool isMatch4 = (str4 ==  DNAStrand("CCGG"));
//    REQUIRE( isMatch4 );

//    DNAStrand str5 = str1.substr(2,6);
//    bool isMatch5 = (str5 ==  DNAStrand("CCGGTT"));
//    REQUIRE( isMatch5 );


//    int exceptionsCaught = 0;

//    try {
//        //Check bad start
//        str1.substr(-1,4);
//    } catch (out_of_range e) {
//        exceptionsCaught++;
//    }

//    try {
//        //Check bad length
//        str1.substr(3, -1);
//    } catch (out_of_range e) {
//        exceptionsCaught++;
//    }

//    try {
//        //Check start + length invalid
//        str1.substr(3, 6);
//   } catch (out_of_range e) {
//        exceptionsCaught++;
//    }

//    REQUIRE( exceptionsCaught == 3 );
//}

