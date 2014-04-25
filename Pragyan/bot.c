#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 
#include <stdlib.h> 

struct GameUnits{ 
	char id[3]; 
	int posX; 
	int posY; 
	int health; 
	char color[4];
}; 
struct GameUnitsMod{
	int alive; 
	char id[3]; 
	int posX; 
	int posY; 
	int health; 
	char color[4]; 
}; 
	
char map[17][22], color;
int dx, dy;
struct GameUnits temp;
struct GameUnitsMod pes1, pes2, pes3, pet1, pet2, peh1, pehq;
struct GameUnitsMod pms1, pms2, pms3, pmt1, pmt2, pmh1, pmhq;
struct GameUnitsMod ces1, ces2, ces3, cet1, cet2, ceh1, cehq;
struct GameUnitsMod cms1, cms2, cms3, cmt1, cmt2, cmh1, cmhq;
/*** Assignment of necessary variables ***/
void mark(struct GameUnitsMod g){
	map[g.posY][g.posX] = g.id[0];
}

void assign2(struct GameUnitsMod *gu, struct GameUnits t){
	if(t.health > 0) gu->alive = 1;
	else gu->alive = 1;
	strcpy(gu->id, t.id);
	strcpy(gu->color, t.color);
	gu->posX = t.posX;
	gu->posY = t.posY;
	gu->health = t.health;
}

void assign(struct GameUnits t, int type, int when){
	if(strcmp(t.id, "s1") == 0){
		if(type==1){
			if(when=='p') assign2(&pms1, t);
			else assign2(&cms1, t), mark(cms1);
		}else{
			if(when=='p') assign2(&pes1, t);
			else assign2(&ces1, t), mark(ces1);
		}
	}else if(strcmp(t.id, "s2") == 0){
		if(type==1){
			if(when=='p') assign2(&pms2, t);
			else assign2(&cms2, t),  mark(cms2);
		}else{
			if(when=='p') assign2(&pes2, t);
			else assign2(&ces2, t), mark(ces2);
		}
	}else if(strcmp(t.id, "s3") == 0){
		if(type==1){
			if(when=='p') assign2(&pms3, t);
			else assign2(&cms3, t), mark(cms3);
		}else{
			if(when=='p') assign2(&pes3, t);
			else assign2(&ces3, t), mark(ces3);
		}
	}else if(strcmp(t.id, "t1") == 0){
		if(type==1){
			if(when=='p') assign2(&pmt1, t);
			else assign2(&cmt1, t),  mark(cmt1);
		}else{
			if(when=='p') assign2(&pet1, t);
			else assign2(&cet1, t), mark(cet1);
		}
	}else if(strcmp(t.id, "t2") == 0){
		if(type==1){
			if(when=='p') assign2(&pmt2, t);
			else assign2(&cmt2, t), mark(cmt2);
		}else{
			if(when=='p') assign2(&pet2, t);
			else assign2(&cet2, t), mark(cet2);
		}
	}else if(strcmp(t.id, "h1") == 0){
		if(type==1){
			if(when=='p') assign2(&pmh1, t);
			else assign2(&cmh1, t), mark(cmh1);
		}else{
			if(when=='p') assign2(&peh1, t);
			else assign2(&ceh1, t),  mark(ceh1);
		}
	}else if(strcmp(t.id, "hq") == 0){
		if(type==1){
			if(when=='p') assign2(&pmhq, t);
			else assign2(&cmhq, t);
		}else{
			if(when=='p') assign2(&pehq, t);
			else assign2(&cehq, t);
		}
	}
}

void assignRemainingValues(){
	if(pes1.alive != 1) pes1.alive = -1;
	if(pes2.alive != 1) pes2.alive = -1;
	if(pes3.alive != 1) pes3.alive = -1;
	if(pet1.alive != 1) pet1.alive = -1;
	if(pet2.alive != 1) pet2.alive = -1;
	if(peh1.alive != 1) peh1.alive = -1;
	if(pehq.alive != 1) pehq.alive = -1;

	if(pms1.alive != 1) pms1.alive = -1;
	if(pms2.alive != 1) pms2.alive = -1;
	if(pms3.alive != 1) pms3.alive = -1;
	if(pmt1.alive != 1) pmt1.alive = -1;
	if(pmt2.alive != 1) pmt2.alive = -1;
	if(pmh1.alive != 1) pmh1.alive = -1;
	if(pmhq.alive != 1) pmhq.alive = -1;

	if(ces1.alive != 1) ces1.alive = -1;
	if(ces2.alive != 1) ces2.alive = -1;
	if(ces3.alive != 1) ces3.alive = -1;
	if(cet1.alive != 1) cet1.alive = -1;
	if(cet2.alive != 1) cet2.alive = -1;
	if(ceh1.alive != 1) ceh1.alive = -1;
	if(cehq.alive != 1) cehq.alive = -1;

	if(cms1.alive != 1) cms1.alive = -1;
	if(cms2.alive != 1) cms2.alive = -1;
	if(cms3.alive != 1) cms3.alive = -1;
	if(cmt1.alive != 1) cmt1.alive = -1;
	if(cmt2.alive != 1) cmt2.alive = -1;
	if(cmh1.alive != 1) cmh1.alive = -1;
	if(cmhq.alive != 1) cmhq.alive = -1;
}

void constructMap(){
	strcpy(map[0], "oooo---------ooooooo");
	strcpy(map[1], "o--oo------ooooooooo");
	strcpy(map[2], "o-oooo-----ooooooooo");
	strcpy(map[3], "oooo-ooo--ooooooooo-");
	strcpy(map[4], "oooo---oooooo--ooo--");
	strcpy(map[5], "oooooo-ooooo---ooo--");
	strcpy(map[6], "oooooooooooo---ooo--");
	strcpy(map[7], "-oooo-oooooooo-oooo-");
	strcpy(map[8], "--ooo---oooooooooooo");
	strcpy(map[9], "--ooo---ooooo-oooooo");
	strcpy(map[10],"--ooo--oooooo---oooo");
	strcpy(map[11],"-ooooooooo--ooo-oooo");
	strcpy(map[12],"ooooooooo-----oooo-o");
	strcpy(map[13],"ooooooooo------oo--o");
	strcpy(map[14],"ooooooo---------oooo");
}
/*** End of assignment of necessary variables ***/

/*** Find changes from last state ***/
static const int NOCHANGE = 0;
static const int HQATTACKED = 1;
static const int SATTACKED = 2;
static const int TATTACKED = 3;
static const int HATTACKED = 4;
static const int SKILLED = 22;
static const int TKILLED = 33;
static const int HKILLED = 44;
static const int ENEMYMOVED = 5;
int TATTACKEDWHO = 0;
int SATTACKEDWHO = 0;
int MOVESBY = 0;	// moves 0-s1, 1-s2, 2-s3, 3-t1, 4-t2, 5-h
int findChanges(){
	// attacks by the enemy
	if(cmhq.health < pmhq.health) return HQATTACKED;
	if(cms1.alive == -1 && pms1.alive == 1){ cms1.alive = -1; SATTACKEDWHO = 1; return SKILLED; }
	if(cms1.health < pms1.health && pms1.alive == 1){ SATTACKEDWHO = 1; return SATTACKED; }
	if(cms2.alive == -1 && pms2.alive == 1){ cms2.alive = -1; SATTACKEDWHO = 2; return SKILLED; }
	if(cms2.health < pms2.health && pms2.alive == 1){ SATTACKEDWHO = 2; return SATTACKED; }
	if(cms3.alive == -1 && pms3.alive == 1){ cms3.alive = -1; SATTACKEDWHO = 3; return SKILLED; }
	if(cms3.health < pms3.health && pms3.alive == 1){ SATTACKEDWHO = 3; return SATTACKED; }
	if(cmt1.alive == -1 && pmt1.alive == 1){ cmt1.alive = -1; TATTACKEDWHO = 1; return TKILLED; }
	if(cmt1.health < pmt1.health && pmt1.alive == 1){ TATTACKEDWHO = 1; return TATTACKED; }
	if(cmt2.alive == -1 && pmt2.alive == 1){ cmt2.alive = -1; TATTACKEDWHO = 2; return TKILLED; }
	if(cmt2.health < pmt2.health && pmt2.alive == 1){ TATTACKEDWHO = 2; return TATTACKED; }
	if(cmh1.alive == -1 && pmh1.alive == 1){ cmh1.alive = -1; return HKILLED; }
	if(cmh1.health < pmh1.health && pmh1.alive == 1){ return HATTACKED; }

	// find the moves of the enemy
	if(ces1.posX != pes1.posX || ces1.posY != pes1.posY){ MOVESBY = 0; return ENEMYMOVED; }
	if(ces2.posX != pes2.posX || ces2.posY != pes2.posY){ MOVESBY = 1; return ENEMYMOVED; }
	if(ces3.posX != pes3.posX || ces3.posY != pes3.posY){ MOVESBY = 2; return ENEMYMOVED; }
	if(cet1.posX != pet1.posX || cet1.posY != pet1.posY){ MOVESBY = 3; return ENEMYMOVED; }
	if(cet2.posX != pet2.posX || cet2.posY != pet2.posY){ MOVESBY = 4; return ENEMYMOVED; }
	if(ceh1.posX != peh1.posX || ceh1.posY != peh1.posY){ MOVESBY = 5; return ENEMYMOVED; }

	return NOCHANGE;
}
/*** End of changes from last state ***/

/*** Supportive functions ***/
int inrange(struct GameUnitsMod g, int a, int b, int c, int d){
	if(g.posY >= a && g.posY <=b && g.posX >= c && g.posY <= d) return 1;
	return 0;
}
/*** End of Supportive functions ***/

/*** Action functions ***/
int nochange(){
	printf("AttackUnit(t2,hq)");
}
int hqattacked(){
	int i, j, f=0;
	// check the possible range of attack
	// use h1 to attack the attacker
	if(color == 'b'){
		// check from 9,14 to 14,19
		for(i=9; i<=14; i++){
			f = 0;
			for(j=14; j<=19; j++){
				if(ceh1.posY == i && ceh1.posX == j){
					if(cmt1.alive == 1 && inrange(cmt1, 9, 14, 14, 19)){ printf("AttackPoint(t1,%d,%d)",j,i); return 0; }
					if(cmh1.alive == 1 && inrange(cmh1, 9, 14, 14, 19)){ printf("AttackPoint(h1,%d,%d)",j,i); return 0; }
					if(cms1.alive == 1 && inrange(cms1, 9, 14, 14, 19)){ printf("AttackPoint(s1,%d,%d)",j,i); return 0; }
					if(cms2.alive == 1 && inrange(cms2, 9, 14, 14, 19)){ printf("AttackPoint(s2,%d,%d)",j,i); return 0; }
					if(cms3.alive == 1 && inrange(cms3, 9, 14, 14, 19)){ printf("AttackPoint(s3,%d,%d)",j,i); return 0; }
				}
				else if(ces1.posY == i && ces1.posX == j){
					
				}
				else if(ces2.posY == i && ces2.posX == j){

				}
				else if(ces3.posY == i && ces3.posX == j){

				}
				else if(cet1.posY == i && cet1.posX == j){

				}
				else if(cet2.posY == i && cet2.posX == j){

				}
			}
		}
	}else{
		// check from 0,0 to 5,5

	}
}
int skilled(){

}
int sattacked(){

}
int tkilled(){

}
int tattacked(){

}
int hkilled(){

}
int hattacked(){

}
int enemymoved(){

}
/*** End of Action Functions ***/

int myNextMove(struct GameUnits previousState[], struct GameUnits currentState[], char myColor){
	int i;
	color = myColor;
	if(myColor == 'r') dx = dy = 1;
	else dx = dy = -1;

	for(i=0; i<14; i++){
		temp = previousState[i];
		if(temp.color[0] == myColor) assign(temp, 1, 'p');
		else assign(temp, 2, 'p');
		temp = currentState[i];
		if(temp.color[0] == myColor) assign(temp, 1, 'c');
		else assign(temp, 2, 'c');
	}

	assignRemainingValues();
	constructMap();
	int change = findChanges();

	if(change == NOCHANGE) return nochange();
	else if (change == HQATTACKED) return hqattacked();
	else if (change == SKILLED) return skilled();
	else if (change == SATTACKED) return sattacked();
	else if (change == TKILLED) return tkilled();
	else if (change == TATTACKED) return tattacked();
	else if (change == HKILLED) return hkilled();
	else if (change == HATTACKED) return hattacked();
	else if (change == ENEMYMOVED) return enemymoved();
	else return nochange();
}

int main(){
	return 0;
}