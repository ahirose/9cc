#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//トークンの種類
typedef enum{
	TK_RESERVED, //記号
	TK_NUM, //整数トークン
	TK_EOF, //入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

//トークン型
struct Token
{
	TokenKind kind; //トークン型
	Token *next;	//次の入力トークン
	int val;	// kindがTK_NUMの場合、その数値
	char *str;	//トークン文字列
};

//現在着目しているトークン
Token *token;

//エラーを報告するための関数
//printfと同じ引数をとる

void error(char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	exit(1);
}

// return true and step forward to the next token if the next one is the expected character
// return false for the others.
bool consume(char op){
	if(token->kind != TK_RESERVED || token->str[0] != op)
		error("''%c'ではありません",op);
	token=token->next;
}


// step forward to the next token if the next one is the expected character,
// show error for the others
void expect(char op){
	if(token->kind!=TK_RESERVED||)
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "you need two parameters\n");
		return 1;
	}
	char *p = argv[1];

	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");
	printf("  mov rax, %ld\n", strtol(p, &p, 10));

	while (*p)
	{
		if (*p == '+')
		{
			p++;
			printf(" add rax, %ld\n", strtol(p, &p, 10));
			continue;
		}

		if (*p == '-')
		{
			p++;
			printf(" sub rax, %ld\n", strtol(p, &p, 10));
			continue;
		}

		fprintf(stderr, "undefined charactor: '%c'\n", *p);
		return 1;
	}
	printf("  ret\n");
	return 0;
}
