#include <stdio.h>
#include <string.h>

// ===================== BACK END =====================
struct Question {
    char question[200];
    char options[4][100];
    int correctOption;
};

// Function to load all quiz questions
int loadQuestions(struct Question quiz[]) {
    // Question 1
    strcpy(quiz[0].question, "What is the capital of India?");
    strcpy(quiz[0].options[0], "Mumbai");
    strcpy(quiz[0].options[1], "New Delhi");
    strcpy(quiz[0].options[2], "Kolkata");
    strcpy(quiz[0].options[3], "Chennai");
    quiz[0].correctOption = 2;

    // Question 2
    strcpy(quiz[1].question, "Who developed the C programming language?");
    strcpy(quiz[1].options[0], "Bjarne Stroustrup");
    strcpy(quiz[1].options[1], "Dennis Ritchie");
    strcpy(quiz[1].options[2], "James Gosling");
    strcpy(quiz[1].options[3], "Guido van Rossum");
    quiz[1].correctOption = 2;

    // Question 3
    strcpy(quiz[2].question, "Which symbol is used for single-line comments in C?");
    strcpy(quiz[2].options[0], "//");
    strcpy(quiz[2].options[1], "/* */");
    strcpy(quiz[2].options[2], "#");
    strcpy(quiz[2].options[3], "--");
    quiz[2].correctOption = 1;

    // Question 4
    strcpy(quiz[3].question, "Which data type is used to store a single character in C?");
    strcpy(quiz[3].options[0], "char");
    strcpy(quiz[3].options[1], "int");
    strcpy(quiz[3].options[2], "float");
    strcpy(quiz[3].options[3], "double");
    quiz[3].correctOption = 1;

    // Question 5
    strcpy(quiz[4].question, "What is the output of 5 + 3 * 2 in C?");
    strcpy(quiz[4].options[0], "16");
    strcpy(quiz[4].options[1], "11");
    strcpy(quiz[4].options[2], "13");
    strcpy(quiz[4].options[3], "10");
    quiz[4].correctOption = 2;

    // Question 6
    strcpy(quiz[5].question, "Which header file is used for input and output in C?");
    strcpy(quiz[5].options[0], "stdio.h");
    strcpy(quiz[5].options[1], "conio.h");
    strcpy(quiz[5].options[2], "stdlib.h");
    strcpy(quiz[5].options[3], "string.h");
    quiz[5].correctOption = 1;

    // Question 7
    strcpy(quiz[6].question, "Which loop is guaranteed to execute at least once?");
    strcpy(quiz[6].options[0], "for");
    strcpy(quiz[6].options[1], "while");
    strcpy(quiz[6].options[2], "do-while");
    strcpy(quiz[6].options[3], "if");
    quiz[6].correctOption = 3;

    // Question 8
    strcpy(quiz[7].question, "Which keyword is used to return a value from a function?");
    strcpy(quiz[7].options[0], "break");
    strcpy(quiz[7].options[1], "continue");
    strcpy(quiz[7].options[2], "exit");
    strcpy(quiz[7].options[3], "return");
    quiz[7].correctOption = 4;

    // Question 9
    strcpy(quiz[8].question, "Which operator is used to compare two values in C?");
    strcpy(quiz[8].options[0], "=");
    strcpy(quiz[8].options[1], "==");
    strcpy(quiz[8].options[2], "!=");
    strcpy(quiz[8].options[3], "&&");
    quiz[8].correctOption = 2;

    // Question 10
    strcpy(quiz[9].question, "Which of these is a logical operator in C?");
    strcpy(quiz[9].options[0], "&");
    strcpy(quiz[9].options[1], "||");
    strcpy(quiz[9].options[2], "%");
    strcpy(quiz[9].options[3], "$");
    quiz[9].correctOption = 2;

    return 10; // total number of questions
}

// Function to check answer
int checkAnswer(int userChoice, int correctOption) {
    return userChoice == correctOption;
}

// ===================== FRONT END =====================
void displayQuestion(struct Question q, int qNumber) {
    int i;
    printf("\nQuestion %d: %s\n", qNumber + 1, q.question);
    for (i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, q.options[i]);
    }
}

int main() {
    struct Question quiz[20];
    int totalQuestions = loadQuestions(quiz);
    int score = 0, choice, i;

    printf("====================================\n");
    printf("        WELCOME TO QUIZ GAME        \n");
    printf("====================================\n");

    for (i = 0; i < totalQuestions; i++) {
        displayQuestion(quiz[i], i);
        printf("Enter your answer (1-4): ");
        scanf("%d", &choice);

        if (checkAnswer(choice, quiz[i].correctOption)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %s\n", quiz[i].options[quiz[i].correctOption - 1]);
        }
    }

    printf("\n====================================\n");
    printf("           QUIZ FINISHED!           \n");
    printf("====================================\n");
    printf("Your Final Score: %d / %d\n", score, totalQuestions);

    if (score == totalQuestions)
        printf("Excellent!\n");
    else if (score >= totalQuestions / 2)
        printf("Good job!\n");
    else
        printf("Better luck next time!\n");

    return 0;
}
