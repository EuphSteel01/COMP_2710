/*
 * File Name: project4_Banister_jnb0047.cpp
 * Author: Jess Banister
 * Project4
 * Sources: Stackoverflow.com, Dr. Li's lectures and slides and project hint, conversing with
 * other students
 */

//Libary imports.
#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct trivia_node {
    string question;
    string input;
    int point; // data item
    trivia_node *next; //pointer to next trivia node
};

//creates a pointer to trivia_node.
typedef trivia_node* ptr_node;


int question_num;
ptr_node final_node;

//#define UNIT_TESTING
#define trivia_quiz
// Prototypes
//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& questionList) {
    ptr_node new_ptr = new trivia_node;
    string input;
    string question;
    cout << "\nEnter a new question: ";
    getline(cin, new_ptr->question);
    cout << "Enter an answer: ";
    getline(cin, new_ptr->input);
    cout << "Enter award points: ";
    cin >> new_ptr->point;
    cin.ignore();
    final_node->next = new_ptr;
    final_node = new_ptr;
}

//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node questionList, int askNum) {
    int end = 0;
    ptr_node cur_ptr = questionList;
    if (questionList == NULL)
        return 0;
    if (askNum < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
    }
    else if (question_num < askNum) {
        cout << "Warning - There is only " << question_num << " trivia in the list.";
    }
    else {
        for (int x = 0; x < askNum; x++) {
            cout << "\nQuestion: " << cur_ptr->question << endl;
            cout << "Answer: ";
            string answer;
            getline(cin, answer);
            if (answer == cur_ptr->input) {
                cout << "Your answer is correct. You receive " << cur_ptr->point <<" points.\n";
                end += cur_ptr->point;
                cout << "Your total points: " << end << "\n";
            }
            else {
                cout << "Your answer is wrong. The correct answer is " << cur_ptr->input << "\n";
                cout << "Your total points: " << end << "\n";
            }
            cur_ptr = cur_ptr->next;
        }
    }
return 0;
}

//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& questionList) {
    //ptr_node questionList;
    //ptr_node questionList;
    question_num = 3;
    ptr_node question1 = new trivia_node;
    question1->question = "How long was the shortest war on record? (Hint: how many minutes)";
    question1->input = "38";
    question1->point = 100;
    
    ptr_node question2 = new trivia_node;
    question2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)?";
    question2->input = "Bank of Italy";
    question2->point = 50;
    questionList->next = question2;
    ptr_node question3 = new trivia_node;

    question3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    question3->input = "Wii Sports";
    question3->point = 20;
    question2->next = question3;
    final_node = question3;
}

//creates two versions.
//#define UNIT_TESTING
#define triva_quiz

int main() {
#ifdef UNIT_TESTING
    Unit_Test();
    return 0;
}
#endif

#ifdef trivia_quiz
ptr_node node_list = new trivia_node;
//Creates a new trivia game /
//Sets up three original questions/
//Sets up loop for user to input his or her own questions.
//Quiz questions are stored in liked list.
init_question_list(node_list);
cout << "*** Welcome to Jess's trivia quiz game ***\n";
string cont = "Yes";
do {
    add_question(node_list);
    question_num++;
    cout << "Continue? (Yes/No): ";
    cin >> cont;
    cin.ignore();
}
while (cont == "Yes");

// This is start of Trivia quiz game
ask_question(node_list, question_num);
cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
return 0;
}
#endif

//Test cases to check whether the methods work.
void Unit_Test() {
    ptr_node node_list1 = new trivia_node;

    init_question_list(node_list1);
    cout <<"Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list1, 0);
    cout <<"\nCase 1 passed\n\n";
    
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an\nincorrect answer." << endl;
    ptr_node node_list2 = new trivia_node;
    ask_question(node_list2, 1);
    cout << "\nCase 2.1 passed\n\n";
    
    ptr_node node_list3 = new trivia_node;
    init_question_list(node_list3);
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
    ask_question(node_list3, 1);
    cout << "\nCase 2.2 passed\n\n";
    
    ptr_node node_list4 = new trivia_node;
    init_question_list(node_list4);
    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list.";
    ask_question(node_list4, 3);
    cout << "\nCase 3 passed\n\n";
    
    ptr_node node_list5 = new trivia_node;
    init_question_list(node_list5);
    cout <<"Unit Test Case 4: Ask 5 questions in the linked list.";
    ask_question(node_list5, 5);
    cout << "\nCase 4 passed\n\n";
    
    cout << "*** End of the Debugging Version ***\n";
}
