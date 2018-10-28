#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define NAME_MAX 20

struct weapon{
    char name[NAME_MAX];
    int price;
    int attack;
    struct weapon *next;
};

struct weapon* createWeapon(void)
{
    struct weapon* head;
    struct weapon *p1, *p2;//p2记录上一个，P1记录正在操作的
    p1 = p2 = (struct weapon*)malloc(sizeof(struct weapon));
    scanf("%s", &p1->name);
    scanf("%d", &p1->price);
    scanf("%d", &p1->attack);
    int n = 0;
    while((p1->price!=0) && (p1->attack != 0))
    {
        n++;
        if(n==1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct weapon*)malloc(sizeof(struct weapon));
        scanf("%s", &p1->name);
        scanf("%d", &p1->price);
        scanf("%d", &p1->attack);
    }
    p2->next = NULL;
    return head;
}

int main(int argc, const char *argv[]){
    /***
     * test weapon
     */
    #if 0
    struct weapon *head = NULL;
    struct weapon w1 = {"w1", 100, 100}, w2 = {"w2", 200, 200}, w3 = {"w3", 300, 300};
    head = &w1;
    w1.next = &w2;
    w2.next = &w3;
    w3.next = NULL;
    while(head != NULL)
    {
        printf("%s,%d,%d\n", head->name, head->price, head->attack);
        head = head->next;
    }
    #endif
    /***
     * test createWeapon(){}
     */
    struct weapon *testW = createWeapon();
    while(testW != NULL)
    {
        printf("%s,%d,%d\n", testW->name, testW->price, testW->attack);
        testW = testW->next;
    }
    return 0;
}
