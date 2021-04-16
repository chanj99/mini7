//product.c

#include <stdio.h>
#include "product.h"
#include <string.h>


int deleteProduct(Product *p){
	p->price = -1;
	p->weight = -1;
	p->star = -1;
	printf("삭제됨!\n");
	return 1;

}

int selectMenu(){
	int menu = 0;
	printf("\n메뉴를 고르세요!\n");
	printf("******************\n");
	printf("1. 제품 조회\n");
	printf("2. 제품 추가\n");
	printf("3. 제품 수정\n");
	printf("4. 제품 삭제\n");
	printf("5. 제품 검색\n");
	printf("6. 파일 저장\n");
	printf("0. 종료\n");
	printf("원하는 메뉴는?");
	scanf(" %d", &menu);
	return menu;

}

int addProduct(Product *p){
	int count =0;
	printf("제품명은?");
	scanf("%s",p->name);
	printf("중량은(g)?");
	scanf(" %d",&p->weight);
	printf("가격은?");
	scanf(" %d", &p->price);
	printf("별점은?");
	scanf(" %d", &p->star);
	printf("추가됨!\n");
	count++;
	return count;
}

void updateProduct(Product *p){
	printf("제품명은?");
	scanf(" %s",p->name);
	printf("중량은(g)?");
	scanf(" %d", &p->weight);
	printf("가격은?");
	scanf(" %d", &p->price);
	printf("별점은?");
	scanf(" %d", &p->star);
}

void readProduct(Product p){
	printf("제품명 :   중량    판매가격    별점\n");
	if(p.weight != -1)
		printf("  %s    %d(gram)   %d원    %d 개\n ", p.name, p.weight, p.price, p.star );

}

