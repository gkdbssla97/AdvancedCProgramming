//
// Created by 하윤 on 2021/11/28.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct contact{
    char name[21];
    char phone[16];
    char birth[9];
} CONTACT;
int Registration(CONTACT *st, int idx);
void ShowAll(CONTACT *st, int idx);
int Delete(CONTACT * st, int idx);
void FindByBirth(CONTACT *st, int idx);
int Exit();
int main(void) {
    CONTACT st[100];

    int idx = 0;
    while(1) {
        //CONTACT tmp;
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");

        int num;
        scanf("%d", &num);
        getchar();
        if(num == 1) {
            int result = Registration(st, idx);
            if(result == 1) idx++;
        }
        if(num == 2) {
            ShowAll(st, idx);
        }
        if(num == 3) {
            int result = Delete(st, idx);
            if(result == 1) idx--;
        }
        if(num == 4) {
            FindByBirth(st, idx);
        }
        else if(num == 5)
            return Exit();
    }
}
int Registration(CONTACT *st, int idx) {
    CONTACT tmp;
    if (idx >= 100) {
        printf("OVERFLOW\n");
        return 0;
    }
    else if (idx >= 1) {
        printf("Name:"); // 고정
        scanf("%s", tmp.name);
        printf("Phone_number:"); // 고정
        scanf("%s", tmp.phone);
        printf("Birth:"); //고정
        scanf("%s", tmp.birth);
        int flag;
        for (int i = 0; i < idx; i++) {
            flag = 0;
            if (strcmp(st[i].name, tmp.name) > 0) {
                flag = 1;
                if(idx == 1)
                    st[idx] = st[0];
                else {
                    for (int j = idx - 1; j >= i; j--) {
                        st[j + 1] = st[j];
                    }
                }
                st[i] = tmp;
                //printf("tmp:\n%s %s %s\n", tmp.name, tmp.phone, tmp.birth);
                //printf("st:\n%s %s %s\n", st[i].name, st[i].phone, st[i].birth);
                break;
            }
        } if(flag == 0) st[idx] = tmp;
        idx++;
        printf("<<%d>>\n", idx);
    }
    else {
        printf("Name:"); // 고정
        scanf("%s", st[0].name);
        printf("Phone_number:"); // 고정
        scanf("%s", st[0].phone);
        printf("Birth:"); //고정
        scanf("%s", st[0].birth);
        idx++;
        printf("<<%d>>\n", idx);
    }
    return 1;
}
void ShowAll(CONTACT *st, int idx) {
    if (idx != 0) {
        //printf("idx:%d\n", idx);
        for (int i = 0; i < idx; i++)
            printf("%s %s %s\n", st[i].name, st[i].phone, st[i].birth);
    }
}
int Delete(CONTACT *st, int idx) {
    CONTACT tmp;
    if (idx == 0) {
        printf("NO MEMBER\n");
        return 0;
    }
    printf("Name:"); // 고정
    scanf("%s", tmp.name);
    for (int i = 0; i < idx; i++) {
        if (strcmp(st[i].name, tmp.name) == 0) {
            for (int j = i + 1; j < idx; j++)
                st[j - 1] = st[j];
            return 1;
        }
    } return 0;
}
void FindByBirth(CONTACT *st, int idx) {
    int month;
    printf("Birth:"); // 고정
    scanf("%d", &month);
    getchar();
    char mon[2] = {0, };
    for(int i = 0; i < idx; i++) {
        mon[0] = st[i].birth[4];
        mon[1] = st[i].birth[5];
        int ctod = atoi(mon);
        //printf("ctod:%d\n", ctod);
        if(ctod == month)
            printf("%s %s %s\n", st[i].name, st[i].phone, st[i].birth);
    }
}
int Exit() {
    return 0;
}

