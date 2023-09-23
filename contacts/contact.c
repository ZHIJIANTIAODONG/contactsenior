#include "contact.h"

void InitContact(struct Contact*ps)
{
    //memset(ps->data,0,sizeof(ps->data));
    //ps->size =0;//设置通讯录最初只有0个元素
    ps->data =(struct PeoInfo*)malloc(DEFAULT_SZ*sizeof(struct PeoInfo));
    //恰巧data也是此类型指针
    if(ps->data == NULL)
    {
        return ;
    }
    ps->size=0;
    ps->capacity=DEFAULT_SZ;
    //把文件中已经存放的通讯录信息加载到通讯录中
    LoadContact(ps);
}

void CheckCapacity(struct Contact* ps);

void LoadContact(Contact* ps)
{
    PeoInfo tmp={0};
    FILE* pfRead = fopen("contact.dat","rb");
    if(pfRead == NULL)
    {
        printf("LoadContact:%s\n",strerror(errno));
        return ;
    }
    //读取文件，存放到通讯录中
    while(fread(&tmp,sizeof(PeoInfo),1,pfRead))
    {
        CheckCapacity(ps);
        ps->data[ps->size] = tmp;
        ps->size++;
    }
    fclose(pfRead);
    pfRead=NULL;
}

void CheckCapacity(struct Contact* ps)
{
    if(ps->size==ps->capacity)
    {
        //增容
        struct PeoInfo *ptr = realloc(ps->data,(ps->capacity+2)*sizeof(PeoInfo));
        if(ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity+=2;
            printf("增容成功\n");
        }
        else
        {
            printf("增容失败\n");
        }
    }
}

void AddContact(struct Contact* ps)
{
    /*if(ps->size == MAX)
    {
        printf("通讯录已满，无法增加\n");
    }
    else
    {
        printf("请输入名字：");
        scanf("%s",ps->data[ps->size].name);
        printf("请输入年龄：");
        scanf("%d",&(ps->data[ps->size].age));
        printf("请输入性别：");
        scanf("%s",ps->data[ps->size].sex);
        printf("请输入电话：");
        scanf("%s",ps->data[ps->size].tele);
        printf("请输入地址：");
        scanf("%s",ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功\n");
    }*/
    CheckCapacity(ps);
        printf("请输入名字：");
        scanf("%s",ps->data[ps->size].name);
        printf("请输入年龄：");
        scanf("%d",&(ps->data[ps->size].age));
        printf("请输入性别：");
        scanf("%s",ps->data[ps->size].sex);
        printf("请输入电话：");
        scanf("%s",ps->data[ps->size].tele);
        printf("请输入地址：");
        scanf("%s",ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功\n");
}

void ShowContact(const struct Contact* ps)
{
    if(ps->size==0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i=0;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
        for(i=0;i<ps->size;i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
            ps->data[i].name,
            ps->data[i].age,
            ps->data[i].sex,
            ps->data[i].tele,
            ps->data[i].addr);
        }
    }
}

static int FindByName(const struct Contact* ps,char name[MAX_NAME])
{
    int i=0;
    for(i = 0;i<ps->size;i++)
    {
        if(0 == strcmp((ps->data[i].name),name))
        {
            return i;
        }
    }    
    return -1;
}
void DelContact(struct Contact* ps)
{
    int pos=0;
    char name[MAX_NAME];
    printf("请输入要删除人的名字：");
    scanf("%s",name);
    //1.查找
    pos = FindByName(ps,name);//找到了返回名字所在元素的下标，找不到返回-1
    if(pos == -1)
    {
        printf("用户不在\n");
    }
    else
    {
        int j=0;
        for(j=pos;j< ps->size-1;j++)
        {
            ps->data[j] = ps->data[j+1];
        }
        ps->size--;
        printf("删除成功\n");
    }
    //2.删除
}

void SearchCONTACT(const struct Contact* ps)
{
    int pos=0;
    char name[MAX_NAME];
    printf("请输入要查找人的名字：");
    scanf("%s",name);
    pos = FindByName(ps,name);
    if (pos == -1)
    {
        printf("查找的人不存在\n");
    }
    else
    {
        printf("%20s\t%4s\t%5s\t%12s\t%20s\n","名字","年龄","性别","电话","地址");

        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
            ps->data[pos].name,
            ps->data[pos].age,
            ps->data[pos].sex,
            ps->data[pos].tele,
            ps->data[pos].addr);

    }
}

void ModifyContact(struct Contact* ps)
{
    int pos = 0;
    char name[MAX_NAME];
    printf("请输入要修改人的名字：");
    scanf("%s",name);
    pos = FindByName(ps,name);
    if(pos == -1)
    {
        printf("要修改人的信息不存在\n");
    }
    else
    {
        printf("请输入名字：");
        scanf("%s",ps->data[pos].name);
        printf("请输入年龄：");
        scanf("%d",&(ps->data[pos].age));
        printf("请输入性别：");
        scanf("%s",ps->data[pos].sex);
        printf("请输入电话：");
        scanf("%s",ps->data[pos].tele);
        printf("请输入地址：");
        scanf("%s",ps->data[pos].addr);
        printf("修改完成\n");
    }
}

void DestroyContcat(Contact* ps)
{
    free(ps->data);
    ps->data=NULL;
}

void SaveContact(Contact* ps)
{
    FILE* pfWrite=fopen("contact.dat","wb");
    if(pfWrite == NULL)
    {
        printf("SaveContact:%s\n",strerror(errno));
        return;
    }
    //写通讯录中的数据到文件中
    int i=0;
    for(i=0;i<ps->size;i++)
    {
        fwrite(&(ps->data[i]),sizeof(PeoInfo),1,pfWrite);
    }
    fclose(pfWrite);
    pfWrite=NULL;
}






