//main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

int main(){
        Product p[20];
        int menu = 0, count = 0, index =0;

	count = loadData(p);
	index = count;


        while(1){
        menu = selectMenu();

        if(menu == 0) break;

        else if(menu == 2){//추가

              count += addProduct(&p[index]);
	      index++;

        }
        else if(menu == 1){ //출력
		if(count>0){
                listProduct(p, index);
		}
		else
			printf("현재 물건이 없습니다!!\n");
        }

        else if(menu == 3){//데이터 업데이트
		int num;
                listProduct(p, index);
		printf("수정할 번호를 고르세요!!(취소는 0)");
		scanf("%d", &num);
		if(num<= 0){
			printf("취소됨!\n");
			continue;
		}
		updateProduct(&p[num-1]);
		continue;
        }


        else if(menu == 4){
		int num;
		listProduct(p, index);
		printf("삭제할 물건의 번호를 고르세요!!(취소는 0번)");
		scanf("%d", &num);
		if(num == 0){
			printf("취소됨!\n");
			continue;
		}
		int isdelete;
		printf("정말로 삭제하시겠습니까? (삭제 1)");
		scanf("%d", &isdelete);
		if(isdelete ==  1)
			if(deleteProduct(&p[num-1]))
			 count--;

        }

	else if(menu == 5){ //검색기능 추가
		search(p, index);

	}

	else if(menu ==6){ //파일 저장 기능 추가
		saveData(p, index);
	}


     }

        return 0;
}

