/***********************************************************
�ҵ���Ϣ:                                                 *
  ����: ������		����:1985��2��26��                    *
  ��ҵѧУ: 2007���ڳɶ�����ѧ                          *
  �����ַ: �Ĵ�������Ϫ���ɽ��5��                       *
  ��ϵQQ: 287307421  ��ϵ�绰: 13558690869                *
  ��ϵEmail: wangjianlin1985@126.com 287307421            *
  ˫���ֳ����Ա���: http://shop34864101.taobao.com        *
  ˫���ֳ������ĵ�: http://287307421.paipai.com           *
  ��վ: http://www.shuangyulin.com                        *
                                                          *
  ��Ҫ������������ϵ�ң���֤���У�                      *
***********************************************************/

#include<stdio.h>
#include "stdlib.h"
#include "string.h"
#define N 10
struct information
{
	int num1;//�����//
	int rklx;//�������//
	int num2;//����Ʒ���//
	int sj1[3];//��������//
	float dj;//����Ʒ����//
	int sl;//����Ʒ����//
	int num3;//�ֿ���//
	char name[10];//������//
	int sj2[3];//�������//
};struct information inf[N];

/*******************************************************       
����:��½��������֤����
������
����1��password
  ���ͣ�char []
  ˵�����û��������   
����ֵ��1��0
  ���ͣ�int
  ˵����1��ʾͨ����֤��0��ʾû��ͨ��
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
����:���ļ�����Ϣ���ṹ��������
������
����1��information
  ���ͣ�inf[]
  ˵���������洢���ļ������Ĺ�����Ϣ
����ֵ��i
  ���ͣ�int
  ˵������ʾʵ�ʶ�ȡ���ĸ���
 *******************************************************/
 int readFromFile(struct information inf[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen("FILENAME.txt","rb");  /*���ļ�*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*���ļ��ж���ѧ��*/
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
����:�ṹ�������еĹ�����Ϣ������ļ�
������
����1��information
  ���ͣ�inf[]
  ˵���������洢���ļ������Ĺ�����Ϣ
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ����
 *******************************************************/

void writeToFile(struct information inf[],int length)
{
	
	FILE *fp=NULL;
	int i=0;

	fp=fopen("FILENAME.txt","wb");
 
	if(fp==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}

	for(i=0;i<length;i++)
		fwrite(inf+i,sizeof(struct information),1,fp);

	fclose(fp);

}



 /*******************************************************       
����:���������ɾ����¼
������
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��delete_num1
  ���ͣ�int
  ˵������ʾҪ�����ɾ����¼
����ֵ��length
		ɾ������Ϣ�ĸ���        
 *******************************************************/
int delete_inf(struct information inf[],int delete_num1,int length)
{
	int i,j;
	char choice;
	for(i=0;i<length;i++)
	{
		if(delete_num1==inf[i].num1)
       {
			printf("�ҵ���!�����±���:%d\n", i);
			printf("����Ʒ���Ϊ: %d\n",inf[i].num2);		
			printf("�����Ϊ:     %d\n",inf[i].num1);
			printf("��������:       %d��%d��%d��\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
			printf("�������Ϊ:     %d��%d��%d��\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
			printf("�ֿ���Ϊ:     %d\n",inf[i].num3);
			printf("������Ϊ:       %s\n",inf[i].name);
			printf("����Ʒ����Ϊ: %2.1f\n",inf[i].dj);
			printf("����Ʒ����Ϊ: %d\n",inf[i].sl);
			printf("\n\n");
			break; 
		}
    }
    if(i<length)
	{
 		printf("��ȷʵҪɾ������������?(Y/N)\n");
		getchar();
		scanf("%c",&choice);
		if(choice=='Y'||choice=='y')
		{
			for(j=i;j<length;j++)
				inf[j]=inf[j+1];
			length=length-1;
 	 	    printf("ɾ���ɹ�!\n");
		}                
	}
    else
        printf("\nָ��������Ų�����!\n");
	return length;
}


/**********************************************************
����:��ӡ�ļ�¼
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ����
**********************************************************/
void print(struct information inf[],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("����Ʒ���Ϊ: %d\n",inf[i].num2);		
		printf("�����Ϊ:     %d\n",inf[i].num1);
		printf("��������:       %d��%d��%d��\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
		printf("�������Ϊ:     %d��%d��%d��\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
		printf("�ֿ���Ϊ:     %d\n",inf[i].num3);
		printf("������Ϊ:       %s\n",inf[i].name);
		printf("����Ʒ����Ϊ: %2.1f\n",inf[i].dj);
		printf("����Ʒ����Ϊ: %d\n",inf[i].sl);
		printf("\n\n");
	}				
}


/*******************************************************       
����:������Ʒ��Ŵ�С������ʾ��¼
������
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ����
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
����:�ж�������Ƿ�Ψһ
������
����1��information
  ���ͣ�inf[]
  ˵�����洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��peoinf
  ���ͣ�int
  ˵����Ҫ�жϵ������ 
����ֵ��1��0(flag)
  ���ͣ�int
  ˵����1��ʾ�����Ψһ��0��ʾ����Ų�Ψһ
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
 ����:ͳ��������������Ʒ���ܽ��
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��t
  ���ͣ�float
  ˵����������������Ʒ���ܽ�� 
����ֵ��t
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
����:������Ϣ���ṹ��������
������
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ��i
  ���ͣ�int
  ˵������ʾ������Ϣ��ʵ������ĳ���
 *******************************************************/
int f1(struct information inf[],int Length)
{
	int i=Length;
	int endFlag=0;
	int flag;
		printf("�������Ʒ����������ϵͳ���������Ϊ0��������\n");
	while(i<N)
	{
		while(1)
		{
			printf("�����������: \n");
				scanf("%d",&inf[i].num1);
			if(inf[i].num1==0)
			{
				endFlag=1;
				break;
			}
			flag=unique(inf,i,inf[i].num1);
			if(flag) break;
			printf("����Ϣ�Ѿ����ڣ����������룡\n");
		}
			if(endFlag==1)break;
		
			printf("��ѡ�� �������: \n");
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("*                                                  *\n");
            printf("*     1: �ɹ����    2: �������  3: ����Ʒ      *\n");
            printf("*                                                  *\n");
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				scanf("%d",&inf[i].rklx);
				switch(inf[i].rklx)
					{
						case 1:printf(" �ɹ����\n �ͻ����Ϊ��Ӧ��");break;
						case 2:printf("�ɹ����\n");break;
						case 3:printf("�ɹ����\n �ͻ����Ϊ�˻����");break;
						default:printf("error\n");
					}
			printf("������ ����Ʒ���: \n");
				scanf("%d",&inf[i].num2);
			printf("������ ��������: \n"); 
			printf("�������Ϊ��\n");
				scanf("%d",&inf[i].sj1[0]);
			printf("�����·�Ϊ��\n");
				scanf("%d",&inf[i].sj1[1]);
			printf("��������Ϊ��\n");
				scanf("%d",&inf[i].sj1[2]);
			printf("������ ����Ʒ����: \n");
				scanf("%f",&inf[i].dj);
			printf("������ ����Ʒ����: \n");
				scanf("%d",&inf[i].sl);
			printf("������ �ֿ���: \n");
				scanf("%d",&inf[i].num3);
			printf("������ ������: \n");
				scanf("%s",&inf[i].name);
			printf("������ �������: \n");
				printf("������Ϊ��\n");
				scanf("%d",&inf[i].sj2[0]);
			printf("����·�Ϊ��\n");
				scanf("%d",&inf[i].sj2[1]);
			printf("�������Ϊ��\n");
				scanf("%d",&inf[i].sj2[2]);
			
			while(getchar()!='\n')
				continue;
				i++;
	}
	return i;//������ɺ��������ж��ٸ���Ϣ
}



/*******************************************************       
����:��������Ʒ��Ų��Ҽ�¼ 
������
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��infnum
  ���ͣ�int
  ˵������ʾҪ���ҵ�����Ʒ���
����ֵ����
 *******************************************************/
void queryInfo(struct information inf[],int length,int infnum)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(infnum==inf[i].num2)
        {
			printf("�ҵ���������ȫ����¼Ϊ\n");
			printf("����Ʒ���Ϊ: %d\n",inf[i].num2);
			printf("�����Ϊ:     %d\n",inf[i].num1);
			printf("��������:       %d��%d��%d��\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
			printf("�������Ϊ:     %d��%d��%d��\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
			printf("�ֿ���Ϊ:     %d\n",inf[i].num3);
			printf("������Ϊ:       %s\n",inf[i].name);
			printf("����Ʒ����Ϊ: %2.1f\n",inf[i].dj);
			printf("����Ʒ����Ϊ: %d\n",inf[i].sl);
			break;
        }
    }
    if(i>=length)
        printf("\n�����ڣ�\n");
}


 /*******************************************************       
����:�������ڴ������в�������
������
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��year
  ���ͣ�int
  ˵������ʾҪ�������
  ����4��month
  ���ͣ�int
  ˵������ʾҪ�����·�
  ����5��day
  ���ͣ�int
  ˵������ʾҪ��������
����ֵ����
 *******************************************************/
void rukuriqi(struct information inf[],int length,int year,int month,int day)
{
	int i=0;
	int found=0;
	if(!(year>=1949&&year<=2010&&month>=0&&month<=12&&day>=0&&day<=31))	
		printf("������󣡣�");
	else
		if(year>=1949&&year<=2010&&month>=0&&month<=12&&day>=0&&day<=31)
		{
			for(i=0;i<length;i++)
			{
					if(inf[i].sj2[0]==year&&inf[i].sj2[1]==month&&inf[i].sj2[2]==day)
					{
						found++;
						if(found==1)
							printf("�ҵ���������ȫ����¼Ϊ\n");

							printf("����Ʒ���Ϊ: %d\n",inf[i].num2);
							printf("�����Ϊ:     %d\n",inf[i].num1);
							printf("��������:       %d��%d��%d��\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
							printf("�������Ϊ:     %d��%d��%d��\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
							printf("�ֿ���Ϊ:     %d\n",inf[i].num3);
							printf("������Ϊ:       %s\n",inf[i].name);
							printf("����Ʒ����Ϊ: %2.1f\n",inf[i].dj);
							printf("����Ʒ����Ϊ: %d\n",inf[i].sl);
							printf("\n");
					}
				
			}	
				if(found==0)
					printf("sorry!!!û���ҵ�!!!\n");
		}
			
}




 /*******************************************************       
����:��ָ����ʽ��ʾȫ����¼
������
����1��information
  ���ͣ�inf[]
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��j
  ���ͣ�int
  ˵������ʾҪ���ҵ������
����ֵ����
 *******************************************************/
void zhidinggeshi(struct information inf[],int j,int length)
	{
		int i;
		if(j==1)
		{
			for(i=0;i<length;i++)
				printf("�����Ϊ%d\n",inf[i].num1);
		}
		if(j==2)
		{
			for(i=0;i<length;i++)
				printf("����Ʒ���%d\n",inf[i].num2);
		}
		if(j==3)
		{
			for(i=0;i<length;i++)
				printf("��������Ϊ%d��%d��%d��\n",inf[i].sj1[0],inf[i].sj1[1],inf[i].sj1[2]);
		}
		if(j==4)
		{
			for(i=0;i<length;i++)
				printf("����Ʒ����Ϊ%f\n",inf[i].dj);
		}
		if(j==5)
		{
			for(i=0;i<length;i++)
				printf("�������Ϊ%d��%d��%d��\n",inf[i].sj2[0],inf[i].sj2[1],inf[i].sj2[2]);
		}
		if(j==6)
		{
			for(i=0;i<length;i++)
				printf("����Ʒ����Ϊ%d\n",inf[i].sl);
		}
		if(j==7)
		{
			for(i=0;i<length;i++)
				printf("�ֿ���Ϊ%d\n",inf[i].num3);
		}
		if(j==8)
		{
			for(i=0;i<length;i++)
				printf("������Ϊ%s\n",inf[i].name);
		}
			while(getchar()!='\n')
				continue;
	}



/*******************************************************       
����:��ʾ�˵�
��������   
����ֵ����
 *******************************************************/
void main()
{
	struct information inf[N];
	int length=0;
	int i,s=0;
	char password[10];

	 /*====��֤�û��Ŀ��ֱ����ȷΪֹ====*/
	do{
		printf("������������룺");
		scanf("%s",&password);
		s=login(password);
		}while(s==0);
	length=readFromFile(inf);
		while(1)
		{
			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("+              ��Ʒ����������ϵͳ                     +\n");
			printf("+                                                       +\n");
			printf("+            1. ���������Ϣ��¼                        +\n");
			printf("+            2. ��ָ����ʽ��ʾȫ����¼                  +\n");
			printf("+            3. ��������Ʒ��Ų��Ҽ�¼                +\n");
			printf("+            4. ����������ڲ��Ҽ�¼                    +\n");
			printf("+            5. ���������ɾ����¼                    +\n");
	     	printf("+            6. ������Ʒ��Ŵ�С������ʾ��¼  ����    +\n");
			printf("+            7. ͳ��������������Ʒ���ܽ��            +\n");
			printf("+            8. �������                                +\n");
			printf("+                                                       +\n");
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			printf("��������Ҫ������ָ�����\n");
			scanf("%d",&i);
			switch(i)
			{
				int j,infnum,delete_num1;
				int year,month,day,t1=1;
				float add_money;
				char choice;
				case 1:
						length=f1(inf,length);
						printf("\n����%d����Ϣ\n",length);
						writeToFile(inf,length);
					break;
				case 2:
					while(t1)
					{
						printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
						printf("*                                                  *\n");
						printf("*       1: �����         2: ����Ʒ���        *\n");
						printf("*       3: ��������         4: ����Ʒ����        *\n");
						printf("*       5: �������         6: ����Ʒ����        *\n");
						printf("*       7: �ֿ���         8: ������              *\n");
						printf("*                                                  *\n");
						printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
						printf("��������Ҫ���������\n");
							scanf("%d",&j);
						zhidinggeshi(inf,j,length);
						printf("Ҫ����������(y/n)\n");
						
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
						printf("��������Ҫ�������Ʒ���: ");
							scanf("%d",&infnum);
						queryInfo(inf,length,infnum);
						getchar();
						printf("Ҫ����������(y/n)\n");
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
						printf("����������ڲ��Ҽ�¼\n");
						printf("������ �������: \n");
						printf("������Ϊ��\n");
							scanf("%d",&year);
						printf("����·�Ϊ��\n");
							scanf("%d",&month);
						printf("�������Ϊ��\n");
							scanf("%d",&day);
						rukuriqi(inf,length,year,month,day);
						getchar();
						printf("Ҫ����������(y/n)\n");
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
					printf("���������ɾ����¼\n");
					printf("������Ҫɾ���������\n");
					scanf("%d",&delete_num1);
					length=delete_inf(inf,delete_num1,length);
					printf("\n�ֻ���%d����Ϣ\n",length);
					writeToFile(inf,length);
					getchar();
						printf("Ҫ����ɾ����¼��(y/n)\n");
							scanf("%c",&choice);
						if(choice=='y'||choice=='Y')
							t1=1;
						else
							t1=0;
					}
					t1=1;
					break;

				case 6:
					printf("������Ʒ��Ŵ�С������ʾ��¼\n");
					pailian(inf,length);
					print(inf,length);
					writeToFile(inf,length);
					printf("�����ɹ���\n\n");
					break;

				case 7:
					printf("ͳ��������������Ʒ���ܽ��\n");
					add_money=add(inf,length);
					printf("��������Ʒ���ܽ��Ϊ  %5.4f\n",add_money);
					break;

				case 8:
						writeToFile(inf,length);
						getchar();
						printf("��ȷ��Ҫ������(y/n)\n");
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


			
