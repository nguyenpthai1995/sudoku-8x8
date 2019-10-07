/*
	kiem tra dieu kien ma tran dau vao xem co thoa hay chua, tranh truong hop ma tran ban dau chua chuan
	neu ma tran ban dau chuan roi thi tien hanh them cac gia tri o trong de hoan thanh ma tran
*/

#include<iostream>
using namespace std;
int A[8][8]; //ma tran ban dau
int R[8][8]; //ma tran sau khi hoan thanh
int B[9]; //voi cac gia tri tu 0->8 de dem so luong cac gia tri trong moi hang, cot, o vuong con 4x4
int countT = 0; //dem so ma tran sau khi hoan thanh, dung de dung bai toan o cac ma tran co nhieu ket qua

bool checkSatis(int x, int y, int k){
	bool ans = true;
	int count = 1;
	for(int i=0; i<8; i++)
		if(A[x][i] == k || A[i][y] == k)  //kiem tra doc ngang
			ans = false;
			
	int a = x/4, b = y/4;
	for(int i = a*4; i < a*4+4; i++)    //kiem tra trong pham vi 4x4 
		for(int j = b*4; j < b*4+4; j++)
			if(A[i][j] == k)
				count++;
				
	if(count > 2)      //trong pham vi 4 o con 4x4 duoc trung 1 so toi da chi duoc 2 lan
		ans = false;
	return ans;
}

void resetMatric(){
	for(int i = 0; i < 9; i++)
		B[i] = 0;	
}

bool checkMatric(){
	bool ans = true;
	for(int i = 0; i < 8; i++){
		resetMatric();
		for(int j = 0; j < 8; j++){
			if(A[i][j] > 0){
				B[A[i][j]]++;
				if(B[A[i][j]] > 1)    //kiem tra cac hang ban dau khong co gia tri trung nhau
					ans = false;
			}
		}
	}
	for(int i = 0; i < 8; i++){
		resetMatric();
		for(int j = 0; j < 8; j++){
			if(A[j][i] > 0){
				B[A[j][i]]++;
				if(B[A[j][i]] > 1)   //kiem tra cac cot ban dau khong co gia tri trung nhau
					ans = false;
			}
		}
	}
		
	//kiem tra 4 ma tran con 4x4 
	resetMatric();	
	for(int i = 0; i < 4; i++)  // tren trai
		for(int j = 0; j < 4; j++)
			if(A[i][j] > 0){
				B[A[i][j]]++;
				if(B[A[j][i]] > 2)   
					ans = false;
			}
	resetMatric();
	for(int i = 0; i < 4; i++)    //tren phai
		for(int j = 4; j < 8; j++)
			if(A[i][j] > 0){
				B[A[i][j]]++;
				if(B[A[j][i]] > 2)   
					ans = false;
			}
	resetMatric();
	for(int i = 4; i < 8; i++)    //duoi trai
		for(int j = 0; j < 4; j++)
			if(A[i][j] > 0){
				B[A[i][j]]++;
				if(B[A[j][i]] > 2)   
					ans = false;
			}
	resetMatric();
	for(int i = 4; i < 8; i++)   //duoi phai
		for(int j = 4; j < 8; j++)
			if(A[i][j] > 0){
				B[A[i][j]]++;
				if(B[A[j][i]] > 2)   
					ans = false;
			}
	return ans;
}

void saveResult(){
	for(int i = 0; i < 64; i++)
		R[i/8][i%8] = A[i/8][i%8];
}

void resetMR(){
	for(int i = 0; i < 64; i++)
		R[i/8][i%8] = 0;	
}

bool result(int x, int y){
	if(countT == 0){
		if(y == 8){
			if(x == 7){
					countT++;	 
					saveResult();			
			}else{
				result(x+1,0);  //y=0 chay lai tu cot dau tien, x+1 tang hang de duyet tiep
			}
		}
		else if(A[x][y] == 0){
			
			for(int k = 1; k < 9; k++)
				if(checkSatis(x,y,k)){  //k se co nhieu gia tri vi du: 3,4,7 voi moi gia tri la 1 nhanh cua cay
					A[x][y] = k; //moi nhanh do ta gan gia tri tai o 0 lai bang k (k=3)
					result(x,y+1); //di thang xuong toi khi het nhanh k=3 do
					A[x][y] = 0; //gan lai gia tri o ve lai 0 de cho cac nhanh k=4,7 khac di vao o nay					
				}		
		}else if(A[x][y] != 0){
			result(x,y+1);
		}
	}
	return (countT>0)?true:false;
}

void printMatric(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++)
			cout << R[i][j] << " ";
		cout << endl;
	}
}

int main(){
	int T,c;
	freopen("sudoku_8x8.txt","r",stdin);
	cin >> T;
	
	for(int tc = 1; tc <= T; tc++){
		countT = 0;
		resetMR();
		for(int i = 0; i < 64; i++){
			cin >> c;
			A[i/8][i%8] = c;
		}
		if(checkMatric()){
			if(result(0,0)){
				cout << "Test case #" << tc << ": YES" << endl;
				printMatric();	
			}else
				cout << "Test case #" << tc << ": NO" << endl;		
		}else
			cout << "Test case #" << tc << ": NO" << endl;	
						
	}
	return 0;
}
