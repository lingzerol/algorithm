
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXN  64
#define Sid 8
int direction[8][2] = { { -2,1 },{ -1,2 },{ 1,2 },{ 2,1 },{ 2,-1 },{ 1,-2 },{ -1,-2 },{ -2,-1 } };

typedef struct {
	int x, y, k;
	int divideDirection[8];
}Position;
typedef struct Stack{
	Position *base, *top;
	Position *elem;
	int size;
}Stack;

Stack stack;


void Init(Stack *s) {
	s->size = 64;
	s->base = (Position *)malloc(sizeof(Position)*s->size);
	s->top = s->base;
}
void Push(Position *e) {
	memcpy(stack.top++, e, sizeof(Position));
}
void Pop(Position *e) {
	memcpy(e, --stack.top, sizeof(Position));
}
int map[8][8];
int check(Position *elem) {
	if (elem->x >= 0 && elem->x < 8 && elem->y >= 0 && elem->y < 8 && map[elem->x][elem->y] == 0) {
		return 1;
	}
	return 0;
}
int empty() {
	if (stack.top != stack.base)
		return 0;
	else return 1;
}
void SortDirection(Position *Pos) {
	int i, j,tmp;
	Position Next1, Next2;
	int pos[8];
	for (i = 0; i < 8; ++i) {
		pos[i] = 0;
		Next1.x = Pos->x + direction[i][0];
		Next1.y = Pos->y + direction[i][1];
		if(check(&Next1))
		for (j = 0; j < 8; ++j) {
			Next2.x = Next1.x + direction[j][0];
			Next2.y = Next1.y + direction[j][1];
			if(check(&Next2))pos[i]++;
		}
	}

	for (i = 0; i < 8; ++i)Pos->divideDirection[i] = i;
	for (i = 0; i < 8; ++i) {
		for (j = i + 1; j < 8; ++j) {
			if (pos[i]>pos[j]) {
				tmp = pos[i]; pos[i] = pos[j]; pos[j] = tmp;
				tmp = Pos->divideDirection[i];
				Pos->divideDirection[i] = Pos->divideDirection[j];
				Pos->divideDirection[j] = tmp;
			}
		}
	}
	i = 0;
	while (pos[i] == 0)i++;
	Pos->k = i - 1;
}//作用：找出空闲位置，然后按照不同方向的可跳道路的数目排序，先跳到可跳道路数目少的地方，再跳到可跳数目多的地方，防止出现调到非常空的位置去，从而无法实现跳满整个棋盘

int main() {
	Position start, Nextp,Nowp,Nextnp;
	int m = 1;
	int i, j;
	int flag;
	memset(map, 0, sizeof(map));
	start.x = 2;
	start.y = 3;
	start.k = 0;
	map[2][3] = 1;
	SortDirection(&start);
	Init(&stack);
	Push(&start);
	while (!empty()) {
		Pop(&Nowp);
		Nowp.k++;
		if (Nowp.k < 8) {
			Nextp.x = Nowp.x + direction[Nowp.divideDirection[Nowp.k]][0];
			Nextp.y = Nowp.y + direction[Nowp.divideDirection[Nowp.k]][1];
			map[Nextp.x][Nextp.y] = map[Nowp.x][Nowp.y]+1;
			SortDirection(&Nextp);
			if (map[Nextp.x][Nextp.y] == 63) {
				for (i = 0; i < 8; ++i) {
					Nextnp.x = Nextp.x + direction[i][0];
					Nextnp.y = Nextp.y + direction[i][1];
					if (check(&Nextnp)) {
						map[Nextnp.x][Nextnp.y] = 64;
						break;
					}
				}
				if (i < 8) {
					break;
				}
			}
		}
		Push(&Nowp);
		Push(&Nextp);
	}
	if (!empty())
	{
		for (i = 0; i < 8; ++i) {
			for (j = 0; j < 8; ++j) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}
	else printf("no");
	scanf("%d", &m);
}