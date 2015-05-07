/*Universidade Federal de Alagoas - Campus A.C. Simões
Developer: Paulo Henrique da Silva Santos
Description: Somador de binário 4 bits.
*/
#include <stdio.h>

//Gate XOR
gateXor(int bit1, int bit2){
	return bit1 ^ bit2;
}
 //Gate AND
gateAnd(int bit1, int bit2){
	return bit1 & bit2
}
 //Gate OR
gateOr(int bit1, int bit2){
	return bit | bit2;
}

int main(int argc, char *argv[ ]) {
	int binaryOne[3], binaryTwo[3];
	int sum[3], i;
	
	//Character to integer conversion
	
	binaryOne[0]=argv[1][0]-48;
	binaryOne[1]=argv[1][1]-48;
	binaryOne[2]=argv[1][2]-48;
	binaryOne[3]=argv[1][3]-48;
	
	binaryTwo[0]=argv[2][0]-48;
	binaryTwo[1]=argv[2][1]-48;
	binaryTwo[2]=argv[2][2]-48;
	binaryTwo[3]=argv[2][3]-48;
	
	//carry
	carryIn=0;
	carryOut=0;
	
	//sum
	for(i=3; i>=0; i--){
		sum[i]=gateXor(carryIn,gateXor(binaryOne[i], binaryTwo[i]));
		carryOut=gateOr(gateAnd(binaryOne[i] + binaryTwo[i]),gateAnd(gateXor(binaryOne[i] + binaryTwo[i], carryIn)));
		carryIn=carryOut;
	}
	
	if(carryIn == 1){
		printf("%d %d %d %d %d\n", carryIn, sum[0], sum[1], sum[2], sum[3]);
	}else{
		printf("%d %d %d %d\n", sum[0], sum[1], sum[2], sum[3]);
			
	}
		
}
