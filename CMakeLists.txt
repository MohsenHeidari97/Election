cmake_minimum_required(VERSION 3.19)
project(ElectionMain)

set(CMAKE_CXX_STANDARD 17)

add_executable(ElectionMain main.cpp Time.cpp Time.h Date.cpp Date.h Person.cpp Person.h Candidate.cpp Candidate.h Vote.cpp Vote.h VoteKiosk.cpp VoteKiosk.h Ministry.cpp Ministry.h VoteBranch.cpp VoteBranch.h CandidateState.h DateTime.cpp DateTime.h)