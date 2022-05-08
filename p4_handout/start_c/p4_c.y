%{
/* Kenneth Loyola
 * G01211826
 * CS-440
 * 
 * Mython Project 4 - Intermediate Code
 * Translate mython source code to MIPs assembly
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Yacc Variables */
extern int yylineno;
extern int yylex();
int yyerror();

/* Error & Report Messages */
const char* pass_msg = "Input Accepted\n";
const char* mips_entry = "\n.text\n.globl main\nmain:\n";
const char* mips_exit = "\n\tli $v0, 10\n\tsyscall\n";

/* Semantic/IC Functions */
void cleanUp();
void checkAlloc();
void resetScopes();
void resetRegs(int c);
void addToScope();
void printScopes();
void loadStoreRegs(int c);
void pop(); //stack
void push(); //stack
int getOpenReg(int c);
int checkType(char *idName);
int checkID(char *idName);
char* checkIDStr(char *idName);

/* Semantic/IC Variables */
char *funcName = NULL;
char recentReg[5];
int inCall = 0, inPrint = 0, inReturn = 0; //boolean checkers
int callCheck = 0, callArgs = 0; //caller attributes
int strID = 0, stackSize = 0, top = -1, labID = -1; //string and stack/label vars
int *stack = NULL; //stack of labels
int tRegs[8], aRegs[4]; //$t and $a registers (FIXED)

/* Symbol Table Structure */
typedef struct table {
	char *id_name;
	char *strVal;
	int val;
	int type;
} SymbolTable;
//SymbolTable Scope Pointer
SymbolTable *scopes = NULL;
int numScopes = 0; //keeps track number of scopes

%}
 
%token ADD MINUS MUL DIV EQ LT LE GT GE ASSIGN NE
%token DEF ENDDEF IF ENDIF ELSE WHILE ENDWHILE PRINT INPUT TRUE FALSE RETURN
%token LP RP COLON COMMA COMMENT

%union{
	char id_name[100];
	char str[100];
	int num;
	struct {
		char curName[100];
		int reg;
		int val;
		int strChk;
	} local;
}

%token <str> STRING ID
%token <num> NUMBER
%type <local> print_exp expression exp rel_exp term factor
%type <id_name> assign_head
%type <str> call_head

%%

program		: func_list_head end_list

func_list_head	: function_list {
			resetScopes(); //clears out the scope list
			resetRegs(1); //clears out the registers (t's and a's)
			funcName = strdup("global"); //sets function name
			checkAlloc(funcName); //checks allocation
		}

function_list 	: function_list function { 
	       		resetScopes(); //clears out the scope list
		}
		| %empty

function	: func_head statements ENDDEF {
			resetRegs(0); //clears out only t regs
			//if coming from return, then move return value
			if(inReturn) printf("\tmove $v0, %s\n", recentReg);
			//loads return address and returns
			printf("\tlw $ra, %s_RA\n", funcName); 
			printf("\tjr $ra\n");
			resetRegs(0); //resets the registers once again
		}

func_head	: def_head LP parameters RP COLON {
			printf(".text\n\tsw $ra, %s_RA\n", funcName);
			printScopes(); //prints out the scopes 
		}
	  	| def_head LP RP COLON {
			printf(".text\n\tsw $ra, %s_RA\n", funcName);
		}

def_head	: DEF ID {
			printf(".text\n%s:\n.data\n%s_RA: .word 0\n.align 2\n", $2, $2);
			funcName = strdup($2);	//allocates the ID to funcName
			checkAlloc(funcName); //checks allocation
			printf("%s_registers: .space 48\n", funcName);
		}

parameters	: parameters COMMA ID {
	   		//Prints out the parameters and adds it to the scope
			printf("%s_%s: .word 0\n", funcName, $3);
			addToScope($3, "", 2, 0);
		}
		| ID {
			printf("%s_%s: .word 0\n", funcName, $1);
			addToScope($1, "", 2, 0); //adds param to scope
		}

statements	: statements statement 
		| statement

statement	: assignment_stmt 
		| print_stmt 
		| input_stmt 
		| condition_stmt 
		| while_stmt 
		| call_stmt 
		| return_stmt

assignment_stmt	: assign_head expression {
			//uses the recent reg available
			printf("\tsw %s,%s_%s\n", recentReg, funcName, $1);
			resetRegs(0); //resets the registers
			//adds to the scope
			addToScope($1, $2.curName, $2.strChk, $2.val);
		}

assign_head	: ID ASSIGN {
			if(checkID($1) == -1){
				printf(".data\n.align 2\n%s_%s: .word 0\n.text\n", funcName, $1);
				strcpy($$, $1); //assign the ID to the NT attribute
			}
		}

return_stmt	: RETURN exp {
			inReturn = 1;
		}

expression	: rel_exp {
			snprintf(recentReg, 4, "$t%d", $1.reg); //assigns the attribute value
			$$.strChk = 0; //0 for no string (its bool/int)
		}
		| exp {
			//assigns the attribute values for the NT
			$$.reg = $1.reg;
			$$.val = $1.val;
			$$.strChk = $1.strChk;
			strcpy($$.curName, $1.curName); //gets the name
		}

 /* A whole bunch of similar code (not sure if it can be simplified because of NT references; etc. $$ */

rel_exp		: exp EQ exp {
			$$.reg = $1.reg; //assigns the register used
			//prints out the relation expression
			printf("\tseq $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			tRegs[$3.reg] = 0;
		}
		| exp NE exp {
			$$.reg = $1.reg; //assigns the register used
			//prints out the relation expression
			printf("\tsne $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			tRegs[$3.reg] = 0;
		}
		| exp LT exp {
			$$.reg = $1.reg; //assigns the register used
			//prints out the relation expression
			printf("\tslt $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			tRegs[$3.reg] = 0;
		}
		| exp LE exp {
			$$.reg = $1.reg; //assigns the register used
			//prints out the relation expression
			printf("\tsle $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			tRegs[$3.reg] = 0;
		}
		| exp GT exp {
			$$.reg = $1.reg; //assigns the register used
			//prints out the relation expression
			printf("\tsgt $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			tRegs[$3.reg] = 0;
		}
		| exp GE exp {
			$$.reg = $1.reg; //assigns the register used
			//prints out the relation expression
			printf("\tsge $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			tRegs[$3.reg] = 0;
		}
		| LP rel_exp RP {
			$$.reg = $2.reg; //gets the rel_exp reg
		}

exp		: exp ADD term {
			$$.reg = $1.reg; //gets the first register
			$$.val = $1.val + $3.val; //adds them up
			printf("\tadd $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			snprintf(recentReg, 4, "$t%d", $$.reg); //sets recent reg
			tRegs[$3.reg] = 0; //clears operand reg
		}
		| exp MINUS term {
			$$.reg = $1.reg; //gets the first register
			$$.val = $1.val - $3.val; //subtracts them
			printf("\tsub $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			snprintf(recentReg, 4, "$t%d", $$.reg); //sets recent reg
			tRegs[$3.reg] = 0; //clears operand reg
		}
		| term {
			$$.reg = $1.reg; //gets the first reg
			$$.val = $1.val; //gets the value from term attribute
			$$.strChk = $1.strChk; //string checker
			strcpy($$.curName, $1.curName); //gets name
		}

term		: term MUL factor {
			$$.reg = $1.reg; //gets the first register
			$$.val = $1.val * $3.val; //gets product
			printf("\tmul $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			snprintf(recentReg, 4, "$t%d", $$.reg); //sets recent reg
			tRegs[$3.reg] = 0; //clears operand reg
		}
		| term DIV factor {
			$$.reg = $1.reg; //gets the first register
			$$.val = $1.val / $3.val; //divides them (Int)
			printf("\tdiv $t%d,$t%d,$t%d\n", $1.reg, $1.reg, $3.reg);
			snprintf(recentReg, 4, "$t%d", $$.reg); //sets recent reg
			tRegs[$3.reg] = 0; //clears operand reg
		}
		| factor {
			$$.reg = $1.reg; //gets the first reg
			$$.val = $1.val; //gets the value from factor attribute
			$$.strChk = $1.strChk; //string checker
			strcpy($$.curName, $1.curName); //gets name
		}

factor		: LP exp RP {
			$$.reg = $2.reg; //gets the reg from exp
			$$.val = $2.val; //gets the val
			$$.strChk = $2.strChk; //string checker
			strcpy($$.curName, $2.curName);
		}
		| NUMBER {
			$$.reg = getOpenReg(0); //gets an open reg
			$$.val = $1; //gets the value of number
			printf("\tli $t%d, %d\n", $$.reg, $1);
			snprintf(recentReg, 4, "$t%d", $$.reg);
			if(inCall){ //if procedure call
				printf("\tmove $a%d, $t%d\n", getOpenReg(1), $$.reg);
				resetRegs(0);
			}
		}
		| STRING {
			$$.reg = getOpenReg(0); //gets open t reg
			$$.strChk = 1; //string checker to true (1)
			strcpy($$.curName, $1); //sets the current name
			printf(".data\nstr%d:\t.asciiz %s\n.text\n", strID, $1);
			snprintf(recentReg, 4, "$t%d", $$.reg);
			printf("\tla $t%d, str%d\n", $$.reg, strID);
			strID += 1; //increments string counter
		}
		| ID {
			$$.reg = getOpenReg(0); //gets open t reg
			$$.strChk = checkType($1); //check the type of ID
			if($$.strChk){ //if string, then set current name
				strcpy($$.curName, checkIDStr($1));
				checkAlloc($$.curName);
			}
			else //else, set the value to int value of ID
				$$.val = checkID($1);
			snprintf(recentReg, 4, "$t%d", $$.reg); //sets the recent reg
			printf("\tlw %s, %s_%s\n", recentReg, funcName, $1);
			if(inCall){ //if procedure all
				printf("\tmove $a%d, $t%d\n", getOpenReg(1), $$.reg);
				resetRegs(0); //resets the t regs
			}
		}
		| TRUE {
			$$.val = 1; //1 for TRUE
			$$.reg = getOpenReg(0);
			snprintf(recentReg, 4, "$t%d", $$.reg);
			$$.strChk = 0;
			printf("\tli $t%d, 1\n", $$.reg);
		}
		| FALSE {
			$$.reg = getOpenReg(0); //gets open reg
			$$.val = 0; //0 for FALSE
			snprintf(recentReg, 4, "$t%d", $$.reg);
			$$.strChk = 0;
			printf("\tli $t%d, 0\n", $$.reg);
		}
		| MINUS factor {
			printf("\tneg $t%d,$t%d\n", $2.reg, $2.reg);
		}
		| call_stmt

print_stmt	: print_head print_exp RP

print_head	: PRINT LP {
			inPrint = 1; //now in print stmt
		}

print_exp	: print_exp COMMA expression {
			if(inPrint){
				//if string, then syscall 4, else 1
				int sysID = ($3.strChk) ? 4 : 1;
				printf("\tli $v0,%d\n\tmove $a0,%s\n\tsyscall\n", sysID, recentReg);
				resetRegs(0); //resets the t regs
			}
		}
		| expression {
			$$.reg = $1.reg; //gets the expression reg
			$$.val = $1.val; //gets the expression val
			strcpy($$.curName, $1.curName); //gets string
			if(inPrint){
				//if string, then syscall 4, else 1
				int sysID = ($1.strChk) ? 4 : 1;
				printf("\tli $v0,%d\n\tmove $a0,%s\n\tsyscall\n", sysID, recentReg);
				resetRegs(0); //resets the t regs
			}
		}

input_stmt	: assign_head INPUT LP RP {
	   		//syscall on input
			printf("\tli $v0,5\n\tsyscall\n");
			snprintf(recentReg, 4, "$v0"); //stores return value from input call
			printf("\tsw %s,%s_%s\n", recentReg, funcName, $1);
		}

call_stmt	: call_head RP {
			printf("\tjal %s\n", $1); //jump and link
			loadStoreRegs(1); //shows the loading of registers after call
			printf("\tmove $t%d, $v0\n", getOpenReg(0)); //gets return value
			resetRegs(1); //clears out the a and t regs
		}
		| call_head expr_list RP {
			printf("\tjal %s\n", $1); //jump and link
			loadStoreRegs(1); //shows the recovery of regs after call
			printf("\tmove %s,$v0\n", recentReg); //return value
			if(callCheck == 2){ //call checker
				printf("\tmove $a%d,%s\n", callArgs, recentReg);
				callArgs += 1; //increments the arg register counter
			}
			resetRegs(2); //resets only the a regs
			if(strcmp(funcName, "global") == 0) //if global
				callCheck -= 1; //decrements the checker
		}

call_head	: ID LP {
			if(strcmp(funcName, "global") == 0)
				callCheck += 1; //if global, increase call checker
			loadStoreRegs(0); //shows the storing of registers before call
			inCall = 1;
			strcpy($$, $1); //copies the string ID
		}

condition_stmt	: if_head statements ENDIF {
			printf("\nL%d:\n", stack[top]); //shows label
			//pops off the stack
			--top;
			stackSize -= 1; //decreases size
			stack = realloc(stack, sizeof *stack * stackSize);
		}
		| if_head statements else_head statements ENDIF {
			printf("\nL%d:\n", stack[top]); //shows label
			pop(); //pops off the stack
		}

if_head		: IF expression COLON {
			labID += 1;
			//Reallocates the stack for label
			stackSize += 1; //increases size
			stack = realloc(stack, sizeof *stack * stackSize);
			//increases top and sets it to the labels
			++top;
			stack[top] = labID; //sets new label
			//prints out the label to jump to
			printf("\tbeqz $t%d,L%d\n", $2.reg, stack[top]);
		}

else_head	: ELSE COLON {
	  		labID += 1;
			//Reallocates the stack for label
			stackSize += 1; //increases size
			stack = realloc(stack, sizeof *stack * stackSize);
			//increases top and sets it to the labels
			++top;
			stack[top] = labID; //sets new label
	  		//prints out the labels
			printf("\tj L%d\nL%d:\n", stack[top], stack[top-1]);
		}

while_stmt	: while_head statements ENDWHILE {
	   		//prints the labels
			printf("\tj L%d\nL%d:\n", stack[top-1], stack[top]);
			pop(); //pops out the labels
		}

while_head	: WHILE {
			labID += 2; //increase the label counter
			push(); //push the labels onto stack
			printf("L%d:\n", stack[top-1]);
		}
		  expression COLON {
			//prints out the expression's resulting reg and label
			printf("\tbeqz $t%d,L%d\n", $3.reg, stack[top]);
			int tmpReg = getOpenReg(0); //takes a t reg
		}

expr_list	: expr_list COMMA exp 
		| exp

end_list	: { 
	 		// generate .main 
            		printf(mips_entry);
			printf("\n.data\n.align 2\nglobal_registers: .space 48\n.text\n");
          	}
          	  statements { 
			//generate exit 
           		printf(mips_exit);
          	}

%%

/* MAIN METHOD */
int main() {
	//Parser Begins
 	yyparse();
	
	//YAY, REACHED PASS AND GET OUTTA HERE
	fprintf(stderr, "%s", pass_msg);
   	return 0;
}
 
/* YYERROR FUNCTION */
int yyerror(){
	//prints out an error for syntax
   	fprintf(stderr, "Syntax Error at Line %d\n", yylineno);
	cleanUp(); //cleans up memory alloc
   	exit(-1);
}

/* Resets the scope to NULL while freeing up its elements */
void resetScopes(){
	if(scopes){
		//loops through array of scopes
		for(int i = 0; i < numScopes; ++i){
			//free its members
			if(scopes[i].id_name) free(scopes[i].id_name);
			if(scopes[i].strVal) free(scopes[i].strVal);
			scopes[i].id_name = NULL;
			scopes[i].strVal = NULL;
			//free(scopes[i]); //frees the struct
		}
		free(scopes); //frees the scopes array
		scopes = NULL;
	}
}

/* Cleans up memory allocated variables */
void cleanUp(){
	resetScopes(); //cleans up the scope
	if(funcName) free(funcName); //if defined, then free
	if(stack) free(stack); //same here
}

/* Checks for improper memory allocation */
void checkAlloc(char *str){
	if(str == NULL){
		fprintf(stderr, "ERROR: Malloc Null at Line %d\n", yylineno);
		cleanUp(); //cleans up
		exit(-1);
	}
}

/* Resets the registers of t and a */
void resetRegs(int c){
	//var c determines whether to reset t, a, or both
	if(c == 0 || c == 1){
		for(int i = 0; i < 7; ++i) //8 registers of $t
			tRegs[i] = 0; //resets to 0
	}
	
	if(c == 1 || c == 2){
		for(int k = 0; k < 3; ++k) //4 registers of $a
			aRegs[k] = 0; //resets to 0
	}
}

/* Adds scope to scopes array */
void addToScope(char *idName, char* str, int type, int val){
	numScopes += 1; //increments # of scopes for memory alloc
	
	//Extend the memory of scopes
	scopes = realloc(scopes, sizeof *scopes * numScopes);
	
	//Sets the members of the new struct
	int ind = numScopes - 1; //index of new struct
	scopes[ind].id_name = strdup(idName);
	scopes[ind].strVal = strdup(str); //deep copies
	scopes[ind].val = val;
	scopes[ind].type = type;
}

/* Prints out the scopes */
void printScopes(){
	//Loops through the array of scopes
	for(int i = 0; i < numScopes; ++i){
		//prints the scope name and current function name
		printf("\tsw $a%d,%s_%s\n", i, funcName, scopes[i].id_name);
	}
}

/* Prints out the loading/storing of registers after/before procedure */
void loadStoreRegs(int c){
	//If loading, then set string to lw, else sw
	char ins[3];
	if(c == 1)
		strcpy(ins, "lw");
	else
		strcpy(ins, "sw");

	//prints out first load without offset
	printf("\t%s $t0, %s_registers\n", ins, funcName);

	//Int offset for registers
	int offset = 4;
	for(int i = 1; i < 8; ++i){ //loops thru t registers
		printf("\t%s $t%d, %s_registers+%d\n", ins, i, funcName, offset);
		offset += 4;
	}
	
	//Now loop through the a registers
	for(int k = 0; k < 4; ++k){
		printf("\t%s $a%d, %s_registers+%d\n", ins, k, funcName, offset);
		offset += 4; //increments offset by 4 bytes
	}
}

/* Pops the two labels off the stack */
void pop(){
	stack[top] = 0; //'frees' the top of the stack
	--top; //decrements
	stack[top] = 0; //frees the next top
	--top;

	stackSize -= 2; //decreases size

	//Reallocates the stack
	stack = realloc(stack, sizeof *stack * stackSize);
}

/* Push two labels onto the stack */
void push(){
	//Reallocates the stack for two more labels
	stackSize += 2; //increases size
	stack = realloc(stack, sizeof *stack * stackSize);
	
	//increases top and sets it to the labels
	++top;
	stack[top] = labID;
	++top;
	stack[top] = labID + 1;
}

/* Gets an available t or a register (via c var) */
int getOpenReg(int c){
	if(c == 0){ //if t regs, then loop and find one
		for(int i = 0; i < 8; ++i){
			if(tRegs[i] == 0){
				tRegs[i] = 1;
				return i; //return reg number(index)
			}
		}
	}
	else{ //else loop through the arg regs
		for(int k = 0; k < 4; ++k){
			if(aRegs[k] == 0){
				aRegs[k] = 1;
				return k; //return a reg num
			}
		}
	}

	return -1; //satisfies -Wreturn-type warning
}

/* Checks the type of the idName if in scope */
int checkType(char *idName){
	//Loops through the scopes
	for(int i = 0; i < numScopes; ++i){
		if(strcmp(scopes[i].id_name, idName) == 0)
			return scopes[i].type;
	}
	//else return -1;
	return -1;
}

/* Checks for ID within the scopes array */
int checkID(char *idName){
	//Loops thru the scopes
	for(int i = 0; i < numScopes; ++i){
		if(strcmp(scopes[i].id_name, idName) == 0) //compare check
			return scopes[i].val;
	}
	return -1;
}

/* Checks for the string val of the given ID within the scopes */
char* checkIDStr(char *idName){
	//Loops thru the scopes
	for(int i = 0; i < numScopes; ++i){
		if(strcmp(scopes[i].id_name, idName) == 0) //compare check
			return scopes[i].strVal;
	}
	return "";
}












