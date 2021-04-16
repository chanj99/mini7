//product.h
//

#ifndef _PP_
#define _PP_


typedef struct Product {
	 char name[50]; //제품명 문자열선언
	 int weight, price, star, numstar;
  	  //중량, 판매가격, 별점, 별점개수
} Product;

int addProduct(Product *p); //물건 목록 만들기
void readProduct(Product p); //물건 목록 읽기
void updateProduct(Product *p); //물건 목록 업데이트
int selectMenu(); //처음 선택 메뉴
int deleteProduct(Product *p);


#endif

