#include <stdlib.h>

typedef int type;

void print (type num) {
    system("cls");
    printf("%d", num);
}

char perep(type num, char zn, char c) {     // проверка на переполнение
    char re=0;
    type small=1,big;
    while (small>0)
        small<<=1;
    big=small-1;
    if (zn>0)
        {if (num>(big-(c-'0'))/10)
            re=1;}
    else if (num<(small+(c-'0'))/10)
            re=1;
    return re;
}

type read_it() {
    char c,zn=1,col=0;
    type num=0;
    enum sos {empty, zero, minus, number} sost;
    sost=empty;
    while (1) {
        c=getch();
        if (sost==number) {
            if ((c>='0') && (c<='9')) {
                if (perep(num,zn,c)==0) {
                    num=num*10+zn*(c-'0');
                    ++col;
                    print(num);
                }
            }
            if (c==8) {
                num/=10;
                --col;
                if ((col==1) && (zn==-1)) {
                    sost=minus;
                    system("cls");
                    printf("%c",'-');
                } else if (col==0) {
                    sost=empty;
                    system("cls");
                } else
                    print(num);
            }
            if (c==13)
                return num;
        }
        if (sost==empty) {
            if (c=='-') {
                sost=minus;
                system("cls");
                putch(c);
                ++col;
                zn=-1;
            }
            if (c=='0') {
                sost=zero;
                print(num);
                ++col;
            }
            if ((c>'0') && (c<='9')) {
                sost=number;
                num=c-'0';
                print(num);
                ++col;
            }
        }
        if (sost==minus) {
            if ((c>'0') && (c<='9')) {
                sost=number;
                ++col;
                num=-(c-'0');
                print(num);
            }
            if (c==8) {
                sost=empty;
                zn=1;
                system("cls");
                --col; // счетчик должен быть == 0
            }
        }
        if (sost==zero) {
            if ((c>'0') && (c<='9')) {
                sost=number;
                print(num);
                num=c-'0';
            }
            if (c==8) {
                sost=empty;
                system("cls");
                --col; // счетчик должен быть == 0
            }
        }
    }
}

int main() {
    type x;
    x=read_it();
    print(x);
    printf(" - your number");
    return 0;
}
