
/* FILE NAME: project2_Banister_jnb0047
* AUTHOR: Jess Banister
* SOURCES: Project 2 hints pdf, Codecademy for the booleans,
* and lectures for rand utilization and formatting.
*/
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

//VARIABLES
const int A_acc = 33;
const int B_acc = 55;
/*
* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){
    if (A_alive & B_alive) {
        return true;
    }
    else if (B_alive & C_alive) {
        return true;
    }
    else if (A_alive & C_alive) {
        return true;
    }
    else {
        return false;
    }
    return false;
}
/*
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive){
    int shoot_target_result;
    shoot_target_result = rand() % 100;

    if (shoot_target_result < A_acc) {
        if (C_alive) {
            C_alive = false;
        }
        else {
            B_alive = false;
        }
    }
}
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* C_alive indicates Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change C_alive into false if Charlie is killed
*/
void Bob_shoots(bool& A_alive, bool& C_alive){
    int shoot_target_result;
    shoot_target_result = rand() % 100;

    if (shoot_target_result < B_acc) {
        if (C_alive) {
            C_alive = false;
        }
        else {
            A_alive = false;
        }
    }
}
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change B_alive into false if Bob is killed
*/
void Charlie_shoots(bool& A_alive, bool& B_alive){
    if (B_alive) {
        B_alive = false;
    }
    else {
        A_alive = false;
    }
}
/*
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive){
    if (!B_alive || !C_alive) {
        int shoot_target_result = rand() % 100;
        if (shoot_target_result < A_acc) {
            if (C_alive) {
                C_alive = false;
            }
            else {
                B_alive = false;
            }
        }
    }
}
//Simple method to implement pause function in linux
void Press_any_key(void){
    cout << "Press Enter to continue...";
    //Pause Command for Linux Terminal
    cin.ignore().get();
}

//TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

//VARIABLES CONTINUED
const int TOTAL_RUNS = 10000;
bool A_alive;
bool B_alive;
bool C_alive;
bool two_alive;
int aaronWins;
int bobWins;
int charlieWins;
int aaronWins2;
int bobWins2;
int charlieWins2;


int main() {
    //Initializes Random number generator's seed and calls test functions
    cout << "*** Welcome to Jess' Duel Simulator ***\n";
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    srand(time(0));
    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();
    
    //Starts strategy 1 and runs 10,000 times
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    Press_any_key();
    for (int i = 0; i < TOTAL_RUNS; i++ ){// duel start
        bool a_Alive = true;
        bool b_Alive = true;
        bool c_Alive = true;
        while (at_least_two_alive(a_Alive, b_Alive, c_Alive)) {
            if (a_Alive) {
                Aaron_shoots1(b_Alive, c_Alive);
            }
            if (b_Alive) {
                Bob_shoots(a_Alive, c_Alive);
            }
            if (c_Alive) {
                Charlie_shoots(a_Alive, b_Alive);
            }
        }
        if (a_Alive) {
            aaronWins++;
        }
        if (b_Alive) {
            bobWins++;
        }
        else {
            charlieWins++;
        }
    }
    cout << "Aaron won " << aaronWins << "/10000 duels or " << static_cast<double>(aaronWins) / TOTAL_RUNS * 100 << "%\n"
    << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
    << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
    << endl;
        
    //Starts strategy 2 and runs 10,000 times
    cout << "Ready to test strategy 2 (run 10000 times):\n";
    Press_any_key();
    for (int i = 0; i < TOTAL_RUNS; i++ ){
        bool a_Alive = true;
        bool b_Alive = true;
        bool c_Alive = true;
        while (at_least_two_alive(a_Alive, b_Alive, c_Alive)) {
            if (a_Alive) {
                Aaron_shoots2(b_Alive, c_Alive);
            }
            if (b_Alive) {
                Bob_shoots(a_Alive, c_Alive);
            }
            if (c_Alive) {
                Charlie_shoots(a_Alive, b_Alive);
            }
        }
        if (a_Alive) {
            aaronWins2++;
        }
        if (b_Alive) {
            bobWins2++;
        }
        if (c_Alive) {
            charlieWins2++;
        }
    }
    cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"
    << "Bob won " << bobWins2 << "/10000 duels or " << static_cast<double>(bobWins2) / TOTAL_RUNS * 100 << "%\n"
    << "Charlie won " << charlieWins2 << "/10000 duels or " << static_cast<double>(charlieWins2) / TOTAL_RUNS * 100 << "%\n"
    << endl;
    
    if (aaronWins > aaronWins2) {
        cout << "Strategy 1 is better than strategy 2.\n";
    }
    else if (aaronWins < aaronWins2) {
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    return 0;
}

//Test function for at_least_two_alive()
void test_at_least_two_alive(void) {
cout << "Unit Testing 1: Function - at_least_two_alive()\n";
cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
assert(true == at_least_two_alive(true, true, true));
cout << "\t\tCase passed ...\n";
cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
assert(true == at_least_two_alive(false, true, true));
cout << "\t\tCase passed ...\n";
cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
assert(true == at_least_two_alive(true, false, true));
cout << "\t\tCase passed ...\n";
cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
assert(true == at_least_two_alive(true, true, false));
cout << "\t\tCase passed ...\n";
cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
assert(false == at_least_two_alive(false, false, true));
cout << "\t\tCase passed ...\n";
cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
assert(false == at_least_two_alive(false, true, false));
cout << "\t\tCase passed ...\n";
cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
assert(false == at_least_two_alive(true, false, false));
cout << "\t\tCase passed ...\n";
cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
assert(false == at_least_two_alive(false, false, false));
cout << "\t\tCase passed ...\n";
}

//Test function for Aaron_shoots1()
void test_Aaron_shoots1(void) {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    B_alive = true;
    C_alive = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    assert(true == B_alive);
    B_alive = false;
    C_alive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    assert(false == B_alive);
    B_alive = true;
    C_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n"
    << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(B_alive, C_alive);
    assert(false == C_alive);
}

//Test function for Bob_shoots()
void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    A_alive = true;
    C_alive = true;
    cout << "\tCase 1: Aaron alive, Charlie alive\n"
    << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);
    assert(true == A_alive);
    A_alive = false;
    C_alive = true;
    cout << "\tCase 2: Aaron dead, Charlie alive\n"
    << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);
    assert(false == A_alive);
    A_alive = true;
    C_alive = false;
    cout << "\tCase 3: Aaron alive, Charlie dead\n"
    << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(A_alive, C_alive);
    assert(false == C_alive);
}

//Test function for Charlie_shoots()
void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    A_alive = true;
    B_alive = true;
    cout << "\tCase 1: Aaron alive, Bob alive\n"
    << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(A_alive, B_alive);
    assert(true == A_alive);
    A_alive = false;
    B_alive = true;
    cout << "\tCase 2: Aaron dead, Bob alive\n"
    << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(A_alive, B_alive);
    assert(false == A_alive);
    A_alive = true;
    B_alive = false;
    cout << "\tCase 3: Aaron alive, Bob dead\n"
    << "\t\tCharlie is shooting at Aaron\n";
    Charlie_shoots(A_alive, B_alive);
    assert(false == C_alive);
}

//Test function for Aaron_shoots2()
void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    B_alive = true;
    C_alive = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n"
    << "\t\tAaron intentionally misses his first shot\n"
    << "\t\tBoth Bob and Charlie are alive\n";
    Aaron_shoots2(B_alive, C_alive);
    assert(true == B_alive);
    assert(true == C_alive);
    B_alive = false;
    C_alive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(B_alive, C_alive);
    assert(false == B_alive);
    B_alive = true;
    C_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n"
    << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots2(B_alive, C_alive);
    assert(false == C_alive);
}

