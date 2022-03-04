# H1 C언어(코드블럭)을 이용한 랜덤학생성적프로그램
많은 학생들의 성적을 보다 간단하고, 편하게 관리 수정을할 수 있게 만든
프로그램입니다.

1. 랜덤학생 성적입력 
2. 출력
3. 검색
4. 종료
5. 화면초기화
6. 성적초기화
7. 수정
8. 정렬
9. 삽입
9가지 기능을 이용하여 메뉴를 만들었습니다.

## H2 각 메뉴의 중요 기능 살펴보기
이름, 학번, 성적 등급 등등 구조체를 선언하여 기능을 좀더 간결성 향상에 도움을 주었습니다.
1. 랜덤성적 입력
for문을 이용하여 등록할 랜덤학생을 구하였습니다.
ASCII코드 10진수를 참고하여 랜덤값을 구하였습니다.
```
    int i = 0;
    for(i = 0; i < total_count; i ++){
        student[i].name[0] = rand() %(25-0+1)+0+'A';
        student[i].name[1] = rand() %(25-0+1)+0+'A';
        student[i].name[2] = rand() %(25-0+1)+0+'A';
```
2.  등급
따로 메뉴에는 없지만 점수 평균에 따라 등급을 매기는 함수를 따로 선언하였습니다.
```
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
```
3. 검색
 입력된 학생을 콕 집어 한명을 검색하고 싶을때 사용하는 기능입니다.
 학생 이름을 입력할때 대소문자 구분없이 검색할 수 있게 string 헤더파일을 추가하였습니다.
 ```
 for(i = 0; i < total_count; i++){
        if(!strnicmp(&student[i].name[0], &name[0], 3)){
            score_print(student[i].name, 1);
            find_flag = 1;
```
8. 정렬
성적을 받을 수 있는 STU copy_student[total_count]를 선언하여
오름차순 내림차순 기능을 만들었습니다.

```
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
```

