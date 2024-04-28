void printmatrix(double result[14][14]);
int Matrixdotproduct(int A[2][2], int B[2][2]);
void Main(int input[28][28], int filter[2][2],int output [14][14]);
void printmatrix2(double result[7][7]);
void layer1(int input[28][28], double filter[2][2], double output[14][14]);
void layer2(double input[14][14], double filter[2][2], double output[7][7]);
void FIFO(int flag,int data_in ,int data_out );
