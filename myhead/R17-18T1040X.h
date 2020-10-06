#ifndef R17_18T1040X_H_INCLUDED
#define R17_18T1040X_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Body�^�̐錾
typedef struct {
	double	height;		//�g��
	double	weight;		//�̏d
} Body;

//Membe�^�̐錾r
typedef struct member{
	struct member	*next;		//���̃m�[�h�ւ̃|�C���^
	int				ID;			//ID�i���o�[
	char			name[25];	//����
	Body			info;		//�g�̏��
} Member;


//�֐��̃v���g�^�C�v�錾
Member *Alloc_Node(void);
void print_list(Member *start);
void print_node(Member *node);
void load_data(Member *start);
void name_Search(Member *start);
void ID_Search(Member *start);
int menu(void);

#endif

