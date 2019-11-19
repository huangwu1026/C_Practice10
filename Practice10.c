//三子棋(两方下棋，一方先连成3个棋子成一条直线（同一行，同一列，对角线），即为胜利
/*
解题思路:
1.创建棋盘并初始化
2.打印棋盘
3.玩家落子
4.判断胜负
5.电脑落子
6.判断胜负
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M_R0W 3
#define M_C0L 3
char ChessBoard[M_R0W][M_C0L];
void Init(){
	//设置随机种子
	srand((unsigned int)time(0));
	for (int i = 0; i < M_R0W; i++){
		for (int j = 0; j < M_C0L; j++){
			ChessBoard[i][j] = ' ';
		}
	}
}
void Print(){
	printf("+---+---+---+\n");
	for (int i = 0; i < M_R0W; i++){
		printf("| %c | %c | %c |\n", ChessBoard[i][0], ChessBoard[i][1], ChessBoard[i][2]);
		printf("+---+---+---+\n");
	}
}
void PlayerMove(){
	printf("玩家落子:\n");
	while (1){
		printf("请输入棋子的位置的坐标(行，列）:");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= M_R0W || col < 0 || col >= M_C0L){
			//输入坐标有误
			printf("您的输入有误，请重新输入\n");
			continue;
		}
		if (ChessBoard[row][col] != ' '){
			//该位置已经有棋子了
			printf("您输入的位置，已经又棋子了\n");
			continue;
		}
		//落子
		ChessBoard[row][col] = 'x';
		break;
	}
}
void ComputerMove(){
	//采取随机数的方式
	printf("电脑落子\n");
	while (1){
		int row = rand() % M_R0W;
		int col = rand() % M_C0L;
		if (ChessBoard[row][col] != ' '){
			//该位置已经有棋子了
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}
}
//返回'x'表示玩家获胜
//返回'o'表示电脑获胜
//返回' '表示胜负未分
//返回'q'表示和棋
int IsFull(){
	//若循环遍历整个棋盘，只要找到一个空格，就为没满   若整个棋盘遍历完后，还没找到空格，就为满了
	for (int row = 0; row < M_R0W; row++){
		for (int col = 0; col < M_C0L; col++){
			if (ChessBoard[row][col] == ' '){
				//棋盘没满
				return 0;
			}
		}
	}
	//棋盘满了
	return 1;
}
char CheckWinner(){
	//检测同一行
	for (int row = 0; row < M_R0W; row++){
		if (ChessBoard[row][0] != ' '&&ChessBoard[row][0] == ChessBoard[row][1]
			&& ChessBoard[row][0] == ChessBoard[row][2])
			return ChessBoard[row][0];
	}
	//检测同一列
	for (int col = 0; col < M_C0L; col++){
		if (ChessBoard[0][col] != ' '&&ChessBoard[0][col] == ChessBoard[1][col]
			&& ChessBoard[0][col] == ChessBoard[2][col])
			return ChessBoard[0][col];
	}
	//检测对角线
	if (ChessBoard[0][0] != ' '&& ChessBoard[0][0] == ChessBoard[1][1]
		&& ChessBoard[0][0] == ChessBoard[2][2])
		return ChessBoard[0][0];
	if (ChessBoard[0][2] != ' '&&ChessBoard[0][2] == ChessBoard[1][1]
		&& ChessBoard[0][2] == ChessBoard[2][0])
		return ChessBoard[0][2];
	//是否和棋
	if (IsFull()){
		return 'q';
	}
	return ' ';
}

int main(){
	//规定下棋双方为电脑和玩家
	//1.创建棋盘并初始化，全设为空格，代表空棋盘
	Init();
	char winner;
	while (1){
		//2.打印棋盘
		Print();
		//3.玩家落子
		PlayerMove();
		//4.判断胜负
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
		//5.电脑落子
		ComputerMove();
		//6.判断胜负
		winner = CheckWinner();
		if (winner != ' '){
			//空格胜负未分，继续输入
			//不是空格结束跳出循环
			break;
		}
	}
	if (winner == 'x'){
		printf("恭喜你，你赢了\n");
		Print();
	}
	else if (winner == 'o'){
		printf("真遗憾，你输了\n");
	}
	else{
		printf("平局\n");
	}
	system("pause");
	return 0;
}
