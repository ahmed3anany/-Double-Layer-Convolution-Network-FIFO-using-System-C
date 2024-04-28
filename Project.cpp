#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
using namespace std;
void printmatrix(double result[14][14])
{int i;
int j;
 for(i = 0; i < 14; ++i)
 {
	 for(j = 0; j < 14; ++j)
	 {
		 printf("%f ",result[i][j]);
		 if(j == 13)
			 printf("\n");
 }}}
void printmatrix2(double result[7][7])
{int i;
int j;
 for(i = 0; i < 7; ++i)
 {
	 for(j = 0; j < 7; ++j)
	 {
		 printf("%f ",result[i][j]);
		 if(j == 6)
			 printf("\n");
 }}}
int Matrixdotproduct(int A[2][2], int B[2][2]) {
    int C = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[1][0]*B[0][1] + A[1][1]*B[1][1];
    return C;
}

void layer1(int input[28][28], double filter[2][2], double output[14][14]) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            // get the current 2x2 block
            double block[2][2] = {{input[i*2][j*2], input[i*2][j*2+1]}, {input[i*2+1][j*2], input[i*2+1][j*2+1]}};

            // perform element-wise multiplication with the filter and sum the results
            double sum = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    sum += block[k][l] * filter[k][l];
                }
            }

            // assign the sum to the corresponding output element
            output[i][j] = sum;
        }
    }
}
void layer2(double input[14][14], double filter[2][2], double output[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            int block[2][2] = {{input[i*2][j*2], input[i*2][j*2+1]}, {input[i*2+1][j*2], input[i*2+1][j*2+1]}};


            int sum = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    sum += block[k][l] * filter[k][l];
                }
            }


            output[i][j] = sum;
        }
    }
}
//void Main(int input[28][28], int filter[2][2],int output [14][14]){
//	int x;
//	int y;
//	int stride = 2;
//	int M[4];
//	int x_axis=0;
//	int y_axis=0;
//	int Matrix[2][2];
//	int q=0;
//	int output_vec[1][196];
//	int counter = 0;
//		while(y_axis < 28){
//			while (x_axis < 28){
//				for (x = y_axis; x < (y_axis+2);x++){
//					for(y = x_axis ;y < (x_axis+2);y++){
//						M[q]=input[x][y];
//						q++;
//					}
//				}
//				q = 0;
//				Matrix[0][0]=M[0];
//				Matrix[0][1]=M[1];
//				Matrix[1][0]=M[2];
//				Matrix[1][1]=M[3];
//				printmatrix2(Matrix);
//				output_vec[1][counter]= Matrixdotproduct(Matrix,filter);
//				//printf("%d ",output_vec[1][counter]);
//
//				x_axis = x_axis+ 2;
//				counter ++;
//			}
//		x_axis = 0;
//		y_axis = y_axis+ 2;
//
//		}
//		printf("\n");
//		//printf("%d ",output_vec);
//	int OX;
//	int OY;
//	int counter2=0;
//	for(OX = 0;OX < 14;OX++){
//		for(OY = 0;OY<14;OY++){
//			output[OX][OY]= output_vec[1][counter2];
//			counter2 ++;
//		}
//		OY =0;
//	}
////	printmatrix(output);
//}

void conv (int input[28][28], double filter1[2][2],double filter2[2][2],double output[7][7]){

double out [14][14];
layer1(input,filter1,out);
layer2(out,filter2,output);
}
//void FIFO(int flag,int data_in ,int data_out ) {
//    int buffer[199];
//    int write_ptr;
//    int read_ptr;
//    int num_items;
//
////    FIFO() : write_ptr(0), read_ptr(0), num_items(0) {}
//
//    if(flag == 1){
//        buffer[write_ptr] = data_in;
//        write_ptr++;
//        num_items++;
//        if (write_ptr == 196) {
//            write_ptr = 0;
//        }
//    }
//
//    if(flag == 0){
//        data_out = buffer[read_ptr];
//        read_ptr++;
//        num_items--;
//        if (read_ptr == 196) {
//            read_ptr = 0;
//        }
//    }

//    bool is_empty() const {
//        return num_items == 0;
//    }
//
//    bool is_full() const {
//        return num_items == FIFO_DEPTH;
//    }


