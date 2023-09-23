//1.存放1000个好友信息
//2.增加好友信息
//3.删除指定名字的好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息
//#include "contact.h"
#include "contact.c"

void menu()
{
    printf("*************************\n");
    printf("****1.add****2.del*******\n");
    printf("****3.search*4.modify****\n");
    printf("****5.show***6.sort******\n");
    printf("****7.save   0.exit******\n");
    printf("*************************\n");
}
int main()
{
    int input = 0;
    struct Contact con;//con就是通讯录，里面包含 data指针和size,capacity
    //当前元素的个数
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch(input)
        {
            case ADD:
                 AddContact(&con);
                 break;
            case DEL:
                 DelContact(&con);
                 break;
            case SEARCH:
                 SearchCONTACT(&con);
                 break;
            case MODIFY:
                 ModifyContact(&con);
                 break;
            case SHOW:
                 ShowContact(&con);//传值，参数压栈系统开销较大
                 break;
            case SORT:
                
                break;
            case SAVE:
                 SaveContact(&con);
                 break;
             case EXIT:
                 SaveContact(&con);
                  //销毁通讯录-释放动态开辟的内存
                 DestroyContcat(&con);
                 printf("退出通讯录\n");
                 break;
            default:
                printf("选择错误\n");
                break;
        }
    } while (input);
    return 0;
}















