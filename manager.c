//manager.c


#include <stdio.h>
#include <string.h>
#include "manager.h"

void listProduct(Product *p, int count){//목록 전체 읽기
	printf("제품명:  중량   판매가격   별점\n");
	printf("================================\n");
	for(int i =0; i<count; i++){
		if(p[i].price == -1 && p[i].weight==-1 && p[i].star == -1 )continue;
		printf("%d", i+1);
		printf("  %s    %d(gram)   %d원    %d 개\n ", p[i].name, p[i].weight, p[i].price, p[i].star);

	}
}


void saveData(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");

	for(int i =0; i<count; i++){

		if(p[i].price == -1 && p[i].weight==-1 && p[i].star == -1 )continue;
		fprintf(fp, "%s %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].star );

	}
		fclose(fp);
		printf("==> 저장완료!!\n");


}

int loadData(Product *p){
	int count = 0;
	FILE *fp;
	fp = fopen("product.txt", "rt"); //읽기모드로 파일 열기
	if(fp == NULL){
		printf("==> 파일 없음\n");
		return 0;
	}
	else if(fp != NULL){
		for(int i =0; i<100; i++){
			fscanf(fp, "%s", p[i].name);
			if(feof(fp)) break;
			fscanf(fp, "%d", &p[i].weight);
			fscanf(fp, "%d", &p[i].price);
			fscanf(fp, "%d", &p[i].star);
			count++;
		}
		fclose(fp);
		printf("==>로딩성공!\n");
		return count;

	}

}

void search(Product *p, int count){
	printf("검색할 내용을 고르세요!\n");
	printf("=======================\n");
	printf("1. 이름\n");
	printf("2. 가격\n");
	printf("3. 별점\n");
	printf("==>");
	int num;
	scanf("%d", &num);

	if(num == 1){
	char search[30];
	int productnum=0;
	printf("검색할 물건 이름은? ");
	scanf("%s", search);

	printf("제품명:  중량   판매가격   별점\n");
	printf("================================\n");
	for(int k=0; k<count; k++){
		if(strstr(p[k].name, search)){
		printf("%d", productnum+1);
		printf(" %s   %d(gram)  %d원   %d 개\n ", p[k].name, p[k].weight, p[k].price, p[k].star);
		productnum++;
	}

		}
	if(productnum == 0){
		printf("검색된 데이터 없음!\n");
	}

	}

	if(num == 2){
	int searchprice;
	int productnum=0;
	printf("검색할 물건의 가격은? ");
	scanf("%d", &searchprice);

	printf("제품명:  중량   판매가격   별점\n");
	printf("================================\n");
	for(int k=0; k<count; k++){
		if(p[k].price ==  searchprice){
		printf("%d", productnum+1);
		printf(" %s   %d(gram)  %d원   %d 개\n ", p[k].name, p[k].weight, p[k].price, p[k].star);
		productnum++;
		}
       	}
	if(productnum == 0){
		printf("검색된 데이터 없음!\n");
	}

	}

	else if(num == 3){
	int searchstar;
	int productnum=0;
	printf("검색할 물건의 별점은? ");
	scanf("%d", &searchstar);

	printf("제품명:  중량   판매가격   별점\n");
	printf("================================\n");
	for(int k=0; k<count; k++){
		if(p[k].star ==  searchstar){
		printf("%d", productnum+1);
		printf("  %s    %d(gram)   %d원    %d 개\n ", p[k].name, p[k].weight, p[k].price, p[k].star);
		productnum++;
		}

		}

	if(productnum == 0){
		printf("검색된 데이터 없음!\n");
	}
	}



	}

