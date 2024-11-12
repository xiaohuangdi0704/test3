/***********************************************************
我的信息:                                                 *
  姓名: 汪建林		生日:1985年2月26日                    *
  毕业学校: 2007年于成都理工大学                          *
  家乡地址: 四川渠县望溪乡包山村5组                       *
  联系QQ: 287307421  联系电话: 13558690869                *
  联系Email: wangjianlin1985@126.com 287307421            *
  双鱼林程序淘宝店: http://shop34864101.taobao.com        *
  双鱼林程序拍拍店: http://287307421.paipai.com           *
  网站: http://www.shuangyulin.com                        *
                                                          *
  需要更多程序可以联系我，保证运行！                      *
***********************************************************/

#include<stdio.h>
#include "stdlib.h"
#include "string.h"
#define N 10
struct information
{
	int num1;//入库编号//
	int rklx;//入库类型//
	int num2;//入库产品编号//
	int sj1[3];//生产日期//
	float dj;//入库产品单价//
	int sl;//入库产品数量//
	int num3;//仓库编号//
	char name[10];//经办人//
	int sj2[3];//入库日期//
};struct information inf[N];

/*******************************************************       
功能:登陆函数，验证口令
参数：
参数1：password
  类型：char []
  说明：用户输入口令   
返回值：1或0
  类型：int
  说明：1表示通过验证；0表示没有通过
 *******************************************************/
int login(char password[])
 {
     static char key[10]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }


  /*******************************************************       
功能:从文件读信息到结构体数组中
参数：
参数1：information
  类型：inf[]
  说明：用来存储从文件读到的管理信息
返回值：i
  类型：int
  说明：表示实际读取到的个数
 *******************************************************/
 int readFromFile(struct information inf[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen("FILENAME.txt","rb");  /*打开文件*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*从文件中读入学生*/
		{
     
			if(i>=N)
				break;
			if(fread(inf+i,sizeof(struct information),1,fp))
				i++;
		}

		fclose(fp);
	}
    return i;
}
/*******************************************************       
功能:结构体数组中的管理信息输出到文件
参数：
参数1：information
  类型：inf[]
  说明：用来存储从文件读到的管理信息
参数2：length
  类型：int
  说明：表示实际数组的长度 
返回值：无
 *******************************************************/

void writeToFile(struct information inf[],int length)
{
	
	FILE *fp=NULL;
	int i=0;

	fp=fopen("FILENAME.txt","wb");
 
	if(fp==NULL)
	{
		printf("打开文件出错！\n");
		exit(0);
	}

	for(i=0;i<length;i++)
		fwrite(inf+i,sizeof(struct information),1,fp);

	fclose(fp);

}



 /*******************************************************       
功能:根据入库编号删除记录
参数：
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：delete_num1
  类型：int
  说明：表示要入库编号删除记录
返回值：length
		删除后信息的个数        
 *******************************************************/
int delete_inf(struct information inf[],int delete_num1,int length)
{
	int i,j;
	char choice;
	for(i=0;i<length;i++)
	{
		if(delete_num1==inf[i].num1)
       {
			printf("找到啦!它的下标是:%d\n", i);
			printf("入库产品编号为: %d\n",inf[i].num2);		
			printf("入库编号为:     %d\n",inf[i].num1);
			printf("生产日期:       %d年%d月%d日\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
			printf("入库日期为:     %d年%d月%d日\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
			printf("仓库编号为:     %d\n",inf[i].num3);
			printf("经办人为:       %s\n",inf[i].name);
			printf("入库产品单价为: %2.1f\n",inf[i].dj);
			printf("入库产品数量为: %d\n",inf[i].sl);
			printf("\n\n");
			break; 
		}
    }
    if(i<length)
	{
 		printf("你确实要删除这个入库编号吗?(Y/N)\n");
		getchar();
		scanf("%c",&choice);
		if(choice=='Y'||choice=='y')
		{
			for(j=i;j<length;j++)
				inf[j]=inf[j+1];
			length=length-1;
 	 	    printf("删除成功!\n");
		}                
	}
    else
        printf("\n指定的入库编号不存在!\n");
	return length;
}


/**********************************************************
功能:打印的纪录
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
返回值：无
**********************************************************/
void print(struct information inf[],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("入库产品编号为: %d\n",inf[i].num2);		
		printf("入库编号为:     %d\n",inf[i].num1);
		printf("生产日期:       %d年%d月%d日\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
		printf("入库日期为:     %d年%d月%d日\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
		printf("仓库编号为:     %d\n",inf[i].num3);
		printf("经办人为:       %s\n",inf[i].name);
		printf("入库产品单价为: %2.1f\n",inf[i].dj);
		printf("入库产品数量为: %d\n",inf[i].sl);
		printf("\n\n");
	}				
}


/*******************************************************       
功能:按入库产品编号从小到大显示记录
参数：
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
返回值：无
 *******************************************************/
void pailian(struct information inf[],int length)
{
	struct information inf1[N];
	int i,j,k;
	for(i=0;i<length-1;i++)
	{
		k=i;
		for(j=i+1;j<length;j++)
			if(inf[k].num2>inf[j].num2)
				k=j;
			if(k!=i)
			{
				inf1[N+1]=inf[i];
				inf[i]=inf[k];
				inf[k]=inf1[N+1];
			}
	}

}
/*******************************************************       
功能:判断入库编号是否唯一
参数：
参数1：information
  类型：inf[]
  说明：存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：peoinf
  类型：int
  说明：要判断的入库编号 
返回值：1或0(flag)
  类型：int
  说明：1表示入库编号唯一；0表示入库编号不唯一
 *******************************************************/
int unique(struct information inf[],int length,int peoinf)
{
	int flag=1,i;
	for(i=0;i<length;i++)
	{
		if(inf[i].num1==peoinf)
		{ 
			flag=0;
			break;
		}
	}
return (flag);
}




/*******************************************************  
 功能:统计所有生产入库产品的总金额
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：t
  类型：float
  说明：所有生产入库产品的总金额 
返回值：t
*******************************************************/


float add(struct information inf[],int length)
{
	float t=0;
	int i;
	for(i=0;i<length;i++)
		t+=inf[i].dj*inf[i].sl;
	return(t);
}


 /*******************************************************       
功能:输入信息到结构体数组中
参数：
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
返回值：i
  类型：int
  说明：表示增加信息后，实际数组的长度
 *******************************************************/
int f1(struct information inf[],int Length)
{
	int i=Length;
	int endFlag=0;
	int flag;
		printf("请输入产品入库操作管理系统（以入库编号为0结束）：\n");
	while(i<N)
	{
		while(1)
		{
			printf("请输入入库编号: \n");
				scanf("%d",&inf[i].num1);
			if(inf[i].num1==0)
			{
				endFlag=1;
				break;
			}
			flag=unique(inf,i,inf[i].num1);
			if(flag) break;
			printf("该信息已经存在，请重新输入！\n");
		}
			if(endFlag==1)break;
		
			printf("请选择 入库类型: \n");
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("*                                                  *\n");
            printf("*     1: 采购入库    2: 生产入库  3: 入库产品      *\n");
            printf("*                                                  *\n");
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				scanf("%d",&inf[i].rklx);
				switch(inf[i].rklx)
					{
						case 1:printf(" 采购入库\n 客户编号为供应商");break;
						case 2:printf("采购入库\n");break;
						case 3:printf("采购入库\n 客户编号为退货入库");break;
						default:printf("error\n");
					}
			printf("请输入 入库产品编号: \n");
				scanf("%d",&inf[i].num2);
			printf("请输入 生产日期: \n"); 
			printf("生产年份为：\n");
				scanf("%d",&inf[i].sj1[0]);
			printf("生产月份为：\n");
				scanf("%d",&inf[i].sj1[1]);
			printf("生产日期为：\n");
				scanf("%d",&inf[i].sj1[2]);
			printf("请输入 入库产品单价: \n");
				scanf("%f",&inf[i].dj);
			printf("请输入 入库产品数量: \n");
				scanf("%d",&inf[i].sl);
			printf("请输入 仓库编号: \n");
				scanf("%d",&inf[i].num3);
			printf("请输入 经办人: \n");
				scanf("%s",&inf[i].name);
			printf("请输入 入库日期: \n");
				printf("入库年份为：\n");
				scanf("%d",&inf[i].sj2[0]);
			printf("入库月份为：\n");
				scanf("%d",&inf[i].sj2[1]);
			printf("入库日期为：\n");
				scanf("%d",&inf[i].sj2[2]);
			
			while(getchar()!='\n')
				continue;
				i++;
	}
	return i;//新增完成后，数组中有多少个信息
}



/*******************************************************       
功能:根据入库产品编号查找记录 
参数：
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：infnum
  类型：int
  说明：表示要查找的入库产品编号
返回值：无
 *******************************************************/
void queryInfo(struct information inf[],int length,int infnum)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(infnum==inf[i].num2)
        {
			printf("找到啦！它的全部记录为\n");
			printf("入库产品编号为: %d\n",inf[i].num2);
			printf("入库编号为:     %d\n",inf[i].num1);
			printf("生产日期:       %d年%d月%d日\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
			printf("入库日期为:     %d年%d月%d日\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
			printf("仓库编号为:     %d\n",inf[i].num3);
			printf("经办人为:       %s\n",inf[i].name);
			printf("入库产品单价为: %2.1f\n",inf[i].dj);
			printf("入库产品数量为: %d\n",inf[i].sl);
			break;
        }
    }
    if(i>=length)
        printf("\n不存在！\n");
}


 /*******************************************************       
功能:根据日期从数组中查找数据
参数：
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：year
  类型：int
  说明：表示要查找年份
  参数4：month
  类型：int
  说明：表示要查找月份
  参数5：day
  类型：int
  说明：表示要查找日期
返回值：无
 *******************************************************/
void rukuriqi(struct information inf[],int length,int year,int month,int day)
{
	int i=0;
	int found=0;
	if(!(year>=1949&&year<=2010&&month>=0&&month<=12&&day>=0&&day<=31))	
		printf("输入错误！！");
	else
		if(year>=1949&&year<=2010&&month>=0&&month<=12&&day>=0&&day<=31)
		{
			for(i=0;i<length;i++)
			{
					if(inf[i].sj2[0]==year&&inf[i].sj2[1]==month&&inf[i].sj2[2]==day)
					{
						found++;
						if(found==1)
							printf("找到啦！它的全部记录为\n");

							printf("入库产品编号为: %d\n",inf[i].num2);
							printf("入库编号为:     %d\n",inf[i].num1);
							printf("生产日期:       %d年%d月%d日\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
							printf("入库日期为:     %d年%d月%d日\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
							printf("仓库编号为:     %d\n",inf[i].num3);
							printf("经办人为:       %s\n",inf[i].name);
							printf("入库产品单价为: %2.1f\n",inf[i].dj);
							printf("入库产品数量为: %d\n",inf[i].sl);
							printf("\n");
					}
				
			}	
				if(found==0)
					printf("sorry!!!没有找到!!!\n");
		}
			
}




 /*******************************************************       
功能:用指定格式显示全部记录
参数：
参数1：information
  类型：inf[]
  说明：用来存储管理信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：j
  类型：int
  说明：表示要查找的入库编号
返回值：无
 *******************************************************/
void zhidinggeshi(struct information inf[],int j,int length)
	{
		int i;
		if(j==1)
		{
			for(i=0;i<length;i++)
				printf("入库编号为%d\n",inf[i].num1);
		}
		if(j==2)
		{
			for(i=0;i<length;i++)
				printf("入库产品编号%d\n",inf[i].num2);
		}
		if(j==3)
		{
			for(i=0;i<length;i++)
				printf("生产日期为%d年%d月%d日\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
		}
		if(j==4)
		{
			for(i=0;i<length;i++)
				printf("入库产品单价为%f\n",inf[i].dj);
		}
		if(j==5)
		{
			for(i=0;i<length;i++)
				printf("入库日期为%d年%d月%d日\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
		}
		if(j==6)
		{
			for(i=0;i<length;i++)
				printf("入库产品数量为%d\n",inf[i].sl);
		}
		if(j==7)
		{
			for(i=0;i<length;i++)
				printf("仓库编号为%d\n",inf[i].num3);
		}
		if(j==8)
		{
			for(i=0;i<length;i++)
				printf("经办人为%s\n",inf[i].name);
		}
			while(getchar()!='\n')
				continue;
	}



/*******************************************************       
功能:显示菜单
参数：无   
返回值：无
 *******************************************************/
void main()
{
	struct information inf[N];
	int length=0;
	int i,s=0;
	char password[10];

	 /*====验证用户的口令，直到正确为止====*/
	do{
		printf("请输入操作密码：");
		scanf("%s",&password);
		s=login(password);
		}while(s==0);
	length=readFromFile(inf);
		while(1)
		{
			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("+              产品入库操作管理系统                     +\n");
			printf("+                                                       +\n");
			printf("+            1. 输入入库信息记录                        +\n");
			printf("+            2. 用指定格式显示全部记录                  +\n");
			printf("+            3. 根据入库产品编号查找记录                +\n");
			printf("+            4. 根据入库日期查找记录                    +\n");
			printf("+            5. 根据入库编号删除记录                    +\n");
	     	printf("+            6. 按入库产品编号从小到大显示记录  　　    +\n");
			printf("+            7. 统计所有生产入库产品的总金额            +\n");
			printf("+            8. 程序结束                                +\n");
			printf("+                                                       +\n");
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("请输入您要操作的指令序号\n");
			scanf("%d",&i);
			switch(i)
			{
				int j,infnum,delete_num1;
				int year,month,day,t1=1;
				float add_money;
				char choice;
				case 1:
						length=f1(inf,length);
						printf("\n现有%d个信息\n",length);
						writeToFile(inf,length);
					break;
				case 2:
					while(t1)
					{
						printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
						printf("*                                                  *\n");
						printf("*       1: 入库编号         2: 入库产品编号        *\n");
						printf("*       3: 生产日期         4: 入库产品单价        *\n");
						printf("*       5: 入库日期         6: 入库产品数量        *\n");
						printf("*       7: 仓库编号         8: 经办人              *\n");
						printf("*                                                  *\n");
						printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
						printf("请输入你要操作的序号\n");
							scanf("%d",&j);
						zhidinggeshi(inf,j,length);
						printf("要继续输入吗(y/n)\n");
						
						scanf("%c",&choice);
						if(choice=='y'||choice=='Y')
							t1=1;
						else
							t1=0;
					}
					t1=1;
					break;
				case 3:
					while(t1)
					{
						printf("请输入有要查的入库产品编号: ");
							scanf("%d",&infnum);
						queryInfo(inf,length,infnum);
						getchar();
						printf("要继续查找吗(y/n)\n");
							scanf("%c",&choice);
						if(choice=='y'||choice=='Y')
							t1=1;
						else
							t1=0;
					}
					t1=1;
					break;

				case 4:
					while(t1)
					{
						printf("根据入库日期查找记录\n");
						printf("请输入 入库日期: \n");
						printf("入库年份为：\n");
							scanf("%d",&year);
						printf("入库月份为：\n");
							scanf("%d",&month);
						printf("入库日期为：\n");
							scanf("%d",&day);
						rukuriqi(inf,length,year,month,day);
						getchar();
						printf("要继续查找吗(y/n)\n");
							scanf("%c",&choice);
						if(choice=='y'||choice=='Y')
							t1=1;
						else
							t1=0;
					}
					t1=1;
					break;
				case 5:
					while(t1)
					{
					printf("根据入库编号删除记录\n");
					printf("请输入要删除的入库编号\n");
					scanf("%d",&delete_num1);
					length=delete_inf(inf,delete_num1,length);
					printf("\n现还有%d个信息\n",length);
					writeToFile(inf,length);
					getchar();
						printf("要继续删除记录吗(y/n)\n");
							scanf("%c",&choice);
						if(choice=='y'||choice=='Y')
							t1=1;
						else
							t1=0;
					}
					t1=1;
					break;

				case 6:
					printf("按入库产品编号从小到大显示记录\n");
					pailian(inf,length);
					print(inf,length);
					writeToFile(inf,length);
					printf("排练成功！\n\n");
					break;

				case 7:
					printf("统计所有生产入库产品的总金额\n");
					add_money=add(inf,length);
					printf("生产入库产品的总金额为  %5.4f\n",add_money);
					break;

				case 8:
						writeToFile(inf,length);
						getchar();
						printf("您确定要结束吗(y/n)\n");
							scanf("%c",&choice);
						if(choice=='y'||choice=='Y')
							break;
						else 
							exit(0);
				default:
					printf("error\n");
					}
		}
}


			
