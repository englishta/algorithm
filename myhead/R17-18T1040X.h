#ifndef R17_18T1040X_H_INCLUDED
#define R17_18T1040X_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Body型の宣言
typedef struct {
	double	height;		//身長
	double	weight;		//体重
} Body;

//Membe型の宣言r
typedef struct member{
	struct member	*next;		//次のノードへのポインタ
	int				ID;			//IDナンバー
	char			name[25];	//氏名
	Body			info;		//身体情報
} Member;


//関数のプロトタイプ宣言
Member *Alloc_Node(void);
void print_list(Member *start);
void print_node(Member *node);
void load_data(Member *start);
void name_Search(Member *start);
void ID_Search(Member *start);
int menu(void);

#endif

