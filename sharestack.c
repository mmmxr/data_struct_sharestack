#include <stdio.h>
#include "seqstack.h"
//用一个数组实现两个栈
//[0,top1)
//(top2,MAX_SIZE]
#define MAX_SIZE 100
typedef char ShareStackType;
typedef struct ShareStack
{
    ShareStackType data[MAX_SIZE];
    size_t top1;
    size_t top2;
    
}ShareStack;
void ShareStackInit(ShareStack* stack)
{
    if(stack==NULL)
    {
        return;
    }
    stack->top1=0;
    stack->top2=MAX_SIZE;
}
void ShareStackPush1(ShareStack* stack,ShareStackType value)
{
    if(stack==NULL)
    {
        return;
    }
    if(stack->top1==stack->top2)
    {
        return;
    }
    stack->data[stack->top1++]=value;
}
void ShareStackPush2(ShareStack* stack,ShareStackType value)
{
    if(stack==NULL)
    {
        return;
    }
    if(stack->top1==stack->top2)
    {
        return;
    }
    stack->data[stack->top2--]=value;
}
void ShareStackpPop1(ShareStack* stack)
{
    if(stack==NULL)
    {
        return;
    }
    stack->top1--;
}
void ShareStackpPop2(ShareStack* stack)
{
    if(stack==NULL)
    {
        return;
    }
    stack->top2++;
}
int ShareStackTop1(ShareStack* stack,ShareStackType* value)
{
    if(stack==NULL)
    {
        return 0;
    }
    if(stack->top1==stack->top2)
    {
        return 0;
    }
    *value=stack->data[stack->top1-1];
    return 1;

}

int ShareStackTop2(ShareStack* stack,ShareStackType* value)
{
    if(stack==NULL)
    {
        return 0;
    }
    if(stack->top1==stack->top2)
    {
        return 0;
    }
    *value=stack->data[stack->top2+1];
    return 1;

}














/////////////////////////////////////////
//测试
////////////////////////////////////////

void Sharestackprintchar1(ShareStack* stack)
{
    size_t i=0;
    for(;i<stack->top1;i++)
    {
        printf("%c ",stack->data[i]);
    }
    printf("\n");
}
void Sharestackprintchar2(ShareStack* stack)
{
    size_t i=MAX_SIZE;
    for(;i>stack->top2;i--)
    {
        printf("%c ",stack->data[i]);
    }
    printf("\n");
}
void Test()
{
    ShareStack stack;
    ShareStackType value;
    ShareStackInit(&stack);
    ShareStackPush1(&stack,'a');
    ShareStackPush1(&stack,'b');
    ShareStackPush1(&stack,'c');
    ShareStackPush1(&stack,'d');
    Sharestackprintchar1(&stack);
    int ret=ShareStackTop1(&stack,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("top1 expect d,actual %c\n",value);
    ShareStackPush2(&stack,'a');
    ShareStackPush2(&stack,'b');
    ShareStackPush2(&stack,'c');
    ShareStackPush2(&stack,'d');
    Sharestackprintchar2(&stack);
    ret=ShareStackTop2(&stack,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("top1 expect d,actual %c\n",value);
    ShareStackpPop1(&stack);
    ShareStackpPop1(&stack);
    Sharestackprintchar1(&stack);
    ShareStackpPop2(&stack);
    ShareStackpPop2(&stack);
    Sharestackprintchar2(&stack);
}

















int main()
{
    Test();
    return 0;
}
