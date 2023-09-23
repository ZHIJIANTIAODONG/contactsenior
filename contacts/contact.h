#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//#define MAX      1000
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

enum Option
{
    EXIT,//0
    ADD,//1
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
    SAVE 
};

typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;

//通讯录类型
typedef struct Contact
{
    struct PeoInfo *data;
    int size;
    int capacity;//记录当前通讯录最大容量
}Contact;

//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchCONTACT(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void DestroyContcat(Contact* ps);
void SaveContact(Contact* ps);
void LoadContact(Contact* ps);

