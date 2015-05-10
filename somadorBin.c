/* 
UFAL - Campus A.C. Simões 
Developer: Paulo Henrique da Silva Santos
Computer science - 2015.1 
*/

#include <stdio.h>

// Gate XOR
int gateXor(int bit1, int bit2){
	return bit1 ^ bit2;
}
 // Gate AND
int gateAnd(int bit1, int bit2){
	return bit1 & bit2;
}
 // Gate OR
int gateOr(int bit1, int bit2){
	return bit1 | bit2;
}

int main(int argc, char *argv[]) {
	int binaryOne[4], binaryTwo[4];
	int sum[4], i;
	
	// Character to integer conversion and atribution paramments
	for(i=0; i <= 4; i++){
		binaryOne[i] = argv[1][i] - 48;
		binaryTwo[i] = argv[2][i] - 48;
    }
    
	// Carry
	int carryIn = 0;
	int carryOut = 0;
	
	// Sum
	for(i = 3; i >= 0; i--){
		sum[i] = gateXor(carryIn,gateXor(binaryOne[i], binaryTwo[i]));
		carryOut = gateOr(gateAnd(binaryOne[i], binaryTwo[i]), gateAnd(carryIn, gateXor(binaryOne[i], binaryTwo[i])));
		carryIn = carryOut;
	}
	
	// Results
	if(carryIn == 1){
		printf("%d%d%d%d%d\n", carryIn, sum[0], sum[1], sum[2], sum[3]);
	} else{
		printf("%d%d%d%d\n", sum[0], sum[1], sum[2], sum[3]);
			
	}

	return 0;
}
