//������(�������壬һ��������3�����ӳ�һ��ֱ�ߣ�ͬһ�У�ͬһ�У��Խ��ߣ�����Ϊʤ��
/*
����˼·:
1.�������̲���ʼ��
2.��ӡ����
3.�������
4.�ж�ʤ��
5.��������
6.�ж�ʤ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M_R0W 3
#define M_C0L 3
char ChessBoard[M_R0W][M_C0L];
void Init(){
	//�����������
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
	printf("�������:\n");
	while (1){
		printf("���������ӵ�λ�õ�����(�У��У�:");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= M_R0W || col < 0 || col >= M_C0L){
			//������������
			printf("����������������������\n");
			continue;
		}
		if (ChessBoard[row][col] != ' '){
			//��λ���Ѿ���������
			printf("�������λ�ã��Ѿ���������\n");
			continue;
		}
		//����
		ChessBoard[row][col] = 'x';
		break;
	}
}
void ComputerMove(){
	//��ȡ������ķ�ʽ
	printf("��������\n");
	while (1){
		int row = rand() % M_R0W;
		int col = rand() % M_C0L;
		if (ChessBoard[row][col] != ' '){
			//��λ���Ѿ���������
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}
}
//����'x'��ʾ��һ�ʤ
//����'o'��ʾ���Ի�ʤ
//����' '��ʾʤ��δ��
//����'q'��ʾ����
int IsFull(){
	//��ѭ�������������̣�ֻҪ�ҵ�һ���ո񣬾�Ϊû��   ���������̱�����󣬻�û�ҵ��ո񣬾�Ϊ����
	for (int row = 0; row < M_R0W; row++){
		for (int col = 0; col < M_C0L; col++){
			if (ChessBoard[row][col] == ' '){
				//����û��
				return 0;
			}
		}
	}
	//��������
	return 1;
}
char CheckWinner(){
	//���ͬһ��
	for (int row = 0; row < M_R0W; row++){
		if (ChessBoard[row][0] != ' '&&ChessBoard[row][0] == ChessBoard[row][1]
			&& ChessBoard[row][0] == ChessBoard[row][2])
			return ChessBoard[row][0];
	}
	//���ͬһ��
	for (int col = 0; col < M_C0L; col++){
		if (ChessBoard[0][col] != ' '&&ChessBoard[0][col] == ChessBoard[1][col]
			&& ChessBoard[0][col] == ChessBoard[2][col])
			return ChessBoard[0][col];
	}
	//���Խ���
	if (ChessBoard[0][0] != ' '&& ChessBoard[0][0] == ChessBoard[1][1]
		&& ChessBoard[0][0] == ChessBoard[2][2])
		return ChessBoard[0][0];
	if (ChessBoard[0][2] != ' '&&ChessBoard[0][2] == ChessBoard[1][1]
		&& ChessBoard[0][2] == ChessBoard[2][0])
		return ChessBoard[0][2];
	//�Ƿ����
	if (IsFull()){
		return 'q';
	}
	return ' ';
}

int main(){
	//�涨����˫��Ϊ���Ժ����
	//1.�������̲���ʼ����ȫ��Ϊ�ո񣬴��������
	Init();
	char winner;
	while (1){
		//2.��ӡ����
		Print();
		//3.�������
		PlayerMove();
		//4.�ж�ʤ��
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
		//5.��������
		ComputerMove();
		//6.�ж�ʤ��
		winner = CheckWinner();
		if (winner != ' '){
			//�ո�ʤ��δ�֣���������
			//���ǿո��������ѭ��
			break;
		}
	}
	if (winner == 'x'){
		printf("��ϲ�㣬��Ӯ��\n");
		Print();
	}
	else if (winner == 'o'){
		printf("���ź���������\n");
	}
	else{
		printf("ƽ��\n");
	}
	system("pause");
	return 0;
}
