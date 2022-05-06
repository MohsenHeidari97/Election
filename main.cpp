#include <iostream>
#include "Person.h"
#include "Candidate.h"
#include "Vote.h"
#include "Ministry.h"

using namespace std;

int main() {

//    Candidate c("Mohsen", "H", "M", "1234567890", 41, "Lisans");
//    Candidate c2("Mohammad", "S", "a", "0987654321", 45, "doctora");
//    Candidate c3("AmirAli", "J", "M", "6789054321", 46, "Ph.D");
//    Candidate c4("Hasan", "Ab", "Ghader", "55555", 50, "Diploma");
//    Candidate candidates[] = {c ,c2, c3, c4};
//    int arrSize = sizeof(candidates) / sizeof(candidates[0]);


//    Ministry m;
//    m.authenticateCandidate(candidates, arrSize, Ministry::confirm);
//    Candidate *  Ah = m.getCandidates();
//    int arrSize2 = sizeof(Ah) / sizeof(Ah[0]);

///******************************///

Ministry ministry;
ministry.showVoteBranch();


    return 0;

}