#include<stdio.h>
#include<string.h>
/*搭建结构体*/ 
struct book{
	char name[30];
	double price;
};
/*一个读入书本信息的函数*/ 
struct book* getbook(struct book* p)
{
	getchar();
	gets(p->name);
	scanf("%lf",&p->price);
	
	return p;
}
/*找出拥有最小最大价格的书并使用指针传值*/ 
struct book *min(struct book *a,int size,struct book *ret)
{
	int i;
	*ret = a[0];
	for ( i=0; i<size; i++)
	{
		if ( ret->price > a[i].price)
		{
			*ret = a[i];
		}
	}
	return ret;
}

struct book *max(struct book *a,int size,struct book *ret)
{
	int i;
	*ret = a[0];
	for ( i=0; i<size; i++)
	{
		if ( ret->price < a[i].price)
		{
			*ret = a[i];
		}
	}
	return ret;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	struct book list[n];
	
	int i;
	for ( i=0; i<n; i++)
	{
		getbook(&list[i]);
	}

	struct book smax,smin;
	min(list,n,&smin);
	max(list,n,&smax);
	
	printf("%.2f, %s\n",smax.price,smax.name);
	printf("%.2f, %s\n",smin.price,smin.name);
	
	return 0;
 } 