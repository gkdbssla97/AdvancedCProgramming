//
// Created by 하윤 on 2021/12/18.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct person {
    char *Name;
    char *Phone_num;
    char *Birth;
    struct person *next;
};
struct person * c;

int registration(struct person **list, int cnt, int max);
void showall(struct person *list, int cnt);
int delete(struct person **list, int cnt);
void findbirth(struct person *list, int cnt);

int main(void){ // main 함수는 수정 없이 그대로 사용
    int in, cnt=0, max;
    struct person *list=NULL;
    printf("Max_num:"); // 불필요한 코드이지만, 삭제하면 안 됨
    scanf("%d", &max);// 불필요한 코드이지만, 삭제하면 안 됨
    getchar();
    while(1){
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &in);
        getchar();
        switch(in){
            case 1:
                cnt=registration(&list, cnt, max);
                break;
            case 2:
                showall(list, cnt);
                break;
            case 3:
                cnt=delete(&list, cnt);
                break;
            case 4:
                findbirth(list, cnt);
                break;
            default:
                break;
        } if (!(in>0&&in<5))
            break;
    }
    return 0;
}
int registration(struct person **list, int cnt, int max){
    char name[101], p_num[101], birth[101];
    struct person *new, *p = *list, *q = *list;
    new = (struct person *)malloc(sizeof(struct person));
    new->next = NULL;
    if (cnt<max){ // 불필요한 코드이지만, 삭제하면 안 됨
        // new_node 만들기 & new_node에 고객 정보 입력
        // new_node 고객 정보를 연결 할 위치 탐색
        // 고객의 이름 순으로 적절한 위치에 new_node 연결
        // 4가지 경우 고려
        // (1) 첫 번째 등록 고객인 경우
        // (2) 연결할 위치가 list의 첫 번째 위치인 경우
        // (3) 연결할 위치가 list의 중간 위치인 경우
        // (4) 연결할 위치가 list의 마지막 위치인 경우
        // ccnt 값 수정 & 출력
        printf("Name:");
        scanf("%s", name);
        getchar();
        printf("Phone_number:");
        scanf("%s", p_num);
        getchar();
        printf("Birth:");
        scanf("%s", birth);
        getchar();

        int len = strlen(name);
        new->Name = (char *) malloc((len + 1) * sizeof(char));
        //new->Name = name;
        strcpy(new->Name, name);
        len = strlen(p_num);
        new->Phone_num = (char *) malloc((len + 1) * sizeof(char));
        //new->Phone_num = p_num;
        strcpy(new->Phone_num, p_num);
        len = strlen(birth);
        new->Birth = (char *) malloc((len + 1) * sizeof(char));
        //new->Birth = birth;
        strcpy(new->Birth, birth);

        if(*list == NULL) {
            //new->next = p;
            *list = new;
            (*list)->next = NULL;
            cnt++;
        }
        else {
            if (strcmp(p->Name, new->Name) > 0 && p == *list) {
                //printf("name:%s\n",p->Name);
                (*list) = new;
                (*list)->next = p;
            }
            else {
                int flag = 0;
                for (int i = 0; i < cnt; i++, p = p->next) {
                    if (strcmp(p->Name, new->Name) > 0) {
                        flag = 1;
                        q->next = new;
                        new->next = p;
                        //p->next = NULL;
                        break;
                    }
                    q = p;
                }
                if (flag == 0) {
                    q->next = new;
                    //new->next = NULL;
                }
            }
            cnt++;
        }
        printf("<<%d>>\n", cnt);
    } else // 불필요한 코드이지만, 삭제하면 안 됨
        printf("OVERFLOW\n");

    return cnt;
}
void showall(struct person *list, int cnt){
    struct person * p = list;
    for(int i = 0; i < cnt; i++, p = p->next)
        printf("%s %s %s\n", p->Name, p->Phone_num, p->Birth);
}
int delete(struct person **list, int cnt) { // 삭제할 고객 정보의 위치 찾기
    // 삭제할 고객의 앞 node의 next를 삭제할 고객의 다음 고객에 연결
    // 삭제할 고객의 정보를 저장한 메모리를 free
    char name[101];
    if(cnt == 0) {
        printf("NO MEMBER\n");
        return cnt;
    }
    printf("Name:");
    scanf("%s", name);
    getchar();
    struct person *p = (*list);
    struct person *remove = (*list);
    struct person *q;

    int flag = 0;
    for(int i = 0; i < cnt; i++, remove = remove->next) {
        if (strcmp(remove->Name, name) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) return cnt;
    if(*list == remove) {
        if(cnt == 1) {
            free(remove);
            cnt--;
            return cnt;
        }
        else {
            *list = (*list)->next;
            free(remove);
            cnt--;
            return cnt;
        }
    } else {
        for(int i = 0; i < cnt; i++, p = p->next) {
            if (p == remove) {
                q->next = remove->next;
                free(remove);
                cnt--;
                return cnt;
            } q = p;
        }
    }
    return cnt;
}
void findbirth(struct person *list, int cnt) {
    int num;
    printf("Birth:");
    scanf("%d", &num);
    getchar();

    char month[2] = {0,};
    for(int i = 0; i < cnt; i++, list = list->next) {
        month[0] = list->Birth[4];
        month[1] = list->Birth[5];
        int ctod = atoi(month);
        if(ctod == num) {
            printf("%s %s %s\n", list->Name, list->Phone_num,
                   list->Birth);
            //break;
        }
    }
}


