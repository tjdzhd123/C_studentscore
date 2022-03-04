#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define DIVIDE 3

struct info_edu{

    char name[10];
    int id;
    int gender;
    int c;
    int java;
    int kotlin;
    int total;
    double avr;
    char grade;

};

typedef struct info_edu STU;
int total_count = 0;
void input_score(STU *student);
char grade_value(double avr);
void score_print(STU *student, int count);
void search_score(STU *student);
void remove_score(STU *student);
void update_score(STU *student);
void sort_score(STU *student);
void insert_score(STU *student);

int main()
{
    int menu = 0;
    int flag = 0;
    STU student[MAX_SIZE];

    printf("등록할 학생 수 :");
    scanf("%d", &total_count);

    while(!flag){
        printf("1. 성적입력(랜덤) \t");
        printf("2. 성적출력 \t");
        printf("3. 성적검색 \n");
        printf("4. 프로그램 종료 \t");
        printf("5. 화면초기화 \t");
        printf("6. 성적초기화 \n");
        printf("7. 성적수정 \t");
        printf("\t8. 성적정렬 \t");
        printf("9. 성적삽입 \n");
        printf("메뉴선택 : ");
        scanf("%d", &menu);

        switch(menu){
            case 1 : input_score(student);
                      getchar();
                      getchar();
                      system("cls"); break;
            case 2 : score_print(student, total_count);
                      getchar();
                      getchar();
                      system("cls"); break;
            case 3 : search_score(student);
                      getchar();
                      getchar();
                      system("cls"); break;
            case 4 : flag = 1; break;
            case 5 : printf("**화면초기화 완료** \n");
                      system("cls"); break;
            case 6 : remove_score(student);
                      getchar();
                      getchar();
                      system("cls"); break;
            case 7 : update_score(student);
                      getchar();
                      getchar();
                      system("cls"); break;
            case 8 :  sort_score(student);
                      getchar();
                      getchar();
                      system("cls"); break;
            case 9 : insert_score(student);
                      getchar();
                      getchar();
                      system("cls"); break;
            default : printf("다시 입력하세요 \n");
        }
    }

    return 0;
}

void input_score(STU *student){
    int i = 0;
    for(i = 0; i < total_count; i ++){
        student[i].name[0] = rand() %(25-0+1)+0+'A';
        student[i].name[1] = rand() %(25-0+1)+0+'A';
        student[i].name[2] = rand() %(25-0+1)+0+'A';

        student[i].id = rand() %(999-100+1)+100;
        student[i].gender = rand() %(1-0+1)+0;
        student[i].c = rand() %(100-0+1)+0;
        student[i].java = rand() %(100-0+1)+0;
        student[i].kotlin = rand() %(100-0+1)+0;

        student[i].total = student[i].c+ student[i].java+ student[i].kotlin;
        student[i].avr = student[i].total / (double) DIVIDE;

        student[i].grade = grade_value(student[i].avr);
    }
    printf("**성적입력 완료** \n");
    return;
}

char grade_value(double avr){
    char grade = 0;
    if(avr > 90.0){
        grade = 'A';
    }else if(avr >= 80.0 && avr < 90.0){
        grade = 'B';
    }else if(avr >= 70.0 && avr < 80.0){
        grade = 'C';
    }else if(avr >= 60.0 && avr < 70.0){
        grade = 'D';
    }else{
        grade = 'F';
    }
    return grade;
}

void score_print(STU *student, int count){
    int i = 0;

    for(i = 0; i < count; i++){
        printf("%5d %5s %5d %5s %5d %5d %5d %5d %10.2lf %5c \n", i+1, student[i].name,
               student[i].id, (student[i].gender==1)? "남":"여", student[i].c,
               student[i].java, student[i].kotlin, student[i].total, student[i].avr,
               student[i].grade);
    }
    return;
}

void search_score(STU *student){
    int i = 0;
    int find_flag = 0;
    char name[10] = "";

    printf("검색할 학생을 입력하세요.(대소문자 구별 없음) :");
    scanf("%s", &name[0]);

    for(i = 0; i < total_count; i++){
        if(!strnicmp(&student[i].name[0], &name[0], 3)){
            score_print(student[i].name, 1);
            find_flag = 1;
            printf("**검색 완료**\n ");
        }
    }

    if(!find_flag){
        printf("검색할 학생이 없습니다. \n");
    }
    return;
}

void remove_score(STU *student){
    int i = 0;
    int find_flag = 0;
    char name[10] = "";

    printf("삭제할 학생을 입력하세요. (대소문자 구별 없음) :");
    scanf("%s", &name[0]);

    for(i = 0; i < total_count; i ++){
         if(!strnicmp(&student[i].name[0], &name[0], 3)){
            strcpy(&student[i].name[0], "");
            student[i].id = 0;
            student[i].c = 0;
            student[i].java = 0;
            student[i].kotlin = 0;

            student[i].total = student[i].c+ student[i].java+ student[i].kotlin;
            student[i].avr = student[i].total / (double) DIVIDE;

            student[i].grade = grade_value(student[i].avr);
            find_flag = 1;
         }
    }
    score_print(student, name[10]);
    if(!find_flag){
        printf("삭제할 학생이 없습니다. \n");
    }else{
        printf("**학생성적 삭제완료** \n");
    }
    return;
}

void update_score(STU *student){
    int i = 0;
    int find_flag = 0;
    char name[10] = "";

    printf("수정할 학생을 입력하세요. (대소문자 구별 없음) :");
    scanf("%s", &name[0]);

    for(i = 0; i < total_count; i++){
        if(!strnicmp(&student[i].name[0], &name[0], 3)){
            printf("%s c 과목 점수(%d) 수정점수 : ", &name[0], student[i].c);
            scanf("%d", &student[i].c);
            printf("%s java 과목 점수(%d) 수정점수 : ", &name[0], student[i].java);
            scanf("%d", &student[i].java);
            printf("%s kotlin 과목 점수(%d) 수정점수 : ", &name[0], student[i].kotlin);
            scanf("%d", &student[i].kotlin);

            student[i].total = student[i].c+ student[i].java+ student[i].kotlin;
            student[i].avr = student[i].total / (double) DIVIDE;

            student[i].grade = grade_value(student[i].avr);
            find_flag = 1;
        }
    }
    if(!find_flag){
        printf("수정할 학생이 없습니다. \n");
    }else{
        printf("**성적수정 완료** \n");
    }

}

void sort_score(STU *student){
    STU copy_student[total_count];
    STU buffer_student;
    int i = 0;
    int j = 0;
    int sort = 0;

    for(i = 0; i < total_count; i++){
        memcpy(&copy_student[i], &student[i], sizeof(student[i]));
    }
    printf("오름차순(0) 내림차순(1) :");
    scanf("%d", &sort);

    if(sort==0){
        for(i = 0; i < total_count-1; i++){
            for(j = i+1;j < total_count ; j++){
                if(copy_student[i].total > copy_student[j].total){
                    memcpy(&buffer_student, &copy_student[i], sizeof(student[i]));
                    memcpy(&copy_student[i], &copy_student[j], sizeof(student[i]));
                    memcpy(&copy_student[j], &buffer_student, sizeof(student[i]));
                }
            }
        }
    }else{
        for(i = 0; i < total_count-1; i++){
            for(j = i+1;j < total_count ; j++){
                if(copy_student[i].total < copy_student[j].total){
                    memcpy(&buffer_student, &copy_student[i], sizeof(student[i]));
                    memcpy(&copy_student[i], &copy_student[j], sizeof(student[i]));
                    memcpy(&copy_student[j], &buffer_student, sizeof(student[i]));
                }
            }
        }
    }
    score_print(copy_student, total_count);
}

void insert_score(STU *student){

    if(total_count+1 >= MAX_SIZE){
        printf("사이즈 추가로 추가할 수 없습니다. \n");
        return;
    }else{
        total_count++;
        printf("삽입할 학생 이름(3자 A~Z) :");
        scanf("%s", &student[total_count-1].name[0]);
        printf("삽입할 학생 번호(4자 100~999) :");
        scanf("%d", &student[total_count-1].id);
        printf("삽입할 학생 성별(여자 : 0, 남자 : 1) :");
        scanf("%d", &student[total_count-1].gender);
        printf("삽입할 학생 c 점수(0~100) :");
        scanf("%d", &student[total_count-1].c);
        printf("삽입할 학생 java 점수(0~100) :");
        scanf("%d", &student[total_count-1].java);
        printf("삽입할 학생 kotlin 점수(0~100) :");
        scanf("%d", &student[total_count-1].kotlin);

        student[total_count-1].total = student[total_count-1].c+ student[total_count-1].java+ student[total_count-1].kotlin;
        student[total_count-1].avr = student[total_count-1].total / (double) DIVIDE;

        student[total_count-1].grade = grade_value(student[total_count-1].avr);
    }
    printf("학생추가 완료 \n");

}
