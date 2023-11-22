#include "grading.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct score {
    int sub_id;
    int score;
} Score;

typedef struct student {
    int id;
    Score scores[105];
    int score_idx, max_score;
} Student;

void add_score(Student *st) {
    st->scores[st->score_idx].score += 10;
}

int max(int a, int b) {
    return (a > b) * a + (a <= b) * b;
}

int cmp(const void *a, const void *b) {
    Score *sa = (Score *) a;
    Score *sb = (Score *) b;
    return sa->sub_id - sb->sub_id;
}

int cmp2(const void *a, const void *b) {
    Student *sa = (Student *) a;
    Student *sb = (Student *) b;
    return sa->id - sb->id;
}

void grading(char answer[10][maxL], Submission* sub, int num_of_submission) {
    int student_idx = 0;
    Student students[55] = {0};
    for(int i = 0; i < num_of_submission; ++i) {
        int now_idx = -1;
        for(int j = 0; j < student_idx; ++j) {
            if(students[j].id == sub[i].studentID) {
                now_idx = j;
                break;
            }
        }

        if(now_idx == -1) {
            now_idx = student_idx;
            students[student_idx].id = sub[i].studentID;
            student_idx++;
        }

        students[now_idx]
            .scores[students[now_idx].score_idx]
            .sub_id = sub[i].subID;

        for(int tc = 0; tc < 10; ++tc) {
            if(strcmp(answer[tc], sub[i].outputs[tc]) == 0) {
                add_score(&(students[now_idx]));
            }
        }
        students[now_idx].max_score = max(
            students[now_idx].max_score, 
            students[now_idx]
                .scores[students[now_idx].score_idx]
                .score
        );
        students[now_idx].score_idx++;
    }

    qsort(students, student_idx, sizeof(Student), cmp2);
    for(int i = 0; i < student_idx; ++i) {
        qsort(students[i].scores, students[i].score_idx, sizeof(Score), cmp);
    }

    for(int i = 0; i < student_idx; ++i) {
        for(int j = 0; j < students[i].score_idx; ++j) {
            printf("Student %d gets %d with Submission %d.\n", 
                students[i].id, 
                students[i].scores[j].score, 
                students[i].scores[j].sub_id
            );
        }

        printf("Student %d gets %d in this exam.\n", 
            students[i].id, 
            students[i].max_score
        );
    }
}