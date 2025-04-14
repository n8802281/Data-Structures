#define input "input.txt"
#define output "output.txt"
#include <stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int** createMatrix(int rowNum, int colNum){
	int i, j;
	int** matrix = (int**)malloc(rowNum * sizeof(int*));
	for (i = 0; i < rowNum; i++) {
		matrix[i] = (int*)malloc(colNum * sizeof(int));
		for (j = 0; j < colNum; j++)
			matrix[i][j] = 999999;
	}
	return matrix;
}

void shiftUp(int** matrix, int rowIndex, int colIndex) {
	int a=-1,b=-1;
	if(colIndex > 0)
		a = matrix[rowIndex][colIndex-1];
	if(rowIndex > 0)
		b = matrix[rowIndex-1][colIndex];
	if(matrix[rowIndex][colIndex] < b && b>=a){
		//printf("\nswaping  matrix[%d][%d]=%d and matrix[%d][%d]= %d\n",rowIndex,colIndex,matrix[rowIndex][colIndex],rowIndex-1,colIndex,matrix[rowIndex-1][colIndex]);
		swap(&matrix[rowIndex][colIndex],&matrix[rowIndex-1][colIndex]);
		shiftUp(matrix, rowIndex-1, colIndex);
	}else if(matrix[rowIndex][colIndex] < a && a>=b){
		//printf("\nswaping  matrix[%d][%d]=%d and matrix[%d][%d]= %d\n",rowIndex,colIndex,matrix[rowIndex][colIndex],rowIndex,colIndex-1,matrix[rowIndex][colIndex-1]);		
		swap(&matrix[rowIndex][colIndex],&matrix[rowIndex][colIndex-1]);
		shiftUp(matrix, rowIndex, colIndex-1);
	}
}

void insertMatrix(int** matrix, int value, int rowNum, int colNum) {
	matrix[rowNum - 1][colNum - 1] = value;
	shiftUp(matrix, rowNum - 1, colNum - 1);
}

void shiftDown(int** matrix, int rowIndex, int colIndex) {
	int a = matrix[rowIndex+1][colIndex]; 
	int b = matrix[rowIndex][colIndex+1];
	if(a != 999999 || b != 999999){
		if(matrix[rowIndex][colIndex] > a && a<=b){
			swap(&matrix[rowIndex][colIndex],&matrix[rowIndex+1][colIndex]);
			shiftDown(matrix, rowIndex+1, colIndex);
		}
		else if(matrix[rowIndex][colIndex] > b && b<=a){
			swap(&matrix[rowIndex][colIndex],&matrix[rowIndex][colIndex+1]);
			shiftDown(matrix, rowIndex, colIndex+1);
		}
	}
}

int extractMin(int** matrix) {
	int min = matrix[0][0];
	matrix[0][0] = 999999;
	shiftDown(matrix, 0, 0);
	return min;
}

void destroyMatrix(int** matrix, int rowNum){
	if (NULL == matrix)
		return;
	for (int i = 0; i < rowNum; i++)
		free(matrix[i]);
	free(matrix);
}

void findMaxAndSwap(int** matrix, int rowNum, int colNum){//no need to find max
	int max = -1;
	int maxRow,maxCol;
	for(int i = rowNum-1; i >= 0; i--){
		for(int j = colNum-1; j >= 0 ; j--){
			if(matrix[i][j] != 999999){
				if(matrix[i][j] > max){
					max = matrix[i][j];
					maxRow = i;
					maxCol = j;					
				}
				break;
			}
		}
	}
	matrix[0][0] = 999999;
	swap(&matrix[0][0],&matrix[maxRow][maxCol]);
}

int main(){
	FILE *filein,*fileout;
	filein = fopen(input,"r");
    fileout = fopen(output,"w");
    char ch,ch2;
    int cycle = getc(filein) - '0';
    int type;
    int var[10];
    ch = getc(filein);
	while(cycle){
		//get type
    	type = getc(filein) - '0';
    	ch = getc(filein);// ch=\n
    	
    	int k;
    	if(type == 1){//get var when inserting
    		for(int i = 0; i < 10 ; i++)
    			var[i] = 0;
    		k = 0;
    		ch2 = ch;
			ch = getc(filein); //first char
    		while(1){
    			ch2 = ch;
				ch = getc(filein); 
				if(ch2 <='9' && ch2 >='0'){
					var[k] = var[k]*10+(ch2-'0');	
					//printf("\nset var[%d] to %d\n",k,var[k]);
				}
				
				if(ch == ' ') 
					k++;
    			else if(ch == '\n') 	
    				break;
			}	
		}
		
		//set up the matrix
    	int** matrix = createMatrix(30, 30);
    	ch2 = ch;
		ch = getc(filein); 
		int insvar;
		int rrow = 0, ccol = 0, rownum = 0, colnum = 0;
    	while(1){
    		ch2 = ch;
			ch = getc(filein); 
			if(ch == '\n' && ch2 == '\n'){
				rownum = rrow;
				break;	
			} 
			if(ch2 <='9' && ch2 >='0'){
				if(matrix[rrow][ccol] == 999999) {
					matrix[rrow][ccol] = 0;	
				}
				matrix[rrow][ccol] = matrix[rrow][ccol]*10+(ch2-'0');
				//printf("\nset matrix[%d][%d] to %d\n",rrow,ccol,matrix[rrow][ccol]);	
			}else if (ch2 == 'x')
				matrix[rrow][ccol] = 999999;
			if(ch == ' ') 
				ccol++;
			else if (ch == '\n'){
				colnum = ccol + 1;
				ccol = 0;
				rrow+=1;
			}
		}
		
        //run the command
        int minvalue = 0;
        if(type == 1){//insert
			for(int i = 0 ; i <= k ; i ++){
				insertMatrix(matrix, var[i], rownum, colnum);
			}
    	}
		if(type == 2)//extract-min
			minvalue = extractMin(matrix);
		
		//printing output
		if(type == 1){//insert
			//printf("Insert");
			fprintf(fileout,"Insert");
			for(int i = 0 ; i <= k ; i ++){
				//printf(" %d",var[i]);
				fprintf(fileout," %d",var[i]);
			}
			//printf("\n");
			fprintf(fileout,"\n");
    	}else if(type == 2){//extract-min
			//printf("Extract-min %d\n",minvalue);
			fprintf(fileout,"Extract-min %d\n",minvalue);
		}
		//print matrix	
		for(int i = 0 ; i < rownum ; i++){
			if(matrix[i][0] == 999999){
				//printf("x");
				fprintf(fileout,"x");	
			}else{
				//printf("%d",matrix[i][0]);
				fprintf(fileout,"%d",matrix[i][0]);
			}
			for(int j = 1 ; j < colnum ; j++){
				//printf(" ");
				fprintf(fileout," ");
				if(matrix[i][j] == 999999){
					//printf("x");
					fprintf(fileout,"x");
				}else{
					//printf("%d",matrix[i][j]);
					fprintf(fileout,"%d",matrix[i][j]);	
				}		
			}
			//printf("\n");
			fprintf(fileout,"\n");
		}
		//printf("\n");
		if(cycle !=1)fprintf(fileout,"\n");
		//printf("k is %d\n",k);
		destroyMatrix(matrix, rownum);
		cycle--;
    }
	fclose(filein);
    fclose(fileout);
	return 0;
} 
