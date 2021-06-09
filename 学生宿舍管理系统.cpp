# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
# define F "����.txt" //�ļ�·��

typedef struct Student {
	int lh;			//����¥��
	int roomnum;	//�����
	int bednum;		//��λ��
	int num;		//ѧ��
	char name[20];	//����
	char xy[100];	//ѧԺ
	char bj[15];	//�༶
	char sex[10];	//�Ա�
	struct Student *next;
} Stu;

//��¼����
void login() {
	char userName[5];
	char password[5];
	int i,sum;
	//system("color 3E");
	printf("\n\n   ---------------------------------��ӭʹ��---------------------------------\n");
	for(i=1; i<4; i++) {
		printf("\n       �����������û���:");
		gets(userName);
		printf("\n       ��������������:");
		gets(password);
		if ((strcmp(userName,"001")==0) && (strcmp(password,"123")==0)) { /*��֤�û���������*/

			printf("\n   ---------------------------------��½�ɹ�---------------------------------");
			Sleep(500);
			return;
		} else {
			if(i<3) {
				printf("\n     �û����������������������!\n");
			} else {
				printf("\n     ��������3�ν��û������������ϵͳ���˳�!");
				exit(0);
			}
		}
	}
}

//�˵�ѡ��
int menu_select() {
	int a;
	do {
		system("cls");
		printf("\n\n\t\t----------------------ѧ���������ϵͳ----------------------\n\n");
		printf("\t\t��� 1. ���ѧ����Ϣ                        ���\n\n");
		printf("\t\t��� 2. ��ʾѧ����Ϣ                        ���\n\n");
		printf("\t\t��� 3. ����Ϣ������ʾ                    ���\n\n");
		printf("\t\t��� 4. ����ѧ����Ϣ                        ���\n\n");
		printf("\t\t��� 5. ����ѧ����Ϣ                        ���\n\n");
		printf("\t\t��� 6. �޸�ѧ����Ϣ                        ���\n\n");
		printf("\t\t��� 7. ɾ��ѧ����Ϣ                        ���\n\n");
		printf("\t\t��� 8. ����Ϣд���ļ�                      ���\n\n");
		printf("\t\t��� 9. ��ȡ�ļ��е���Ϣ                    ���\n\n");
		printf("\t\t��� 0. �˳�ϵͳ                            ���\n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
		scanf("%d",&a);
	} while(a<0||a>9);
	return a;
}

//���ѧ����Ϣ
Student *input(int n) {
	int i;
	Stu *head,*l,*r;
	if(n<=0) {
		return NULL;
	}
	l=(Stu *)malloc(sizeof(Stu));
	printf("\t\t����¥��:");
	scanf("%d",&l->lh);
	printf("\t\t�����:");
	scanf("%d",&l->roomnum);
	printf("\t\t��λ��:");
	scanf("%d",&l->bednum);
	printf("\t\tѧԺ:");
	scanf("%s",&l->xy);
	printf("\t\t�༶:");
	scanf("%s",&l->bj);
	printf("\t\tѧ��:");
	scanf("%d",&l->num);
	printf("\t\t����:");
	scanf("%s",&l->name);
	printf("\t\t�Ա�:");
	scanf("%s",&l->sex);
	printf("\n");
	head=l;
	for(i=1; i<n; i++) {
		r=(Stu *)malloc(sizeof(Stu));
		printf("\t\t����¥��:");
		scanf("%d",&r->lh);
		printf("\t\t�����:");
		scanf("%d",&r->roomnum);
		printf("\t\t��λ��:");
		scanf("%d",&r->bednum);
		printf("\t\tѧԺ:");
		scanf("%s",&r->xy);
		printf("\t\t�༶:");
		scanf("%s",&r->bj);
		printf("\t\tѧ��:");
		scanf("%d",&r->num);
		printf("\t\t����:");
		scanf("%s",&r->name);
		printf("\t\t�Ա�:");
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

//���ѧ����Ϣ
void output(Stu *head) {
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
	printf("�༶                ѧ��                 ����                  �Ա�\n");
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL) {
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	} else {
		do {
			printf("%3d%20d%20d%30s%20s%20d%20s%20s\n",p->lh,p->roomnum,p->bednum,p->xy,p->bj,p->num,p->name,p->sex);
			p=p->next;
		} while(p!=NULL);
	}
}

//����˵�
int sort_menu() {
	int a;
	do {
		system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n");
		printf("\t\t\t1. ��������¥������\n\n");
		printf("\t\t\t2. ���շ��������\n\n");
		printf("\t\t\t3. ���մ�λ������\n\n");
		printf("\t\t\t4. ����ѧ������\n\n");
		printf("\t\t\t0. ���ص����˵�\n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t\t��ѡ����Ҫ���е�ѡ�(0-4):");
		scanf("%d",&a);
	} while(a<0||a>8);
	return a;
}
//����ѡ��˵�
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

//����ѧ����Ϣ
void insert(Stu *head) {
	Stu *p,*pnew;
	int m;
	pnew=(Stu *)malloc(sizeof(Stu));
	printf("\t\t����¥��:");
	scanf("%d",&pnew->lh);
	printf("\t\t�����:");
	scanf("%d",&pnew->roomnum);
	printf("\t\t��λ��:");
	scanf("%d",&pnew->bednum);
	printf("\t\tѧԺ:");
	scanf("%s",&pnew->xy);
	printf("\t\t�༶:");
	scanf("%s",&pnew->bj);
	printf("\t\tѧ��:");
	scanf("%d",&pnew->num);
	printf("\t\t����:");
	scanf("%s",&pnew->name);
	printf("\t\t�Ա�:");
	scanf("%s",&pnew->sex);
	printf("\n");
	printf("\t\t\t��������Ҫ�嵽��λ�ã�");
	scanf("%d",&m);
	p=head;
	for(int j=1; j<m&&p!=NULL; j++) {
		p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}

//���Ҳ˵�
int find_menu() {
	int a;
	do {
		system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n");
		printf("\t\t\t1. ��������¥�Ų���\n\n");
		printf("\t\t\t2. ���շ���Ų���\n\n");
		printf("\t\t\t3. ���մ�λ�Ų���\n\n");
		printf("\t\t\t4. ����ѧԺ����\n\n");
		printf("\t\t\t5. ���հ༶����\n\n");
		printf("\t\t\t6. ����ѧ�Ų���\n\n");
		printf("\t\t\t7. ������������\n\n");
		printf("\t\t\t8. �����Ա����\n\n");
		printf("\t\t\t0. ���ص����˵�\n\n");
		printf("\t\t------------------------------------------------------------\n");
		printf("\t\t��ѡ����Ҫ���е�ѡ�(1-8):");
		scanf("%d",&a);
	} while(a<0||a>8);
	return a;
}
//����ѡ��˵�
int find_select(Stu *head,int n) {
	Stu *p;
	switch(n) {
		case 1:
			system("cls");
			p=head;
			int a;
			printf("\n\t\t\tҪ���ҵ�����¥��Ϊ��");
			scanf("%d",&a);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵķ����Ϊ��");
			scanf("%d",&b);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵĴ�λ��Ϊ��");
			scanf("%d",&c);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵ�ѧԺΪ��");
			scanf("%s",&d);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵİ༶Ϊ��");
			scanf("%s",&e);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵ�ѧ��Ϊ��");
			scanf("%d",&f);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵ�����Ϊ��");
			scanf("%s",&g);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
			printf("\n\t\t\tҪ���ҵ��Ա�Ϊ��");
			scanf("%s",&h);
			printf(" -------------------------------------------------------------------------------");
			printf("-------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
			printf("�༶                ѧ��                 ����                  �Ա�\n");
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
//�޸�ѧ����Ϣ
void correct(Stu *head) {
	int a;
	printf("\n\t\t\t�����뽫Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d",&a);
	Stu *p;
	p=head;
	while(p!=NULL) {
		if(a==p->num) {
			printf("\t\tҪ�޸ĵ�����¥��:");
			scanf("%d",&p->lh);
			printf("\t\tҪ�޸ĵķ����:");
			scanf("%d",&p->roomnum);
			printf("\t\tҪ�޸ĵĴ�λ��:");
			scanf("%d",&p->bednum);
			printf("\t\tҪ�޸ĵ�ѧԺ:");
			scanf("%s",&p->xy);
			printf("\t\tҪ�޸ĵİ༶:");
			scanf("%s",&p->bj);
			printf("\t\tҪ�޸ĵ�ѧ��:");
			scanf("%d",&p->num);
			printf("\t\tҪ�޸ĵ�����:");
			scanf("%s",&p->name);
			printf("\t\tҪ�޸ĵ��Ա�:");
			scanf("%s",&p->sex);
			printf("\n");
		}
		p=p->next;
	}
}

//ɾ��ѧ����Ϣ
Student *del(Stu *head) {
	int x,y;
	printf("\n\t\t\t1.ɾ��ĳ��ѧ����Ϣ");
	printf("\n\t\t\t2.ɾ��ȫ��ѧ����Ϣ\n");
	printf("\n\t\t\tѡ��1��2��");
	scanf("%d",&x);
	if(x==1) {
		printf("\n\t\t\t�����뽫Ҫɾ��ѧ����λ�ã�");
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
		printf("\n\t\t\tɾ���ɹ���\n");
		return head;
	} else if(x==2) {
		head=NULL;
		printf("\n\t\t\tɾ���ɹ���\n");
		return head;
	} else {
		printf("������󣬷������˵���\n");
		return head;
	}
}

//д���ļ�
void write_file(Stu *head) {
	FILE *fp;
	if((fp=fopen(F,"at+"))==NULL) {
		printf("�ļ���ʧ�ܣ�\n");
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
	// ˢ�»���������������������д���ļ�
	fflush(fp);
	fclose(fp);
}

//��ȡ�ļ�
void read_file() {
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	printf(" ����¥��          �����               ��λ��                ѧԺ                     ");
	printf("�༶                ѧ��                 ����                  �Ա�\n");
	printf(" -------------------------------------------------------------------------------");
	printf("-------------------------------------------------------------------------------\n");
	int lh;			//����¥��
	int roomnum;	//�����
	int bednum;		//��λ��
	int num;		//ѧ��
	char name[20];	//����
	char xy[100];	//ѧԺ
	char bj[15];	//�༶
	char sex[10];	//�Ա�
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
				printf("\t\t\t����ѧ���ĸ�����");
				scanf("%d",&n);
				if(n<=0) {
					printf("\n\t\t\t��������ȷ������!");
					Sleep(500);
					break;
				} else {
					printf("\n\t\t\t����ѧ������\n\n");
					head=input(n);
					break;
				}
			case 2:
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t��ʾѧ������\n");
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
				printf("\t\t\t����Ҫ�����ѧ������Ϣ\n");
				insert(head);
				printf("\n\t\t����ɹ���\n");
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
				printf("\n\t\t\t�޸ĳɹ���\n");
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
				printf("\n\t\t\tд��ɹ���\n");
				system("pause");
				break;
			case 9:
				printf("\n\t\t\t��ȡ�ɹ���\n");
				read_file();
				system("pause");
				break;
			case 0:
				printf("\n\t\t\tллʹ��\n");
				exit(0);
		}
	}
}
