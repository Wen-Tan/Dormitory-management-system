# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
# define F "数据.txt" //文件路径

typedef struct Student {
	int lh;			//宿舍楼号
	int roomnum;	//房间号
	int bednum;		//床位号
	int num;		//学号
	char name[20];	//姓名
	char xy[100];	//学院
	char bj[15];	//班级
	char sex[10];	//性别
	struct Student *next;
} Stu;

//登录界面
void login() {
	char userName[5];
	char password[5];
	int i,sum;
	//system("color 3E");
	printf("\n\n   ---------------------------------欢迎使用---------------------------------\n");
	for(i=1; i<4; i++) {
		printf("\n       请输入您的用户名:");
		gets(userName);
		printf("\n       请输入您的密码:");
		gets(password);
		if ((strcmp(userName,"001")==0) && (strcmp(password,"123")==0)) { /*验证用户名和密码*/

			printf("\n   ---------------------------------登陆成功---------------------------------");
			Sleep(500);
			return;
		} else {
			if(i<3) {
				printf("\n     用户名或密码错误，请重新输入!\n");
			} else {
				printf("\n     您已连续3次将用户名或密码输错，系统将退出!");
				exit(0);
			}
		}
	}
}

//菜单选项
int menu_select() {
	int a;
	do {
		system("cls");
		printf("\n\n\t\t----------------------学生宿舍管理系统----------------------\n\n");
		printf("\t\t☆☆ 1. 添加学生信息                        ☆☆\n\n");
		printf("\t\t☆☆ 2. 显示学生信息                        ☆☆\n\n");
		printf("\t\t☆☆ 3. 按信息排序并显示                    ☆☆\n\n");
		printf("\t\t☆☆ 4. 插入学生信息                        ☆☆\n\n");
		printf("\t\t☆☆ 5. 查找学生信息                        ☆☆\n\n");
		printf("\t\t☆☆ 6. 修改学生信息                        ☆☆\n\n");
		printf("\t\t☆☆ 7. 删除学生信息                        ☆☆\n\n");
		printf("\t\t☆☆ 8. 将信息写入文件                      ☆☆\n\n");
		printf("\t\t☆☆ 9. 读取文件中的信息                    ☆☆\n\n");
		printf("\t\t☆☆ 0. 退出系统                            ☆☆\n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t请选择您要运行的选项按(0-9):");
		scanf("%d",&a);
	} while(a<0||a>9);
	return a;
}

//添加学生信息
Student *input(int n) {
	int i;
	Stu *head,*l,*r;
	if(n<=0) {
		return NULL;
	}
	l=(Stu *)malloc(sizeof(Stu));
	printf("\t\t宿舍楼号:");
	scanf("%d",&l->lh);
	printf("\t\t房间号:");
	scanf("%d",&l->roomnum);
	printf("\t\t床位号:");
	scanf("%d",&l->bednum);
	printf("\t\t学院:");
	scanf("%s",&l->xy);
	printf("\t\t班级:");
	scanf("%s",&l->bj);
	printf("\t\t学号:");
	scanf("%d",&l->num);
	printf("\t\t姓名:");
	scanf("%s",&l->name);
	printf("\t\t性别:");
	scanf("%s",&l->sex);
	printf("\n");
	head=l;
	for(i=1; i<n; i++) {
		r=(Stu *)malloc(sizeof(Stu));
		printf("\t\t宿舍楼号:");
		scanf("%d",&r->lh);
		printf("\t\t房间号:");
		scanf("%d",&r->roomnum);
		printf("\t\t床位号:");
		scanf("%d",&r->bednum);
		printf("\t\t学院:");
		scanf("%s",&r->xy);
		printf("\t\t班级:");
		scanf("%s",&r->bj);
		printf("\t\t学号:");
		scanf("%d",&r->num);
		printf("\t\t姓名:");
		scanf("%s",&r->name);
		printf("\t\t性别:");
		scanf("%s",&r->sex);
		printf("\n");
		l->next=r;
		l=r;
		if(i==n-1) {
			l->next=NULL;
		}
	}
	return head;
}

//输出学生信息
void output(Stu *head) {
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	printf(" 宿舍楼号          房间号               床位号                学院                     ");
	printf("班级                学号                 姓名                  性别\n");
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL) {
		printf("\n\t\t\t学生信息为空！\n");
	} else {
		do {
			printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
			p=p->next;
		} while(p!=NULL);
	}
}

//排序菜单
int sort_menu() {
	int a;
	do {
		system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n");
		printf("\t\t\t1. 按照宿舍楼号排序\n\n");
		printf("\t\t\t2. 按照房间号排序\n\n");
		printf("\t\t\t3. 按照床位号排序\n\n");
		printf("\t\t\t4. 按照学号排序\n\n");
		printf("\t\t\t0. 返回到主菜单\n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t\t请选择您要运行的选项按(0-4):");
		scanf("%d",&a);
	} while(a<0||a>8);
	return a;
}
//排序选择菜单
int sort_select(Stu *head,int n) {
	Stu *p,*q;
	int lh;
	int roomnum;
	int bednum;
	int num;
	char name[20];
	char xy[100];
	char bj[15];
	char sex[10];
	switch(n) {
		case 1:
			system("cls");
			for(p=head; p!=NULL; p=p->next) {
				for(q=p->next; q!=NULL; q=q->next) {
					if(p->lh>q->lh) {
						lh=q->lh;
						roomnum=q->roomnum;
						bednum=q->bednum;
						strcpy(xy,q->xy);
						strcpy(bj,q->bj);
						num=q->num;
						strcpy(name,q->name);
						strcpy(sex,q->sex);

						q->lh=p->lh;
						q->roomnum=p->roomnum;
						q->bednum=p->bednum;
						strcpy(q->xy,p->xy);
						strcpy(q->bj,p->bj);
						q->num=p->num;
						strcpy(q->name,p->name);
						strcpy(q->sex,p->sex);

						p->lh=lh;
						p->roomnum=roomnum;
						p->bednum=bednum;
						strcpy(p->xy,xy);
						strcpy(p->bj,bj);
						p->num=num;
						strcpy(p->name,name);
						strcpy(p->sex,sex);
					}
				}
			}
			output(head);
			system("pause");
			return 1;
		case 2:
			system("cls");
			for(p=head; p!=NULL; p=p->next) {
				for(q=p->next; q!=NULL; q=q->next) {
					if(p->roomnum>q->roomnum) {
						lh=q->lh;
						roomnum=q->roomnum;
						bednum=q->bednum;
						strcpy(xy,q->xy);
						strcpy(bj,q->bj);
						num=q->num;
						strcpy(name,q->name);
						strcpy(sex,q->sex);

						q->lh=p->lh;
						q->roomnum=p->roomnum;
						q->bednum=p->bednum;
						strcpy(q->xy,p->xy);
						strcpy(q->bj,p->bj);
						q->num=p->num;
						strcpy(q->name,p->name);
						strcpy(q->sex,p->sex);

						p->lh=lh;
						p->roomnum=roomnum;
						p->bednum=bednum;
						strcpy(p->xy,xy);
						strcpy(p->bj,bj);
						p->num=num;
						strcpy(p->name,name);
						strcpy(p->sex,sex);
					}
				}
			}
			output(head);
			system("pause");
			return 1;
		case 3:
			system("cls");
			for(p=head; p!=NULL; p=p->next) {
				for(q=p->next; q!=NULL; q=q->next) {
					if(p->bednum>q->bednum) {
						lh=q->lh;
						roomnum=q->roomnum;
						bednum=q->bednum;
						strcpy(xy,q->xy);
						strcpy(bj,q->bj);
						num=q->num;
						strcpy(name,q->name);
						strcpy(sex,q->sex);

						q->lh=p->lh;
						q->roomnum=p->roomnum;
						q->bednum=p->bednum;
						strcpy(q->xy,p->xy);
						strcpy(q->bj,p->bj);
						q->num=p->num;
						strcpy(q->name,p->name);
						strcpy(q->sex,p->sex);

						p->lh=lh;
						p->roomnum=roomnum;
						p->bednum=bednum;
						strcpy(p->xy,xy);
						strcpy(p->bj,bj);
						p->num=num;
						strcpy(p->name,name);
						strcpy(p->sex,sex);
					}
				}
			}
			output(head);
			system("pause");
			return 1;
		case 4:
			system("cls");
			for(p=head; p!=NULL; p=p->next) {
				for(q=p->next; q!=NULL; q=q->next) {
					if(p->num>q->num) {
						lh=q->lh;
						roomnum=q->roomnum;
						bednum=q->bednum;
						strcpy(xy,q->xy);
						strcpy(bj,q->bj);
						num=q->num;
						strcpy(name,q->name);
						strcpy(sex,q->sex);

						q->lh=p->lh;
						q->roomnum=p->roomnum;
						q->bednum=p->bednum;
						strcpy(q->xy,p->xy);
						strcpy(q->bj,p->bj);
						q->num=p->num;
						strcpy(q->name,p->name);
						strcpy(q->sex,p->sex);

						p->lh=lh;
						p->roomnum=roomnum;
						p->bednum=bednum;
						strcpy(p->xy,xy);
						strcpy(p->bj,bj);
						p->num=num;
						strcpy(p->name,name);
						strcpy(p->sex,sex);
					}
				}
			}
			output(head);
			system("pause");
			return 1;
		case 0:
			system("pause");
			return 0;
	}
}

//插入学生信息
void insert(Stu *head) {
	Stu *p,*pnew;
	int m;
	pnew=(Stu *)malloc(sizeof(Stu));
	printf("\t\t宿舍楼号:");
	scanf("%d",&pnew->lh);
	printf("\t\t房间号:");
	scanf("%d",&pnew->roomnum);
	printf("\t\t床位号:");
	scanf("%d",&pnew->bednum);
	printf("\t\t学院:");
	scanf("%s",&pnew->xy);
	printf("\t\t班级:");
	scanf("%s",&pnew->bj);
	printf("\t\t学号:");
	scanf("%d",&pnew->num);
	printf("\t\t姓名:");
	scanf("%s",&pnew->name);
	printf("\t\t性别:");
	scanf("%s",&pnew->sex);
	printf("\n");
	printf("\t\t\t请输入想要插到的位置：");
	scanf("%d",&m);
	p=head;
	for(int j=1; j<m&&p!=NULL; j++) {
		p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}

//查找菜单
int find_menu() {
	int a;
	do {
		system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n");
		printf("\t\t\t1. 按照宿舍楼号查找\n\n");
		printf("\t\t\t2. 按照房间号查找\n\n");
		printf("\t\t\t3. 按照床位号查找\n\n");
		printf("\t\t\t4. 按照学院查找\n\n");
		printf("\t\t\t5. 按照班级查找\n\n");
		printf("\t\t\t6. 按照学号查找\n\n");
		printf("\t\t\t7. 按照姓名查找\n\n");
		printf("\t\t\t8. 按照性别查找\n\n");
		printf("\t\t\t0. 返回到主菜单\n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t\t请选择您要运行的选项按(1-8):");
		scanf("%d",&a);
	} while(a<0||a>8);
	return a;
}
//查找选择菜单
int find_select(Stu *head,int n) {
	Stu *p;
	switch(n) {
		case 1:
			system("cls");
			p=head;
			int a;
			printf("\n\t\t\t要查找的宿舍楼号为：");
			scanf("%d",&a);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(p->lh==a)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 2:
			system("cls");
			p=head;
			int b;
			printf("\n\t\t\t要查找的房间号为：");
			scanf("%d",&b);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(p->roomnum==b)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 3:
			system("cls");
			p=head;
			int c;
			printf("\n\t\t\t要查找的床位号为：");
			scanf("%d",&c);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(p->bednum==c)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 4:
			system("cls");
			p=head;
			char d[100];
			printf("\n\t\t\t要查找的学院为：");
			scanf("%s",&d);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(strcmp(p->xy,d)==0)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 5:
			system("cls");
			p=head;
			char e[15];
			printf("\n\t\t\t要查找的班级为：");
			scanf("%s",&e);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(strcmp(p->bj,e)==0)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 6:
			system("cls");
			p=head;
			int f;
			printf("\n\t\t\t要查找的学号为：");
			scanf("%d",&f);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(p->num==f)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 7:
			system("cls");
			p=head;
			char g[20];
			printf("\n\t\t\t要查找的姓名为：");
			scanf("%s",&g);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(strcmp(p->name,g)==0)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 8:
			system("cls");
			p=head;
			char h[10];
			printf("\n\t\t\t要查找的性别为：");
			scanf("%s",&h);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" 宿舍楼号          房间号               床位号                学院                     ");
			printf("班级                学号                 姓名                  性别\n");
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				if(strcmp(p->sex,h)==0)
					printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
				p=p->next;
			}
			system("pause");
			return 1;
		case 0:
			system("pause");
			return 0;
	}
}
//修改学生信息
void correct(Stu *head) {
	int a;
	printf("\n\t\t\t请输入将要修改的学生的学号：");
	scanf("%d",&a);
	Stu *p;
	p=head;
	while(p!=NULL) {
		if(a==p->num) {
			printf("\t\t要修改的宿舍楼号:");
			scanf("%d",&p->lh);
			printf("\t\t要修改的房间号:");
			scanf("%d",&p->roomnum);
			printf("\t\t要修改的床位号:");
			scanf("%d",&p->bednum);
			printf("\t\t要修改的学院:");
			scanf("%s",&p->xy);
			printf("\t\t要修改的班级:");
			scanf("%s",&p->bj);
			printf("\t\t要修改的学号:");
			scanf("%d",&p->num);
			printf("\t\t要修改的姓名:");
			scanf("%s",&p->name);
			printf("\t\t要修改的性别:");
			scanf("%s",&p->sex);
			printf("\n");
		}
		p=p->next;
	}
}

//删除学生信息
Student *del(Stu *head) {
	int x,y;
	printf("\n\t\t\t1.删除某个学生信息");
	printf("\n\t\t\t2.删除全部学生信息\n");
	printf("\n\t\t\t选择1或2：");
	scanf("%d",&x);
	if(x==1) {
		printf("\n\t\t\t请输入将要删除学生的位置：");
		scanf("%d",&y);
		Stu *p,*q;
		int i;
		if(y-1==0) {
			head=head->next;
		} else {
			p=head;
			for(i=1; i<y&&p->next!=NULL; i++) {
				p=p->next;
			}
			q=p->next;
			p->next=q->next;
		}
		printf("\n\t\t\t删除成功！\n");
		return head;
	} else if(x==2) {
		head=NULL;
		printf("\n\t\t\t删除成功！\n");
		return head;
	} else {
		printf("输入错误，返回主菜单！\n");
		return head;
	}
}

//写入文件
void write_file(Stu *head) {
	FILE *fp;
	if((fp=fopen(F,"at+"))==NULL) {
		printf("文件打开失败！\n");
	}
	Stu *p;
	p=head;
	while(p!=NULL) {
		fprintf(fp,"%d\t",p->lh);
		fprintf(fp,"%d\t",p->roomnum);
		fprintf(fp,"%d\t",p->bednum);
		fprintf(fp,"%s\t",p->xy);
		fprintf(fp,"%s\t",p->bj);
		fprintf(fp,"%d\t",p->num);
		fprintf(fp,"%s\t",p->name);
		fprintf(fp,"%s\n",p->sex);
		p=p->next;
	}
	// 刷新缓冲区，将缓冲区的内容写入文件
	fflush(fp);
	fclose(fp);
}

//读取文件
void read_file() {
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	printf(" 宿舍楼号          房间号               床位号                学院                     ");
	printf("班级                学号                 姓名                  性别\n");
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	int lh;			//宿舍楼号
	int roomnum;	//房间号
	int bednum;		//床位号
	int num;		//学号
	char name[20];	//姓名
	char xy[100];	//学院
	char bj[15];	//班级
	char sex[10];	//性别
	FILE *fp;
	fp=fopen(F,"rt");
	while(fscanf(fp,"%d\t%d\t%d\t%s\t%s\t%d\t%s\t%s",&lh,&roomnum,&bednum,&xy,&bj,&num,&name,&sex)!=EOF) {
		printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",lh,roomnum,bednum,xy,bj,num,name,sex);
	}
}

int main() {

	int n,m,x,y;
	login();
	Stu *head=NULL;
	Stu *pnew;
	for(;;) {
		switch(menu_select()) {
			case 1:
				system("cls");
				printf("\n\n\t\t------------------------------------------------------------\n\n");
				printf("\t\t\t输入学生的个数：");
				scanf("%d",&n);
				if(n<=0) {
					printf("\n\t\t\t请输入正确的人数!");
					Sleep(500);
					break;
				} else {
					printf("\n\t\t\t输入学生数据\n\n");
					head=input(n);
					break;
				}
			case 2:
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t显示学生数据\n");
				output(head);
				system("pause");
				break;
			case 3:
				do {
					x=sort_select(head,sort_menu());
				} while(x!=0);
				break;
			case 4:
				system("cls");
				printf("\n\n\t\t------------------------------------------------------------\n\n");
				printf("\t\t\t输入要插入的学生的信息\n");
				insert(head);
				printf("\n\t\t插入成功！\n");
				system("pause");
				break;
			case 5:
				system("cls");
				do {
					y=find_select(head,find_menu());
				} while(y!=0);
				break;
			case 6:
				system("cls");
				printf("\n\n\t\t------------------------------------------------------------\n\n");
				correct(head);
				printf("\n\t\t\t修改成功！\n");
				system("pause");
				break;
			case 7:
				system("cls");
				printf("\n\n\t\t------------------------------------------------------------\n\n");
				head=del(head);
				system("pause");
				break;
			case 8:
				write_file(head);
				printf("\n\t\t\t写入成功！\n");
				system("pause");
				break;
			case 9:
				printf("\n\t\t\t读取成功！\n");
				read_file();
				system("pause");
				break;
			case 0:
				printf("\n\t\t\t谢谢使用\n");
				exit(0);
		}
	}
}
